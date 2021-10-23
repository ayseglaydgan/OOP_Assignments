#include <iostream>
#include <vector>
#include <string>
#include "solo_test.h"

using namespace std;

int main()
{
    vector<vector<GAME>> board;
    int player_type = 0;
    int table_type = 0;

    cout << "Welcome to the Perfect SoloTest Game <3" << endl;

    while (table_type <= 0 || table_type > 6)
    {
        cout << "Choose Game Table Type (1-6)" << endl;
        cout << "See all shapes by typing 0" << endl;
        cout << "Enter command:";
        cin >> table_type;
        switch (table_type)
        {
        case 0:
            cout << "Shape 1" << endl;
            printBoard(createBoard_1());
            cout << "Shape 2" << endl;
            printBoard(createBoard_2());
            cout << "Shape 3" << endl;
            printBoard(createBoard_3());
            cout << "Shape 4" << endl;
            printBoard(createBoard_4());
            cout << "Shape 5" << endl;
            printBoard(createBoard_5());
            cout << "Shape 6" << endl;
            printBoard(createBoard_6());

        case 1:
            board = createBoard_1();
            break;

        case 2:
            board = createBoard_2();
            break;

        case 3:
            board = createBoard_3();
            break;

        case 4:
            board = createBoard_4();
            break;

        case 5:
            board = createBoard_5();
            break;

        case 6:
            board = createBoard_6();
            break;

        default:
            cout << "Invalid input" << endl;
            break;
        }
    }

    cout << "You selected this board" << endl;
    printBoard(board);

    while (player_type != 1 && player_type != 2)
    {
        cout << "Choose Player Type" << endl
             << "1-Human" << endl
             << "2-Computer" << endl;
        cout << "Enter Command:";
        cin >> player_type;
        switch (player_type)
        {
        case 1:
            cout << "Human Selected" << endl;
            break;

        case 2:
            cout << "Computer Selected" << endl;
            break;

        default:
            cout << "Invalid input" << endl;
            break;
        }
    }

    printBoard(board);

    // prevent previous commands
    cin.ignore();
    
    int move_count = 0;

    while (1)
    {
        string command;
        if (player_type == 1)
        {
            cout << "Enter Command:";
            getline(cin, command);
            
            cout << "Your command:" << command << endl;
        }
        else if (player_type == 2)
        {
            command = generateComputerCommand(board.size());
        }

        if (playGame(board, command, player_type, table_type, move_count) == 1)
            break;
    }
    printBoard(board);
}