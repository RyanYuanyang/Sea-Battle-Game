#This is the Makefile

FLAGS = -pedantic-errors -std=c++11

Seabattle: instruction.o challenge.o AI.o main.o printBoard.o input_ships_shell.o genBoard.o printRecord.o
	g++ $(FLAGS) $^ -o $@

instruction.o: instruction.cpp instruction.h
	g++ $(FLAGS) -c $<

challenge.o: challenge.cpp challenge.h genBoard.h printBoard.h printRecord.h
	g++ $(FLAGS) -c $<

AI.o: AI.cpp AI.h genBoard.h printBoard.h input_ships_shell.h
	g++ $(FLAGS) -c $<

printBoard.o: printBoard.cpp printBoard.h
	g++ $(FLAGS) -c $<

input_ships_shell.o: input_ships_shell.cpp input_ships_shell.h
	g++ $(FLAGS) -c $<

printRecord.o: printRecord.cpp printRecord.h
	g++ $(FLAGS) -c $<

genBoard.o: genBoard.cpp genBoard.h
	g++ $(FLAGS) -c $<

main.o: main.cpp instruction.h challenge.h AI.h
	g++ $(FLAGS) -c $<

clean:
	rm *.o Seabattle
