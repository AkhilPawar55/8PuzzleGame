#pragma once
#include <vector>

using namespace std;

class Display
{
public:
	Display();
	~Display();

	void printBoard(vector<int>& board);
};

