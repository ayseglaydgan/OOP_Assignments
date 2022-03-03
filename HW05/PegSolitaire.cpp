#include <iostream>
#include <string>
#include <vector>
#include "PegSolitaire.h"

using namespace std;

namespace HW05_AysegulAydogan {

PegSolitaire::PegSolitaire() : BoardGame2d() {
    this->boardSize = 7;
    this->gameName = "PegSolitaire";
    initialize();
}

void PegSolitaire::print() const
{
    BoardGame2d::print();

    //row_num = 1 because first row used for letter coordinates
    int row_num = 1;

    // leave a tab for printing "abcdefg"
    cout << "  ";
    
    //to adjust the coordinates
    for (int i = 0; i < this->boardSize; ++i)
    {
        cout << char('a' + i);
    }
    cout << endl;

    //some lines of code by heart to adjust strong enum types
    // Update (5.11.2021). I understand now :)
    // I think it is a good idea to use enum types to make the code more readable
    for (const vector<int> board_1d : this->gameBoard)
    {
        cout << row_num << " ";
        for (int cell : board_1d)
        {
            if (cell == GAME_PEG::BLANK)
                cout << " ";
            if (cell == GAME_PEG::PEG)
                cout << "P";
            if (cell == GAME_PEG::DOT)
                cout << ".";
        }
        row_num += 1;
        cout << endl;
    }
}

int PegSolitaire::boardScore() const
{
    int remainingPeg = 0;
    for (int i = 0; i < boardSize; ++i)
    {
        for (int j = 0; j < boardSize; ++j)

        {
            if (gameBoard[i][j] == GAME_PEG::PEG)
            {
                //to calculate score
                remainingPeg++;
                // check up
                if (i - 2 >= 0 && gameBoard[i - 2][j] == GAME_PEG::DOT && gameBoard[i - 1][j] == GAME_PEG::PEG)
                    return -1;
                // check down
                if (i + 2 < gameBoard.size() && gameBoard[i + 2][j] == GAME_PEG::DOT && gameBoard[i + 1][j] == GAME_PEG::PEG)
                    return -1;
                // check right
                if (j + 2 < gameBoard.size() && gameBoard[i][j + 2] == GAME_PEG::DOT && gameBoard[i][j + 1] == GAME_PEG::PEG)
                    return -1;
                // check left
                if (j - 2 >= 0 && gameBoard[i][j - 2] == GAME_PEG::DOT && gameBoard[i][j - 1] == GAME_PEG::PEG)
                    return -1;
            }
        }
    }
    return remainingPeg;
}

void PegSolitaire::initialize()
{
    GAME_PEG P = GAME_PEG::PEG;
    GAME_PEG D = GAME_PEG::DOT;
    GAME_PEG _ = GAME_PEG::BLANK;
    vector<vector<int>> temp =
        {
            {_, _, P, P, P, _, _},
            {_, _, P, P, P, _, _},
            {P, P, P, P, P, P, P},
            {P, P, P, D, P, P, P},
            {P, P, P, P, P, P, P},
            {_, _, P, P, P, _, _},
            {_, _, P, P, P, _, _}};

    this->gameBoard = temp;
}

string PegSolitaire::generateComputerCommand() const
{
    string command = "";
    char first = char(BoardGame2d::generateRandom('A', 'A' + boardSize - 1));
    char second = char(BoardGame2d::generateRandom('1', '1' + boardSize - 1));
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
    command.push_back(' ');
    command.push_back(last);

    return command;
}

bool PegSolitaire::isValidCommand() const
{
    int isValid = true;
    if (command.empty() || command.length() != 4)
    {
        isValid = false;
    }
    // check for second parameter is number
    else if (command[1] - '0' > 9)
    {
        isValid = false;
    }
    else if (command[0] < 'A' || command[0] > 'A' + boardSize - 1)
    {
        isValid = false;
    }
    else if ((command[1] - '0') < 1 || (command[1] - '0') > boardSize)
    {
        isValid = false;
    }
    else if (command[2] != ' ')
    {
        isValid = false;
    }
    else if (command[3] != 'L' && command[3] != 'U' && command[3] != 'R' && command[3] != 'D')
    {
        isValid = false;
    }

    return isValid;

}

bool PegSolitaire::isValidMove() const
{
    const int size = boardSize;
    const int i = (command[1] - '0') - 1;
    const int j = (command[0] - 'A');
    const char direction = command[3];

    // check if the i or j is in bounds
    if (i < 0 || i >= size || j < 0 || j >= size)
    {
        return false;
    }

    //checks the playing point is peg
    if (gameBoard[i][j] == GAME_PEG::DOT || gameBoard[i][j] == GAME_PEG::BLANK)
    {
        return false;
    }
    //checks the exceptions for up direction
    else if (direction == 'U' && i - 2 >= 0 && gameBoard[i - 2][j] == GAME_PEG::DOT && gameBoard[i - 1][j] == GAME_PEG::PEG)
    {
        return true;
    }
    //checks the exceptions for down direction
    else if (direction == 'D' && (i + 2) < gameBoard.size() && gameBoard[i + 2][j] == GAME_PEG::DOT && gameBoard[i + 1][j] == GAME_PEG::PEG)
    {
        return true;
    }
    //checks the exceptions for the left direction
    else if (direction == 'L' && (j - 2) >= 0 && gameBoard[i][j - 2] == GAME_PEG::DOT && gameBoard[i][j - 1] == GAME_PEG::PEG)
    {
        return true;
    }
    //checks the exceptions for the right direction
    else if (direction == 'R' && (j + 2) < size && gameBoard[i][j + 2] == GAME_PEG::DOT && gameBoard[i][j + 1] == GAME_PEG::PEG)
    {
        return true;
    }

    return false;
}

void PegSolitaire::move()
{
    const int i = (command[1] - '0') - 1;
    const int j = (command[0] - 'A');
    const char direction = command[3];

    //SWAP according to direction
    int temp = gameBoard[i][j];
    if (direction == 'U') //UP
    {
        gameBoard[i][j] = gameBoard[i - 2][j];
        gameBoard[i - 1][j] = GAME_PEG::DOT;
        gameBoard[i - 2][j] = temp;
    }
    else if (direction == 'D') //DOWN
    {
        gameBoard[i][j] = gameBoard[i + 2][j];
        gameBoard[i + 1][j] = GAME_PEG::DOT;
        gameBoard[i + 2][j] = temp;
    }
    else if (direction == 'L') //LEFT
    {
        gameBoard[i][j] = gameBoard[i][j - 2];
        gameBoard[i][j - 1] = GAME_PEG::DOT;
        gameBoard[i][j - 2] = temp;
    }
    else if (direction == 'R') //RIGHT
    {
        gameBoard[i][j] = gameBoard[i][j + 2];
        gameBoard[i][j + 1] = GAME_PEG::DOT;
        gameBoard[i][j + 2] = temp;
    }
}

void PegSolitaire::printGameManual() const
{
    cout << "Welcome to Peg Solitaire!" << endl;
    cout << "The rules are simple:" << endl;
    cout << "You have to move a peg from one place to another place." << endl;
    cout << "You can move a peg up, down, left or right." << endl;
    cout << "You can move a peg only if the place you want to move to is a dot." << endl;
    cout << "Command Example: A5 U (move to up from A5 location)" << endl;
    cout << "Press Any Key and Enter to Continue:";
    int garbage;
    cin >> garbage;
    cin.ignore();
}

void PegSolitaire::printFinishMessage() const
{
    cout << "Congratulations! You won the game!" << endl;
    cout << "You have completed the game in " << moveCount << " moves." << endl;
    cout << "Your score (Remaining Peg):" << boardScore() << endl;
}

// same as super class functionality
void PegSolitaire::playUser(string command)
{
    BoardGame2d::playUser(command);
}

void PegSolitaire::playAuto()
{   
    BoardGame2d::playAuto();
}

bool PegSolitaire::endGame() const
{
    return BoardGame2d::endGame();
}

void PegSolitaire::playGame()
{
    BoardGame2d::playGame();
}

} // namespace HW05_AysegulAydogan