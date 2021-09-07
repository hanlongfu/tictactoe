#include <iostream>
#include "dec.h"
using namespace std;

//setting up the board
string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};

int player = 1;   //player initialized to 1
int position = 0; //position initialized to 0

//print the board
void introduction()
{
    cout << "Press [enter] to begin: ";
    getchar(); // halts the screen
    cout << '\n';
    
    cout << '\n';
    cout << "*******************\n";
    cout << "----Tic-Tac-Toe----\n";
    cout << "*******************\n";
     
    cout << "Player 1) X\n";
    cout << "Player 2) O\n";
    
    cout << "The 3x3 grid is shown below: \n\n";
    
    cout << "     |      |       \n";
    cout << "  1  |   2  |   3   \n";
    cout << "_____|______|_______\n";
    cout << "     |      |       \n";
    cout << "  4  |   5  |   6   \n";
    cout << "_____|______|_______\n";
    cout << "     |      |       \n";
    cout << "  7  |   8  |   9   \n";
    cout << "     |      |       \n";
}

//check winner function
bool is_winner()
{
    //default set to false
    bool winner = false;
    
    //check the rows
    if((board[0]==board[1]) && (board[1]==board[2]) && board[0] != " "){
        winner = true;
    }
    
    else if((board[3]==board[4]) && (board[4]==board[5]) && board[3] != " "){
        winner = true;
    }
    
    else if((board[6]==board[7]) && (board[7]==board[8]) && board[6] != " "){
        winner = true;
    }
    
    //check the cols
    else if((board[0]==board[3]) && (board[3]==board[6]) && board[0] != " "){
        winner = true;
    }
    
    else if((board[1]==board[4]) && (board[4]==board[7]) && board[1] != " "){
        winner = true;
    }
    
    else if((board[2]==board[5]) && (board[5]==board[8]) && board[2] != " "){
        winner = true;
    }
    
    //check the diagonals
    else if((board[0]==board[4]) && (board[4]==board[8]) && board[0] != " "){
        winner = true;
    }
    
    else if((board[2]==board[4]) && (board[4]==board[6]) && board[2] != " "){
        winner = true;
    }
    
    return winner;
    
}
 

//check if the location is occupied
bool is_filled()
{
    bool filled = true;
    for(int i=0; i<9; i++){
        if(board[i] == " ") filled = false;
    }
    return filled;
}

//draw the board for every iteration of the function
void draw()
{
    cout << "     |      |       \n";
    cout << "  " << board[0] << "  |  " << board[1] << "   |  " << board[2] << "\n";
    cout << "_____|______|_______\n";
    cout << "     |      |       \n";
    cout << "  " << board[3] << "  |  " << board[4] << "   |  " << board[5] << "\n";
    cout << "_____|______|_______\n";
    cout << "     |      |       \n";
    cout << "  " << board[6] << "  |  " << board[7] << "   |  " << board[8] << "\n";
    cout << "     |      |       \n";
    cout << "\n";
}

//check if a position is occupied & record user's input
void set_position()
{
    cout << "Player " << player << " (Enter 1 to 9): ";
    while(!(cin>>position))
    {
        cout << "Please enter a valid number between 1 and 9: " << endl;
        cin.clear();      //flushing the buffer
        cin.ignore();
    }
    
    //if a position is not already occupied
    //
    while(board[position-1] != " ")
    {
        cout << "Oops, that position is already filled\n Try again\n";
        cout << "Player " << player << "'s Turn ( Enter 1 to 9): ";
        cin >> position;
        cout<< "\n";
    }
    
}

//update board to include occupied positions
void update_board()
{
    if(player%2 == 1)
    {
        board[position-1]="X";
    }else{
        board[position-1]="O";
    }
}

//switch player
void change_player()
{
    //player alternate between 1 and 2
    if(player==1) player++;
    else player--;
}

void take_turn()
{
    //no winner and is not fully occupied
    while(!is_winner() && !is_filled())
    {
        set_position();
        update_board();
        change_player();
        draw();
    }
}

void end_game()
{
    if(is_winner()){
        cout << "There is a winner!" << endl;
    }
    else if(is_filled())
    {
        cout << "There is a tie!" << endl;
    }
}
