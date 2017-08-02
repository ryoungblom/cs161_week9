

/**********************************
 ** Program Filename: TicTacToe.hpp
 ** Author: reuben youngblom
 ** Date: November 23rd 2016
 ** Description: This is the header file for TicTacToe.cpp.  Creates class TicTacToe and a Board object, and a char to tell whose turn it is, and a play function
 ** Input: No real input for header, but will take user input in main and TicTacToe.cpp
 ** Output: No real output in header, but Board.cpp and TicTacToe.cpp will output game board
 **********************************/

#include "Board.hpp"

class TicTacToe  //creates tic tac to class
{
private:
    Board gamePlay;  //board object, initialized to start a game
    char turn;  //char to hold whose turn it is, x or o
    char p2;  //second player, will set to the opposite of whatever first player chooses (either x or o)
public:
    void play (char p1);  //play function that holds gameplay logic and functions
};
