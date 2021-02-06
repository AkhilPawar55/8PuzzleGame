#include "stdafx.h"
#include "Tree.h"
#include "Board.h"


Tree::Tree()
{
	root = NULL;
	whichHeuristic = true;
}

Tree::Tree(Tree const& other)
{
	root = other.root;
	unexplored = other.unexplored;
	explored = other.explored;
	solvedPath = other.solvedPath;
	whichHeuristic = other.whichHeuristic;
}

Tree& Tree::operator=(Tree const& other)
{
	if (this != &other)
	{
		root = other.root;
		unexplored = other.unexplored;
		explored = other.explored;
		solvedPath = other.solvedPath;
		whichHeuristic = false;
	}
	return *this;
}

Tree::~Tree()
{
	delete root;
	unexplored.clear();
	explored.clear();
	solvedPath.clear();
}

void Tree::build()
{
	MakeRoot();
	node* curr = new node;
	while (unexplored.size() > 0)
	{
		curr = unexplored.front();					//stores the node with smallest heuristic value in curr
		explored.push_back(curr);
		unexplored.erase(unexplored.begin());		//erases the element from unexplored that is expanded
		cout << "SELECTING THE FIRST ELEMENT FROM THE 'UNEXPLORED' VECTOR AND EXPANDING IT" << endl;		
		Insert(curr);								//expands the nodes of the node with smallest heuristic
	}
	
	
}

void Tree::Sort()
{
	cout << "SORTING THE ELEMENTS OF THE 'UNEXPLORED' VECTOR BASED ON THE TOTAL COST" << endl;
	cout << endl;

	node* temp = new node;
	
	for(int j = 0; j < unexplored.size() - 1; j++)
	{
		for (int i = 0; i < unexplored.size() - 1; i++)
		{
			if (unexplored[i]->total_cost > unexplored[i + 1]->total_cost)
			{
				temp = unexplored[i];
				unexplored[i] = unexplored[i + 1];
				unexplored[i + 1] = temp;
			}

		}
	}

	for (int i = 0; i < unexplored.size(); i++)
	{
		cout << "The sorted Total Cost: " << unexplored[i]->total_cost << endl;
	}
	cout << endl;
	cout << "THE VECTOR HAS BEEN SORTED" << endl;
}

void Tree::MakeRoot()
{
	node* t1 = new node;
	t1->board.initializeBoard(t1->current_state);
	t1->board.scrambleBoard(t1->current_state);

	t1->board.printBoard(t1->current_state);
	cout << endl;

	if (whichHeuristic)
	{
		t1->h_cost = CalculateHeuristic(t1);
	}
	else
	{
		t1->h_cost = CalculateHamming(t1);
	}
	t1->g_cost = 1;

	t1->child1 = NULL;
	t1->child2 = NULL;
	t1->child3 = NULL;
	t1->child4 = NULL;
	t1->parent = NULL;

	if (isEmpty())
	{
		root = t1;
		unexplored.push_back(root);
	}

	cout << "-----------------------------Initial State of the Board-----------------------------" << endl;
}

void Tree::MakeMove(node* current, node* t, int dir)
{
	for (int i = 0; i < current->current_state.size(); i++)
	{
		t->current_state.push_back(current->current_state[i]);
	}

	t->board.slideTile(t->current_state, dir);
}

void Tree::Insert(node* current)
{
	cout << "GENERATING ALL POSSIBLE CHILD OF THE CURRENT NODE!" << endl;
	node* t1 = new node;
	MakeMove(current, t1, 0);
	if (!(CheckCurrent(current, t1)) && !(CheckExplored(t1)))
	{
		t1->board.printBoard(t1->current_state);
		cout << endl;
		if (whichHeuristic)
		{
			t1->h_cost = CalculateHeuristic(t1);
		}
		else
		{
			t1->h_cost = CalculateHamming(t1);
		}
		t1->g_cost = current->g_cost + 1;
		t1->total_cost = t1->h_cost + t1->g_cost;
		cout << "The total cost of the node: " << t1->total_cost << endl;
		cout << endl;
		t1->child1 = NULL;
		t1->child2 = NULL;
		t1->child3 = NULL;
		t1->child4 = NULL;
		t1->parent = current;
	}
	else
	{
		t1->current_state.clear();
	}
	

	node* t2 = new node;
	MakeMove(current, t2, 1);
	if (!(CheckCurrent(current, t2)) && !(CheckExplored(t2)))
	{
		t2->board.printBoard(t2->current_state);
		cout << endl;
		if (whichHeuristic)
		{
			t2->h_cost = CalculateHeuristic(t2);
		}
		else
		{
			t2->h_cost = CalculateHamming(t2);
		}
		t2->g_cost = current->g_cost + 1;
		t2->total_cost = t2->h_cost + t2->g_cost;
		cout << "The total cost of the node: " << t2->total_cost << endl;
		cout << endl;
		t2->child1 = NULL;
		t2->child2 = NULL;
		t2->child3 = NULL;
		t2->child4 = NULL;
		t2->parent = current;
	}
	else
	{
		t2->current_state.clear();
	}
	

	node* t3 = new node;
	MakeMove(current, t3, 2);
	if (!(CheckCurrent(current, t3)) && !(CheckExplored(t3)))
	{
		t3->board.printBoard(t3->current_state);
		cout << endl;
		if (whichHeuristic)
		{
			t3->h_cost = CalculateHeuristic(t3);
		}
		else
		{
			t3->h_cost = CalculateHamming(t3);
		}
		t3->g_cost = current->g_cost + 1;
		t3->total_cost = t3->h_cost + t3->g_cost;
		cout << "The total cost of the node: " << t3->total_cost << endl;
		cout << endl;
		t3->child1 = NULL;
		t3->child2 = NULL;
		t3->child3 = NULL;
		t3->child4 = NULL;
		t3->parent = current;
	}
	else
	{
		t3->current_state.clear();
	}

	node* t4 = new node;
	MakeMove(current, t4, 3);
	if (!(CheckCurrent(current, t4)) && !(CheckExplored(t4)))
	{
		t4->board.printBoard(t4->current_state);
		cout << endl;
		if (whichHeuristic)
		{
			t4->h_cost = CalculateHeuristic(t4);
		}
		else
		{
			t4->h_cost = CalculateHamming(t4);
		}
		t4->g_cost = current->g_cost + 1;
		t4->total_cost = t4->h_cost + t4->g_cost;
		cout << "The total cost of the node: " << t4->total_cost << endl;
		cout << endl;
		t4->child1 = NULL;
		t4->child2 = NULL;
		t4->child3 = NULL;
		t4->child4 = NULL;
		t4->parent = current;
	}
	else
	{
		t4->current_state.clear();
	}

	if ((current->child1 == NULL) && (t1->current_state.size() > 0))
	{
		current->child1 = t1;
		if (!(current->board.isBoardSolved(current->current_state)))
		{
			unexplored.push_back(current->child1);
		}
		else
			delete t1;
	}
	if ((current->child2 == NULL) && (t2->current_state.size() > 0))
	{
		current->child2 = t2;
		if (!(current->board.isBoardSolved(current->current_state)))
		{
			unexplored.push_back(current->child2);
		}
		else
			delete t2;
	}
	if ((current->child3 == NULL) && (t3->current_state.size() > 0))
	{
		current->child3 = t3;
		if (!(current->board.isBoardSolved(current->current_state)))
		{
			unexplored.push_back(current->child3);
		}
		else
			delete t3;
	}
	if ((current->child4 == NULL) && (t4->current_state.size() > 0))
	{
		current->child4 = t4;
		if (!(current->board.isBoardSolved(current->current_state)))
		{
			unexplored.push_back(current->child4);
		}
		else
			delete t4;
	}

	cout << "AND PUSHING THEM IN THE 'UNEXPLORED' VECTOR" << endl;

	Sort();
	CheckSuccess(current);
}

int Tree::CalculateHeuristic(node* current)
{
	int cst[3][3];
	int mDist = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cst[i][j] = current->current_state[j + (3 * i)];
		}
	}

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			int value = cst[x][y];
			if (value == 0)
				value = 9;
			int targetX = (value - 1) / 3;
			int targetY = (value - 1) % 3;
			int distX = abs(x - targetX);
			int distY = abs(y - targetY);
			mDist = mDist + distX + distY;
		}
	}
	cout << "The manhattan distance heuristic is: " << mDist << endl;
	return mDist;
}

void Tree::CheckSuccess(node* current)
{
	bool pass1 = true;
	bool pass2 = true;
	bool pass3 = true;
	bool pass4 = true;

	if (current->child1 != NULL)
	{
		pass1 = current->child1->board.isBoardSolved(current->child1->current_state);
	}
	else
	{
		pass1 = false;
	}

	if (current->child2 != NULL)
	{
		pass2 = current->child2->board.isBoardSolved(current->child2->current_state);
	}
	else
	{
		pass2 = false;
	}

	if (current->child3 != NULL)
	{
		pass3 = current->child3->board.isBoardSolved(current->child3->current_state);
	}
	else
	{
		pass3 = false;
	}

	if (current->child4 != NULL)
	{
		pass4 = current->child4->board.isBoardSolved(current->child4->current_state);
	}
	else
	{
		pass4 = false;
	}

	if (pass1)
	{
		cout << "SUCCESSFULLY SOLVED THE PUZZLE!" << endl;
		PrintSolvedPath(current->child1);
		while (!unexplored.empty())
		{
			unexplored.erase(unexplored.begin());
		}
	}
	else if (pass2)
	{
		cout << "SUCCESSFULLY SOLVED THE PUZZLE!" << endl;
		PrintSolvedPath(current->child2);
		while (!unexplored.empty())
		{
			unexplored.erase(unexplored.begin());
		}
	}
	else if (pass3)
	{
		cout << "SUCCESSFULLY SOLVED THE PUZZLE!" << endl;
		PrintSolvedPath(current->child3);
		while (!unexplored.empty())
		{
			unexplored.erase(unexplored.begin());
		}
	}
	else if (pass4)
	{
		cout << "SUCCESSFULLY SOLVED THE PUZZLE!" << endl;
		PrintSolvedPath(current->child4);
		while (!unexplored.empty())
		{
			unexplored.erase(unexplored.begin());
		}
	}
}

bool Tree::CheckExplored(node* t)
{
	int r = 0;
	bool check = true;
	for (int i = 0; i < explored.size(); i++)
	{
		check = true;
		while (check && r < explored[i]->current_state.size())
		{
			if (explored[i]->current_state[r] == t->current_state[r])
			{
				r++;
			}
			else
			{
				check = false;
			}
		}
	}

	return check;
}

bool Tree::CheckCurrent(node* current, node* t)
{
	int r = 0;
	bool check = true;
	while (check && r < current->current_state.size())
	{
		if (current->current_state[r] == t->current_state[r])
		{
			r++;
		}
		else
		{
			check = false;
		}
	}
	return check;
}

void Tree::PrintSolvedPath(node* solvedNode)
{
	int i = 0;
	solvedPath.push_back(solvedNode);

	while (solvedPath[i]->parent != NULL)
	{
		solvedPath.push_back(solvedPath[i]->parent);
		i++;
	}

	for (int j = solvedPath.size(); j > 0; j--)
	{
		solvedPath[j - 1]->board.printBoard(solvedPath[j-1]->current_state);
		cout << endl;
		cout << endl;
	}
	cout << "_____________________________________END_____________________________________" << endl;
	cout << endl;
}

int Tree::CalculateHamming(node* current)
{
	int hDist = 0;
	vector<int> f = { 1,2,3,4,5,6,7,8,0 };
	for (int i = 0; i < f.size(); i++)
	{
		if (current->current_state[i] != f[i])
		{
			hDist++;
		}
	}

	cout << "The Hamming heuristic is: " << hDist << endl;
	return hDist;
}