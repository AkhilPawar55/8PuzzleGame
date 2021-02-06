#include <vector>
#include "Board.h"

using namespace std;

#pragma once
struct node
{
	node *child1;
	node *child2;
	node *child3;
	node *child4;
	node *parent;
	Board board;
	vector<int> current_state;
	int total_cost;
	int g_cost;
	int h_cost;
	vector<int> final_state = { 1,2,3,4,5,6,7,8,0 };
};
class Tree
{
public:
	node *root;
	vector<node*> unexplored;
	vector<node*> explored;
	vector<node*> solvedPath;
	bool whichHeuristic;

	Tree();
	~Tree();
	Tree(const Tree& other);
	Tree& operator=(const Tree& other);

	int CalculateHeuristic(node* current);
	int CalculateHamming(node* current);
	void MakeRoot();
	void MakeMove(node* current, node* t, int dir);
	void Insert(node* current);
	void build();
	void Sort();
	bool isEmpty() const { return root == NULL; }
	void CheckSuccess(node* current);
	bool CheckExplored(node* t);
	bool CheckCurrent(node* current, node* t);
	void PrintSolvedPath(node* solvedNode);
};

