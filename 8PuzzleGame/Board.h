#pragma once
#include <iostream>
#include <vector>
#include "Display.h"

using namespace std;
class Board : public Display
{
public:
	int i;

	Board();
	~Board();
	friend bool operator==(const Board& left, const Board& right);
	
	void initializeBoard(vector<int>& board);
	void scrambleBoard(vector<int>& board);
	void slideTile(vector<int>& board, int move);
	bool isBoardSolved(vector<int>& board);
};

