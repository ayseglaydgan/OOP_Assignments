#ifndef PEGSOLITAIRE_H
#define PEGSOLITAIRE_H

#include <iostream>
#include <string>
#include <vector>
#include "BoardGame2d.h"

using namespace std;

namespace HW05_AysegulAydogan {

enum GAME_PEG {
  BLANK = 0,
  PEG = 1,
  DOT = 2
};

class PegSolitaire : public BoardGame2d {
    
public:
    PegSolitaire();

    // override expected methods
    void playUser(string command) override;
    void playAuto() override;
    void print() const override;
    bool endGame() const override;
    int boardScore() const override;
    void initialize() override;

    // override other methods
    void printGameManual() const override;
    void printFinishMessage() const override;

private:
    // helper functions
    bool isValidCommand() const override;
    bool isValidMove() const override;
    void move() override;
    string generateComputerCommand() const override;
    void playGame() override;

};


} // namespace HW05_AysegulAydogan

#endif