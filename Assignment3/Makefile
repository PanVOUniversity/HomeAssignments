# Project name
PROJECT = transformer_tests

# Compiler
CXX = g++

# Source files
SRC = Transformer.cpp Weapon.cpp Autobot.cpp Decepticon.cpp Critic.cpp test_transformer.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Google Test flags
GTEST_LIBS = -lgtest -lgtest_main -pthread

# Executable target
$(PROJECT): $(OBJ)
	$(CXX) -o $(PROJECT) $(OBJ) $(GTEST_LIBS)

# Compile object files
%.o: %.cpp
	$(CXX) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJ) $(PROJECT)
