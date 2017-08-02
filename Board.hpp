
/**********************************
 ** Program Filename: Board.hpp
 ** Author: reuben youngblom
 ** Date: November 23rd 2016
 ** Description: This is the header file for Board.cpp.  Creates enum for gameStatus, and has prototypes for Board functions.
 ** Input: No real input for header, but will take user input in main and TicTacToe.cpp
 ** Output: No real output in header, but Board.cpp and TicTacToe.cpp will output game board
 **********************************/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

enum Status {X_WON, O_WON, DRAW, UNFINISHED};  //enum for limited list of gameStatus options

class Board  //creates Board class
{
private:
    int counter=0;  //will use this to count number of times gameStatus is called to determine when a draw occurs
public:
    char boardArray [4][4];  //creates array for tic tac toe board
    void setBoard();  //prototype for setBoard (initializes board)
    void print();  //prototype for print function, which will print the board
    bool makeMove(char turn, int CX, int CY);  //makeMove prototype, will allow a player to make a move. Takes the player whose turn it is and coordinates as functions
    Status gameState ();  //gameState prototype. Will return one of the enum options as the status
    int checkStatus ();  //prototype for function that I made to handle the logic of a win
};


