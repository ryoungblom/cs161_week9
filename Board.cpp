
/**********************************
 ** Program Filename: Board.cpp
 ** Author: reuben youngblom
 ** Date: November 23rd 2016
 ** Description: Board.cpp file.  Has functions to set game board to blank and create the coordinates, print the board, make a move, and a function with all the logic for determining a win.
 ** Input: User input. Will take player from main and coordinates from TicTacToe, And uses these to print current board game and make moves and check the status of the game
 ** Output: will print current board game and status in the even of a win or draw.
 **********************************/


#include "Board.hpp"

void Board::setBoard()  //function for setting the board to "blank", which is numeric coordinates and dots
{
    for (int i = 0; i < 4; ++i)  //loops through first dimension of array
    {
        for (int j = 0; j < 4; ++j)  //nested loop through second dimension of array so all coordinates are hit
        {
            boardArray[i][j] = '.';  //each loop through sets a '.' in each place
        }
    }
    
    boardArray[0][0] = ' ';  //sets upper left coodinate to be blank
    boardArray[0][1] = '0';
    boardArray[1][0] = '0';
    boardArray[0][2] = '1';  //these set the "walls" to be numeric coordinates
    boardArray[2][0] = '1';
    boardArray[0][3] = '2';
    boardArray[3][0] = '2';
}


void Board::print()  //function to print the board
{
    
    for (int i = 0; i < 4; ++i)  //loops through first dimension of array
    {
        for (int j = 0; j < 4; ++j)  //loops through second dimension of array
        {
            cout << boardArray[i][j] << ' ';  //outputs each cell
        }
        cout << endl;  //prints an endline as a space
    }
}


bool Board::makeMove(char turn, int CX, int CY)  //function to let a player make a move.  takes the layer whose turn it is, and their coordinates as arguments
{
    
    if (boardArray[CX][CY] != '.')  //if their chosen coordiantes contain info (i.e. is not filled with a '.')
    {
        return false;  //return false
    }
    
    else  //but barring this (i.e. if it DOES have a '.')
    {
        boardArray[CX][CY] = turn;   //put the player's mark in that cell
        return true;   //and return true
    }
}


Status Board::gameState()  //this calculates the status of the game
{
    Status gameStatus;  //create enum Status variable
    counter++;   //tracks how many times this function is called.  I use this later to determine whether or not a draw occured, since a draw is always after a specified number of turns and so this function will get called the same number of times every time there's a draw.  The game also checks for a winner before checking for a draw in case someone wins on the very last turn.
    
    if (Board::checkStatus() == 1)  //takes checkStatus info from checkStatus function below.  If logic shakes out that X wins, checkStatus kicks back 1, and gameStatus here will return 1.
    {
        gameStatus = X_WON;
    }
    else if (Board::checkStatus()== 2)  //same for O winning, gamestatus will equal 2
    {
        gameStatus = O_WON;
    }
    
    else if (counter == 32)  //if the counter above hits 32 (after checking for a winner), the proper number of turns have happened for a draw (assuming neither x nor o won).  It's 32 because in my TicTacToe function, I sometimes call gameState a few times (i.e. I check right at the beginning to reset it, and then at least once a turn, and sometimes to run loops, etc.) so it's not a strict 1-to-1 correlation.  But in every case, if gameState is called 32 times and neither X nor O has won, it's a draw.
    {
        gameStatus = DRAW;  //so it changes gameState to DRAW
    }
    
    else
    {
        gameStatus = UNFINISHED;  //if none of these abov situations obtain, the game is ongoing and it will return UNFINISHED
    }
    
    return gameStatus;
}


int Board::checkStatus()  //made this to handle the logic for a win.  Since wins only happen when x's or o's are in one of three horizontal or vertical lines or one of two diagonal lines, I could write out all the possibilities manually.
{
    int winner;  //creates variable to return. In gameStatus function, each int possibility correlates with a status.
    
    /*********************************
     this section checks for a winner via brute force logic.  Not the most elegant, but it works.  I essentially put in every winning combination for either x and o to win.  This will kick back either a 1 (if X wins), a 2(if o wins), or a 4 (if no winning scenarios have obtained, meaning that the game is still  unfinished.  These return values are passed to gameStatus() function, which checks against outcomes.  If it passes a 1, gameStatus returns X_WINS; a 2, O_WINS; and a 4, UNFINISHED.
     ********************************/
    
    
    //this section checks for x win scenarios
    
    if (boardArray[1][1] == 'x' && boardArray[1][2] == 'x' && boardArray[1][3] =='x')
    {winner = 1;}
    else if (boardArray[2][1] == 'x' && boardArray[2][2] == 'x' && boardArray[2][3] == 'x')
    {winner = 1;}
    else if (boardArray[3][1] == 'x' && boardArray[3][2] == 'x' && boardArray[3][3] == 'x')
    {winner = 1;}
    else if (boardArray[1][1] == 'x' && boardArray[2][1] == 'x' && boardArray[3][1] == 'x')
    {winner = 1;}
    else if (boardArray[1][2] == 'x' && boardArray[2][2] == 'x' && boardArray[3][2] == 'x')
    {winner = 1;}
    else if (boardArray[1][3] == 'x' && boardArray[2][3] == 'x' && boardArray[3][3] == 'x')
    {winner = 1;}
    else if (boardArray[1][3] == 'x' && boardArray[2][2] == 'x' && boardArray[3][1] == 'x')
    {winner = 1;}
    else if (boardArray[1][1] == 'x' && boardArray[2][2] == 'x' && boardArray[3][3] == 'x')
    {winner = 1;}
    
    
    //this section checks for o win scenarios
    
    else if (boardArray[1][1] == 'o' && boardArray[1][2] == 'o' && boardArray[1][3] == 'o')
    {winner = 2;}
    else if (boardArray[2][1] == 'o' && boardArray[2][2] == 'o' && boardArray[2][3] == 'o')
    {winner = 2;}
    else if (boardArray[3][1] == 'o' && boardArray[3][2] == 'o' && boardArray[3][3] == 'o')
    {winner = 2;}
    else if (boardArray[1][1] == 'o' && boardArray[2][1] == 'o' && boardArray[3][1] == 'o')
    {winner = 2;}
    else if (boardArray[1][2] == 'o' && boardArray[2][2] == 'o' && boardArray[3][2] == 'o')
    {winner = 2;}
    else if (boardArray[1][3] == 'o' && boardArray[2][3] == 'o' && boardArray[3][3] == 'o')
    {winner = 2;}
    else if (boardArray[1][3] == 'o' && boardArray[2][2] == 'o' && boardArray[3][1] == 'o')
    {winner = 2;}
    else if (boardArray[1][1] == 'o' && boardArray[2][2] == 'o' && boardArray[3][3] == 'o')
    {winner = 2;}
    
    else winner = 4;   //if and only if none of the above scenarios obtain, set winner to 4 and return 4 (implying that the game is still ongoing)
    
    return winner;  //returns the value of winner to gameStatus
}
