all:
	g++ -I src/Include -L src/lib -o runTests VectorClass.cpp Particle.cpp Tests.cpp -lmingw32 -lSDL2main -lSDL2