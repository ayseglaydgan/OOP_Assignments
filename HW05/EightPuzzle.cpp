#include <iostream>
#include <string>
#include <vector>
#include "EightPuzzle.h"

using namespace std;

namespace HW05_AysegulAydogan {

EightPuzzle::EightPuzzle() : BoardGame2d() {
    this->boardSize = 3;
    this->blankPlaceX = 1;
    this->blankPlaceY = 1;
    this->gameName = "EightPuzzle";
    initialize();
}

void EightPuzzle::initialize()
{
    // generate random 3x3 board
    vector<vector<int>> board;
    for (int i = 0; i < boardSize; i++)
    {
        board.push_back(vector<int>());
        for (int j = 0; j < boardSize; j++)
        {
            
            int num = generateRandom(0, boardSize * boardSize - 1);
            while (boardContains(board, num))
            {
                num = generateRandom(0, boardSize * boardSize - 1);
            }
            if (num == 0)
            {
                blankPlaceY = i;
                blankPlaceX = j;
            }
            board[i].push_back(num);
        }
    }

    vector<vector<int>> temp = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 0, 8}
    };
    

    this->gameBoard = board;

    // re generate till it is solvable
    while (!isSolvable())
    {
        initialize();
    }
}

void EightPuzzle::print() const
{
    BoardGame2d::print();

    for (const auto board1D : gameBoard)
    {
        cout << "+---+---+---+" << endl;
        for (const auto cell : board1D)
        {
            if (cell == 0)
                cout << "|   ";
            else
                cout << "| " << cell << " ";
        }
        cout << "|" << endl;
    }

    cout << "+---+---+---+" << endl;
}

int EightPuzzle::boardScore() const
{
    int checkFinish = 1;
    for (const auto board1D : gameBoard)
    {
        for (const auto cell : board1D)
        {
            if (cell == checkFinish || cell == 0)
            {
                checkFinish++;
            }
            if (checkFinish == 10)
                return moveCount;
        }
    }

    return -1;
}

bool EightPuzzle::isValidCommand() const
{
    if (command == "U" || command == "D" || command == "L" || command == "R")
        return true;
    else
        return false;
}

bool EightPuzzle::isValidMove() const
{
    // check directions in eight puzzle
    // first check U direction
    if (command == "U")
    {
        if (blankPlaceY + 1 >= boardSize)
            return false;
    }
    // check D direction
    else if (command == "D")
    {
        if (blankPlaceY - 1 < 0)
            return false;
    }
    // check L direction
    else if (command == "L")
    {
        if (blankPlaceX + 1 >= boardSize)
            return false;
    }
    // check R direction
    else if (command == "R")
    {
        if (blankPlaceX - 1 < 0)
            return false;
    }

    return true;
}

void EightPuzzle::move()
{
    // check U direction
    if (command == "U")
    {
        gameBoard[blankPlaceY][blankPlaceX] = gameBoard[blankPlaceY + 1][blankPlaceX];
        gameBoard[blankPlaceY + 1][blankPlaceX] = 0;
        blankPlaceY++;
    }
    // check D direction
    else if (command == "D")
    {
        gameBoard[blankPlaceY][blankPlaceX] = gameBoard[blankPlaceY - 1][blankPlaceX];
        gameBoard[blankPlaceY - 1][blankPlaceX] = 0;
        blankPlaceY--;
    }
    // check L direction
    else if (command == "L")
    {
        gameBoard[blankPlaceY][blankPlaceX] = gameBoard[blankPlaceY][blankPlaceX + 1];
        gameBoard[blankPlaceY][blankPlaceX + 1] = 0;
        blankPlaceX++;
    }
    // check R direction
    else if (command == "R")
    {
        gameBoard[blankPlaceY][blankPlaceX] = gameBoard[blankPlaceY][blankPlaceX - 1];
        gameBoard[blankPlaceY][blankPlaceX - 1] = 0;
        blankPlaceX--;
    }
}

string EightPuzzle::generateComputerCommand() const
{
    // to get the direction
    char direction = ' ';
    switch (generateRandom(1, 4))
    {
    case 1:
        direction = 'U';
        break;
    case 2:
        direction = 'D';
        break;
    case 3:
        direction = 'L';
        break;
    case 4:
        direction = 'R';
        break;
    default:
        break;
    }

    string command;
    command.push_back(direction);
    return command;
}

void EightPuzzle::printGameManual() const
{
    cout << "Welcome to the Eight Puzzle game!" << endl;
    cout << "The goal of the game is to get the numbers in order from 0 to 8." << endl;
    cout << "The game is played on a 3x3 board." << endl;
    cout << "The game has 4 commands. U (up), D (down), L (left), R (right)." << endl;
    cout << "Press Any Key and Enter to Continue:";
    int garbage;
    cin >> garbage;
    cin.ignore();
}

void EightPuzzle::printFinishMessage() const
{
    cout << "Congratulations! You won the game!" << endl;
    cout << "You made " << moveCount << " moves." << endl;
    cout << "Your score is equal to your move count." << endl;
}

// same as super class functionality
void EightPuzzle::playUser(string command)
{
    BoardGame2d::playUser(command);
}

void EightPuzzle::playAuto()
{   
    BoardGame2d::playAuto();
}

bool EightPuzzle::endGame() const
{
    return BoardGame2d::endGame();
}

void EightPuzzle::playGame()
{
    BoardGame2d::playGame();
}

// helper function to check if given puzzle is solvable
bool EightPuzzle::isSolvable() const
{
    int inverseCount = 0;
    for (int i = 0; i < boardSize - 1; i++)
        for (int j = i + 1; j < boardSize; j++)
            if (gameBoard[j][i] > 0 && gameBoard[i][j] > 0 && gameBoard[j][i] > gameBoard[i][j])
                inverseCount++;
    
    return (inverseCount % 2 == 0);
}

} // end of namespace