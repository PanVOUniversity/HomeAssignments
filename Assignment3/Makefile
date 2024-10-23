# Project name
PROJECT = transformer_tests

# Compiler
CXX = g++

# Source files
SRC = src/Transformer.cpp src/Weapon.cpp src/Autobot.cpp src/Decepticon.cpp tests/test_transformer.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Executable target
final: $(OBJ)
	$(CXX) -o $(PROJECT) $(OBJ)

# Compile object files
%.o: %.cpp
	$(CXX) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJ) $(PROJECT)
