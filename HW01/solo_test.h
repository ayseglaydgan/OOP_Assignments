#include <iostream>
#include <vector>
#include <random>

using namespace std;

enum class GAME
{
    DOT,
    P,
    BLANK
};

vector<vector<GAME>> createBoard_1();

vector<vector<GAME>> createBoard_2();

vector<vector<GAME>> createBoard_3();

vector<vector<GAME>> createBoard_4();

vector<vector<GAME>> createBoard_5();

vector<vector<GAME>> createBoard_6();

bool isValidCommand(const int &board_length, const string &command);

bool checkMove(const vector<vector<GAME>> &board, const char &direction, const int &i, const int &j);

int gameFinish(const vector<vector<GAME>> &board);

void printBoard(const vector<vector<GAME>> &board);

bool playGame(vector<vector<GAME>> &board, const string &command, const int &type);

int generateRandom(const int &min, const int &max);

string generateComputerCommand(const int &board_length);
