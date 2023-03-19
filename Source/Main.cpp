#include <iostream>
#include "./headers/game.hpp"

// In single-player Player1 is bot --> Caty :)

int main()
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

	system("cls");
	std::cout << "\n\n ------------ Have a nice day ------------\n\n";
	std::cin.get();
}




