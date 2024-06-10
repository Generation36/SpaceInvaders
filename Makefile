PROJECT=SpaceInvaders

CXX = g++
CXX_FLAGS = -Wall -std=c++11 -lglfw -lGL -lGLEW -lpthread

EXE=main

all: $(EXE)
	
main: main.o
	$(CXX) main.o -o main $(CXX_FLAGS)
	mv *.o main ./bin

main.o: ./src/main.cpp
	$(CXX) ./src/main.cpp $(CXX_FLAGS) -c

#dont forget to add the full path when create hello_window
hello_window: hello_window.o
	$(CXX) hello_window.o -o hello_window $(CXX_FLAGS) 
	mv *.o hello_window ./bin

hello_window.o: ./src/hello_window.cpp
	$(CXX) ./src/hello_window.cpp $(CXX_FLAGS) -c

clean:
	cd $(shell pwd)/bin && rm -f *



