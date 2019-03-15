test: main.cpp
	g++ -Wall -o $@ $< $(pkg-config --cflags --libs SDL2 ) -lopengl32 -mwindows
