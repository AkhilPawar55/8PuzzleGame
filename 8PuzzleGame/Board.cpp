
#include <vector>
#include "stdafx.h"
#include "Board.h"
#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;
typedef unsigned int uint;

Board::Board()
{
}

Board::~Board()
{
}

void Board::initializeBoard(vector<int>& board)
{
	board.push_back(1);
	board.push_back(2);
	board.push_back(3);
	board.push_back(4);
	board.push_back(5);
	board.push_back(6);
	board.push_back(7);
	board.push_back(8);
	board.push_back(0);
}

void Board::scrambleBoard(vector<int>& board)
{
	srand(time(NULL));
	int move;
	while (isBoardSolved(board))
	{
		for (int i = 0; i < 30; i++)
		{
			move = rand() % 5;
			slideTile(board, move);
		}
	}
}
void Board::slideTile(vector<int>& board, int move)
{
	int emptyTile;
	bool legalMoves[4] = { 1,1,1,1 }; //0 = up, 1 = down, 2 = right, 3 = left

	for (int i = 0; i < board.size(); i++)
	{
		if (board[i] == 0)
		{
			emptyTile = i;
		}
	}
	

	if ((emptyTile + 1) % 3 == 0)
	{
		legalMoves[2] = false;
	}

	if ((emptyTile - 1) % 3 == 2 || (emptyTile - 1) % 3 == -1)
	{
		legalMoves[3] = false;
	}

	if (emptyTile + 3 > 8)
	{
		legalMoves[1] = false;
	}

	if (emptyTile - 3 < 0)
	{
		legalMoves[0] = false;
	}

	switch (move)
	{

	case 0:
		if (legalMoves[move])
		{
			board[emptyTile] = board[emptyTile - 3];
			board[emptyTile - 3] = 0;
			emptyTile = emptyTile - 3;
		}
		break;

	case 1:
		if (legalMoves[move])
		{
			board[emptyTile] = board[emptyTile + 3];
			board[emptyTile + 3] = 0;
			emptyTile = emptyTile + 3;
		}
		break;

	case 2:
		if (legalMoves[move])
		{
			board[emptyTile] = board[emptyTile + 1];
			board[emptyTile + 1] = 0;
			emptyTile = emptyTile + 1;
		}
		break;

	case 3:
		if (legalMoves[move])
		{
			board[emptyTile] = board[emptyTile - 1];
			board[emptyTile - 1] = 0;
			emptyTile = emptyTile - 1;
		}
		break;

	default:
		break;
	}
}

bool Board::isBoardSolved(vector<int>& board)
{
	vector<int> solvedBoard = { 1,2,3,4,5,6,7,8,0 };
	bool boardSolved = true;
	uint row = 0;
	while (boardSolved && row < board.size())
	{
		//compares each element of board with solvedBoard
		if (solvedBoard[row] == board[row])
		{
			row++;
		}
		else
			boardSolved = false;
	}
	return boardSolved;
}

bool operator==(const Board & left, const Board & right)
{
	return left.i == right.i;
}