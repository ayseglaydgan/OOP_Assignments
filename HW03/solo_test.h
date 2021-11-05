#include <iostream>
#include <vector>

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
    PegSolitaire(const int &type);
    PegSolitaire(const int &board_type, const int &player_type);
    class Cell;

    void printBoard();

    bool allGame(); // plays for human and computer

    bool play(Cell cell); // plays for human
    bool play(); // plays for computer
    bool playGame(); // plays for computer

    void setCommand(const string &command);
    void setPlayer(const int &player_type);

    int getPlayer() const;
    vector<vector<Cell>> getBoard() const;

    //Inline functions for number of pegs and empty cells
    int getPegs() const;
    int getEmptyCells() const;
    int getRemoved() const;

    bool getIsGameFinish() const;

    // initially maked a stsatic function
    // to use when we want to a randomm number between in a range
    static int generateRandom(const int &min, const int &max);
    string generateComputerCommand();

private:
    vector<vector<Cell>> board;

    int board_type;
    int player_type;
    int move_count = 0;
    int peg_count = 0;
    int empty_count = 0;

    bool isGameFinish = false;

    string command = "";
    int command_i = 0;
    // decltype used here
    decltype(command_i) command_j = 0;
    char command_direction = 'U';

    // helper functions
    void initBoard(const vector<vector<GAME>> &temp_board);
    int longestLine();

    // this helper functions would be const
    // but they calling a non const function
    int isValidCommand();
    bool checkMove();
    
    void move();
    int gameFinish();
    void saveGame() const;
    void loadGame();
    void cellCounter();
    

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
    void setState(const GAME &state);
    int getRow() const;
    int getColumn() const;
    GAME getState() const;

private:
    GAME state;
    int column;
    int row;
};

// Inline functions for Pegsolitare class
inline void PegSolitaire::setPlayer(const int &_player) { player_type = _player; }
inline int PegSolitaire::getPlayer() const { return player_type; }
inline vector<vector<PegSolitaire::Cell>> PegSolitaire::getBoard() const { return board; }


// Get remaining peg counts
inline int PegSolitaire::getPegs() const { return peg_count; }
// Get empty cell counts
inline int PegSolitaire::getEmptyCells() const { return empty_count; }
// Get remaining removed cell counts
inline int PegSolitaire::getRemoved() const { return move_count; }

inline bool PegSolitaire::getIsGameFinish() const { return isGameFinish; }




 
//Inline functions from Cell class
inline void PegSolitaire::Cell::setRow(const int &_row) { row = _row; }

inline void PegSolitaire::Cell::setColumn(const int &_column) { column = _column; }

inline void PegSolitaire::Cell::setState(const GAME &_state) { state = _state; }

inline int PegSolitaire::Cell::getRow() const { return row; }

inline int PegSolitaire::Cell::getColumn() const { return column; }

inline GAME PegSolitaire::Cell::getState() const { return state; }
