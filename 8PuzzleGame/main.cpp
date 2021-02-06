// HW3.cpp : Defines the entry point for the console application.
//
#include <vector>
#include "stdafx.h"
#include "Board.h"
#include "Tree.h"
#include <iostream>
#include <memory>
#include <thread>

using namespace std;

void task1()
{
	Tree t;
	t.build();
};

void task2()
{
	Tree t;
	Tree t1(t);
	t1 = t;
	t1.build();
};

int main()
{
	Tree t;
	Tree t2(t);
	t2 = t;
	t2.build();			//Will use Hamming Heuristic
	t.build();			//Will use Manhattan distance Heuristic
	
	/*
	NOTE: THE COMMENTED PART BELOW IS USING MULTITHREADING. USING 2 THREADS, ONE THREAD USING "MANHATTAN DISTANCE",
	OTHER ONE USING "HAMMING HEURISTIC" 

	th2 is solved using "Hamming Heuristic"
	th1 is solved using "Manhattan Distance Heuristic"
	*/

	/*thread th1 = thread(task1);
	thread th2 = thread(task2);

	th2.join();
	th1.join();*/

	return 0;
}

