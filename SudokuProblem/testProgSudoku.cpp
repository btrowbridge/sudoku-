
#include <iostream>
#include <cmath>
#include "sudoku.h"

using namespace std;

void testSudoku(int[][9]); // for testing cases
int main()
{
	//cases 1 with solution
	int g[9][9] = { { 0, 0, 0, 6, 7, 0, 0, 0, 0 },
					{ 2, 0, 8, 0, 4, 3, 7, 5, 0 }, 
					{ 0, 0, 0, 0, 0, 0, 0, 2, 0 },
					{ 0, 0, 0, 0, 9, 1, 3, 0, 5 },
					{ 0, 0, 4, 0, 0, 0, 1, 0, 0 },
					{ 5, 0, 9, 3, 6, 0, 0, 0, 0 },
					{ 0, 5, 1, 0, 0, 0, 0, 0, 0 },
					{ 0, 4, 2, 1, 5, 0, 8, 0, 9 },
					{ 0, 0, 0, 0, 2, 4, 0, 0, 0 }};
	
	//case 2 with solution
	int h[9][9] = { { 1, 9, 5, 6, 7, 2, 4, 3, 8 },
					{ 2, 0, 8, 0, 4, 3, 7, 5, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 2, 0 },
					{ 0, 0, 0, 0, 9, 1, 3, 0, 5 },
					{ 0, 0, 4, 0, 0, 0, 1, 0, 0 },
					{ 5, 0, 9, 3, 6, 0, 0, 0, 0 },
					{ 0, 5, 1, 0, 0, 0, 0, 0, 0 },
					{ 0, 4, 2, 1, 5, 0, 8, 0, 9 },
					{ 0, 0, 0, 0, 2, 4, 0, 0, 0 },};

	//case 3 without solution
	int i[9][9] = { { 0, 0, 3, 0, 0, 2, 0, 0, 0 },
					{ 2, 6, 0, 0, 9, 4, 0, 0, 0 },
					{ 0, 0, 8, 5, 3, 0, 0, 0, 6 },
					{ 0, 5, 6, 0, 0, 0, 1, 9, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 2, 1, 0, 0, 0, 5, 7, 0 },
					{ 6, 0, 0, 0, 2, 5, 4, 0, 0 },
					{ 0, 0, 0, 9, 1, 0, 0, 6, 7 },
					{ 0, 0, 8, 6, 0, 0, 9, 0, 0 } };


	//testing cases
	cout << "Case 1" << endl;
	testSudoku(g);
	cout << endl;

	cout << "Case 2" << endl;
	testSudoku(h);
	cout << endl;

	cout << "Case 3" << endl;
	testSudoku(i);
	cout << endl;

	//manual input case
	cout << "Input Case" << endl;
	sudoku inSudoku;
	inSudoku.inputSudoku();
	inSudoku.printSudokuGrid();
	inSudoku.solveSudoku();
	inSudoku.printSudokuGrid();


}    

//for purpose of reusing code to test the cases
void testSudoku(int g[9][9]){
	sudoku mySudoku;
	mySudoku.initializeSudokuGrid(g);

	mySudoku.printSudokuGrid();

	if (mySudoku.solveSudoku()){
		cout << "Solution Found" << endl;
		mySudoku.printSudokuGrid();
	}
	else
		cout << "No solutions" << endl;
}