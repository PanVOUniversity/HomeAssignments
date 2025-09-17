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


struct Image
{
public:
    
    int width;
    int height;
    std::string path;

    // Constructor to initialize headers
    Image(int width, int height, std::string path) : width(width), height(height), path(path)
    {
        const int imageSize = width * height;

        
    }
    

    //raw to array
    std::vector<unsigned char> readToVector(std::string path, int size)
    {
        // Open the file in binary mode
        std::ifstream file(path, std::ios::binary);

        //allocating vector
        std::vector<unsigned char> output (size);

        //write into file
        if (!file.read(reinterpret_cast<char*>(output.data()), size))
        {
            throw std::runtime_error("Error reading file: " + path);
        }
        //blueAndRedChanging(output);
        return output;

    }

    void writeToRaw(std::string filename, std::vector<unsigned char> vector)
    {
        std::ofstream file(filename, std::ios::binary);
        file.write(reinterpret_cast<const char*>(vector.data()), vector.size());
        file.close();
    }

    std::vector<std::vector<unsigned char>> oneDimToTwoDim(std::vector <unsigned char> one_dim)
    {
        std::vector<std::vector<unsigned char>> two_dim(height, std::vector<unsigned char>(width));
        for (int y = 0; y<height; y++)
        {
            for (int x = 0; x<width; x++)
            {
                two_dim[y][x] = one_dim[y * width + x];
            }
        }
        return two_dim;
    }

    std::vector<unsigned char> twoDimToOneDim(std::vector<std::vector<unsigned char>> two_dim)
    {
        std::vector<unsigned char> one_dim(width*height);
        for (int x = 0; x<width; x++)
        {
            for (int y = 0; y < height; y++)
            {
                one_dim[x + y * width] = two_dim[y][x];
            }
        }
        return one_dim;
    }

    std::vector<unsigned char> clockwiseRotate(std::vector<unsigned char> img)
    {
        auto img_2d = oneDimToTwoDim(img);
        std::vector<std::vector<unsigned char>> rotated_img(width, std::vector<unsigned char>(height));

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                rotated_img[x][height - y - 1] = img_2d[y][x];
            }
        }

        return twoDimToOneDim(rotated_img);
    }


    std::vector<unsigned char> counterClockwiseRotate(std::vector<unsigned char> img)
    {
        return clockwiseRotate(clockwiseRotate(clockwiseRotate(img)));
    }

    std::pair<std::vector<std::vector<float>>, int> makeKernel(int sigma)
    {
        int kernel_size = (sigma * 6) + 1;  // Kernel size based on sigma
        int kernel_length = kernel_size;    // Kernel is square
        std::vector<std::vector<float>> kernel(kernel_length, std::vector<float>(kernel_length));

        float sum = 0.0f;  // For normalization

        // Compute the kernel
        int radius = kernel_length / 2;
        for (int y = -radius; y <= radius; y++)
        {
            for (int x = -radius; x <= radius; x++)
            {
                // Calculate Gaussian value
                kernel[y + radius][x + radius] = (1.0f / (2.0f * 3.14f * sigma * sigma)) * std::exp(-((x * x + y * y) / (2.0f * sigma * sigma)));
                sum += kernel[y + radius][x + radius];
            }
        }

        // Normalize the kernel so that the sum is 1
        for (int y = 0; y < kernel_length; y++)
        {
            for (int x = 0; x < kernel_length; x++)
            {
                kernel[y][x] /= sum;
            }
        }

        return {kernel, kernel_length};
    }

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

    void saveAsGaussianImage(std::vector<unsigned char> img, int sigma)
    {
        auto img_2d = oneDimToTwoDim(img);

        auto kernel_pair = makeKernel(sigma);
        auto kernel = kernel_pair.first;
        int kernel_length = kernel_pair.second;
        int kernel_radius = kernel_length / 2;

        // Create an output image (initialize with zeros)
        std::vector<std::vector<unsigned char>> blurred_img(height, std::vector<unsigned char>(width, 0));

        // Convolve the image with the kernel
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                float sum = 0.0f;

                for (int ky = -kernel_radius; ky <= kernel_radius; ky++)
                {
                    for (int kx = -kernel_radius; kx <= kernel_radius; kx++)
                    {
                        // Boundary handling using manual clamping
                        int ny = y + ky;
                        int nx = x + kx;

                        if (ny < 0) ny = 0;
                        if (ny >= height) ny = height - 1;
                        if (nx < 0) nx = 0;
                        if (nx >= width) nx = width - 1;

                        sum += img_2d[ny][nx] * kernel[ky + kernel_radius][kx + kernel_radius];
                    }
                }

                // Store the clamped result
                blurred_img[y][x] = static_cast<unsigned char>(clamp(std::round(sum), 0.0f, 255.0f));
            }
        }

        // Convert the blurred 2D image back to 1D
        auto blurred_img_1d = twoDimToOneDim(blurred_img);

        // Save the output as a new RAW file
        writeToRaw("gaussian_blurred.raw", blurred_img_1d);
    }


};
#endif