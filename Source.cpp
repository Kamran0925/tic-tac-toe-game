#include<iostream>
#include<ctime>
#include<string>
#include<iomanip>
#include<cstdlib>
using namespace std;
void ticTacToe();
void posValidation(char*, int, int&);
void placeSymbol(char*, int, char, int);
bool gameOverStatus(char*, int, char);
void displayBoard(char *, int);
int giveRandomPos(int);
void randomPosValidation(char *board, int size, int &pos);
void symbolValidation(int &);
int main()
{
	ticTacToe();
	return 0;
}
void ticTacToe()
{
	int takeBoardSize();
	void placeNull(char *, int);
	int selectOpponent();
	void displayPositionsOnTable(int);
	void chooseSymbol(char &, char &);
	//	void displayBoard(char *, int );
	void playGameWithComp(char *, int, char *, char, char);
	void playGameWithHuman(char *, int, char*, char*, char, char);
	//	void posValidation(char* ,int  , int );
	//	void placeSymbol(char* ,int  , char ,int );
	//	bool gameOverStatus(char*, int, char);
	cout << "\n(*-*)Welcome to Tic Tac Toe game(*.-)";
	cout << "\n-------------------------------------";
	int size = takeBoardSize();
	char *board = new char[size*size];
	placeNull(board, size);
	int opponent = selectOpponent();
	char p1Name[15], p2Name[15] = "Computer";
	if (opponent == 1)
	{
		cout << "\nEnter  player 1 name:";
		cin.ignore();
		cin.getline(p1Name, 15, '\n');
		char p1Symbol, p2Symbol;
		cout << "\n" << p1Name;
		chooseSymbol(p1Symbol, p2Symbol);
		char playAgain = 'n';
		do
		{
			playGameWithComp(board, size, p1Name, p1Symbol, p2Symbol);
			cout << "\nDo you want to play again:";
			cout << "\nPress 'y' or 'Y':";
			cout << "\nIf you want to exit, press any key:";
			cin >> playAgain;
			if (playAgain != 'y' || playAgain != 'Y')
				exit(0);
		} while (playAgain == 'y' || playAgain == 'Y');
	}
	else
	{
		cout << "\nEnter player 1 name:";
		cin.ignore();
		cin.getline(p1Name, 15, '\n');
		cout << "\nEnter player 2 name:";
		cin.getline(p2Name, 15, '\n');
		char p1Symbol, p2Symbol;
		chooseSymbol(p1Symbol, p2Symbol);
		char playAgain = 'n';
		do
		{
			playGameWithHuman(board, size, p1Name, p2Name, p1Symbol, p2Symbol);
			cout << "\nDo you want to play again?";
			cout << "\nPress 'y' or 'Y':";
			cout << "\nIf you want to exit, press any key:";
			cin >> playAgain;
			if (playAgain != 'y' || playAgain != 'Y')
				return;
		} while (playAgain == 'y' || playAgain == 'Y');
	}
}
void playGameWithHuman(char *board, int  size, char* p1Name, char* p2Name, char p1Symbol, char p2Symbol)
{
	int pos, counter = size*size;
	while (counter>0)
	{
		cout << p1Name << "\nEnter position you want to mark:";
		cin >> pos;
		posValidation(board, size, pos);
		placeSymbol(board, size, p1Symbol, pos);
		displayBoard(board, size);
		if (gameOverStatus(board, size, p1Symbol) == true)
		{
			cout << "\n" << p1Name << " wins!";
			return;
		}
		cout << p2Name << "\nEnter position you want to mark:";
		cin >> pos;
		posValidation(board, size, pos);
		placeSymbol(board, size, p1Symbol, pos);
		displayBoard(board, size);
		if (gameOverStatus(board, size, p2Symbol) == true)
		{
			cout << "\n" << p2Name << " wins!";
			return;
		}
		counter--;
	}
	cout << "\nThe match has drawn!";
}
void playGameWithComp(char *board, int size, char *p1Name, char p1Symbol, char p2Symbol)
{
	//	void randomPosValidation(char*,int, int);

	int pos, counter = size*size;
	while (counter > 0)
	{
		cout << p1Name << "\nEnter position you want to mark:";
		cin >> pos;
		posValidation(board, size, pos);
		placeSymbol(board, size, p1Symbol, pos);
		displayBoard(board, size);
		if (gameOverStatus(board, size, p1Symbol) == true)
		{
			cout << "\n" << p1Name << " wins!";
			return;
		}
		pos = giveRandomPos(size);
		randomPosValidation(board, size, pos);
		placeSymbol(board, size, p2Symbol, pos);
		displayBoard(board, size);
		if (gameOverStatus(board, size, p2Symbol) == true)
		{
			cout << "\nComputer wins!";
			return;
		}
		counter--;
	}
	cout << "\nThe match has drawn!";
}
bool gameOverStatus(char* board, int size, char symbol)
{
	//check rows
	bool status;
	for (int i = 0; i < size; i++)
	{
		status = true;
		for (int j = i*size, counter = 0; counter <= size - 1; j++, counter++)
		{
			if (*(board + j) != symbol)
			{
				status = false;
				break;
			}
		}
		if (status == true)
			return true;
	}
	//check col
	for (int i = 0; i < size; i++)
	{
		status = true;
		for (int j = i, counter = 0; counter <= size - 1; counter++, j = j + size)
		{
			if (*(board + j) != symbol)
			{
				status = false;
				break;
			}
		}
		if (status == true)
			return true;
	}
	//check left diagonal
	status = true;
	for (int k = 0, counter = 1; counter <= size; counter++, k = 1 + k + size)
	{
		if (*(board + k) != symbol)
		{
			status = false;
			break;
		}
	}
	if (status == true)
		return true;
	//check right diagonal
	status = true;
	for (int k = size - 1, counter = 1; counter <= size; counter++, k = counter * size - counter)
	{
		if (*(board + k) != symbol)
		{
			status = false;
			break;
		}
	}
	if (status == true)
		return true;
	return false;
}
void randomPosValidation(char *board, int size, int &pos)
{
	bool isPosNull(char*, int, int);
	while (isPosNull(board, size, pos) == true)
	{
		pos = giveRandomPos(size);
	}
}

bool isPosNull(char*board, int size, int pos)
{
	if (*(board + pos) == '\0')
		return true;
	else
		return false;
}
void placeSymbol(char *board, int size, char p1Symbol, int  pos)
{
	*(board + pos) = p1Symbol;
}
void posValidation(char *board, int size, int &pos)
{
	pos = pos - 1;
	while (1)
	{
		while (pos >= size*size || pos < 0)
		{
			cout << "\nInvalid Position!";
			cout << "\nEnter position between 1 & " << size*size << ":";
			cin >> pos;
			pos = pos - 1;
		}
		if (*(board + pos) != '\0')
		{
			cout << "\nPosition already occupied!";
			cout << "\nEnter another position:";
			cin >> pos;
			pos = pos - 1;
			continue;
		}
		break;
	}
}
int giveRandomPos(int size)
{
	srand(0);
	return (rand() % (size*size) + 1);
}
void displayBoard(char *board, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		cout << "\n_";
		for (int k = 1; k <= size; k++)
		{
			cout << "____";
		}
		cout << "\n| ";
		for (int j = 0; j < size; j++)
		{
			cout << *(board + i*size + j) << " | ";
		}
	}
	cout << "\n_";
	for (int i = 1; i <= size; i++)
	{
		cout << "____";
	}
}
void chooseSymbol(char &player1Symbol, char &player2Symbol)
{
	int choice;
	//	void symbolValidation(int &);
	cout << "\nChoose your symbol.";
	cout << "\nPress 1 for 0. \nPress 2 for X.";
	cout << "\nEnter your choice:";
	cin >> choice;
//	symbolValidation(choice);
	if (choice == 1)
	{
		player1Symbol = 'O';
		player2Symbol = 'X';
	}
	else
	{
		player1Symbol = 'X';
		player2Symbol = 'O';
	}
}
void symbolValidation(int &ch)
{
	while (ch != 1 || ch != 2)
	{
		cout << "\nPress valid number:";
		cin >> ch;
	}
	return;
}
void placeNull(char *board, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			*(board + i*size + j) = '\0';
		}
	}
}

int takeBoardSize()
{
	int size;
	void sizeValidation(int &);

	cout << "\nEnter the size of board:";
	cin >> size;
	sizeValidation(size);
	return size;
}
void sizeValidation(int &size)
{
	while (size < 3 || size > 15)
	{
		cout << "\nEnter size between 3 and 15:";
		cin >> size;
	}
}

int selectOpponent()
{
	int selectOpponent;
	void opponentValidation(int &);

	cout << "\nSelect your opponent:";
	cout << "\nPress 1 for Human VS Computer:";
	cout << "\nPress 2 for Human VS Human:";
	cin >> selectOpponent;
	opponentValidation(selectOpponent);
	return selectOpponent;
}
void opponentValidation(int &selectOpponent)
{
	while (selectOpponent < 0 || selectOpponent > 2)
	{
		cout << "\nSelect valid option!";
		cout << "\nSelect your opponent:";
		cout << "\nPress 1 for Human VS Computer:";
		cout << "\nPress 2 for Human VS Human:";
		cin >> selectOpponent;
	}
}

void displayPositionsOnTable(int size)
{
	int countMaxDigits(int);
	int dig = countMaxDigits(size*size);
	for (int i = 1, counter = 1; i <= size; i++)
	{
		cout << "\n_";
		for (int i = 1; i <= size; i++)
		{
			cout << "___";
			for (int i = 1; i <= dig; i++)
				cout << "_";
		}
		cout << "\n| ";
		for (int i = 0; i < size; i++)
		{
			cout << setw(dig) << counter << " | ";
			counter++;
		}
	}
	cout << "\n_";
	for (int i = 1; i <= size; i++)
	{
		cout << "___";
		for (int i = 1; i <= dig; i++)
			cout << "_";
	}
}
int countMaxDigits(int num)
{
	int count = 0;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return count;
}
