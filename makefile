all: main.cpp Location.cpp Map.cpp
		g++ -o $@ $^
