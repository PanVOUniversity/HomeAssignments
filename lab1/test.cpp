#include<iostream>
#include<vector>
#include<string>
#include<fstream>


struct Image {
public:
    const int fileHeaderSize = 14;
    const int informationHeaderSize = 40;
    unsigned char fileHeader[14];
    unsigned char informationHeader[40];
    int width;
    int height;

    // Constructor to initialize headers
    Image(int width, int height) : width(width), height(height) {
        const int imageSize = width * height + fileHeaderSize + informationHeaderSize;

        // File Header
        fileHeader[0] = 'B';
        fileHeader[1] = 'M';
        fileHeader[2] = imageSize;
        fileHeader[3] = imageSize >> 8;
        fileHeader[4] = imageSize >> 16;
        fileHeader[5] = imageSize >> 24;
        fileHeader[6] = 0;
        fileHeader[7] = 0;
        fileHeader[8] = 0;
        fileHeader[9] = 0;
        fileHeader[10] = fileHeaderSize + informationHeaderSize;
        fileHeader[11] = 0;
        fileHeader[12] = 0;
        fileHeader[13] = 0;

        // Information Header
        informationHeader[0] = informationHeaderSize;
        informationHeader[1] = 0;
        informationHeader[2] = 0;
        informationHeader[3] = 0;
        informationHeader[4] = width;
        informationHeader[5] = width >> 8;
        informationHeader[6] = width >> 16;
        informationHeader[7] = width >> 24;
        informationHeader[8] = height;
        informationHeader[9] = height >> 8;
        informationHeader[10] = height >> 16;
        informationHeader[11] = height >> 24;
        informationHeader[12] = 1; // Planes
        informationHeader[13] = 0;
        informationHeader[14] = 8; // Bits per pixel
        informationHeader[15] = 0;
        informationHeader[16] = 0; // Compression
        informationHeader[17] = 0;
        informationHeader[18] = 0;
        informationHeader[19] = 0;
        informationHeader[20] = 0; // Image size
        informationHeader[21] = 0;
        informationHeader[22] = 0;
        informationHeader[23] = 0;
        informationHeader[24] = 0; // X pixels per meter
        informationHeader[25] = 0;
        informationHeader[26] = 0;
        informationHeader[27] = 0;
        informationHeader[28] = 0; // Y pixels per meter
        informationHeader[29] = 0;
        informationHeader[30] = 0;
        informationHeader[31] = 0;
        informationHeader[32] = 0; // Colors in color table
        informationHeader[33] = 0;
        informationHeader[34] = 0;
        informationHeader[35] = 0;
        informationHeader[36] = 0; // Important color count
        informationHeader[37] = 0;
        informationHeader[38] = 0;
        informationHeader[39] = 0;
    }

    // Method to save pixel data to BMP
    void writeToFile(const std::string& filename, const std::vector<unsigned char>& pixelData) {
        std::ofstream file(filename, std::ios::binary);
        if (!file) {
            throw std::runtime_error("Failed to open file for writing: " + filename);
        }

        // Write headers
        file.write(reinterpret_cast<char*>(fileHeader), fileHeaderSize);
        file.write(reinterpret_cast<char*>(informationHeader), informationHeaderSize);

        // Write pixel data (BMP stores pixel rows bottom-to-top)
        for (int y = height - 1; y >= 0; --y) {
            file.write(reinterpret_cast<const char*>(&pixelData[y * width]), width);
        }
    }
};
