CXX = g++
CXXFLAGS = -shared -g -Wall -Wno-unknown-pragmas -fPIC -Wno-unused-function 

SRC_DIR := dynamic-storage
OBJ_DIR := obj
SRC_LIST = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

OBJS := $(wildcard $(OBJ_DIR:=/*.o))

build: $(OBJS)
	@echo Building ...
	@echo
	$(CXX) $(CXXFLAGS) $(OBJS) -o main.exe
	@echo

compile: $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(notdir $(wildcard $(SRC_DIR)/*.cpp)))))
	@echo

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	@echo Cleaning binary files ...
	rm -f $(OBJ_DIR)/*.o *~