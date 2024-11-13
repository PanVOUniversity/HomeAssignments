#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>



std::vector<uint8_t> txtToVector(std::string path, int width, int height)
{ 
    std::ifstream file(path, std::ios::binary);
    std::vector<uint8_t> imageData(width * height);
    file.read(reinterpret_cast<char*>(imageData.data()), width * height);
    return imageData;
}

std::vector<uint8_t> clockwiseRotate(std::vector<uint8_t> start, int width, int height)
{
    // Create a new vector to store the rotated image
    std::vector<uint8_t> rotatedData(width * height);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Calculate the new index for each pixel
            int newX = y;
            int newY = width - 1 - x;

            // Write the pixel in the new position
            rotatedData[newX * height + newY] = start[y * width + x];
        }
    }

    return rotatedData;
}

void saveImg(const std::string& filename, const std::vector<uint8_t>& imageData, int width, int height) {
    const int fileHeaderSize = 14;
    const int infoHeaderSize = 40;
    const int colorTableSize = 256 * 4; // 256 grayscale colors, each 4 bytes
    const int rowSize = (width + 3) & ~3; // Each row is padded to the nearest multiple of 4 bytes
    const int pixelDataSize = rowSize * height;
    const int fileSize = fileHeaderSize + infoHeaderSize + colorTableSize + pixelDataSize;

    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Could not open file for writing");
    }

    // 1. BMP file header
    uint8_t fileHeader[fileHeaderSize] = {
        'B', 'M',                         // Signature
        static_cast<uint8_t>(fileSize), static_cast<uint8_t>(fileSize >> 8),
        static_cast<uint8_t>(fileSize >> 16), static_cast<uint8_t>(fileSize >> 24), // File size
        0, 0, 0, 0,                       // Reserved
        static_cast<uint8_t>(fileHeaderSize + infoHeaderSize + colorTableSize),     // Offset to pixel data
        0, 0, 0                          // Remaining offset bytes
    };
    file.write(reinterpret_cast<char*>(fileHeader), fileHeaderSize);

    // 2. DIB header (info header)
    uint8_t infoHeader[infoHeaderSize] = {
        static_cast<uint8_t>(infoHeaderSize), 0, 0, 0,  // DIB header size
        static_cast<uint8_t>(width), static_cast<uint8_t>(width >> 8),
        static_cast<uint8_t>(width >> 16), static_cast<uint8_t>(width >> 24),  // Width
        static_cast<uint8_t>(height), static_cast<uint8_t>(height >> 8),
        static_cast<uint8_t>(height >> 16), static_cast<uint8_t>(height >> 24), // Height
        1, 0,                               // Color planes
        8, 0,                               // Bits per pixel (8-bit grayscale)
        0, 0, 0, 0,                         // Compression (no compression)
        static_cast<uint8_t>(pixelDataSize), static_cast<uint8_t>(pixelDataSize >> 8),
        static_cast<uint8_t>(pixelDataSize >> 16), static_cast<uint8_t>(pixelDataSize >> 24), // Pixel data size
        0, 0, 0, 0,                         // Horizontal resolution (ignored)
        0, 0, 0, 0,                         // Vertical resolution (ignored)
        0, 1, 0, 0,                       // Number of colors in palette
        0, 0, 0, 0                          // Important colors (0 = all colors are important)
    };
    file.write(reinterpret_cast<char*>(infoHeader), infoHeaderSize);

    /* 3. Grayscale color palette (256 shades of gray)
    for (int i = 0; i < 256; ++i) {
        uint8_t color[4] = { static_cast<uint8_t>(i), static_cast<uint8_t>(i), static_cast<uint8_t>(i), 0 };
        file.write(reinterpret_cast<char*>(color), 4);
    }
    */
    // 4. Write pixel data (with row padding)
    for (int y = 0; y < height; ++y) {
        file.write(reinterpret_cast<const char*>(&imageData[y * width]), width);

        // Padding to make each row a multiple of 4 bytes
        uint8_t padding[3] = { 0, 0, 0 };
        file.write(reinterpret_cast<char*>(padding), rowSize - width);
    }
}

int main()
{
    std::string path;
    int width;
    int height;
    std::cout << "input width"<< std::endl;
    std::cin >> width;
    std::cout << "input height" << std::endl;
    std::cin >> height;
    std::cout << "used memory " << width * height << " bytes" << std::endl; // first step
    std::cout << "input path of txt with raw pixel data";
    std::cin >> path;
    std::vector<uint8_t> pixels = txtToVector(path, width, height);
    auto clock_wise_rotated = clockwiseRotate(pixels, width, height);
    saveImg("clock_wise_rotated.bmp",clock_wise_rotated, width, height);
    saveImg("pixels.bmp", pixels, width, height);
}