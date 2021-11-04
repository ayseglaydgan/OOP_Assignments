#include<iostream>
#include<vector>

using namespace std;

enum class GAME
{
    DOT,
    P,
    BLANK
};

class PegSolitaire
{
public:
    PegSolitaire();
    PegSolitaire(int size);
    class Cell;
    
    void printBoard();

    // Create board functions 
    void createBoard_1();

    vector<vector<Cell>> getBoard();
    
private:
    vector<vector<Cell>> board;

    void assignBoard(const vector<vector<GAME>> &temp_board);

    int longestLine();
};

class PegSolitaire::Cell
{
    public:
        Cell();
        Cell(const int &row, const int &column, const GAME &state);

        void setRow(const int &row);
        void setColumn(const int &column);
        void setGame(const GAME &state);
        int getRow();
        int getColumn();
        GAME getGame();

    private:
        GAME state;
        int column;
        int row;
};