#ifndef KLOTSKI_H
#define KLOTSKI_H

#include <iostream>
#include <string>
#include <vector>
#include "BoardGame2d.h"

using namespace std;

namespace HW05_AysegulAydogan {

class Klotski : public BoardGame2d {
    
public:
    Klotski();

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

    // klotski helpers
    void findCoordinate(int &x, int &y, int num) const;
    bool isOneLetters(int letter) const;
    bool isTwoLetters(int letter) const;

    int emptyCount() const;

};


} // namespace HW05_AysegulAydogan

#endif