V1 = g++
V3 = clang


g++ : 
	$(V1) -o ./Main ./Source/Main.cpp ./Source/Header.hpp ./Source/Source.cpp
	

clang :
	$(V3) -o ./Main ./Source/Main.cpp ./Source/Header.hpp ./Source/Source.cpp

#executable/binary file will be created in bin folder


run : 
	./Main
