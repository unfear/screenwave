# The variable CC will be the compiler to use.
CC=g++
# The CFLAGS will be the options pass to the compiler.
CFLAGS=-c -Wall
#SOURCES=ScreenWave.cpp ImageController.cpp Image.cpp
#OBJECTS=$(SOURCES:.cpp=.o)
#EXECUTABLE=ScreenWave

all: ScreenWave

ScreenWave: ScreenWave.o ImageController.o Image.o
	$(CC) ScreenWave.o ImageController.o Image.o -o ScreenWave

ScreenWave.o: ScreenWave.cpp
	$(CC) $(CFLAGS) -c ScreenWave.cpp

ImageController.o: ImageController.cpp
	$(CC) $(CFLAGS) -c ImageController.cpp

Image.o: Image.cpp
	$(CC) $(CFLAGS) -c Image.cpp

clean:
	rm -rf *.o ScreenWave
