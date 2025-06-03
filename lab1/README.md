# **Lab1: Image Processing with Parallelization**

## **Author**

Пан Владимир Олегович, группа 24.Б81-мм

## **Contacts**

st128934@student.spbu.ru

## **Description**

This project, "Lab1," focuses on fundamental image processing operations, including reading and writing raw image files, converting between 1D and 2D image representations, rotating images (clockwise and counter-clockwise), and applying a Gaussian blur filter.  
Key Update: This version of the project has been enhanced with OpenMP parallelization for computationally intensive tasks, particularly the Gaussian blur operation, to demonstrate performance improvements through multi-threading.

## **Build Instructions**

The project uses a Makefile to simplify compilation. It supports building both a sequential and a parallel version of the executable.

1. **Clean previous builds:**  
   make clean

2. **Build both executables (sequential and parallel):**  
   make

   This command will generate two executables:  
   * start\_sequential: The version compiled without OpenMP parallelization.  
   * start\_parallel: The version compiled with OpenMP parallelization enabled.

*(Note: You might see warnings about ignored OpenMP pragmas during the start\_sequential compilation; this is expected and indicates the pragmas are correctly ignored for the sequential build.)*

## **Run Instructions**

After building, you can run the executables from your terminal:

* **Run the Sequential Version (old):**  
  ./start\_sequential

* **Run the Parallel Version (current):**  
  ./start\_parallel

Each run will process the lena\_gray.raw image (which should be in the same directory as the executables), perform rotations and Gaussian blur, and output new raw image files (cwrotated.raw, ccwrotated.raw, gaussian\_blurred.raw). It will also print the execution times for each operation to the console.

## **Experiment Notes**

This project includes a built-in experiment to compare the performance of sequential versus parallel image processing. The lab1.cpp file contains timing measurements using std::chrono. The detailed results and analysis of this experiment are documented in the separate experiment\_report.md file