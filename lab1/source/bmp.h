/*Pan Vladimir st128934@student.spbu.ru
  BMP
*/
#ifndef BMP
#define BMP
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<cmath>
#include<utility>

#include <omp.h>


struct Image
{
public:
    
    int width;
    int height;
    std::string path;

    // Constructor to initialize headers
    Image(int width, int height, std::string path) : width(width), height(height), path(path)
    {
        // The 'imageSize' variable was unused, so it has been removed to clear the warning.
    }
    

    // Reads raw image data from a file into a 1D vector of unsigned characters.
    std::vector<unsigned char> readToVector(std::string path, int size)
    {
        // Open the file in binary mode
        std::ifstream file(path, std::ios::binary);
        if (!file.is_open()) {
            throw std::runtime_error("Error: Could not open file " + path);
        }

        // Allocate vector to hold image data
        std::vector<unsigned char> output (size);

        // Read data into the vector
        if (!file.read(reinterpret_cast<char*>(output.data()), size))
        {
            throw std::runtime_error("Error reading file: " + path);
        }
        file.close();
        return output;
    }

    // Writes a 1D vector of unsigned characters to a raw file.
    void writeToRaw(std::string filename, std::vector<unsigned char> vector)
    {
        std::ofstream file(filename, std::ios::binary);
        if (!file.is_open()) {
            throw std::runtime_error("Error: Could not open file for writing " + filename);
        }
        file.write(reinterpret_cast<const char*>(vector.data()), vector.size());
        file.close();
    }

    // Converts a 1D image vector to a 2D image vector (height x width).
    std::vector<std::vector<unsigned char>> oneDimToTwoDim(std::vector <unsigned char> one_dim)
    {
        std::vector<std::vector<unsigned char>> two_dim(height, std::vector<unsigned char>(width));
        // Parallelize this loop for potential minor gains.
        // `collapse(2)` combines the two nested loops into a single parallel region.
        #pragma omp parallel for collapse(2)
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                two_dim[y][x] = one_dim[y * width + x];
            }
        }
        return two_dim;
    }

    // Converts a 2D image vector (height x width) back to a 1D image vector.
    std::vector<unsigned char> twoDimToOneDim(std::vector<std::vector<unsigned char>> two_dim)
    {
        std::vector<unsigned char> one_dim(width * height);
        // Parallelize this loop for potential minor gains.
        #pragma omp parallel for collapse(2)
        for (int y = 0; y < height; y++) // Changed outer loop to y for better cache locality with row-major access
        {
            for (int x = 0; x < width; x++)
            {
                one_dim[y * width + x] = two_dim[y][x];
            }
        }
        return one_dim;
    }

    // Rotates a 1D image vector clockwise by 90 degrees.
    std::vector<unsigned char> clockwiseRotate(std::vector<unsigned char> img)
    {
        // Convert 1D to 2D for easier rotation logic
        auto img_2d = oneDimToTwoDim(img);
        // Create a new 2D vector for the rotated image (dimensions swapped)
        std::vector<std::vector<unsigned char>> rotated_img(width, std::vector<unsigned char>(height));

        // Parallelize the rotation loop.
        #pragma omp parallel for collapse(2)
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                // Clockwise rotation formula: new_x = old_y, new_y = height - old_x - 1
                rotated_img[x][height - y - 1] = img_2d[y][x];
            }
        }

        // Convert the rotated 2D image back to 1D
        return twoDimToOneDim(rotated_img);
    }

    // Rotates a 1D image vector counter-clockwise by 90 degrees (three clockwise rotations).
    std::vector<unsigned char> counterClockwiseRotate(std::vector<unsigned char> img)
    {
        // This function reuses the parallelized clockwiseRotate.
        // Be aware of potential overhead from repeated function calls vs. a single parallel loop
        // for a direct counter-clockwise implementation, but for simplicity, this is fine.
        return clockwiseRotate(clockwiseRotate(clockwiseRotate(img)));
    }

    // Creates a 2D Gaussian kernel for blurring.
    std::pair<std::vector<std::vector<float>>, int> makeKernel(int sigma)
    {
        // Kernel size calculation based on sigma, ensuring an odd size.
        int kernel_size = (sigma * 6) + 1;
        if (kernel_size % 2 == 0) kernel_size++; // Ensure odd size for proper radius calculation
        int kernel_length = kernel_size;    // Kernel is square
        std::vector<std::vector<float>> kernel(kernel_length, std::vector<float>(kernel_length));

        float sum = 0.0f;  // For normalization

        // Compute the Gaussian kernel values.
        // These loops are typically small (e.g., for sigma=5, kernel_size=31x31),
        // so parallelizing them might introduce more overhead than benefit.
        int radius = kernel_length / 2;
        for (int y = -radius; y <= radius; y++)
        {
            for (int x = -radius; x <= radius; x++)
            {
                // Calculate Gaussian value using the formula:
                // G(x,y) = (1 / (2 * pi * sigma^2)) * exp(-(x^2 + y^2) / (2 * sigma^2))
                kernel[y + radius][x + radius] = (1.0f / (2.0f * 3.1415926535f * sigma * sigma)) * std::exp(-((static_cast<float>(x * x + y * y)) / (2.0f * sigma * sigma)));
                sum += kernel[y + radius][x + radius];
            }
        }

        // Normalize the kernel so that the sum of all elements is 1.
        for (int y = 0; y < kernel_length; y++)
        {
            for (int x = 0; x < kernel_length; x++)
            {
                kernel[y][x] /= sum;
            }
        }

        return {kernel, kernel_length};
    }

    // Clamps a value between a minimum and maximum.
    template<typename T>
    T clamp(T value, T min_value, T max_value)
    {
        if (value < min_value)
        {
            return min_value;
        }
        else if (value > max_value)
        {
            return max_value;
        }
        else
        {
            return value;
        }
    }

    // Applies a Gaussian blur to an image and saves it as a new raw file.
    void saveAsGaussianImage(std::vector<unsigned char> img, int sigma)
    {
        // Convert 1D image to 2D for processing (this call is already parallelized).
        auto img_2d = oneDimToTwoDim(img);

        // Create the Gaussian kernel (this part is sequential as it's typically fast).
        auto kernel_pair = makeKernel(sigma);
        auto kernel = kernel_pair.first;
        int kernel_length = kernel_pair.second;
        int kernel_radius = kernel_length / 2;

        // Create an output image initialized with zeros.
        std::vector<std::vector<unsigned char>> blurred_img(height, std::vector<unsigned char>(width, 0));

        // Convolve the image with the kernel. This is the most computationally intensive
        // part and is highly parallelizable.
        // `collapse(2)` parallelizes both outer loops, distributing work across threads.
        #pragma omp parallel for collapse(2)
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                float sum = 0.0f;

                // Inner loops for kernel convolution (each pixel's calculation is independent)
                for (int ky = -kernel_radius; ky <= kernel_radius; ky++)
                    {
                    for (int kx = -kernel_radius; kx <= kernel_radius; kx++)
                    {
                        // Boundary handling using manual clamping to avoid out-of-bounds access.
                        int ny = y + ky;
                        int nx = x + kx;

                        if (ny < 0) ny = 0;
                        if (ny >= height) ny = height - 1;
                        if (nx < 0) nx = 0;
                        if (nx >= width) nx = width - 1;

                        sum += img_2d[ny][nx] * kernel[ky + kernel_radius][kx + kernel_radius];
                    }
                }

                // Store the clamped result (pixel value between 0 and 255).
                blurred_img[y][x] = static_cast<unsigned char>(clamp(std::round(sum), 0.0f, 255.0f));
            }
        }

        // Convert the blurred 2D image back to 1D (this call is already parallelized).
        auto blurred_img_1d = twoDimToOneDim(blurred_img);

        // Save the output as a new RAW file.
        writeToRaw("gaussian_blurred.raw", blurred_img_1d);
    }
};
#endif
