
#include <iostream>
#include <cmath>
#include "sudoku.h"
#include <cassert>
#include <exception>
using namespace std;

sudoku::sudoku()
{
    //cout << "Creating new grid to zero." << endl;
    
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			grid[i][j] = 0;
		}
	}
}

sudoku::sudoku(int g[][9])
{
	//  cout << "Creating new grid from g." <<endl;

	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			grid[i][j] = g[i][j];
		}
	}
}

//allow manual inpout of a grid
void sudoku::inputSudoku()
{
	cout << "Please input a sudoku grid manually" << endl;

	int temp; 
	bool eFlag; //exception catching flag for looping
	exception e; //for input exception

	//two dimentional loop
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			//input, exception handling loop until correct input
			do {

				eFlag = false; //init flag

				//instruction
				cout << "Input num from 1-9 at location (" << i + 1 << "," << j + 1 << ") (0 == Blank)" << endl;

				try{ //to catch exceptions
					
					//accept user input
					if (!(cin >> temp)){ //if the input was not taken due to bad input
						cin.clear(); //clear bad input flag
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard input
						throw e;//throw generic exception
					}
					//if out of range
					if (0 > temp || temp > 9){
						throw temp; //throw this integer
					}
				}
				catch(const int temp){ // if input was out of range
					cout << temp << " is out of bounds, try again." << endl;
					eFlag = true; 
				}
				catch (exception& e){ // if input threw an cin error
					cout << e.what() << " is an invalid response, try again." << endl;
					eFlag = true;
				}
			} while (eFlag); //eFlag is true when there is an exception and is initalized to false at begining of loop

			assert(0 <= temp && temp <= 9);// to avoid  further issues, input must be between 0 and 9
			grid[i][j] = temp; //set grid item equal to temp
		}
	}
}
void sudoku::initializeSudokuGrid()
{
	//cout << "Initializing grid to zero." << endl;
	
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			grid[i][j] = 0;
		}
	}
}

void sudoku::initializeSudokuGrid(int g[][9])
{
	//cout << "Copying grid from g." << endl;

	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			grid[i][j] = g[i][j]; // copy members from g
		}
	}
}

void sudoku::printSudokuGrid() const
{
	cout << endl;
    cout << "Printing grid." << endl;
	cout << endl;

	//format the grid and proint each item
	for (int i = 0; i < 9; i++){
		cout << "|";
		for (int j = 0; j < 9; j++){
			cout << grid[i][j] << "|";
		}
		cout << endl;
		cout << "|-----------------|" << endl;
	}
}

bool sudoku::solveSudoku()
{
    int row, col;

	//find empty grid slot
    if (findEmptyGridSlot(row, col)) 
    {   
		//test each number from 1 to 9
        for (int num = 1; num <= 9; num++)  
        {   
			//check to see if the num is allowed in this location
            if (canPlaceNum(row, col, num)) 
            { 
				//cout << "Placing num " << num << " at " << row << "," << col << ")" << endl;
				
                grid[row][col] = num; // place num
				
                if (solveSudoku()) //recursive call
                    return true;
				grid[row][col] = 0; //backtrack
            }
        }
		
        return false; //none of these values were allowed
    }
	else{
		
		return true; //there are no empty slots
	}
}

bool sudoku::findEmptyGridSlot(int &row, int &col) const
{
	//cout << "Looking for empty slot." << endl;
    
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++)
			if (grid[i][j] == 0){
				row = i;
				col = j;
				
				return true;
			}
	}
	return false;
}

bool sudoku::canPlaceNum(int row, int col, int num) const
{
	//cout << "Checking placing number " << num << "in" << "(" << col << "," << row << ")" << endl;
    //check row column and box for num     
	if (numAlreadyInRow(row,num) || numAlreadyInCol(col,num) || numAlreadyInBox(row,col,num))
		return false;
	return true;
}

bool sudoku::numAlreadyInRow(int row, int num) const
{

	//cout << "Checking row " << row << " for number " << num << endl;
	
	for (int i = 0; i < 9; i++){
		if (grid[row][i] == num){
			return true;
		}
	}
	return false;
}

bool sudoku::numAlreadyInCol(int col, int num) const
{
	//cout << "Checking column " << col << " for number " << num << endl;
         
		 for (int i = 0; i < 9; i++){
			 if (grid[i][col] == num){
				 return true;
			 }
		 }
		 return false;
}

bool sudoku::numAlreadyInBox(int smallGridRow, int smallGridCol, 
                             int num) const
{
	int boxX = (smallGridRow / 3) * 3 + 1;//location of the center of the smaller box
	int boxY = (smallGridCol / 3) * 3 + 1;

	//cout << "Chicking box" << "(" << boxX << "," << boxY << ")" << endl;
   
	//check contents of the box by using its center and then checking its surrroundings
		 for (int i = -1; i <= 1; i++){
			 for (int j = -1; j <= 1; j++){
				 if (grid[boxX + i][boxY + j] == num){
					 return true;
				 }
			 }
		}
		return false;
}


