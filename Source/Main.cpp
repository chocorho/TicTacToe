#include <iostream>

#include "./headers/game.hpp"


int main(void)
{
	while (true)
	{
		system("cls");
		game g_object = game();

		if (g_object.set_game_mode() == 0)
		{
			g_object.play_single_player();
		}
		else
		{
			g_object.play_two_player();
		}

		if (g_object.ask_play_again())
		{
			continue;
		}
		break;
	}
	std::cout << "\n Have a nice day\n";
	std::cin.get();
}




