# Project name
PROJECT = transformer_tests

# Compiler
CXX = g++

# Source files
SRC = Transformer.cpp Weapon.cpp Autobot.cpp Decepticon.cpp test_transformer.cpp

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
