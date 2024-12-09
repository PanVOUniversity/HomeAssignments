# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g -I$(GTEST_DIR)/include -pthread

# Source files and headers
SRC = TransformerTest.cpp Advantage.cpp Transformer.cpp City.cpp Autobot.cpp Minicon.cpp Decepticon.cpp
OBJ = $(SRC:.cpp=.o)

# Google Test directories
GTEST_DIR = /usr/local

# Output file for tests
OUTPUT = runTests

# Google Test libraries
GTEST_LIBS = -L$(GTEST_DIR)/lib -lgtest -lgtest_main

# Default target
all: $(OUTPUT)

# Rule to build the test executable
$(OUTPUT): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(OUTPUT) $(OBJ) $(GTEST_LIBS)

# Rule to compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up the object and executable files
clean:
	rm -f $(OBJ) $(OUTPUT)

# Run the tests
run: $(OUTPUT)
	./$(OUTPUT)

# Rebuild everything from scratch
rebuild: clean all

.PHONY: all clean run rebuild
