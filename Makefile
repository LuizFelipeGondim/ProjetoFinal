CPP = g++
CPPFLAGS = -std=c++11 -Iinclude

SRC_DIR = src
INC_DIR = include
TEST_DIR = tests
OBJ_DIR = obj
BIN_DIR = bin

SOURCES = $(wildcard $(SRC_DIR)/.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(filter-out $(SRC_DIR)/main.cpp,$(SOURCES)))
MAIN_OBJECT = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_DIR)/main.cpp)
TEST_SOURCES = $(wildcard $(TEST_DIR)/.cpp)
TEST_MAIN_SOURCE = $(TEST_DIR)/testGameBoardClass.cpp
TEST_MAIN_OBJECT = $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TEST_MAIN_SOURCE))
TEST_OBJECTS = $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(filter-out $(TEST_MAIN_SOURCE),$(TEST_SOURCES)))
EXECUTABLE = $(BIN_DIR)/start_game
TEST_EXECUTABLE = $(BIN_DIR)/run_tests

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(MAIN_OBJECT)
    @mkdir -p $(BIN_DIR)
    $(CPP) $(OBJECTS) $(MAIN_OBJECT) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
    @mkdir -p $(OBJ_DIR)
    $(CPP) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
    @mkdir -p $(OBJ_DIR)
    $(CPP) $(CPPFLAGS) -c $< -o $@

test: $(TEST_EXECUTABLE)
    $(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TEST_MAIN_OBJECT) $(TEST_OBJECTS) $(OBJECTS)
    @mkdir -p $(BIN_DIR)
    $(CPP) $(TEST_MAIN_OBJECT) $(TEST_OBJECTS) $(OBJECTS) -o $@

clean:
    rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean test