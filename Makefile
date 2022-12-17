TARGET = main.out
CC = g++
VERSION = -std=c++17

PREF_SRC = ./Tic-Tac-Toe/
PREF_OBJ = ./Tic-Tac-Toe/Assets/

SRC = $(wildcard $(PREF_SRC)*.cpp)
OBJ = $(patsubst $(PREF_SRC)%.cpp, $(PREF_OBJ)%.o, $(SRC))

$(TARGET): $(OBJ)
	$(CC) $(VERSION) -o $(TARGET) $(OBJ) -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

$(PREF_OBJ)%.o: $(PREF_SRC)%.cpp
	$(CC) $(VERSION) -g -c $< -o $@

clean:
	rm $(PREF_OBJ)$(OBJ) $(TARGET)
