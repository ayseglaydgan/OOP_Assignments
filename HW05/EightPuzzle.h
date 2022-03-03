#ifndef EIGHTPUZZLE_H
#define EIGHTPUZZLE_H

#include <iostream>
#include <string>
#include <vector>
#include "BoardGame2d.h"

using namespace std;

namespace HW05_AysegulAydogan {

class EightPuzzle : public BoardGame2d {
    
public:
    EightPuzzle();

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
    int blankPlaceX;
    int blankPlaceY;

    // helper functions
    bool isValidCommand() const override;
    bool isValidMove() const override;
    void move() override;
    string generateComputerCommand() const override;
    void playGame() override;

    // helper function to check if given puzzle is solvable
    bool isSolvable() const;

};


} // namespace HW05_AysegulAydogan

#endif