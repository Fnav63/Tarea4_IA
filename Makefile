CXX = g++
CXXFLAGS = -Wall -std=c++11

all: generador

generador: main.o perlin.o
	$(CXX) $(CXXFLAGS) -o generador main.o perlin.o

main.o: main.cpp perlin.h
	$(CXX) $(CXXFLAGS) -c main.cpp

perlin.o: perlin.cpp perlin.h
	$(CXX) $(CXXFLAGS) -c perlin.cpp

clean:
	rm -f *.o generador