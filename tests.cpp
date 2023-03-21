#include<iostream>
using namespace std;

int main()
{
	int length = 10;
	char ary[10][10];

	//build board:
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

			//border -- make it so if the user collides with these, they DIE
			if (i == 0 || i == 9 || j == 0 || j == 9)
			{
				ary[i][j] = '$';
				ary[j][i] = '$';
			}
				
		}
	}

	//print board:
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			cout << ary[i][j] << ' ';
		}
		cout << endl;
	}


	return 0;
}