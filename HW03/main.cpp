#include <iostream>
#include <vector>
#include "solo_test.h"

using namespace std;

int main()
{

    int type = 4;

    int player = 2;

    PegSolitaire game(type, player);
    game.printBoard();

    int gameFinish = 0;
    while (gameFinish == 0)
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
            // TODO: computer move
            // command = game.generateComputerCommand();
        }

        gameFinish = game.playGame(); // if game finished, return 1
    }

    game.printBoard();
}