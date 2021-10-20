 #include<iostream>
 #include<vector>
 #include<string>
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
        cout << "Enter command:";
        cin >> table_type;
        switch (table_type)
        {
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
        cout << "Choose Player Type" << endl << "1-Human" << endl << "2-Computer" << endl; 
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


    while (1)
    {
        string command;
        if (player_type == 1) 
        {
            cout << "Enter Command:";
            cin >> command;
        }
        else if (player_type == 2) 
        {
            command = generateComputerCommand(board.size());
        }
        
        
        if (move(board, command) == 1)
            break;
        
    }
    printBoard(board);
    
}