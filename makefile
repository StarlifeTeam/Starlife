
CC=g++
CFLAGS=-std=c++11 -g
H_PATH=C:\SFML_MGW\include
L_PATH=C:\SFML_MGW\lib
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
SRC_PATH=src
OBJ_PATH=obj
BIN_PATH=bin
EXECUTABLE=main

CPP_FILES:=$(wildcard $(SRC_PATH)/*.cpp)
OBJ_FILES:=$(patsubst $(SRC_PATH)/%.cpp,$(OBJ_PATH)/%.o,$(CPP_FILES))

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	$(CC) $(CFLAGS) -I$(H_PATH) -c $< -o $@

build: $(OBJ_FILES)
	$(CC) $(CFLAGS) -I$(H_PATH) -L$(L_PATH) $^ -o $(BIN_PATH)/$(EXECUTABLE) $(LIBS)

run: build
	$(BIN_PATH)/$(EXECUTABLE)

clean:
	del obj\*.o
