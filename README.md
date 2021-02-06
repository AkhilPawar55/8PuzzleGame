# 8-puzzle-problem
Normal 8 puzzle problem using A star path-finding algorithm
8 puzzle board game
In our game we created 3 classes: Board, Tree, Display

Board.cpp

This class contains:
1)	initializeBoard() method that creates the initial board using a vector. The elements are pushed into the vector in a sorted manner. 
2)	scrambleBoard() method shuffles all the elements of the vector in random fashion 30 times, using the rand() predefined function. 
3)	slideTile() function checks whether there are any legal moves or not and accordingly moves the elements of the vector.
4)	isBoardSolved() function defines a vector boardSolved which contains the elements in the sorted manner. Then it compares the elements of the board with the boardSolved vector and return a bool value accordingly.

Tree.cpp

This class contains:
1)	CalculateHeuristic() uses Manhattan distance to calculate the total cost that may be required to reach the goal node from the current node.
2)	CalculateHamming() uses to number of misplaced tiles to calculate heuristic to help in solving the puzzle
3)	MakeRoot() function initializes then scrambles the board. It then calculates the Heuristic function for the scrambled board.
4)	MakeMove() function checks the possible moves for the current node elements and moves them accordingly.
5)	Insert() function stores the current board vector into node. Then it creates 4 child nodes for the current node making moves in four directions. It then checks whether the node is being previously explored or not, by comparing with the explored vector of type node. It also checks whether the current node is equal to the parent node or not. If it not any of the above mentioned then it adds the node into the unexplored vector of type node.
6)	build() function calls the MakeRoot() function then it stores the first element of the unexplored vector that is the vector with lowest heuristic value in the curr node. Then it erases explored elements from the unexplored vector and pushes them in the explored vector.
7)	Sort() function compares the heuristic value for each vector in the unexplored list in ascending order.
8)	CheckSuccess() function checks for each possible child whether it is solved or not by calling the isBoardSolved() function. If solved, then checks whether the unexplored vector is empty or not. If not, the erases the unexplored vector and prints the success message.
9)	CheckExplored() checks whether all the elements are explored or not by comparing it with the explored vector of type node.
10)	CheckCurrent() function compares the parent node and the generated node to see whether they are same or not.
11)	PrintSolvedPath() backtracks the path from the final state to initial state and prints it out from initial state to solved state.

Display.cpp

The display class is inherited by the Board.cpp and contains printBoard() function which prints the board in normal 8 puzzle game form.

