#include<iostream>
#include<vector>
#include"solo_test.h"

using namespace std;

int main()
{
    PegSolitaire _game;
    

    _game = PegSolitaire(4);

    _game.printBoard();
}