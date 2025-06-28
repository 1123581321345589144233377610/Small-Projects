CC = gcc
SRC = main.c integral.c
TARGET = integral

ifeq ($(OS), Windows_NT)
	TARGET = $(TARGET).exe
endif

all:
	$(CC) $(SRC) -o $(TARGET)
run: all
	./$(TARGET)
clean:
	rm -f $(TARGET)

