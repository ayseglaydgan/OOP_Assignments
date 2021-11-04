#include<iostream>
#include<vector>
#include "solo_test.h"

using namespace std;

//if the type of the board is not indicated, create board 4
// if default consturctor used, play as computer
PegSolitaire::PegSolitaire()
{
    player_type = 0;
    board_type = 4;
    createBoard_4();
}

PegSolitaire::PegSolitaire(int type)
{
    if(type == 1)
        createBoard_1();
    else if(type == 2)
        createBoard_2();
    else if(type == 3)
        createBoard_3();
    else if(type == 4)
        createBoard_4();
    else if(type == 5)
        createBoard_5();
    else if(type == 6)
        createBoard_6();
    else
    {
        cerr << "Invalid board type" << endl;
        cerr << "Board 4 assumed as a board type" << endl;
        createBoard_4();
    }
    board_type = type;
    player_type = 1;
}

PegSolitaire::PegSolitaire(int _board_type, int _player_type)
{
    if(_board_type == 1)
        createBoard_1();
    else if(_board_type == 2)
        createBoard_2();
    else if(_board_type == 3)
        createBoard_3();
    else if(_board_type == 4)
        createBoard_4();
    else if(_board_type == 5)
        createBoard_5();
    else if(_board_type == 6)
        createBoard_6();
    else
    {
        cerr << "Invalid board type" << endl;
        cerr << "Board 4 assumed as a board type" << endl;
        createBoard_4();
    }
    board_type = _board_type;
    player_type = _player_type;
}

vector<vector<PegSolitaire::Cell>> PegSolitaire::getBoard()
{
    return board;
}

void PegSolitaire::printBoard()
{
    int row_num = 1;

    // determine the longest line to write all rows
    int longest_line = longestLine();

    cout << "  ";
    //to adjust the coordinates
    for (int i = 0; i < longest_line; ++i)
    {
        cout << char('a' + i);
    }
    cout << endl;

    //some lines of code by heart to adjust strong enum types
    for (const vector<Cell> board_1d : board)
    {
        cout << row_num << " ";
        for (Cell cell : board_1d)
        {
            if (cell.getState() == GAME::DOT)
                cout << ".";
            if (cell.getState() == GAME::P)
                cout << "P";
            if (cell.getState() == GAME::BLANK)
                cout << " ";
        }
        row_num += 1;
        cout << endl;
    }
}

//Saved or Loaded Board can be bigger than implamentation
int PegSolitaire::longestLine()
{

    int longest_line = 0;
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i].size() > longest_line)
            longest_line = board[i].size();
    }
    return longest_line;
}

void PegSolitaire::createBoard_1()
{
    GAME P = GAME::P;
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> temp =
        {
            {_, _, P, P, P, _, _},
            {_, P, P, P, P, P, _},
            {P, P, P, D, P, P, P},
            {P, P, P, P, P, P, P},
            {P, P, P, P, P, P, P},
            {_, P, P, P, P, P, _},
            {_, _, P, P, P, _, _}};
    initBoard(temp);
}

void PegSolitaire::createBoard_2()
{
    GAME P = GAME::P;
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> temp =
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
    initBoard(temp);
}

void PegSolitaire::createBoard_3()
{
    //strong enum
    GAME P = GAME::P;
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> temp =
        {
            {_, _, P, P, P, _, _, _},
            {_, _, P, P, P, _, _, _},
            {_, _, P, P, P, _, _, _},
            {P, P, P, P, P, P, P, P},
            {P, P, P, D, P, P, P, P},
            {P, P, P, P, P, P, P, P},
            {_, _, P, P, P, _, _, _},
            {_, _, P, P, P, _, _, _}};
    initBoard(temp);
}

void PegSolitaire::createBoard_4()
{
    //strong enum
    GAME P = GAME::P;
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> temp =
        {
            {_, _, P, P, P, _, _},
            {_, _, P, P, P, _, _},
            {P, P, P, P, P, P, P},
            {P, P, P, D, P, P, P},
            {P, P, P, P, P, P, P},
            {_, _, P, P, P, _, _},
            {_, _, P, P, P, _, _}};
    initBoard(temp);
}

void PegSolitaire::createBoard_5()
{
    //strong enum
    GAME P = GAME::P;
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> temp =
        {
            {_, _, _, _, P, _, _, _, _},
            {_, _, _, P, P, P, _, _, _},
            {_, _, P, P, P, P, P, _, _},
            {_, P, P, P, P, P, P, P, _},
            {P, P, P, P, D, P, P, P, P},
            {_, P, P, P, P, P, P, P, _},
            {_, _, P, P, P, P, P, _, _},
            {_, _, _, P, P, P, _, _, _},
            {_, _, _, _, P, _, _, _, _}};
    initBoard(temp);
}

void PegSolitaire::createBoard_6()
{
    //strong enum
    GAME P = GAME::P;
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> temp =
        {
            {_, _, D, _, _},
            {_, P, P, _, _},
            {_, P, P, P, _},
            {P, P, P, P, _},
            {P, P, P, P, P}};
    initBoard(temp);
}

void PegSolitaire::initBoard(const vector<vector<GAME>> &temp_board)
{
    for (int i = 0; i < temp_board.size(); ++i)
    {
        board.push_back(vector<Cell>());
        for (int j = 0; j < temp_board[i].size(); ++j)
        {
            // Cell takes row column and GAME state so I give it. temp[i][j] = GAME::P vs
            board[i].push_back(Cell(i, j, temp_board[i][j]));
        } 
    } 
}

void PegSolitaire::setCommand(const string& _command)
{
    command_i = (command[1] - '0') - 1; //conversion to integer
    command_j = (command[0] - 'A'); //conversion to integer
    command_direction = command[3];
}

// Pegsolitare functions 

int PegSolitaire::isValidCommand()
{
    int size = longestLine();
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
    // check for second parameter is number
    else if (command[1] - '0' > 9)
    {
        is_valid = -1;
    }
    else if (command[0] < 'A' || command[0] > 'A' + size - 1)
    {
        is_valid = -1;
    }
    else if ((command[1] - '0') < 1 || (command[1] - '0') > size)
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

bool PegSolitaire::checkMove()
{
    // take longest line for arbitrary boards
    const int size = longestLine();
    int i = command_i;
    int j = command_j;
    char direction = command_direction;

    //checks the playing point is peg
    if (board[i][j].getState() == GAME::DOT || board[i][j].getState() == GAME::BLANK)
    {
        return false;
    }
    //checks the exceptions for up direction
    else if (direction == 'U' && i - 2 >= 0 && board[i - 2][j].getState() == GAME::DOT && board[i - 1][j].getState() == GAME::P)
    {
        return true;
    }
    //checks the exceptions for down direction
    else if (direction == 'D' && (i + 2) < board.size() && board[i + 2][j].getState() == GAME::DOT && board[i + 1][j].getState() == GAME::P)
    {
        return true;
    }
    //checks the exceptions for the left direction
    else if (direction == 'L' && (j - 2) >= 0 && board[i][j - 2].getState() == GAME::DOT && board[i][j - 1].getState() == GAME::P)
    {
        return true;
    }
    //checks the exceptions for the right direction
    else if (direction == 'R' && (j + 2) < size && board[i][j + 2].getState() == GAME::DOT && board[i][j + 1].getState() == GAME::P)
    {
        return true;
    }
    //if non of the if bloks dont work then return false
    return false;
}

bool PegSolitaire::playGame()
{
    const int size = longestLine();

    // use command type to determine SAVE || LOAD or normal command || invalid
    int command_type = isValidCommand();

    if (command_type == -1) //if the command is invalid
    {
        if (player_type== 1)
            cerr << "Invalid command" << endl;
        return false;
    }
    // save funciton
    else if (command_type == 1)
    {
        cout << "SAVE" << endl;
        // TODO
        // saveGame();
        return false;
    }
    // load function
    else if (command_type == 2)
    {
        cout << "LOAD" << endl;
        // TODO
        // loadGame();
        return false;
    }

    // TODO
    // if (!checkMove())
    // {
    //     if (player_type == 1)
    //         cerr << "Invalid direction" << endl;
    //     return false;
    // }

    move_count++;

    // TODO
    // move();

    //gameFinish returns the remaining peg, if it is not -1, that means there are still moves to play.
    auto score = 0;
    // TODO
    // score = gameFinish();
    if (score != -1) // if game is not finished
    {
        cout << "Game is finished. Congrats" << endl;
        cout << "Your score:" << score << endl;
        return true;
    }

    if (player_type == 2)
        cout << "Computer Movement:" << command << endl;

    printBoard();
    return false;
}

// cell consturctors

PegSolitaire::Cell::Cell()
{
    state = GAME::BLANK;
    column = 0;
    row = 0;
    
}

PegSolitaire::Cell::Cell(const int &_row, const int &_column, const GAME &_state)
{
    row = _row;
    column = _column;
    state = _state;  
}