#include<iostream>
#include<vector>
#include <random>
#include "solo_test.h"

using namespace std;


// create first shape and return
vector<vector<GAME>> createBoard_1()
{
    GAME P = GAME::P; // for showing more beautifull in board
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> board = 
    {
        {_,_,P,P,P,_,_},
        {_,P,P,P,P,P,_},
        {P,P,P,D,P,P,P},
        {P,P,P,P,P,P,P},
        {P,P,P,P,P,P,P},
        {_,P,P,P,P,P,_},
        {_,_,P,P,P,_,_}
    };
    return board;
}

// create second shape and return
vector<vector<GAME>> createBoard_2()
{
    GAME P = GAME::P; // for showing more beautifull in board
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> board = 
    {
        {_,_,_,P,P,P,_,_,_},
        {_,_,_,P,P,P,_,_,_},
        {_,_,_,P,P,P,_,_,_},
        {P,P,P,P,P,P,P,P,P},
        {P,P,P,P,D,P,P,P,P},
        {P,P,P,P,P,P,P,P,P},
        {_,_,_,P,P,P,_,_,_},
        {_,_,_,P,P,P,_,_,_},
        {_,_,_,P,P,P,_,_,_}
    };
    return board;
}

// create third shape and return
vector<vector<GAME>> createBoard_3()
{
    GAME P = GAME::P; // for showing more beautifull in board
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> board = 
    {
        {_,_,P,P,P,_,_,_},
        {_,_,P,P,P,_,_,_},
        {_,_,P,P,P,_,_,_},
        {P,P,P,P,P,P,P,P},
        {P,P,P,D,P,P,P,P},
        {P,P,P,P,P,P,P,P},
        {_,_,P,P,P,_,_,_},
        {_,_,P,P,P,_,_,_}
    };
    return board;
}

// create fourth shape and return
vector<vector<GAME>> createBoard_4()
{
    GAME P = GAME::P; // for showing more beautifull in board
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> board = 
    {
        {_,_,P,P,P,_,_},
        {_,_,P,P,P,_,_},
        {P,P,P,P,P,P,P},
        {P,P,P,D,P,P,P},
        {P,P,P,P,P,P,P},
        {_,_,P,P,P,_,_},
        {_,_,P,P,P,_,_}
    };
    return board;
}

// create fifth shape and return
vector<vector<GAME>> createBoard_5()
{
    GAME P = GAME::P; // for showing more beautifull in board
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> board = 
    {
        {_,_,_,_,P,_,_,_,_},
        {_,_,_,P,P,P,_,_,_},
        {_,_,P,P,P,P,P,_,_},
        {_,P,P,P,P,P,P,P,_},
        {P,P,P,P,D,P,P,P,P},
        {_,P,P,P,P,P,P,P,_},
        {_,_,P,P,P,P,P,_,_},
        {_,_,_,P,P,P,_,_,_},
        {_,_,_,_,P,_,_,_,_},
    };
    return board;
}

// create sixth shape and return
vector<vector<GAME>> createBoard_6()
{
    GAME P = GAME::P; // for showing more beautifull in board
    GAME D = GAME::DOT;
    GAME _ = GAME::BLANK;
    vector<vector<GAME>> board = 
    {
        {_,_,D,_,_},
         {_,P,P,_,_},
        {_,P,P,P,_},
         {P,P,P,P,_},
        {P,P,P,P,P}
    };
    return board;
}

bool isValidCommand(const int &board_length, const string &command) 
{
    bool is_valid = true;
    if(command.empty() || command.length() != 4)
    {
        is_valid = false;
    }
    else if(command[0] < 'A' || command[0] > 'A' + board_length - 1)
    {
        is_valid = false;
    }
    else if((command[1] - '0') < 1 || (command[1] - '0') > board_length)
    {
        is_valid = false;
    }
    else if(command[2] != '-')
    {
        is_valid = false;
    }
    else if(command[3] != 'L' && command[3] != 'U' && command[3] != 'R' && command[3] != 'D')
    {
        is_valid = false;
    }
    
    if (!is_valid)
        cout<<"Invalid command"<<endl;

    return is_valid;
}

bool checkMove(const vector<vector<GAME>> &board, const char &direction, const int &i, const int &j)
{
    if(board[i][j] == GAME::DOT || board[i][j] == GAME::BLANK)
    {
        return false;
    }
    else if (direction == 'U' && i - 2 >= 0 && board[i - 2][j] == GAME::DOT && board[i - 1][j] == GAME::P) 
    {
        return true;
    }
    else if(direction == 'D' && (i + 2) < board.size() && board[i + 2][j] == GAME::DOT && board[i + 1][j] == GAME::P)
    {
        return true;
    }
    else if(direction == 'L' && (j - 2) >= 0 && board[i][j - 2] == GAME::DOT && board[i][j - 1] == GAME::P)
    {
        return true;
    }
    else if(direction == 'R' && (j + 2) < board.size() && board[i][j + 2] == GAME::DOT && board[i][j + 1] == GAME::P)
    {
        return true;
    }
    return false;

}

int gameFinish(const vector<vector<GAME>> &board)
{
    int remaining_p = 0;
    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board[i].size(); ++j)
        
        {
            if (board[i][j] == GAME::P)
            {
                remaining_p++;
                // check up
                if (i - 2 >= 0 && board[i - 2][j] == GAME::DOT && board[i - 1][j] == GAME::P) return -1;
                // check down
                if (i + 2 < board.size() && board[i + 2][j] == GAME::DOT && board[i + 1][j] == GAME::P) return -1;
                // check right 
                if (j + 2 < board.size() && board[i][j + 2] == GAME::DOT && board[i][j + 1] == GAME::P) return -1;
                // check left
                if (j - 2 >= 0 && board[i][j - 2] == GAME::DOT && board[i][ j- 1] == GAME::P) return -1; 
            }
        }
    }
    return remaining_p;
}

void printBoard(const vector<vector<GAME>> &board)
{
    int row_num = 1;

    cout << "  ";
    for(int i = 0; i < board.size(); ++i)
    {
        cout<<char('A'+i);
    }
    cout<<endl;
    
    for(const vector<GAME> board_1d: board)
    {
        cout<< row_num <<" ";
        for(const GAME i: board_1d)
        {
            if (i == GAME::DOT) 
                cout << ".";
            if (i == GAME::P) 
                cout << "P";
            if (i == GAME::BLANK) 
                cout << " ";
        }
        row_num+=1;
        cout<<endl;
    }
}

// move function
bool move(vector<vector<GAME>> &board, const string &command)
{
    int i, j;
    const int size = board.size();
    if(isValidCommand(size, command) == true) //if the command is valid
    {
        j = (command[0] - 'A'); //conversion to integer
        i = (command[1] - '0') - 1; //conversion to integer
    }
    else
    {
        return false;
    }
    char direction = command[3];
    if (!checkMove(board, direction, i, j))
    {
        return false;
    }
    

    GAME temp = board[i][j];
    if(direction == 'U') //UP
    {
        board[i][j] = board[i-2][j];
        board[i-1][j] = GAME::DOT;
        board[i-2][j] = temp;
    }
    else if(direction == 'D') //DOWN
    {
        board[i][j] = board[i+2][j];
        board[i+1][j] = GAME::DOT;
        board[i+2][j] = temp;
    }
    else if (direction == 'L') //LEFT
    {
        board[i][j] = board[i][j-2];
        board[i][j-1] = GAME::DOT;
        board[i][j-2] = temp;      
    }
    else if (direction == 'R') //RIGHT
    {
        board[i][j] = board[i][j+2];
        board[i][j+1] = GAME::DOT;
        board[i][j+2] = temp;        
    } 
    else 
    {
        // ! gerekirse en son sil
        cout << "move da en son directionları gecti" << endl;
    }

    int score = gameFinish(board);
    if (score != -1) 
    {
        cout << "Game is finished. Congrats" << endl;
        cout << "Your score:" << score << endl;
        return true;
    }
    cout << "Computer Movement:" << command << endl;
    printBoard(board);
    return false;
}

int generateRandom(const int &min, const int &max)
{
    int random = 0;
    std::random_device generator;
    std::mt19937 gen(generator());
    std::uniform_int_distribution<int> distr(min, max);
    random = distr(generator);
    return random;
}

string generateComputerCommand(const int &board_length) 
{
    string command = "";
    char first = char(generateRandom('A', 'A' + board_length - 1));
    char second = char(generateRandom('1', '1' + board_length - 1));
    char last = 0;
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

