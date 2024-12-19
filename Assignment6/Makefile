PROJECT = classes

CXX = g++

CXXFLAGS = -I. -std=c++11 -Wall -Werror -Wpedantic -g -fPIC
TESTFLAGS = -lgtest -lgtest_main -pthread

SRC = templates.cpp

$(PROJECT) : $(SRC)
	$(CXX) -o $@ $< $(TESTFLAGS)

all: $(PROJECT)

clean:
	rm $(PROJECT)