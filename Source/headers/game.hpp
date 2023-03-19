#include <string>

class game
{
public:
	game();
	~game() {}

	void initialize_board();

	void check_winner();
	int  set_game_mode();

	void single_player();
	void two_players();

	void play_two_player();
	void play_single_player();

	bool check_game_draw();
	bool ask_play_again();
	
	void set_player2();
	void get_player1();
	void get_player2();

	bool ask_play_two_player();

	void print_game_info();
	void print_invalid_message();
	void print_board();
	void print_game_draw();
	void print_win_message(std::string str);


private:
	std::string Player1;
	std::string Player2;

	bool WINNER;
	bool PLAYER_1_TURN;

	char board[3][3];
};



