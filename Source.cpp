#include<iostream>
#include<conio.h> //_getch ()
#include <windows.h> //sleep(1000)
#include<stdlib.h> //rand() num
#include<time.h>
using namespace std;

/*
still to do:
~ grow snake body
/*to do this, maybe try:
* if the user input is 'w' then add 'player_body_model' at the bottom so it will add
  'player_body_model' at ('player_head_model'......s = [+1] [])
* if the user input is 'a' then add 'player_body_model' at the left so it will add
  'player_body_model' at ('player_head_model'......d = [] [+1])

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
	static const int board_size = 10;
	char ary[board_size][board_size]; //the board for the snake game
	int length;
	char player_head_model; //the player will be this char
	char player_body_model;
	int default_position_X; //players default starting X position
	int default_position_Y; //players default starting Y position
	int current_position_X; //players current X position
	int current_position_Y; //players current Y position
	char player_keystroke;

	//food:
	int foodX;
	int foodY;
	char food_model;

public:
	Snake();
	void setup_board(); /*makes the base board for the snake*/
	void print_board(); /*outputs the updated board WITH the user on it*/
	bool is_new_game(); /*determines if the game is new or not*/
	void move_player();
	bool detect_death(); //NEED TO DO

	//food:
	void set_food_position();
	void setFoodX(/*no parameters*/);
	void setFoodY(/*no parameters*/);
	void generate_new_food_coordinates();
	int getFoodX();
	int getFoodY();

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
		user.set_food_position();
		//user.detect_death(); //build this into a function idk which one though
		system("cls");
		user.print_board();
		//Sleep(100);
	}

	cout << endl << endl << endl << endl << endl << endl;
	cout << user.getFoodX()<< endl;
	Sleep(1000);
	cout << user.getFoodY()<< endl;

	return 0;
}




Snake::Snake()
{
	score = 1; //change score to 0

	static const int board_size = 10;
	ary[board_size][board_size];
	length = board_size;
	player_head_model = '*';
	player_body_model = 'o';
	default_position_X = board_size / 2;
	default_position_Y = board_size / 2;
	current_position_X = default_position_X;
	current_position_Y = default_position_Y;
	player_keystroke = 'n';

	//food:
	foodX = board_size / 2;
	foodY = board_size / 2;
	food_model = '@';
}

void Snake::setup_board()
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (i % 2 == 1)
				ary[i][j] = '='; //blank spaces = 32
			else
				ary[j][i] = '=';

			if (j % 2 == 1)
				ary[i][j] = '=';
			else
				ary[j][i] = '=';
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
	if (score == 0 && current_position_X == default_position_X 
		&& current_position_Y == default_position_Y )
		return 1;
	return 0;
}

void Snake::move_player()
{
	if (is_new_game())
		ary[default_position_Y][default_position_X] = player_head_model;
	else if (!is_new_game())
		movement_logic();
}

//bool Snake::detect_death()
//{
//	for (int i = 0; i < length; i++)
//	{
//		for (int j = 0; j < length; j++)
//		{
//			if (current_position_X == -1 || current_position_X == 10 
//				|| current_position_Y == -1 || current_position_Y == 10)
//			{
//				return 0;
//			}
//		}
//	}
//	return 1;
//}

void Snake::current_player_position()
{
	//ary[current_position_Y][current_position_X];
}

void Snake::movement_logic()
{
	current_player_position();

	if (get_player_direction() == 'w')
		ary[current_position_Y -= 1][current_position_X] = player_head_model;
	else if (get_player_direction() == 'a')
		ary[current_position_Y][current_position_X -= 1] = player_head_model;
	else if (get_player_direction() == 's')
		ary[current_position_Y += 1][current_position_X] = player_head_model;
	else if (get_player_direction() == 'd')
		ary[current_position_Y][current_position_X += 1] = player_head_model;
	else
		cin.ignore();
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


//Food:
void Snake::setFoodX(/*no parameters*/)
{
	srand(time(NULL));
	foodX = rand() % board_size;
}

void Snake::setFoodY(/*no parameters*/)
{
	srand(time(NULL));
	foodY = rand() % board_size;
}

int Snake::getFoodX()
{
	//setFoodX();
	return foodX;
}
int Snake::getFoodY()
{
	//setFoodY();
	return foodY;
}

void Snake::set_food_position()
{
	if (ary[current_position_Y][current_position_X] == ary[getFoodY()][getFoodX()])
	{
		generate_new_food_coordinates();
		ary[getFoodY()][getFoodX()] = food_model;
	}
	else if (ary[current_position_Y][current_position_X] != ary[getFoodY()][getFoodX()])
	{
		ary[getFoodY()][getFoodX()] = food_model;
	}
}

void Snake::generate_new_food_coordinates()
{
	setFoodX();
	setFoodY();
}