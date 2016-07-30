#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

char location[10] = {'0','1','2','3','4','5','6','7','8','9'};

int displayMenu(int &player, int &win);
int checkwin();
void displayBoard();
int get_MultiPlayer_Input(int &player);
int get_SinglePlayer_Input(int &player);
int displayResults(int&, int&);

int main()
{
	int player = 1;
	int	win;
	char again;

	do 
	{
		displayMenu(player, win);
		//get_MultiPlayer_Input(player);
		//displayBoard();
		//displayResults(win, player);
		cout << "\nWould You Like to Play Again" << endl
			 << "Please Enter Y or N" << endl;
		cin >> again;
	} while (again == 'y' || again == 'Y');
	
	return 0;
}

/*********************************************
	FUNCTION TO RETURN GAME STATUS
	1 FOR GAME IS OVER WITH RESULT
	2 FOR GAME IS IN PROGRESS
	O GAME IS OVER AND NO RESULT
**********************************************/

int checkwin()
{
	
	if (location[1] == location[2] && location[2] == location[3])
			return 1;
		else if (location[4] == location[5] && location[5] == location[6])
			return 1;
		else if (location[7] == location[8] && location[8] == location[9])
			return 1;
		else if (location[1] == location[4] && location[4] == location[7])
			return 1;
		else if (location[2] == location[5] && location[5] == location[8])
			return 1;
		else if (location[3] == location[6] && location[6] == location[9])
			return 1;
		else if (location[1] == location[5] && location[5] == location[9])
			return 1;
		else if (location[3] == location[5] && location[5] == location[7])
			return 1;
		else if (location[1] != '1' && location[2] != '2' && location[3] != '3' 
					 && location[4] != '4' && location[5] != '5' && location[6] != '6' 
					 && location[7] != '7' && location[8] != '8' && location[9] != '9')
			return 0;
	else
			return 2;
}

void displayBoard()
{
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << location[1] << "  |  " << location[2] << "  |  " << location[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << location[4] << "  |  " << location[5] << "  |  " << location[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << location[7] << "  |  " << location[8] << "  |  " << location[9] << endl;

	cout << "     |     |     " << endl << endl;
}

int get_MultiPlayer_Input(int &player)
{
	int win,
		choice;
	char mark;

	do
	{
		displayBoard();

		if (player % 2)
		 player = 1;

		else
		  player = 2;

		cout << "Player " << player << ", enter a number:  ";
		cin >> choice;

		if (mark = (player == 1))
			{mark = 'X';}
		else 
			mark = 'O';

		if (choice == 1 && location[1] == '1')

			location[1] = mark;
			else if (choice == 2 && location[2] == '2')
				location[2] = mark;
			else if (choice == 3 && location[3] == '3')
				location[3] = mark;
			else if (choice == 4 && location[4] == '4')
				location[4] = mark;
			else if (choice == 5 && location[5] == '5')
				location[5] = mark;
			else if (choice == 6 && location[6] == '6')
				location[6] = mark;
			else if (choice == 7 && location[7] == '7')
				location[7] = mark;
			else if (choice == 8 && location[8] == '8')
				location[8] = mark;
			else if (choice == 9 && location[9] == '9')
				location[9] = mark;
		else
		{
			cout<<"Invalid move\n";

			player--;
			system("PAUSE");
		}
		
		win = checkwin();
		player++; 
	}while (win == 2);

	return win;
}

int get_SinglePlayer_Input(int &player)
{
	int win,
		choice;
	const int MIN = 1,
			  MAX = 9;
	char mark;

	do
	{
		displayBoard();

		if (player % 2)
		 {
			 player = 1;
			 cout << "Player " << player << ", enter a number:  ";
			 cin >> choice;
		 }

		else
		  {
			  player = 2;
			  cout << "Computer Is Choosing A Location" << endl;
			  srand(time(0));
			  choice =  rand() % (MAX - MIN) + MIN; 
		}

		if (mark = (player == 1))
			{mark = 'X';}
		else 
			mark = 'O';

		if (choice == 1 && location[1] == '1')
			location[1] = mark;
			else if (choice == 2 && location[2] == '2')
				location[2] = mark;
			else if (choice == 3 && location[3] == '3')
				location[3] = mark;
			else if (choice == 4 && location[4] == '4')
				location[4] = mark;
			else if (choice == 5 && location[5] == '5')
				location[5] = mark;
			else if (choice == 6 && location[6] == '6')
				location[6] = mark;
			else if (choice == 7 && location[7] == '7')
				location[7] = mark;
			else if (choice == 8 && location[8] == '8')
				location[8] = mark;
			else if (choice == 9 && location[9] == '9')
				location[9] = mark;
		else
		{
			cout << "Invalid move\n";

			player--;
			system("PAUSE");
		}

		win = checkwin();
		player++; 
	}while (win == 2);

	return win;
}

int displayResults(int &win, int &player)
{
	if (win == 1)

	if (--player == 1)
		cout << "Player "<< player <<" wins ";
		else if (player == 2)
			cout << "Computer Wins" << endl;
		else if (player == 0)
			cout << "Game draw" << endl;
	else 
		cout << "Thank You for Playing. . ." << endl;
	if ( player == 1)
		return player = 1;
		else if (player == 2)
			return player = 2;
	else
		return player = 0;
}
int displayMenu(int &player, int &win)
{
	char menu,
		 game;

	cout << "A : Play the Game" << endl;
	cout << "B : Show Game Stats" << endl;
	cout << "C : Quit The Game" << endl;
	cin >> menu;

	switch(menu)
	{
		case 'A' : 
			cout << "S : SINGLE PLAYER" << endl;
			cout << "M : MULTIPLAYER" << endl;
			cin >> game;
			switch(game)
			{
				case 'S' :
					cout << "Single Player" << endl;
					win = get_SinglePlayer_Input(player);
					return win;
					break;
				case 'M' : 
					cout << "MultiPlayer" << endl;
					win = get_MultiPlayer_Input(player);
					return win;
					break;
			}
			break;
		case 'B' : 
			cout << "Show Game Stats . . ." << endl;
			break;
		case 'C' :
			cout << "Quit the Game" << endl;
			return 0;
			break;
	}
}
/*
void getStats(int &player)
	cout << "Player 1 :\tWins\tLoses\tTied" << endl;
	cout << "          \t" << wins << "\t" << loses << "\t" << tie << endl;
	*/