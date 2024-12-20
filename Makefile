CXX = g++
CXXFLAGS = -Wall -g

SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin
LIB_DIR = lib

SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/LinkedList.cpp $(SRC_DIR)/Node.cpp $(SRC_DIR)/Tree.cpp 
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(LIB_DIR)/%.o,$(SOURCES))

HEADERS = $(INCLUDE_DIR)/LinkedList.hpp $(INCLUDE_DIR)/Node.hpp $(INCLUDE_DIR)/Tree.hpp 

EXECUTABLE = $(BIN_DIR)/program

all: directories $(EXECUTABLE)

directories: $(BIN_DIR) $(LIB_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE)

$(LIB_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
	rm -rf $(BIN_DIR) $(LIB_DIR)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

.PHONY: all clean run directories