#include<iostream>
#include<vector>
#include "solo_test.h"

using namespace std;

PegSolitaire::PegSolitaire()
{
}

PegSolitaire::PegSolitaire(int size)
{
    
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

    assignBoard(temp);

}

void PegSolitaire::assignBoard(const vector<vector<GAME>> &temp_board)
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

void PegSolitaire::Cell::setRow(const int &_row)
{
    row = _row;
}

void PegSolitaire::Cell::setColumn(const int &_column)
{
    column = _column;
}

void PegSolitaire::Cell::setGame(const GAME &_state)
{
    state = _state;
}

int PegSolitaire::Cell::getRow()
{
    return row;
}

int PegSolitaire::Cell::getColumn()
{
    return column;
}

GAME PegSolitaire::Cell::getGame()
{
    return state;
}