V1 = g++
V3 = clang


g++ : 
	$(V1) -o TicTacToe ./Source/Main.cpp ./Source/game.cpp ./Source/headers/game.hpp -Wall -W
	

clang :
	$(V3) -o  TicTacToe ./Source/Main.cpp ./Source/game.cpp ./Source/headers/game.hpp -Wall -W

#executable file will be created in bin folder


run : 
	./TicTacToe
