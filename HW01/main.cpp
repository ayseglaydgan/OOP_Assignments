 #include<iostream>
 #include<vector>
 #include<string>
 #include "solo_test.h"

using namespace std;

int main()
{
    vector<vector<GAME>> board;
    board = createBoard_6();
    printBoard(board);
    int i = 0;
    while (1)
    {
        string command = generateComputerCommand(board.size());
        
        
        if (move(board, command) == 1)
            break;
        
    }
    printBoard(board);
    
}