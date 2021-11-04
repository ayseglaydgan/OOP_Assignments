#include<iostream>
#include<vector>
#include "solo_test.h"

using namespace std;

//if the type of the board is not indicated, create board 4
PegSolitaire::PegSolitaire()
{
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
            if (cell.getGame() == GAME::DOT)
                cout << ".";
            if (cell.getGame() == GAME::P)
                cout << "P";
            if (cell.getGame() == GAME::BLANK)
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

