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



    vector<vector<Cell>> getBoard();
    
private:
    vector<vector<Cell>> board;

    // helper functions
    void initBoard(const vector<vector<GAME>> &temp_board);
    int longestLine();
    
    // Create board functions 
    void createBoard_1();
    void createBoard_2();
    void createBoard_3();
    void createBoard_4();
    void createBoard_5();
    void createBoard_6();

    
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

//Inline functions from Cell class
inline void PegSolitaire::Cell::setRow(const int &_row) { row = _row; }

inline void PegSolitaire::Cell::setColumn(const int &_column) { column = _column; }

inline void PegSolitaire::Cell::setGame(const GAME &_state) { state = _state; }

inline int PegSolitaire::Cell::getRow() { return row; }

inline int PegSolitaire::Cell::getColumn() { return column; }

inline GAME PegSolitaire::Cell::getGame() { return state; }