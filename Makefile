all:
	g++ -I src/Include -L src/lib -o startEngine VectorClass.cpp Boundary.cpp Particle.cpp Car.cpp Car_Car_Res.cpp main.cpp -lmingw32 -lSDL2main -lSDL2
#target: dependency
#action

#startEngine: main.o VectorClass.o Matrix.o Particle.o Missile.o CollObjects.o CollObservers.o Timing.o
#action

#main.0: main.cpp
#action

#VectorClass.o : VectorClass.cpp VectorClass.h
#action

#Matrix.o : Matrix.cpp Matrix.h
#action

#Particle.o : Particle.cpp Particle.h
#action

#Missile.o: Missile.cpp Missile.h
#action

#CollObjects.o: CollObject.cpp CollObject.h
#action

#CollObservers.o: CollObserver.cpp CollObserver.h
#action

#Timing.o: Timing.cpp Timing.h
#action

#CollNotify.o: CollNotify.cpp CollNotify.h
#action
