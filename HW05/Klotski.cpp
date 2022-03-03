#include <iostream>
#include <string>
#include <vector>
#include "Klotski.h"

using namespace std;

namespace HW05_AysegulAydogan {

Klotski::Klotski()
{
    this->boardSize = 5;
    this->gameName = "Klotski";
    initialize();
}

void Klotski::initialize()
{
    vector<vector<int>> temp = 
    {   
        {'a','*','*','b',-1},
        {'c','*','*','d',-1},
        {'k','e','f','l',-1},
        {'k','g','h','l',-1},
        {'i',' ',' ','j',-1} 
    };

    /*
    {' ','*','*',' ',-1},
        {' ','*','*',' ',-1},
        {' ',' ',' ',' ',-1},
        {' ',' ',' ',' ',-1},
        {' ',' ',' ',' ',-1} 
        */

    

    this->gameBoard = temp;
}

void Klotski::print() const
{
    BoardGame2d::print();

    cout << "+---+---+---+---+" << endl;
    for (const auto board1D : gameBoard)
    {
        for (const auto cell : board1D)
        {
            if (cell != -1)
                cout << "| " << (char) cell << " ";
        }
        cout << "|" << endl;
    }
    cout << "+---+       +---+" << endl;
}

int Klotski::boardScore() const
{
    if (gameBoard[3][1] == '*' && gameBoard[3][2] == '*' && gameBoard[4][1] == '*' && gameBoard[4][2] == '*')
        return moveCount;
    else
        return -1;
}

void Klotski::printGameManual() const
{
    cout << "Welcome to the Klotski Puzzle game!" << endl;
    cout << "The goal of the game is move the * symbols to bottom center" << endl;
    cout << "Game command: starts with a,b,c,d,e,f,g,h,i and ends with U R L D" << endl;
    cout << "For example, move f to down = f D" << endl;
    cout << "Press Any Key and Enter to Continue:";
    int garbage;
    cin >> garbage;
    cin.ignore();
}

void Klotski::printFinishMessage() const
{
    cout << "Congratulations! You won the game!" << endl;
    cout << "You made " << moveCount << " moves." << endl;
    cout << "Your score is equal to your move count." << endl;
}

bool Klotski::isValidCommand() const
{
    // check if command starts with a,b,c,d,e,f,g,h,i and ends with U or D or L or R
    if (command.length() == 3  && (command[0] >= 'a' && command[0] <= 'l' || command[0] == '*') && command[1] == ' ' && command[2] == 'U' || command[2] == 'D' || command[2] == 'L' || command[2] == 'R')
        return true;
    else
        return false;
}

bool Klotski::isValidMove() const
{
    int firstLetter = command[0];
    int direction = command[2];
    int x = -1;
    int y = -1;
    findCoordinate(x, y, firstLetter);
    if (x == -1 || y == -1)
        return false;

    // check if the first letters are one size
    if (isOneLetters(firstLetter))
    {
        // check up
        if (direction == 'U' && y - 1 >= 0)
        {
            if (gameBoard[y - 1][x] == ' ')
                return true;
            else
                return false;
        }

        // check down
        else if (direction == 'D' && y + 1 <= boardSize - 1)
        {
            if (gameBoard[y + 1][x] == ' ')
                return true;
            else
                return false;
        }

        // check left
        else if (direction == 'L' && x - 1 >= 0)
        {
            if (gameBoard[y][x - 1] == ' ')
                return true;
            else
                return false;
        }

        // check right
        else if (direction == 'R' && x + 1 <= boardSize - 1)
        {
            if (gameBoard[y][x + 1] == ' ')
                return true;
            else
                return false;
        }
    }
    else if (isTwoLetters(firstLetter))
    {
        // check up
        if (direction == 'U' && y - 1 >= 0)
        {
            if (gameBoard[y - 1][x] == ' ')
                return true;
            else
                return false;
        }

        // check down
        else if (direction == 'D' && y + 2 <= boardSize - 1)
        {
            if (gameBoard[y + 2][x] == ' ')
                return true;
            else
                return false;
        }

        // check left
        else if (direction == 'L' && x - 1 >= 0)
        {
            if (gameBoard[y][x - 1] == ' ' && gameBoard[y + 1][x - 1] == ' ')
                return true;
            else
                return false;
        }

        // check right
        else if (direction == 'R' && x + 1 <= boardSize - 1)
        {
            if (gameBoard[y][x + 1] == ' ' && gameBoard[y + 1][x + 1] == ' ')
                return true;
            else
                return false;
        }
    }
    else if (firstLetter == '*')
    {
        // check up
        if (direction == 'U' && y - 1 >= 0)
        {
            if (gameBoard[y - 1][x] == ' ' && gameBoard[y - 1][x + 1] == ' ')
                return true;
            else
                return false;
        }

        // check down
        else if (direction == 'D' && y + 2 <= boardSize - 1)
        {
            if (gameBoard[y + 2][x] == ' ' && gameBoard[y + 2][x + 1] == ' ')
                return true;
            else
                return false;
        }

        // check left
        else if (direction == 'L' && x - 1 >= 0)
        {
            if (gameBoard[y][x - 1] == ' ' && gameBoard[y + 1][x - 1] == ' ')
                return true;
            else
                return false;
        }

        // check right
        else if (direction == 'R' &&  x + 2 <= boardSize - 1)
        {
            if (gameBoard[y][x + 2] == ' ' && gameBoard[y + 1][x + 2] == ' ')
                return true;
            else
                return false;
        }


    }

    return false;
}

void Klotski::move()
{
    int firstLetter = command[0];
    int direction = command[2];
    int x = 0;
    int y = 0;
    findCoordinate(x, y, firstLetter);

    // check if the first letters are one size
    if (isOneLetters(firstLetter))
    {
        // check up
        if (direction == 'U')
        {
            gameBoard[y][x] = ' ';
            gameBoard[y - 1][x] = firstLetter;
        }

        // check down
        else if (direction == 'D')
        {
            gameBoard[y][x] = ' ';
            gameBoard[y + 1][x] = firstLetter;
        }

        // check left
        else if (direction == 'L')
        {
            gameBoard[y][x] = ' ';
            gameBoard[y][x - 1] = firstLetter;
        }

        // check right
        else if (direction == 'R')
        {
            gameBoard[y][x] = ' ';
            gameBoard[y][x + 1] = firstLetter;
        }
    }
    else if (isTwoLetters(firstLetter))
    {
        // check up
        if (direction == 'U' && y - 1 >= 0)
        {
            if (gameBoard[y - 1][x] == ' ')
            {
                gameBoard[y][x] = firstLetter;
                gameBoard[y - 1][x] = firstLetter;
                gameBoard[y + 1][x] = ' ';
            }
            else if (y >= 0 && gameBoard[y - 2][x] == ' ')
            {
                gameBoard[y][x] = ' ';
                gameBoard[y - 1][x] = firstLetter;
                gameBoard[y - 2][x] = firstLetter;
            }
        }

        // check down
        else if (direction == 'D' && y + 2 <= 4)
        {
            if (gameBoard[y + 1][x] == ' ')
            {
                gameBoard[y][x] = firstLetter;
                gameBoard[y + 1][x] = firstLetter;
                gameBoard[y + 2][x] = ' ';
            }
            else if (gameBoard[y + 2][x] == ' ')
            {
                gameBoard[y][x] = ' ';
                gameBoard[y + 1][x] = firstLetter;
                gameBoard[y + 2][x] = firstLetter;
            }
        }

        // check left
        else if (direction == 'L')
        {
            gameBoard[y][x] = ' ';
            gameBoard[y + 1][x] = ' ';
            gameBoard[y][x - 1] = firstLetter;
            gameBoard[y + 1][x - 1] = firstLetter;
        }

        // check right
        else if (direction == 'R')
        {
            gameBoard[y][x] = ' ';
            gameBoard[y + 1][x] = ' ';
            gameBoard[y][x + 1] = firstLetter;
            gameBoard[y + 1][x + 1] = firstLetter;
        }
    }
    else if (firstLetter == '*')
    {
        // check up
        if (direction == 'U')
        {
            gameBoard[y + 1][x] = ' ';
            gameBoard[y + 1][x + 1] = ' ';
            gameBoard[y - 1][x] = firstLetter;
            gameBoard[y - 1][x + 1] = firstLetter;

        }
        
        // check down
        else if (direction == 'D')
        {
            gameBoard[y][x] = ' ';
            gameBoard[y][x + 1] = ' ';
            gameBoard[y + 2][x] = firstLetter;
            gameBoard[y + 2][x + 1] = firstLetter;
        }

        // check left
        else if (direction == 'L')
        {
            gameBoard[y][x + 1] = ' ';
            gameBoard[y + 1][x + 1] = ' ';
            gameBoard[y][x - 1] = firstLetter;
            gameBoard[y + 1][x - 1] = firstLetter;
        }

        // check right
        else if (direction == 'R')
        {
            gameBoard[y][x] = ' ';
            gameBoard[y + 1][x] = ' ';
            gameBoard[y][x + 2] = firstLetter;
            gameBoard[y + 1][x + 2] = firstLetter;
        }
    }
   
    
}

string Klotski::generateComputerCommand() const
{
    string command = "";
    char first = char(BoardGame2d::generateRandom('a',  'l' - 1));
    char last = 0;

    if (generateRandom(0, 10) == 1)
        first = '*';

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
    command.push_back(' ');
    command.push_back(last);

    return command;
}

void Klotski::playUser(string command)
{
    BoardGame2d::playUser(command);
}

void Klotski::playAuto()
{   
    BoardGame2d::playAuto();
}

bool Klotski::endGame() const
{
    return BoardGame2d::endGame();
}

void Klotski::playGame()
{
    BoardGame2d::playGame();
}

void Klotski::findCoordinate(int &x, int &y, int num) const
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (gameBoard[i][j] == num)
            {
                y = i;
                x = j;
                return;
            }
        }
    }
    x = -1;
    y = -1;
}

int Klotski::emptyCount() const
{
    int count = 0;
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (gameBoard[i][j] == ' ')
                count++;
        }
    }
    return count;
}

bool Klotski::isOneLetters(int letter) const
{
    if (letter == 'a' || letter == 'b' || letter == 'c' || letter == 'd' || letter == 'e' || letter == 'f' || letter == 'g' || letter == 'h' || letter == 'i' || letter == 'j')
        return true;
    else
        return false;
}

bool Klotski::isTwoLetters(int letter) const
{
    if (letter == 'k' || letter == 'l')
        return true;
    else
        return false;
}

} // namespace HW05_AysegulAydogan
