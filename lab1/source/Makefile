# C++ compiler to use
CXX = g++

# Source files
SRCS = lab1.cpp

# Header files
HEADERS = bmp.h

# Executable targets
TARGET_SEQ = start_sequential
TARGET_PAR = start_parallel

# Compiler flags for sequential version:
# -Wall: Enable all common warnings
# -std=c++11: Use C++11 standard (or higher, e.g., c++14, c++17, c++20)
CXXFLAGS_SEQ = -Wall -std=c++11

# Compiler flags for parallel version:
# -Wall: Enable all common warnings
# -std=c++11: Use C++11 standard (or higher)
# -fopenmp: Enable OpenMP support for parallelization
CXXFLAGS_PAR = -Wall -std=c++11 -fopenmp

# Linker flags (none needed for this simple case)
LDFLAGS =

# Default 'all' rule: builds both sequential and parallel executables
all: $(TARGET_SEQ) $(TARGET_PAR)

# Rule to build the sequential executable:
# Depends on source files and header files.
# Uses CXXFLAGS_SEQ for compilation.
$(TARGET_SEQ): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS_SEQ) $(SRCS) -o $(TARGET_SEQ) $(LDFLAGS)

# Rule to build the parallel executable:
# Depends on source files and header files.
# Uses CXXFLAGS_PAR for compilation (includes -fopenmp).
$(TARGET_PAR): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS_PAR) $(SRCS) -o $(TARGET_PAR) $(LDFLAGS)

# Clean rule: removes all compiled executables and generated raw image files
clean:
	rm -f $(TARGET_SEQ) $(TARGET_PAR)

	
