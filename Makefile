V1 = g++
V3 = clang


g++ : 
	$(V1) -o ./TicTacToe ./Source/main.cpp ./Source/game.cpp ./Source/headers/game.hpp 
	

clang :
	$(V3) -o ./TicTacToe ./Source/main.cpp ./Source/game.cpp ./Source/headers/game.hpp 

#executable file will be created in bin folder


run : 
	./TicTacToe
