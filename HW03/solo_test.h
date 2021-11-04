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
    PegSolitaire(int type);
    PegSolitaire(int board_type, int player_type);
    class Cell;
    
    void printBoard();



    vector<vector<Cell>> getBoard();

    int getPlayer();
    void setPlayer(const int& player_type);
    
    bool playGame();

    void setCommand(const string& command);
    
private:
    vector<vector<Cell>> board;

    int board_type;
    int player_type;
    int move_count = 0;
    string command;
    int command_i;
    // decltype used here
    decltype(command_i) command_j;
    char command_direction;

    // helper functions
    void initBoard(const vector<vector<GAME>> &temp_board);
    int longestLine();
    int isValidCommand();
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

// Inline functions for Pegsolitare class
inline void PegSolitaire::setPlayer(const int& _player) {player_type = _player;}
inline int PegSolitaire::getPlayer() {return player_type;}



//Inline functions from Cell class
inline void PegSolitaire::Cell::setRow(const int &_row) { row = _row; }

inline void PegSolitaire::Cell::setColumn(const int &_column) { column = _column; }

inline void PegSolitaire::Cell::setGame(const GAME &_state) { state = _state; }

inline int PegSolitaire::Cell::getRow() { return row; }

inline int PegSolitaire::Cell::getColumn() { return column; }

inline GAME PegSolitaire::Cell::getGame() { return state; }