V1 = g++
V3 = clang


g++ : 
	$(V1) -o -Wall -W ./TicTacToe ./Source/Main.cpp ./Source/game.cpp ./Source/headers/game.hpp 
	

clang :
	$(V3) -o  -Wall -W ./TicTacToe ./Source/Main.cpp ./Source/game.cpp ./Source/headers/game.hpp 

#executable file will be created in bin folder


run : 
	./TicTacToe
