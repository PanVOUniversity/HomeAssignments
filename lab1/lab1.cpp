/*Pan Vladimir st128934@student.spbu.ru
  BMP
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include "bmp.h"
#include <chrono> // For timing utilities
#include <iomanip> // For std::fixed and std::setprecision


void test()
{
    // Define the path to the input image. Ensure 'lena_gray.raw' is in the same directory.
    std::string path = "lena_gray.raw"; 
    // Initialize Image object with dimensions and path.
    Image image = Image(512, 512, path);
    std::cout << "Image dimensions: " << image.width << "x" << image.height << std::endl;
    std::cout << "Image size: " << image.width * image.height << " bytes" << std::endl;

    // Read the image data into a 1D vector.
    std::vector<unsigned char> img_data = image.readToVector(path, image.width * image.height);

    // Set precision for outputting floating-point numbers (durations).
    std::cout << std::fixed << std::setprecision(6);

    // --- Timing for clockwiseRotate ---
    std::cout << "\n--- Measuring clockwiseRotate ---" << std::endl;
    auto start_cw = std::chrono::high_resolution_clock::now(); // Record start time
    std::vector<unsigned char> cw_rotated_img = image.clockwiseRotate(img_data); // Execute function
    auto end_cw = std::chrono::high_resolution_clock::now();   // Record end time
    std::chrono::duration<double> duration_cw = end_cw - start_cw; // Calculate duration
    std::cout << "clockwiseRotate took: " << duration_cw.count() << " seconds" << std::endl;
    image.writeToRaw("cwrotated.raw", cw_rotated_img); // Save output

    // --- Timing for counterClockwiseRotate ---
    std::cout << "\n--- Measuring counterClockwiseRotate ---" << std::endl;
    auto start_ccw = std::chrono::high_resolution_clock::now(); // Record start time
    std::vector<unsigned char> ccw_rotated_img = image.counterClockwiseRotate(img_data); // Execute function
    auto end_ccw = std::chrono::high_resolution_clock::now();   // Record end time
    std::chrono::duration<double> duration_ccw = end_ccw - start_ccw; // Calculate duration
    std::cout << "counterClockwiseRotate took: " << duration_ccw.count() << " seconds" << std::endl;
    image.writeToRaw("ccwrotated.raw", ccw_rotated_img); // Save output

    // --- Timing for saveAsGaussianImage ---
    // Applying Gaussian blur to the counter-clockwise rotated image, as in the original `test()` function.
    std::cout << "\n--- Measuring saveAsGaussianImage (with sigma=5) ---" << std::endl;
    auto start_gaussian = std::chrono::high_resolution_clock::now(); // Record start time
    image.saveAsGaussianImage(ccw_rotated_img, 5); // Execute function
    auto end_gaussian = std::chrono::high_resolution_clock::now();   // Record end time
    std::chrono::duration<double> duration_gaussian = end_gaussian - start_gaussian; // Calculate duration
    std::cout << "saveAsGaussianImage took: " << duration_gaussian.count() << " seconds" << std::endl;
    
    std::cout << "\nGenerated output files: cwrotated.raw, ccwrotated.raw, gaussian_blurred.raw" << std::endl;
}

int main()
{
    test(); // Call the test function to perform image operations and timing
    return 0; // Indicate successful execution
}
