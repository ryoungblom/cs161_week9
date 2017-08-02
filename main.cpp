



#include <iostream>
#include <string>
#include <cctype>
using namespace std;

enum Status {X_WON, O_WON, DRAW, UNFINISHED};

class Board
{
private:
    int counter=0;
public:
    char boardArray [4][4];
    void setBoard();
    void print();
    bool makeMove(char turn, int CX, int CY);
    Status gameState ();
    int checkStatus ();
};


void Board::setBoard()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            boardArray[i][j] = '.';
        }
    }
    
    boardArray[0][0] = ' ';
    boardArray[0][1] = '0';
    boardArray[1][0] = '0';
    boardArray[0][2] = '1';
    boardArray[0][3] = '2';
    boardArray[2][0] = '1';
    boardArray[3][0] = '2';
}


void Board::print()
{
    
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout << boardArray[i][j] << ' ';
        }
        cout << endl;
    }
}


bool Board::makeMove(char turn, int CX, int CY)
{
    
    if (boardArray[CX][CY] != '.')
    {
        return false;
    }
    
    else
    {
        boardArray[CX][CY] = turn;
        return true;
    }
}


Status Board::gameState()
{
    Status gameStatus;
    counter++;
    
    if (Board::checkStatus() == 1)
    {
        gameStatus = X_WON;
    }
    else if (Board::checkStatus()== 2)
    {
        gameStatus = O_WON;
    }
    
    else if (counter == 32)
    {
        gameStatus = DRAW;
    }
    
    else
    {
        gameStatus = UNFINISHED;
    }
    
    return gameStatus;
}


int Board::checkStatus()
{
    int winner;
    

 
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



/*********************************/




class TicTacToe
{
private:
    Board gamePlay;
    char turn;
    char p2;
public:
    
    void play (char p1);
};



void TicTacToe::play (char p1)
{
    
    if (p1 == 'x') {p2 = 'o';}
    
    if (p1 == 'o') {p2 = 'x';}
    
    cout << "Ready to begin? Player " << p1 << " will go first." << endl;
    
    gamePlay.setBoard();
    gamePlay.print();
    
    while (gamePlay.gameState() == UNFINISHED)
    {
        
        int moveX = 0;
        int moveY = 0;
        
        cout << "Player " << p1 << ", please enter coordinates" << endl;
        
        cin >> moveX;
        cin >> moveY;
        
        moveX++;
        moveY++;
        
        
        while (gamePlay.makeMove(p1, moveX, moveY) == 0)
        {cout << "That coordinate is already taken!" << endl;
            gamePlay.print();
            
            cout << "Player " << p1 << ", please enter coordinates" << endl;
            
            cin >> moveX;
            cin >> moveY;
            
            moveX++;
            moveY++;

            
            
        }
        
        gamePlay.print();
        
        if (gamePlay.gameState() == X_WON)
        {
            cout << "x Wins!" << endl;
            break;}
        if (gamePlay.gameState() == O_WON)
        {
            cout << "o Wins!" << endl;
            break;}
        if (gamePlay.gameState() == DRAW)
        {cout << "It's a draw!" << endl;
            break;}
        
        
        moveX = 0;
        moveY = 0;
        
        cout << "Player " << p2 << ", please enter coordinates" << endl;
        
        cin >> moveX;
        cin >> moveY;
        
        moveX++;
        moveY++;
        
        
        
        while (gamePlay.makeMove(p2, moveX, moveY) == 0)
        {
            cout << "That coordinate is already taken!" << endl;
            gamePlay.print();
            
            cout << "Player " << p2 << ", please enter coordinates" << endl;
            
            cin >> moveX;
            cin >> moveY;
            
            moveX++;
            moveY++;
            
        }
        gamePlay.print();
        
        if (gamePlay.gameState() == X_WON)
        {
            cout << "X Wins!" << endl;
            break;}
        if (gamePlay.gameState() == O_WON)
        {
            cout << "O Wins!" << endl;
            break;}
        if (gamePlay.gameState() == DRAW)
        {cout << "It's a draw!" << endl;
            break;}
    }
    
    cout << "Thanks for playing!" << endl;
    
}

int main()

{
    
    char player;
    TicTacToe game;
    
    cout << "Hi! It's time to play Tic Tac Toe. Who should go first, player x or player o?" << endl;
    
    cin >> player;
    
    player = tolower(player);
    
    game.play(player);
    
    return 0;
}

