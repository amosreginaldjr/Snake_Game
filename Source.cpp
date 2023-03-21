#include<iostream>
#include<conio.h> //_getch ()
#include <windows.h> //sleep(1000)
using namespace std;

/*
still to do:
~ add fruit
~ grow snake body
~ block the user from seeing their input constantly
~ make the snake move non stop
~ out of bounds area
~ snake dying
~ MORE
*/

class Snake;

/* Snake game movement logic:
w = [-1]  []
a = []    [-1]
s = [+1]  []
d = []    [+1]
*/

class Snake
{
private:
	int score;

private:
	static const int board_size = 11;
	char ary[board_size][board_size]; //the board for the snake game
	int length;
	char player_model; //the player will be this char
	int default_position_X; //players default starting X position
	int default_position_Y; //players default starting Y position
	int current_position_X; //players current X position
	int current_position_Y; //players current Y position
	char player_keystroke;

public:
	Snake();
	void setup_board(); /*makes the base board for the snake*/
	void print_board(); /*outputs the updated board WITH the user on it*/
	bool is_new_game(); /*determines if the game is new or not*/
	void move_player();
	bool detect_death();

	void current_player_position();
	void movement_logic();

	//player direction getter and setter:
	void set_player_direction(char movement);
	char get_player_direction();
};


int main()
{
	Snake user;
	char input = _getch();

	while (input != 'v')
	{
		user.setup_board();
		input = _getch();

		user.set_player_direction(input);
		user.print_board();
		user.move_player();
		//user.detect_death(); //build this into a function idk which one though
		system("cls");
		user.print_board();
		//Sleep(500);
	}

	return 0;
}




Snake::Snake()
{
	score = 1; //change score to 0

	static const int board_size = 11;
	ary[board_size][board_size];
	length = board_size;
	player_model = '*';
	default_position_X = board_size / 2;
	default_position_Y = board_size / 2;
	current_position_X = default_position_X;
	current_position_Y = default_position_Y;
	player_keystroke = 'n';
}

void Snake::setup_board()
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (i % 2 == 1)
				ary[i][j] = '1';
			else
				ary[j][i] = '2';

			if (j % 2 == 1)
				ary[i][j] = '3';
			else
				ary[j][i] = '4';
		}
	}
}

void Snake::print_board()
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			cout << ary[i][j] << ' ';
		}
		cout << endl;
	}
}

bool Snake::is_new_game()
{
	if (score == 0)
		return 1;
	return 0;
}

void Snake::move_player()
{
	if (is_new_game())
		ary[default_position_Y][default_position_X] = player_model;
	else if (!is_new_game())
		movement_logic();
}

bool Snake::detect_death()
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (i == -1 || i == 10 || j == -1 || j == 10)
			{
				current_position_X = i;
				current_position_Y = i;
				current_position_X = j;
				current_position_Y = j;
				return 0;
			}
		}
	}
	return 1;
}

void Snake::current_player_position()
{
	ary[current_position_Y][current_position_X];
}

void Snake::movement_logic()
{
	current_player_position();

	if (get_player_direction() == 'w')
		ary[current_position_Y -= 1][current_position_X] = player_model;
	else if (get_player_direction() == 'a')
		ary[current_position_Y][current_position_X -= 1] = player_model;
	else if (get_player_direction() == 's')
		ary[current_position_Y += 1][current_position_X] = player_model;
	else if (get_player_direction() == 'd')
		ary[current_position_Y][current_position_X += 1] = player_model;
}


void Snake::set_player_direction(char movement)
{
	//if (movement == 'w' || movement == 'a' || movement == 's' || movement == 'd' || movement == 'n')
	player_keystroke = movement;
	//return;
}

char Snake::get_player_direction()
{
	return player_keystroke;
}