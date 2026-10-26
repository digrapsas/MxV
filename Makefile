# "all" is the name of the default target, running "make" without params would use it
all: main

# compiler and flags
CXX      = g++
CXXFLAGS = -O3 -g -march=native -std=c++17 -pedantic -Wall -Wextra -Werror -Wshadow -Wconversion -Wunreachable-code
COMPILE  = $(CXX) $(CXXFLAGS)

debug: CXXFLAGS += -DDEBUG -g
debug: main

# directories
BUILD = ./build
SRC   = ./src

# files
OBJ = $(BUILD)/SparseM.o $(BUILD)/MxV.o $(BUILD)/FullM.o $(BUILD)/main.o
CPP = $(SRC)/*.cpp
EXE = $(BUILD)/a.out

# rules
# -c flag for no linking
main: $(OBJ)
	$(COMPILE)     -o  $(EXE) $(OBJ)

./build/main.o: main.cpp build
	$(COMPILE)  -c -o  $(BUILD)/main.o main.cpp 

./build/FullM.o: ./src/FullM.cpp build
	$(COMPILE)  -c -o  $(BUILD)/FullM.o $(SRC)/FullM.cpp 

./build/MxV.o: ./src/MxV.cpp build
	$(COMPILE)  -c -o  $(BUILD)/MxV.o $(SRC)/MxV.cpp 

./build/SparseM.o: ./src/SparseM.cpp build
	$(COMPILE)  -c -o  $(BUILD)/SparseM.o $(SRC)/SparseM.cpp 

# Make the build directory if it doesn't exist
build:
	mkdir -p $(BUILD)

clean: 
	rm -rf $(BUILD)

run:
	$(EXE)

# These rules do not correspond to a specific file
.PHONY: build clean run