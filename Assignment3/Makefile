# Project name
PROJECT = transformer_tests

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

# Source files
SRC = Autobot.cpp Decepticon.cpp Transformer.cpp Weapon.cpp Critic.cpp test_transformer.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Executable
$(PROJECT): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(PROJECT) $(OBJ)

# Clean object files
clean:
	rm -f $(OBJ) $(PROJECT)
