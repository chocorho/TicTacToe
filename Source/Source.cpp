#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>

// board array
char Cell[3][3] ;

unsigned int turn = 1;
int WINNER = 0;

bool odd_even()
{
	// check even or odd
	if (turn % 2 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Draw_Board()
{
	printf("\n");

	printf("     %c | %c | %c ", Cell[0][0], Cell[0][1], Cell[0][2]);
	printf("\n    ---|---|---\n");
	printf("     %c | %c | %c ", Cell[1][0], Cell[1][1], Cell[1][2]);
	printf("\n    ---|---|---\n");
	printf("     %c | %c | %c ", Cell[2][0], Cell[2][1], Cell[2][2]);

	printf("\n");
}



void Game_Description()
{
	const char* rules = R"( 
 --- Tic Tac Toe --- 

 Player 1 has first turn with 'O'
 Player 2 has second turn with 'X'

** Provide index where you want to mark your 'O' or 'X' within the Board ** 

   :: You need to provide index as shown below :: 

		     |     |
                 0,0 | 0,1 | 0,2
                -----|-----|-----
                 1,0 | 1,1 | 1,2
                -----|-----|-----
                 2,0 | 2,1 | 2,2
                     |     | 


+-----------+----------+--- HERE BEGINS THE GAME ----+----------+----------+----------+ 
)";

	printf("%s", rules);
}



void Next_turn_message()
{
	// Prints who's turn is next 
	if (odd_even())
	{
		std::cout << " \n PLAYER 2's TURN (X)";
	}
	else
	{
		std::cout << " \n PLAYER 1's TURN (O)";
	}
}



void Winner()
{
	// check for straight line pairs horizontally for all rows one-by-one
	for (int i = 0; i < 3; i++)
	{
		if (Cell[i][0] == Cell[i][1])
		{
			if (Cell[i][0] == Cell[i][2] && Cell[i][0] == 'O')
			{
				std::cout << "\n=================== Player 1 WON !! 'O' showing domincancy here :} ======================\n";
				WINNER = 1;
			}
			else if (Cell[i][0] == Cell[i][2] && Cell[i][0] == 'X')
			{
				std::cout << "\n=================== Player 2 WON !! 'X' showing domincancy here :} ======================\n";
				WINNER = 1;
			}
		}
	}

	// check for straight line pairs vertically for all columns one-by-one
	for (int i = 0; i < 3; i++)
	{
		if (Cell[0][i] == Cell[1][i])
		{
			if (Cell[0][i] == Cell[2][i] && Cell[0][i] == 'O')
			{
				std::cout << "\n=================== Player 1 WON !! 'O' showing domincancy here :} ======================\n";
				WINNER = 1;
			}

			else if (Cell[0][i] == Cell[2][i] && Cell[0][i] == 'X')
			{
				std::cout << "\n=================== Player 1 WON !! 'X' showing domincancy here :} ======================\n";
				WINNER = 1;
			}
		}
	}

	// check for straight pair in first diagnol ,i.e, from left-up corner to right-bottom corner
	if (Cell[0][0] == Cell[1][1])
	{
		if (Cell[0][0] == Cell[2][2] && Cell[0][0] == 'O')
		{
			std::cout << "\n=================== Player 1 WON !! 'O' showing domincancy here :} ======================\n";
			WINNER = 1;
		}

		else if (Cell[0][0] == Cell[2][2] && Cell[0][0] == 'X')
		{
			std::cout << "\n=================== Player 1 WON !! 'X' showing domincancy here :} ======================\n";
			WINNER = 1;
		}
	}

	// check for straight pair in second diagnol ,i.e, from left-bottom corner to right-up corner
	if (Cell[2][0] == Cell[1][1])
	{
		if (Cell[2][0] == Cell[0][2] && Cell[2][0] == 'O')
		{
			std::cout << "\n=================== Player 1 WON !! 'O' showing domincancy here :} =======================\n";
			WINNER = 1;
		}

		if (Cell[2][0] == Cell[0][2] && Cell[2][0] == 'X')
		{
			std::cout << "\n=================== Player 1 WON !! 'X' showing domincancy here :} =======================\n";
			WINNER = 1;
		}
	}

}


void reset_board()
{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				Cell[i][j] = ' ';
			}
		}
}


void take_input(int& a, int& b)
{
		do
		{
			std::cout << "\n\nEnter the 1st index : ";
			std::cin >> a;

		} while (a < 0 && a > 2);


		do
		{
			std::cout << "\nEnter the 2nd index : ";
			std::cin >> b;

		} while (b < 0 && b > 2);
}


void Play()
{

	int i;
	int j;

	while (true)
	{
	
			Next_turn_message();
			// take input from user 
			take_input(i, j);



			/* Its player 1 turn when turn is odd, player 2's when turn is even
				   After each turn turn gets incremented by 1 .       */

			if (odd_even())
				if (Cell[i][j] == ' ')
				{
					Cell[i][j] = 'X';
				}
				else
				{
					std::cout << R"(
				
----------------------- INVALID MOVE ** This block is already filled ** HERE YOU GO AGAIN --------------------- )";

					Draw_Board();
					continue;
				}
			else
			{
				if (Cell[i][j] == ' ')
				{
					Cell[i][j] = 'O';
				}
				else
				{
					std::cout << R"(
				
-------------------------- INVALID MOVE ** This block is already filled ** HERE YOU GO AGAIN --------------------------- )";

					Draw_Board();
					continue;
				}
			}




			Draw_Board();
			turn += 1;    // for updating next turn

			Winner();     // check for winner
			if (WINNER == 1)
			{
				break;
			}
	}


	if (WINNER == 0)
	{
		std::cout << "\n\n==================================== GAME DRAW ==========================================\n\n";
	}
}


