TARGET_EXEC := CPTR142_HW4.exe

CC = g++
#CPPFLAGS := -std=c++11
CPPFLAGS := -std=c++0x

BUILD_DIR := ./build
SRC_DIR := ../src
INC_DIR := -I../includes \
			-I.
		
OBJ_DIR := ./obj
#LIB_DIR := ../lib

LIBS :=

BUILD_TARGET := $(BUILD_DIR)/$(TARGET_EXEC)
#INC_FLAGS := $(addprefix -I,$(INC_DIRS))
#SRC = $(SRC_DIR)/$(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.h)

# may want to clean up so that gnuplot stuff is only passed
# to the files that need it (should limit linker warnings)
# see: http://stackoverflow.com/questions/19774795/clang-warning-l-linker-input-unused

$(OBJ_DIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CPPFLAGS) $(INC_DIR) $(LIBS)

all: $(BUILD_TARGET)
	
$(BUILD_TARGET): $(OBJECTS)
	@mkdir -p $(BUILD_DIR)
	$(CC) -o $@ $^ $(CPPFLAGS) $(INC_DIR) $(LIBS)
	
.PHONY: clean

clean:
	rm -f $(OBJ_DIR)/*
	rm -f $(BUILD_DIR)/*
