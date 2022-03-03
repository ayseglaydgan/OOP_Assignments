#ifndef BOARDGAME2D_H
#define BOARDGAME2D_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace HW05_AysegulAydogan {

enum PLAYER {
    HUMAN = 0, 
    COMPUTER = 1
};

class BoardGame2d
{

public:
    BoardGame2d(/* args */);
    virtual ~BoardGame2d() {};

    // expected functions
    virtual void playUser(string command) = 0;
    virtual void playUser() final;
    virtual void playAuto() = 0;
    virtual void playAutoAll() final;
    virtual void print() const = 0;
    friend ostream &operator<<(std::ostream &out,  BoardGame2d* game);
    virtual bool endGame() const = 0;
    virtual int boardScore() const = 0;
    virtual void initialize() = 0;

    static void playVector(vector<BoardGame2d*> games);

    // other functions
    virtual void printGameManual() const = 0;
    virtual void printFinishMessage() const = 0;
    static int generateRandom(int min, int max);
    static bool boardContains(const vector<vector<int>> &board, int num);

    // setters getters
    void setPlayer(int player);
    int getPlayer() const;
    string getName() const;
    
    void setCommand(string command);
    string getCommand() const;

protected:
    // 2d game board
    vector<vector<int>> gameBoard;
    // game board size
    int boardSize;
    // player type
    int playerType;
    // move count
    int moveCount;
    // game command
    string command;
    // keep game name to show in print
    string gameName;

    // helper functions
    virtual bool isValidCommand() const = 0;
    virtual bool isValidMove() const = 0;
    virtual void move() = 0;
    virtual string generateComputerCommand() const = 0;
    virtual void playGame() = 0;
    
private:
    /* data */
    void printMessageHelper() const;

    

};

}  // namespace HW05_AysegulAydogan


#endif