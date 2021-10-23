#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include "solo_test.h"

using namespace std;

// create first shape and return
vector<vector<GAME>> createBoard_1()
{
    //strong enum
    GAME P = GAME::P;
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> board =
        {
            {_, _, P, P, P, _, _},
            {_, P, P, P, P, P, _},
            {P, P, P, D, P, P, P},
            {P, P, P, P, P, P, P},
            {P, P, P, P, P, P, P},
            {_, P, P, P, P, P, _},
            {_, _, P, P, P, _, _}};
    return board;
}

// create second shape and return
vector<vector<GAME>> createBoard_2()
{
    //strong enum
    GAME P = GAME::P;
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> board =
        {
            {_, _, _, P, P, P, _, _, _},
            {_, _, _, P, P, P, _, _, _},
            {_, _, _, P, P, P, _, _, _},
            {P, P, P, P, P, P, P, P, P},
            {P, P, P, P, D, P, P, P, P},
            {P, P, P, P, P, P, P, P, P},
            {_, _, _, P, P, P, _, _, _},
            {_, _, _, P, P, P, _, _, _},
            {_, _, _, P, P, P, _, _, _}};
    return board;
}

// create third shape and return
vector<vector<GAME>> createBoard_3()
{
    //strong enum
    GAME P = GAME::P;
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> board =
        {
            {_, _, P, P, P, _, _, _},
            {_, _, P, P, P, _, _, _},
            {_, _, P, P, P, _, _, _},
            {P, P, P, P, P, P, P, P},
            {P, P, P, D, P, P, P, P},
            {P, P, P, P, P, P, P, P},
            {_, _, P, P, P, _, _, _},
            {_, _, P, P, P, _, _, _}};
    return board;
}

// create fourth shape and return
vector<vector<GAME>> createBoard_4()
{
    //strong enum
    GAME P = GAME::P;
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> board =
        {
            {_, _, P, P, P, _, _},
            {_, _, P, P, P, _, _},
            {P, P, P, P, P, P, P},
            {P, P, P, D, P, P, P},
            {P, P, P, P, P, P, P},
            {_, _, P, P, P, _, _},
            {_, _, P, P, P, _, _}};
    return board;
}

// create fifth shape and return
vector<vector<GAME>> createBoard_5()
{
    //strong enum
    GAME P = GAME::P;
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> board =
        {
            {_, _, _, _, P, _, _, _, _},
            {_, _, _, P, P, P, _, _, _},
            {_, _, P, P, P, P, P, _, _},
            {_, P, P, P, P, P, P, P, _},
            {P, P, P, P, D, P, P, P, P},
            {_, P, P, P, P, P, P, P, _},
            {_, _, P, P, P, P, P, _, _},
            {_, _, _, P, P, P, _, _, _},
            {_, _, _, _, P, _, _, _, _},
        };
    return board;
}

// create sixth shape and return
vector<vector<GAME>> createBoard_6()
{
    //strong enum
    GAME P = GAME::P;
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> board =
        {
            {_, _, D, _, _},
            {_, P, P, _, _},
            {_, P, P, P, _},
            {P, P, P, P, _},
            {P, P, P, P, P}};
    return board;
}

int isValidCommand(const int &board_length, const string &command)
{
    int is_valid = 0;

    // save load 
    if (command.find("SAVE ") != std::string::npos)
        return 1;
    if (command.find("LOAD ") != std::string::npos)
        return 2;
    
    else if (command.empty() || command.length() != 4)
    {
        is_valid = -1;
    }
    else if (command[0] < 'A' || command[0] > 'A' + board_length - 1)
    {
        is_valid = -1;
    }
    else if ((command[1] - '0') < 1 || (command[1] - '0') > board_length)
    {
        is_valid = -1;
    }
    else if (command[2] != '-')
    {
        is_valid = -1;
    }
    else if (command[3] != 'L' && command[3] != 'U' && command[3] != 'R' && command[3] != 'D')
    {
        is_valid = -1;
    }

    return is_valid;
}

bool checkMove(const vector<vector<GAME>> &board, const char &direction, const int &i, const int &j)
{
    //checks the playing point is peg
    if (board[i][j] == GAME::DOT || board[i][j] == GAME::BLANK)
    {
        return false;
    }
    //checks the exceptions for up direction
    else if (direction == 'U' && i - 2 >= 0 && board[i - 2][j] == GAME::DOT && board[i - 1][j] == GAME::P)
    {
        return true;
    }
    //checks the exceptions for down direction
    else if (direction == 'D' && (i + 2) < board.size() && board[i + 2][j] == GAME::DOT && board[i + 1][j] == GAME::P)
    {
        return true;
    }
    //checks the exceptions for the left direction
    else if (direction == 'L' && (j - 2) >= 0 && board[i][j - 2] == GAME::DOT && board[i][j - 1] == GAME::P)
    {
        return true;
    }
    //checks the exceptions for the right direction
    else if (direction == 'R' && (j + 2) < board.size() && board[i][j + 2] == GAME::DOT && board[i][j + 1] == GAME::P)
    {
        return true;
    }
    //if non of the if bloks dont work then return false
    return false;
}

int gameFinish(const vector<vector<GAME>> &board)
{
    int remaining_p = 0;
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)

        {
            if (board[i][j] == GAME::P)
            {
                //to calculate score
                remaining_p++;
                // check up
                if (i - 2 >= 0 && board[i - 2][j] == GAME::DOT && board[i - 1][j] == GAME::P)
                    return -1;
                // check down
                if (i + 2 < board.size() && board[i + 2][j] == GAME::DOT && board[i + 1][j] == GAME::P)
                    return -1;
                // check right
                if (j + 2 < board.size() && board[i][j + 2] == GAME::DOT && board[i][j + 1] == GAME::P)
                    return -1;
                // check left
                if (j - 2 >= 0 && board[i][j - 2] == GAME::DOT && board[i][j - 1] == GAME::P)
                    return -1;
            }
        }
    }
    return remaining_p;
}

void printBoard(const vector<vector<GAME>> &board)
{
    int row_num = 1;

    cout << "  ";
    //to adjust the coordinates
    for (int i = 0; i < board.size(); ++i)
    {
        cout << char('a' + i);
    }
    cout << endl;

    //some lines of code by heart to adjust strong enum types
    for (const vector<GAME> board_1d : board)
    {
        cout << row_num << " ";
        for (const GAME i : board_1d)
        {
            if (i == GAME::DOT)
                cout << ".";
            if (i == GAME::P)
                cout << "P";
            if (i == GAME::BLANK)
                cout << " ";
        }
        row_num += 1;
        cout << endl;
    }
}

// move function
bool playGame(vector<vector<GAME>> &board, const string &command, const int &player_type, const int &table_type, int &move_count)
{
    const int size = board.size();
    int command_type = isValidCommand(size, command);

    if (command_type == -1) //if the command is invalid
    {
        if (player_type == 1)
            cout << "Invalid command" << endl;
        return false;
    } 
    // save funciton
    else if (command_type == 1)
    {
        // TODO call save function
        cout << "Saveee" << endl;
        saveGame(board,command,player_type,table_type, move_count);
        return false;
    }
    // load function
    else if (command_type == 2)
    {
        cout << "Loadddd" << endl;
        return false;
        // TODO call load function
    }

    int i = (command[1] - '0') - 1; //conversion to integer
    int j = (command[0] - 'A');     //conversion to integer
    char direction = command[3];
    if (!checkMove(board, direction, i, j))
    {
        if (player_type == 1)
            cout << "Invalid direction" << endl;
        return false;
    }

    move_count++;
    move(board, direction, i, j);

    //gameFinish returns the remaining peg, if it is not -1, that means there are still moves to play.
    int score = gameFinish(board);
    if (score != -1) // if game is not finished
    {
        cout << "Game is finished. Congrats" << endl;
        cout << "Your score:" << score << endl;
        return true;
    }

    if (player_type == 2)
        cout << "Computer Movement:" << command << endl;

    printBoard(board);
    return false;
}

void move(vector<vector<GAME>> &board, const char &direction, const int &i, const int &j)
{
    //SWAP according to direction
    GAME temp = board[i][j];
    if (direction == 'U') //UP
    {
        board[i][j] = board[i - 2][j];
        board[i - 1][j] = GAME::DOT;
        board[i - 2][j] = temp;
    }
    else if (direction == 'D') //DOWN
    {
        board[i][j] = board[i + 2][j];
        board[i + 1][j] = GAME::DOT;
        board[i + 2][j] = temp;
    }
    else if (direction == 'L') //LEFT
    {
        board[i][j] = board[i][j - 2];
        board[i][j - 1] = GAME::DOT;
        board[i][j - 2] = temp;
    }
    else if (direction == 'R') //RIGHT
    {
        board[i][j] = board[i][j + 2];
        board[i][j + 1] = GAME::DOT;
        board[i][j + 2] = temp;
    }
}

int generateRandom(const int &min, const int &max)
{
    //some lines of code by heart to produce random numbers
    //probably it produces from hardware
    int random = 0;
    std::random_device generator;
    std::mt19937 gen(generator());
    std::uniform_int_distribution<int> distr(min, max);
    random = distr(generator);
    return random;
}

string generateComputerCommand(const int &board_length)
{
    string command = "";
    char first = char(generateRandom('A', 'A' + board_length - 1));
    char second = char(generateRandom('1', '1' + board_length - 1));
    char last = 0;

    // to get the direction
    switch (generateRandom(1, 4))
    {
    case 1:
        last = 'U';
        break;
    case 2:
        last = 'D';
        break;
    case 3:
        last = 'L';
        break;
    case 4:
        last = 'R';
        break;
    default:
        break;
    }
    // cout << "first:" << first << " second:" << second << " last:" << last << endl;
    command.push_back(first);
    command.push_back(second);
    command.push_back('-');
    command.push_back(last);

    return command;
}

void saveGame(const vector<vector<GAME>> &board, const string &command, const int &player_type, const int &table_type, const int &move_count)
{
    string file_name = command.substr(5);
    ofstream fout;
    fout.open(file_name);

    if (!fout.is_open())
    {
        cerr << "Can not create this file " << file_name << endl;
    }

    // write player_type and table_type and move_count to table
    fout << table_type << endl;
    fout << player_type << endl;
    fout << move_count << endl;

    // write board info to file
    for (const vector<GAME> board_line: board )
    {
        for (const GAME i : board_line)
        {
            if (i == GAME::DOT)
                fout << ".";
            if (i == GAME::P)
                fout << "P";
            if (i == GAME::BLANK)
                fout << " ";
        } 
        fout<<endl;    
    }
    fout.close();
}
