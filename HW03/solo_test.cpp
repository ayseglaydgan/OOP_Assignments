#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include "solo_test.h"

using namespace std;

//if the type of the board is not indicated, create board 4
// if default consturctor used, play as computer
PegSolitaire::PegSolitaire()
{
    player_type = 1;
    board_type = 4;
    createBoard_4();
}

//when the object is creating, if a parameter indicated it is our board type.
PegSolitaire::PegSolitaire(const int &type)
{
    if (type == 1)
        createBoard_1();
    else if (type == 2)
        createBoard_2();
    else if (type == 3)
        createBoard_3();
    else if (type == 4)
        createBoard_4();
    else if (type == 5)
        createBoard_5();
    else if (type == 6)
        createBoard_6();
    else
    {
        cerr << "Invalid board type" << endl;
        cerr << "Board 4 assumed as a board type" << endl;
        createBoard_4();
    }
    board_type = type;
    player_type = 1;
}

//when the object is creating, if there is 2 parameter first of it is board type, second is player type
PegSolitaire::PegSolitaire(const int &_board_type, const int &_player_type)
{
    if (_board_type == 1)
        createBoard_1();
    else if (_board_type == 2)
        createBoard_2();
    else if (_board_type == 3)
        createBoard_3();
    else if (_board_type == 4)
        createBoard_4();
    else if (_board_type == 5)
        createBoard_5();
    else if (_board_type == 6)
        createBoard_6();
    else
    {
        cerr << "Invalid board type" << endl;
        cerr << "Board 4 assumed as a board type" << endl;
        createBoard_4();
    }
    board_type = _board_type;
    player_type = _player_type;
}

//Saved or Loaded Board can be bigger than implamentation
// So, take the longest line when detecting the size of the board
int PegSolitaire::longestLine()
{
    int longest_line = 0;
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i].size() > longest_line)
            longest_line = board[i].size();
    }
    return longest_line;
}

void PegSolitaire::cellCounter()
{
    peg_count = 0;
    empty_count = 0;
    for (const vector<Cell> board_1d : board)
    {
        for(const Cell cell : board_1d)
        {
            if (cell.getState() == GAME::P)
            {
                peg_count++;
            }
            else if (cell.getState() == GAME::DOT)
            {
                empty_count++;
            }   
        }
    }
}

void PegSolitaire::printBoard()
{
    cellCounter();
    cout << "Info: Total Peg:" << peg_count + move_count <<" Remaining Peg:" << peg_count << " Empty(Dot) Count:" << empty_count << endl; 

    //row_num = 1 because first row used for letter coordinates
    int row_num = 1;

    // determine the longest line to write all rows
    int longest_line = longestLine();

    // leave a tab for printing "abcdefg"
    cout << "  ";
    
    //to adjust the coordinates
    for (int i = 0; i < longest_line; ++i)
    {
        cout << char('a' + i);
    }
    cout << endl;

    //some lines of code by heart to adjust strong enum types
    // Update (5.11.2021). I understand now :)
    // I think it is a good idea to use enum types to make the code more readable
    for (const vector<Cell> board_1d : board)
    {
        cout << row_num << " ";
        for (Cell cell : board_1d)
        {
            if (cell.getState() == GAME::DOT)
                cout << ".";
            if (cell.getState() == GAME::P)
                cout << "P";
            if (cell.getState() == GAME::BLANK)
                cout << " ";
        }
        row_num += 1;
        cout << endl;
    }
}

// initialize the board with the type of the GAME board
// It will fill our Cell Board due to the type of the temp Game Board
void PegSolitaire::initBoard(const vector<vector<GAME>> &temp_board)
{
    for (int i = 0; i < temp_board.size(); ++i)
    {
        board.push_back(vector<Cell>());
        for (int j = 0; j < temp_board[i].size(); ++j)
        {
            // Cell takes row column and GAME state so I give it. temp[i][j] = GAME::P vs
            board[i].push_back(Cell(i, j, temp_board[i][j]));
        }
    }
}

void PegSolitaire::createBoard_1()
{
    GAME P = GAME::P;
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> temp =
        {
            {_, _, P, P, P, _, _},
            {_, P, P, P, P, P, _},
            {P, P, P, D, P, P, P},
            {P, P, P, P, P, P, P},
            {P, P, P, P, P, P, P},
            {_, P, P, P, P, P, _},
            {_, _, P, P, P, _, _}};
    
    initBoard(temp);
}

void PegSolitaire::createBoard_2()
{
    GAME P = GAME::P;
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> temp =
        {
            {_, _, _, P, P, P, _, _, _},
            {_, _, _, P, P, P, _, _, _},
            {_, _, _, P, P, P, _, _, _},
            {P, P, P, P, P, P, P, P, P},
            {P, P, P, P, D, P, P, P, P},
            {P, P, P, P, P, P, P, P, P},
            {_, _, _, P, P, P, _, _, _},
            {_, _, _, P, P, P, _, _, _},
            {_, _, _, P, P, P, _, _, _}};

    initBoard(temp);
}

void PegSolitaire::createBoard_3()
{
    //strong enum
    GAME P = GAME::P;
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> temp =
        {
            {_, _, P, P, P, _, _, _},
            {_, _, P, P, P, _, _, _},
            {_, _, P, P, P, _, _, _},
            {P, P, P, P, P, P, P, P},
            {P, P, P, D, P, P, P, P},
            {P, P, P, P, P, P, P, P},
            {_, _, P, P, P, _, _, _},
            {_, _, P, P, P, _, _, _}};

    initBoard(temp);
}

void PegSolitaire::createBoard_4()
{
    //strong enum
    GAME P = GAME::P;
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> temp =
        {
            {_, _, P, P, P, _, _},
            {_, _, P, P, P, _, _},
            {P, P, P, P, P, P, P},
            {P, P, P, D, P, P, P},
            {P, P, P, P, P, P, P},
            {_, _, P, P, P, _, _},
            {_, _, P, P, P, _, _}};

    initBoard(temp);
}

void PegSolitaire::createBoard_5()
{
    //strong enum
    GAME P = GAME::P;
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> temp =
        {
            {_, _, _, _, P, _, _, _, _},
            {_, _, _, P, P, P, _, _, _},
            {_, _, P, P, P, P, P, _, _},
            {_, P, P, P, P, P, P, P, _},
            {P, P, P, P, D, P, P, P, P},
            {_, P, P, P, P, P, P, P, _},
            {_, _, P, P, P, P, P, _, _},
            {_, _, _, P, P, P, _, _, _},
            {_, _, _, _, P, _, _, _, _}};

    initBoard(temp);
}

void PegSolitaire::createBoard_6()
{
    //strong enum
    GAME P = GAME::P;
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> temp =
        {
            {_, _, D, _, _},
            {_, P, P, _, _},
            {_, P, P, P, _},
            {P, P, P, P, _},
            {P, P, P, P, P}};

    initBoard(temp);
}

void PegSolitaire::setCommand(const string &_command)
{
    command = _command;
    command_i = (command[1] - '0') - 1; //conversion to integer
    command_j = (command[0] - 'A');     //conversion to integer
    command_direction = command[3];
}

// Pegsolitare functions

int PegSolitaire::isValidCommand()
{
    const int size = longestLine();
    int is_valid = 0;

    // save load
    if (command.find("SAVE ") != std::string::npos)
        return 1;
    if (command.find("LOAD ") != std::string::npos)
        return 2;
    if (command.find("EXIT") != std::string::npos)
        return 3;

    else if (command.empty() || command.length() != 4)
    {
        is_valid = -1;
    }
    // check for second parameter is number
    else if (command[1] - '0' > 9)
    {
        is_valid = -1;
    }
    else if (command[0] < 'A' || command[0] > 'A' + size - 1)
    {
        is_valid = -1;
    }
    else if ((command[1] - '0') < 1 || (command[1] - '0') > size)
    {
        is_valid = -1;
    }
    else if (command[2] != '-')
    {
        is_valid = -1;
    }
    else if (command[3] != 'L' && command[3] != 'U' && command[3] != 'R' && command[3] != 'D')
    {
        is_valid = -1;
    }

    return is_valid;
}

bool PegSolitaire::checkMove()
{
    // take longest line for arbitrary boards
    const int size = longestLine();
    const int i = command_i;
    const int j = command_j;
    const char direction = command_direction;

    //checks the playing point is peg
    if (board[i][j].getState() == GAME::DOT || board[i][j].getState() == GAME::BLANK)
    {
        return false;
    }
    //checks the exceptions for up direction
    else if (direction == 'U' && i - 2 >= 0 && board[i - 2][j].getState() == GAME::DOT && board[i - 1][j].getState() == GAME::P)
    {
        return true;
    }
    //checks the exceptions for down direction
    else if (direction == 'D' && (i + 2) < board.size() && board[i + 2][j].getState() == GAME::DOT && board[i + 1][j].getState() == GAME::P)
    {
        return true;
    }
    //checks the exceptions for the left direction
    else if (direction == 'L' && (j - 2) >= 0 && board[i][j - 2].getState() == GAME::DOT && board[i][j - 1].getState() == GAME::P)
    {
        return true;
    }
    //checks the exceptions for the right direction
    else if (direction == 'R' && (j + 2) < size && board[i][j + 2].getState() == GAME::DOT && board[i][j + 1].getState() == GAME::P)
    {
        return true;
    }
    //if non of the if bloks dont work then return false
    return false;
}

void PegSolitaire::move()
{
    const int i = command_i;
    const int j = command_j;
    const char direction = command_direction;

    //SWAP according to direction
    const Cell temp = board[i][j];
    if (direction == 'U') //UP
    {
        board[i][j] = board[i - 2][j];
        board[i - 1][j].setState(GAME::DOT);
        board[i - 2][j] = temp;
    }
    else if (direction == 'D') //DOWN
    {
        board[i][j] = board[i + 2][j];
        board[i + 1][j].setState(GAME::DOT);
        board[i + 2][j] = temp;
    }
    else if (direction == 'L') //LEFT
    {
        board[i][j] = board[i][j - 2];
        board[i][j - 1].setState(GAME::DOT);
        board[i][j - 2] = temp;
    }
    else if (direction == 'R') //RIGHT
    {
        board[i][j] = board[i][j + 2];
        board[i][j + 1].setState(GAME::DOT);
        board[i][j + 2] = temp;
    }
}

int PegSolitaire::gameFinish()
{
    int remaining_p = 0;
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)

        {
            if (board[i][j].getState() == GAME::P)
            {
                //to calculate score
                remaining_p++;
                // check up
                if (i - 2 >= 0 && board[i - 2][j].getState() == GAME::DOT && board[i - 1][j].getState() == GAME::P)
                    return -1;
                // check down
                if (i + 2 < board.size() && board[i + 2][j].getState() == GAME::DOT && board[i + 1][j].getState() == GAME::P)
                    return -1;
                // check right
                if (j + 2 < board.size() && board[i][j + 2].getState() == GAME::DOT && board[i][j + 1].getState() == GAME::P)
                    return -1;
                // check left
                if (j - 2 >= 0 && board[i][j - 2].getState() == GAME::DOT && board[i][j - 1].getState() == GAME::P)
                    return -1;
            }
        }
    }
    return remaining_p;
}

int PegSolitaire::generateRandom(const int &min, const int &max)
{
    //some lines of code by heart to produce random numbers
    //probably it produces from hardware
    int random = 0;
    std::random_device generator;
    std::mt19937 gen(generator());
    std::uniform_int_distribution<int> distr(min, max);
    random = distr(generator);
    return random;
}

string PegSolitaire::generateComputerCommand()
{
    string command = "";
    char first = char(generateRandom('A', 'A' + longestLine() - 1));
    char second = char(generateRandom('1', '1' + board.size() - 1));
    char last = 0;

    // to get the direction
    switch (generateRandom(1, 4))
    {
    case 1:
        last = 'U';
        break;
    case 2:
        last = 'D';
        break;
    case 3:
        last = 'L';
        break;
    case 4:
        last = 'R';
        break;
    default:
        break;
    }
    // cout << "first:" << first << " second:" << second << " last:" << last << endl;
    command.push_back(first);
    command.push_back(second);
    command.push_back('-');
    command.push_back(last);

    return command;
}

void PegSolitaire::saveGame() const
{
    // take file name from command
    // SAVE filename.txt for example
    const string file_name = command.substr(5);

    // create new file pointer named fout
    ofstream fout;
    fout.open(file_name);

    if (!fout.is_open())
    {
        cerr << "Can not create this file " << file_name << endl;
        return;
    }

    // write player_type and table_type and move_count to table
    fout << board_type << endl;
    fout << player_type << endl;
    fout << move_count << endl;

    // write board info to file
    for (const vector<Cell> board_line : board)
    {
        for (const Cell cell : board_line)
        {
            if (cell.getState() == GAME::DOT)
                fout << ".";
            if (cell.getState() == GAME::P)
                fout << "P";
            if (cell.getState() == GAME::BLANK)
                fout << " ";
        }
        fout << endl;
    }
    fout.close();

    cout << "Game saved to " << file_name << " successfully" << endl;
}

void PegSolitaire::loadGame()
{
    vector<vector<GAME>> board_read;
    const string file_name = command.substr(5);
    ifstream fin;
    fin.open(file_name);

    if (!fin.is_open())
    {
        cerr << "Can not create this file " << file_name << endl;
        return;
    }

    // write player_type and table_type and move_count to table
    fin >> board_type;
    fin >> player_type;
    fin >> move_count;

    string line;

    // ignore last empty character
    fin.ignore();

    while (getline(fin, line))
    {
        board_read.push_back(vector<GAME>());
        int last_index = board_read.size() - 1;
        for (const char element : line)
        {
            if (element == '.')
                board_read[last_index].push_back(GAME::DOT);
            else if (element == 'P')
                board_read[last_index].push_back(GAME::P);
            else // if char is not P or ".", assume that it is a blank point
                board_read[last_index].push_back(GAME::BLANK);
        }
    }

    fin.close();

    // assign read board to original board
    for (int i = 0; i < board.size(); i++)
    {
        board[i].clear();
    }
    board.clear();
    initBoard(board_read);

    cout << "Game loaded from " << file_name << " successfully" << endl;
    cout << "Game Shape Number:" << board_type << endl;
    cout << "Game Type:";
    if (player_type == 1)
        cout << "Player" << endl;
    else
        cout << "Computer" << endl;
    cout << "Move count" << move_count << endl;

    cout << "Game Table:" << endl;
    printBoard();
}


bool PegSolitaire::playGame()
{
    return play();
}

bool PegSolitaire::play()
{
    string command = generateComputerCommand();
    setCommand(command);
    return allGame();
}

bool PegSolitaire::play(Cell position)
{
    position.setRow(command_i);
    position.setColumn(command_j);
    position.setState(GAME::P);
    return allGame();
}

bool PegSolitaire::allGame()
{
    // use command type to determine SAVE || LOAD || EXIT or normal command || invalid
    const int command_type = isValidCommand();

    if (command_type == -1) //if the command is invalid
    {
        if (player_type == 1) //if the player is human
            cerr << "Invalid command" << endl;
        return false;
    }

    // save funciton
    else if (command_type == 1)
    {
        saveGame();
        return false;
    }

    // load function
    else if (command_type == 2)
    {
        loadGame();
        return false;
    }

    // EXIT Condition
    else if (command_type == 3)
    {
        cout << "You exit from game. Game is still active" << endl;
        return true;
    }

    // Check direction and place is valid
    if (!checkMove())
    {
        if (player_type == 1) // if player is human
            cerr << "Invalid direction" << endl;
        return false;
    }

    move_count++;
    move();

    // if computer plays this. It will print computer move
    if (player_type == 2)
        cout << "Computer Movement:" << command << endl;

    //gameFinish returns the remaining peg, if it is not -1, that means there are still moves to play.
    auto score = gameFinish();
    if (score != -1) // if game is finished
    {
        cout << "Game is finished. Congrats" << ". Game is passive now." << endl;
        cout << "Your score:" << score << endl;
        isGameFinish = true;
        return true;
    }

    // print board in every move
    printBoard();
    return false;
}

int PegSolitaire::allPegCounter(const vector<PegSolitaire> &games)
{
    // if there is no game in this vector
    // return -1
    if (games.size() == 0)
    {
        return -1;
    }
    
    int totalPegs = 0;
    for(int i = 0; i < games.size(); ++i)
    {
        cout << "games[" << i << "] Pegs:" << games[i].getPegs() << endl; 
        totalPegs += games[i].getPegs();
    }
    return totalPegs;
}

// cell consturctors

PegSolitaire::Cell::Cell()
{
    state = GAME::BLANK;
    column = 0;
    row = 0;
}

PegSolitaire::Cell::Cell(const int &_row, const int &_column, const GAME &_state)
{
    row = _row;
    column = _column;
    state = _state;
}