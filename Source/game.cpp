#include <stdio.h>
#include <time.h>
#include <iostream>
#include <random>

#include "./headers/game.hpp"

#define COMPUTER "Caty"

// constructor
game::game()
{
	print_game_info();
	initialize_board();

	WINNER = false;
	PLAYER_1_TURN = true;
}


// getter & setter methods
void game::set_player2()
{
	Player2 = COMPUTER;
}

void game::get_player1()
{
	std::cout << "\nPlayer 1 name : ";
	std::cin >> Player1;
}

void game::get_player2()
{
	std::cout << "\nPlayer 2 name : ";
	std::cin >> Player2;
}

// single & two-player
void game::single_player()
{
	get_player1();
	set_player2();
}

void game::two_players()
{
	get_player1();
	get_player2();
}


bool game::ask_play_two_player()
{
	char input;

	while (true)
	{
		std::cout << "\nCHOOSE GAME MODE - SINGLE PLAYER(S/s) or TWO-PLAYER(T/t) : ";
		std::cin >> input;
		char ch = toupper(input);

		if (ch == 'T')
		{
			return true;
		}
		else if (ch == 'S')
		{
			return false;
		}
		std::cin.ignore(1000, '\n');
	}
}


int game::set_game_mode()
{
	if (ask_play_two_player())
	{
		two_players();
		return 1;
	}
	else
	{
		single_player();
		return 0;
	}
}


void game::initialize_board()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
}


// Logging/printing functions

void game::print_game_info()
{
const char* rules = R"( 
 		--- Tic Tac Toe --- 

 		  Player 1 : 'O'
 		  Player 2 : 'X'

** Provide index where you want to mark your 'O' or 'X' within the Board ** 

   :: You need to provide index as shown below :: 

		     |     |
                 0,0 | 0,1 | 0,2
                -----|-----|-----
                 1,0 | 1,1 | 1,2
                -----|-----|-----
                 2,0 | 2,1 | 2,2
                     |     | 


+-----------+----------+----------+----------+----------+
)";

	printf("%s\n", rules);
}


void game::print_game_draw()
{
	std::cout << "\n\n======================== GAME DRAW =========================\n\n";
}


void game::print_invalid_message()
{
	std::cout << R"(------------------- INVALID! PLEASE TRY AGAIN ------------------- )";
}


void game::print_win_message(std::string str)
{
	std::cout << "\n================ Well done! " << str << " you won the match !!================ \n";
}


void game::print_board()
{
	printf("\n");

	printf("     %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
	printf("\n    ---|---|---\n");
	printf("     %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
	printf("\n    ---|---|---\n");
	printf("     %c | %c | %c ", board[2][0], board[2][1], board[2][2]);

	printf("\n\n");
}


void game::check_winner()
{
	// check for straight line pairs horizontally for all rows one-by-one
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1])
		{
			if (board[i][0] == board[i][2] && board[i][0] == 'O')
			{
				system(CLEAR_SCREEN);
				print_board();
				print_win_message(Player1);            
				WINNER = true;
			}
			else if (board[i][0] == board[i][2] && board[i][0] == 'X')
			{
				system(CLEAR_SCREEN);
				print_board();
				print_win_message(Player2);
				WINNER = true;
			}
		}
	}

	// check for straight line pairs vertically for all columns one-by-one
	for (int i = 0; i < 3; i++)
	{
		if (board[0][i] == board[1][i])
		{
			if (board[0][i] == board[2][i] && board[0][i] == 'O')
			{
				system(CLEAR_SCREEN);
				print_board();
				print_win_message(Player1);
				WINNER = true;
			}

			else if (board[0][i] == board[2][i] && board[0][i] == 'X')
			{
				system(CLEAR_SCREEN);
				print_board();
				print_win_message(Player2);
				WINNER = true;
			}
		}
	}

	// check for straight pair in first diagnol ,i.e, from left-up corner to right-bottom corner
	if (board[0][0] == board[1][1])
	{
		if (board[0][0] == board[2][2] && board[0][0] == 'O')
		{
			system(CLEAR_SCREEN);
			print_board();
			print_win_message(Player1);
			WINNER = true;
		}

		else if (board[0][0] == board[2][2] && board[0][0] == 'X')
		{
			system(CLEAR_SCREEN);
			print_board();
			print_win_message(Player2);
			WINNER = true;
		}
	}

	// check for straight pair in second diagnol ,i.e, from left-bottom corner to right-up corner
	if (board[2][0] == board[1][1])
	{
		if (board[2][0] == board[0][2] && board[2][0] == 'O')
		{
			system(CLEAR_SCREEN);
			print_board();
			print_win_message(Player1);
			WINNER = true;
		}

		if (board[2][0] == board[0][2] && board[2][0] == 'X')
		{
			system(CLEAR_SCREEN);
			print_board();
			print_win_message(Player2);
			WINNER = true;
		}
	}

}


void check_input(int num)
{
	while (true)
	{
		std::cout << "Enter ";
		std::cin >> num;

		if (!std::cin)
		{
			std::cout << "Don't pass alphabets dude\n";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			continue;
		}
		std::cout << num << std::endl;
		break;
	}
}


void game::play_two_player()
{
	int i = 0;
	int j = 0;

	while (true)
	{
		system(CLEAR_SCREEN);

		if (check_game_draw())
		{
			print_game_draw();
			break;
		}

		std::cout << "\n     " << Player1 << " - " << "X" << "\n";
		std::cout << "     " << Player2 << " - " << "O" << "\n";

		print_board();

		// input
		do
		{
			std::cout << "Enter 1st index : ";
			std::cin >> i;
		}
		while (i > 2 || i < 0);

		do
		{
			std::cout << "Enter 2nd index : ";
			std::cin >> j;
		}
		while (j > 2 || j < 0);


		// check for correct input
		if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			continue;
		}

		if (PLAYER_1_TURN == true)
		{
			if (board[i][j] != ' ')
			{
				continue;
			}
			else
			{
				board[i][j] = 'X';
				PLAYER_1_TURN = false;

				check_winner();

				if (WINNER)
				{
					break;
				}
			}
		}

		else
		{
			if (board[i][j] != ' ')
			{
				continue;
			}
			else
			{
				board[i][j] = 'O';
				PLAYER_1_TURN = true;

				check_winner();

				if (WINNER)
				{
					break;
				}
			}
		}
	}
}

// ask user if they wants to play again
bool game::ask_play_again() 
{
	char temp_char;

	while (true)
	{
		std::cout << "\nPLAY AGAIN? (Y/y), (N/n) : ";
		std::cin >> temp_char;
		char u_temp_char = toupper(temp_char);

		if (u_temp_char == 'Y')
		{
			return true;
		}

		if (u_temp_char == 'N')
		{
			return false;
		}
		else
		{
			std::cin.ignore(500, '\n');
			continue;
		}
	}
}


bool game::check_game_draw()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
			{
				return false;
			}
		}
	}
	return true;
}

// generate random number in from 0 to 2
int randomNumber()
{
	static std::default_random_engine randomEngine(time(NULL));

	std::uniform_int_distribution<int> randomNumber(0, 2);
	return randomNumber(randomEngine);
}

void game::play_single_player()
{
	int i = 0;
	int j = 0;

	while (true)
	{
		system(CLEAR_SCREEN);

		if (check_game_draw())
		{
			print_game_draw();
			break;
		}

		std::cout << "\n     " << Player1 << " - " << "X" << "\n";
		std::cout << "     " << Player2 << " - " << "0" << "\n";

		print_board();

		if (PLAYER_1_TURN == true)
		{
			// input
			do
			{
				std::cout << "Enter 1st index : ";
				std::cin >> i;
			}
			while (i > 2 || i < 0);

			do
			{
				std::cout << "Enter 2nd index : ";
				std::cin >> j;
			}
			while (j > 2 || j < 0);


			// check for correct input
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				continue;
			}

			if (board[i][j] == ' ')
			{
				board[i][j] = 'O';
				PLAYER_1_TURN = false;
				 
				check_winner();     // problem is here

				if (WINNER)         // problem is here
				{
					break;
				}
			}
			else
			{
				continue;
			}
		}

		else
		{
			while (true)
			{
				i = randomNumber();
				j = randomNumber();

				if (board[i][j] == ' ')
				{
					board[i][j] = 'X';
					PLAYER_1_TURN = true;
					break;
				}
			}
			
			check_winner();

			if (WINNER) {
				break;
			}
		}
	}
}

