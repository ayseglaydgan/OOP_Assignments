#include "BoardGame2d.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>

// for sleep
#include <thread>
#include <chrono>

using namespace std;
namespace HW05_AysegulAydogan {

/**
 * @brief Construct a new Board Game 2d:: Board Game 2d object
 * 
 */
BoardGame2d::BoardGame2d()
{
    this->boardSize = 0;
    this->moveCount = 0;
    this->playerType = PLAYER::HUMAN;
    this->gameName = "BoardGame2d";
}

void BoardGame2d::playUser(string command)
{
    setCommand(command);
    playGame();
}

void BoardGame2d::playUser() 
{
    printGameManual();
    while(!endGame())
    {
        print();
        string command;
        cout << "Enter command:";
        getline(cin, command);
        playUser(command);
    }

    printMessageHelper();
}

bool BoardGame2d::endGame() const
{
    auto score = boardScore();
    if (score == -1)
        return false;
    else
        return true;
}

void BoardGame2d::playGame()
{
    if (!isValidCommand() || !isValidMove())
    {
        cout << "Invalid command" << endl;
        return;
    }
    //print();
    //cout << "Command:" << command << endl;
    moveCount++;
    move();
    
}

void BoardGame2d::playAuto()
{
    do 
    {
        setCommand(generateComputerCommand());
        if (isValidCommand() && isValidMove())
            break;
    } while (true);
    
    playGame();
}

void BoardGame2d::playAutoAll()
{
    
    bool takeInput = true;
    while (!endGame())
    {
        if (takeInput)
        {
            cout << "Press 1 to see result one by one." << endl;
            cout << "Other keys will show the final result directly" << endl;
            int garbage;
            cin >> garbage;
            if (garbage != 1)
            {
                takeInput = false;
                continue;
            }
            playAuto();
            print();
        }
        else
            playAuto();
    }
    
    printMessageHelper();
}

void BoardGame2d::print() const
{
    // clear the terminal
    cout << "\033[H\033[J";
}

std::ostream &operator<<(std::ostream &out,  BoardGame2d* game)
{
    game->print();
    return out;
}

void BoardGame2d::playVector(vector<BoardGame2d*> games)
{

    for (int i = 0; i < games.size(); i++)
    {
        BoardGame2d *game = games[i];
        int choice = 0;
        cout << "------------------------------------------------------" << endl;
        cout << "\tYou are playing " << game->gameName << " now" << endl;
        cout << "------------------------------------------------------" << endl;
        game->print();
        cout << "Do you want to play yourself or computer?" << endl;
        cout << "1- Yourself" << endl;
        cout << "2- Computer" << endl;
        cout << "Choice:" << endl;
        cin >> choice;
        if (choice == 1)
            game->playUser();
        else if (choice == 2)
            game->playAutoAll();
        else
        {
            cout << "Wrong input" << endl;
            i--;
        }
    }
}

int BoardGame2d::generateRandom(int min, int max)
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

// setter getters
void BoardGame2d::setPlayer(int player) 
{
    if (player == 1 || player == 2)
    {
        this->playerType = player;
    }
    else
    {
        cerr << "Wrong player type" << endl;
    }
}

void BoardGame2d::setCommand(string command)
{
    this->command = command;
}

string BoardGame2d::getCommand() const {return this->command;}
int BoardGame2d::getPlayer() const {return this->playerType;}
string BoardGame2d::getName() const {return this->gameName;}

bool BoardGame2d::boardContains(const vector<vector<int>> &board, int num)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == num)
                return true;
        }
    }
    return false;
}

void BoardGame2d::printMessageHelper() const
{
    cout << "You will see resulted board in 3 seconds" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    cout << "You will see resulted board in 2 seconds" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    cout << "You will see resulted board in 1 seconds" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    print();
    printFinishMessage();
}



} // namespace HW05_AysegulAydogan
