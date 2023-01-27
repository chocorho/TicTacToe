#include <iostream>
#include "Header.hpp"

int main()
{
	const char Player1 = 'O';
	const char Player2 = 'X';

	Game_Description();
	reset_board();
	Draw_Board();
	Play();

	std::cin.get();
}

