#include "stdafx.h"
#include "Display.h"
#include <Windows.h>
#include <iostream>

using namespace std;
typedef unsigned int uint;

Display::Display()
{
}


Display::~Display()
{
}

void Display::printBoard(vector<int>& board)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (uint i = 0; i < board.size(); i++)
	{
		if (i % 3 == 0)
			cout << endl;
		cout << board[i] << " ";
	}
}