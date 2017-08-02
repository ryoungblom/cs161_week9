

/**********************************
 ** Program Filename: TicTacToe.cpp
 ** Author: reuben youngblom
 ** Date: November 23rd 2016
 ** Description: TicTacToe.cpp file.  this is the main gameplay logic.  contains play function (described below) and main (which essentially just takes the starting player and sends it to Play()).
 ** Input: User input. Will take player from main and coordinates from Play(), And uses these to send to print and make move functions and check the status of the game via gameState.
 ** Output: will send arguments to print current board game and check status in the even of a win or draw, and will output these statuses.
 **********************************/

#include "TicTacToe.hpp"

void TicTacToe::play (char p1)  // play function, takes player as argument
{
    
    if (p1 == 'x') {p2 = 'o';}  //sets players.  Whichever is sent as the argument is player 1, the other is player 2 and is the opposite symbol.
    
    if (p1 == 'o') {p2 = 'x';}
    
    cout << "Ready to begin? Player " << p1 << " will go first." << endl;  //user directions
    
    gamePlay.setBoard();  //calls setboard function to initialize the board
    gamePlay.print();  //prints out a copy of the board so users can see what's what right off the bat
    
    while (gamePlay.gameState() == UNFINISHED)  //loops through turns so long as the gameState is "unfinished" (i.e. no winners, and no draw)
    {
        
        int moveX = 0;  //initial move coordinates.  refreshes them each time and initializes to zero.
        int moveY = 0;
        
        cout << "Player " << p1 << ", please enter coordinates" << endl;  //user directions
        
        cin >> moveX;  //takes their coordinates and assigns them to MoveX and moveY
        cin >> moveY;
        
        moveX++;  //adds one to all of them because the first row and column of the array are the coordinates
        moveY++;
        
        
        while (gamePlay.makeMove(p1, moveX, moveY) == 0) //if that coordinate is taken.... (i.e. if makeMove kicks back 0 for false)
        {cout << "That coordinate is already taken!" << endl;  //inform the user
            gamePlay.print();  //print the board again with no changes
            
            cout << "Player " << p1 << ", please enter coordinates" << endl;  //and prompt user to re-enter coordinates
            
            cin >> moveX;  //re-asking for coordinates and re-assigning
            cin >> moveY;
            
            moveX++;
            moveY++;  //and then loop starts again to check coordinates
            
        }
        
        gamePlay.print();  //BUT if the coordinates are accepted...
        
        if (gamePlay.gameState() == X_WON)  //...check for status changes.  This checks with gameState to see if X or O has won, and prints out the appropriate message if so.
        {
            cout << "x Wins!" << endl;
            break;}
        if (gamePlay.gameState() == O_WON)
        {
            cout << "o Wins!" << endl;
            break;}
        if (gamePlay.gameState() == DRAW)  //this checks for a draw and prints draw message if it's a draw.
        {cout << "It's a draw!" << endl;
            break;}
        
        
        moveX = 0;  //resets the moveX and moveY integers
        moveY = 0;
        
        cout << "Player " << p2 << ", please enter coordinates" << endl;  //prompts player 2 for moves
        
        cin >> moveX;  //takes player 2's moves in
        cin >> moveY;
        
        moveX++;  //adds one to them for the same reason as above
        moveY++;
        
        
        
        while (gamePlay.makeMove(p2, moveX, moveY) == 0)  //...and goes through the same loop as above.  While move is invalid (0)...
        {
            cout << "That coordinate is already taken!" << endl; //...tell user
            gamePlay.print();  ///...print the board
            
            cout << "Player " << p2 << ", please enter coordinates" << endl;   //...reprompt for coordinates...
            
            cin >> moveX;  //... take them in....
            cin >> moveY;
            
            moveX++;   //add one
            moveY++;   //...and then loop again and check to see if it's valid input
            
        }
        gamePlay.print();  //BUT if coordinates are accepted, then print board game
        
        if (gamePlay.gameState() == X_WON)  //check the status...
        {
            cout << "x Wins!" << endl;
            break;}
        if (gamePlay.gameState() == O_WON)
        {
            cout << "o Wins!" << endl;
            break;}
        if (gamePlay.gameState() == DRAW)  //...check for a draw....
        {cout << "It's a draw!" << endl;
            break;}
    }
    
    cout << "Thanks for playing!" << endl;  //and then, if it breaks out of the above While loop (that is, if game is anything other than UNFINISHED, print "thanks for playing" message
    
}

int main()  //main, left in this time

{
    
    char player;  //creates char for holding user input about what symbol they want
    TicTacToe game;  //creates TicTacToe object
    
    cout << "Hi! It's time to play Tic Tac Toe. Who should go first, player x or player o?" << endl;   //asks for user's choice in symbol
    
    cin >> player;  //takes input and assigns it to Player
    
    player = tolower(player);  //converts it to lower case if it's upper case, because all of my logic checks for lower case xs and os.
    
    game.play(player);  //and finally starts the game
    
    return 0;
}