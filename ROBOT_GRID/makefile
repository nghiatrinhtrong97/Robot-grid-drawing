CC=g++
CFLAGS= -Wall

OBJECTS=main.o Robot.o Grid.o Command.o DimensionCommand.o MoveToCommand.o LineToCommand.o

main: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o main

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

Robot.o: src/Robot.cpp incl/Robot.h
	$(CC) $(CFLAGS) -c src/Robot.cpp

Grid.o: src/Grid.cpp incl/Grid.h
	$(CC) $(CFLAGS) -c src/Grid.cpp -o Grid.o

Command.o: src/Command.cpp incl/Command.h
	$(CC) $(CFLAGS) -c src/Command.cpp -o Command.o

DimensionCommand.o: src/DimensionCommand.cpp incl/DimensionCommand.h
	$(CC) $(CFLAGS) -c src/DimensionCommand.cpp -o DimensionCommand.o

MoveToCommand.o: src/MoveToCommand.cpp incl/MoveToCommand.h
	$(CC) $(CFLAGS) -c src/MoveToCommand.cpp -o MoveToCommand.o

LineToCommand.o: src/LineToCommand.cpp incl/LineToCommand.h
	$(CC) $(CFLAGS) -c src/LineToCommand.cpp -o LineToCommand.o

.PHONY: clean

clean:
	rm -f $(OBJECTS) main