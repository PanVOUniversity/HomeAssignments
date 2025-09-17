# **Code Documentation for Lab1 Image Processing**

This document provides detailed documentation for the C++ code used in Lab1, which focuses on fundamental image processing operations, including parallelization using OpenMP.

## **1\. Image Struct (bmp.h)**

The Image struct encapsulates the core image data and processing functionalities. It handles reading, writing, transforming, and applying filters to grayscale raw image data.

### **Member Variables**

* int width;: Stores the width of the image in pixels.  
* int height;: Stores the height of the image in pixels.  
* std::string path;: Stores the file path of the input raw image.

### **Constructor**

* Image(int width, int height, std::string path)  
  * **Purpose:** Initializes an Image object with specified dimensions and input file path.  
  * **Parameters:**  
    * width: The width of the image.  
    * height: The height of the image.  
    * path: The path to the raw image file.

### **Member Functions**

#### **std::vector\<unsigned char\> readToVector(std::string path, int size)**

* **Purpose:** Reads raw image data from a specified file into a 1D std::vector\<unsigned char\>.  
* **Parameters:**  
  * path: The path to the raw image file to be read.  
  * size: The expected size of the image data in bytes (width \* height for grayscale).  
* **Returns:** A std::vector\<unsigned char\> containing the raw pixel data.  
* **Error Handling:** Throws std::runtime\_error if the file cannot be opened or read.

#### **void writeToRaw(std::string filename, std::vector\<unsigned char\> vector)**

* **Purpose:** Writes a 1D std::vector\<unsigned char\> (raw pixel data) to a specified file.  
* **Parameters:**  
  * filename: The name of the output raw file.  
  * vector: The std::vector\<unsigned char\> containing the pixel data to be written.  
* **Error Handling:** Throws std::runtime\_error if the file cannot be opened for writing.

#### **std::vector\<std::vector\<unsigned char\>\> oneDimToTwoDim(std::vector\<unsigned char\> one\_dim)**

* **Purpose:** Converts a 1D vector of image data into a 2D vector (matrix) representation.  
* **Parameters:**  
  * one\_dim: The 1D std::vector\<unsigned char\> containing the image data.  
* **Returns:** A std::vector\<std::vector\<unsigned char\>\> representing the image as a 2D grid.  
* **Parallelization:** This function utilizes \#pragma omp parallel for collapse(2) to parallelize the nested loops that perform the conversion, potentially speeding up the data restructuring.

#### **std::vector\<unsigned char\> twoDimToOneDim(std::vector\<std::vector\<unsigned char\>\> two\_dim)**

* **Purpose:** Converts a 2D vector (matrix) representation of image data back into a 1D vector.  
* **Parameters:**  
  * two\_dim: The 2D std::vector\<std::vector\<unsigned char\>\> representing the image.  
* **Returns:** A std::vector\<unsigned char\> containing the image data in a 1D format.  
* **Parallelization:** Similar to oneDimToTwoDim, this function also uses \#pragma omp parallel for collapse(2) for parallel execution of the conversion loops.

#### **std::vector\<unsigned char\> clockwiseRotate(std::vector\<unsigned char\> img)**

* **Purpose:** Rotates a 1D image vector 90 degrees clockwise.  
* **Parameters:**  
  * img: The 1D std::vector\<unsigned char\> of the input image.  
* **Returns:** A std::vector\<unsigned char\> representing the rotated image.  
* **Process:**  
  1. Converts the input 1D image to a 2D representation using oneDimToTwoDim.  
  2. Applies the clockwise rotation logic by remapping pixel coordinates.  
  3. Converts the rotated 2D image back to 1D using twoDimToOneDim.  
* **Parallelization:** The core rotation loop is parallelized using \#pragma omp parallel for collapse(2).

#### **std::vector\<unsigned char\> counterClockwiseRotate(std::vector\<unsigned char\> img)**

* **Purpose:** Rotates a 1D image vector 90 degrees counter-clockwise.  
* **Parameters:**  
  * img: The 1D std::vector\<unsigned char\> of the input image.  
* **Returns:** A std::vector\<unsigned char\> representing the counter-clockwise rotated image.  
* **Process:** Achieves a counter-clockwise rotation by performing three consecutive clockwise rotations using the clockwiseRotate function.

#### **std::pair\<std::vector\<std::vector\<float\>\>, int\> makeKernel(int sigma)**

* **Purpose:** Generates a 2D Gaussian kernel (filter matrix) based on a given sigma value.  
* **Parameters:**  
  * sigma: The standard deviation for the Gaussian distribution, controlling the blur intensity.  
* **Returns:** A std::pair containing:  
  * A std::vector\<std::vector\<float\>\> representing the Gaussian kernel.  
  * An int indicating the kernel\_length (size of the square kernel).  
* **Process:** Calculates Gaussian values for each element in the kernel and then normalizes the kernel so that the sum of all its elements is 1\. This ensures the image brightness is preserved after convolution.  
* **Note:** The loops within makeKernel are small and are not parallelized, as the overhead of OpenMP would likely outweigh any benefits.

#### **template\<typename T\> T clamp(T value, T min\_value, T max\_value)**

* **Purpose:** A utility template function to clamp a value within a specified minimum and maximum range.  
* **Parameters:**  
  * value: The input value to be clamped.  
  * min\_value: The minimum allowed value.  
  * max\_value: The maximum allowed value.  
* **Returns:** The clamped value.  
* **Usage:** Used in saveAsGaussianImage to ensure pixel values remain within the valid 0-255 range after convolution.

#### **void saveAsGaussianImage(std::vector\<unsigned char\> img, int sigma)**

* **Purpose:** Applies a Gaussian blur filter to an image and saves the blurred image to a new raw file named gaussian\_blurred.raw.  
* **Parameters:**  
  * img: The 1D std::vector\<unsigned char\> of the input image.  
  * sigma: The standard deviation for the Gaussian kernel, controlling the blur intensity.  
* **Process:**  
  1. Converts the input 1D image to a 2D representation.  
  2. Generates a Gaussian kernel using makeKernel.  
  3. Performs a 2D convolution of the image with the generated kernel. This is the most computationally intensive step.  
  4. Clamps the resulting pixel values to the 0-255 range.  
  5. Converts the blurred 2D image back to 1D.  
  6. Saves the final blurred image to gaussian\_blurred.raw.  
* **Parallelization:** The main convolution loops (iterating over image pixels y and x) are heavily parallelized using \#pragma omp parallel for collapse(2). This significantly speeds up the blurring process by distributing the pixel calculations across multiple CPU threads.

## **2\. lab1.cpp**

This file contains the main function and a test function used for demonstrating and timing the image processing operations.

### **void test()**

* **Purpose:** Orchestrates the image processing operations and measures their execution times.  
* **Process:**  
  1. Loads the lena\_gray.raw image.  
  2. Performs clockwiseRotate and measures its time.  
  3. Performs counterClockwiseRotate and measures its time.  
  4. Applies saveAsGaussianImage (Gaussian blur with sigma=5) to the counter-clockwise rotated image and measures its time.  
  5. Prints the execution times for each operation to the console.  
  6. Saves the output images (cwrotated.raw, ccwrotated.raw, gaussian\_blurred.raw).  
* **Timing:** Uses std::chrono::high\_resolution\_clock for precise time measurements.

### **int main()**

* **Purpose:** The entry point of the program.  
* **Process:** Simply calls the test() function to execute the image processing and timing operations.

## **3\. OpenMP Usage Summary**

OpenMP directives (\#pragma omp parallel for collapse(2)) are strategically placed in computationally intensive loops within the Image struct's methods. The collapse(2) clause is used to parallelize two nested loops as a single work-sharing construct, which can improve load balancing and efficiency for 2D array processing. This approach allows the program to leverage multiple CPU cores, leading to significant speedups for operations like Gaussian blur.

## **4\. Building and Running**

For detailed instructions on how to build and run the sequential and parallel versions of the project, please refer to the README.md file. The Makefile is configured to create two distinct executables (start\_sequential and start\_parallel) for easy comparison.