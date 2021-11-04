#include<iostream>
#include<vector>
#include"solo_test.h"

using namespace std;

int main()
{

    int type = 5;

    int player = 1;

    PegSolitaire game(type, player);
    game.printBoard();


    while (1)
    {
        string command;
        if (game.getPlayer() == 1) // player
        {
            cout << "Enter Command:";

            // take whole line
            // used for (SAVE FILE.txt or LOAD FILE.txt)
            getline(cin, command);
            game.setCommand(command);
        }
        else if (game.getPlayer() == 2) // computer
        {
            // command = game.generateComputerCommand();
        }

        if (game.playGame() == 1) // if game finished, return 1
            break;
    }
    
    game.printBoard();
}