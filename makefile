all:
	make build
	make archive

build:
	make game

game: game.o othello.o main.o
	g++ *.o -o game

main.o: main.cc game.h othello.h
	g++ -c main.cc

game.o: game.cc game.h
	g++ -c game.cc

othello.o: othello.cc othello.h
	g++ -c othello.cc

archive: main.cc game.cc othello.cc makefile
	tar -cvzf tarball.tar.gz game

clean:
	rm *.o game
