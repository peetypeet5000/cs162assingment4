CC = g++ -std=c++11 -g -Wall
exe_file = wumpus
$(exe_file):  game.o file_io.o util.o prog.o  room.o wumpus.o event.o pit.o gold.o rope.o bats.o
	$(CC) game.o file_io.o util.o prog.o room.o wumpus.o  event.o gold.o bats.o pit.o rope.o -o $(exe_file)
game.o: game.cpp
	$(CC) -c game.cpp
util.o: util.cpp
	$(CC) -c util.cpp
file_io.o: file_io.cpp
	$(CC) -c file_io.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp
room.o: room.cpp
	$(CC) -c room.cpp
wumpus.o: wumpus.cpp
	$(CC) -c wumpus.cpp
event.o: event.cpp
	$(CC) -c event.cpp
gold.o: gold.cpp
	$(CC) -c gold.cpp
bats.o: bats.cpp
	$(CC) -c bats.cpp
pit.o: pit.cpp
	$(CC) -c pit.cpp
rope.o: rope.cpp
	$(CC) -c rope.cpp

clean:
	rm *.o $(exe_file)

tar:
	tar -cvf $(exe_file).tar *.cpp *.h Makefile
