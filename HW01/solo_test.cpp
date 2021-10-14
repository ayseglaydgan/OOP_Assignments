#include<iostream>
#include<vector>

using namespace std;

// create fourth shape and return
vector<vector<string>> createBoard_4()
{
    vector<vector<string>> board = 
    {
        {" "," ","p","p","p"," "," "},
        {" "," ","p","p","p"," "," "},
        {"p","p","p","p","p","p","p"},
        {"p","p","p",".","p","p","p"},
        {"p","p","p","p","p","p","p"},
        {" "," ","p","p","p"," "," "},
        {" "," ","p","p","p"," "," "}
    };
    return board;
}

bool isValidCommand(const int &board_length, const string &command) 
{
    bool is_valid = true;
    cout << "Command:" << command << endl;
    cout << "board length: " << board_length << endl;
    if(command.empty() || command.length() != 4)
    {
        cout << "emptyim" << endl;
        is_valid = false;
    }
    else if(command[0] < 'a' || command[0] > 'a' + board_length - 1)
    {
        cout << "harf sikintisi" << endl;
        is_valid = false;
    }
    else if((command[1] - '0') < 1 || (command[1] - '0') > board_length)
    {
        cout << "Command[1]:" << command[1] << endl;
        cout << "board length gg" << endl;
        is_valid = false;
    }
    else if(command[2] != '-')
    {
        cout << "- işareti gg" << endl;
        is_valid = false;
    }
    else if(command[3] != 'L' && command[3] != 'U' && command[3] != 'R' && command[3] != 'D')
    {
        cout << "Yön gg" << endl;
        is_valid = false;
    }
    
    if (!is_valid)
        cout<<"Invalid command"<<endl;

    return is_valid;
}

bool checkMove(const vector<vector<string>> &board, const char &direction, const int &i, const int &j)
{
    if(board[i][j] == "." || board[i][j] == " ")
    {
        cout << "You can't change \".\" or empty location" << endl;
        return false;
    }
    else if (direction == 'U' && i - 2 >= 0 && board[i - 2][j] == "." && board[i - 1][j] == "p") 
    {
        cout << "U gg " << endl;
        return true;
    }
    else if(direction == 'D' && (i + 2) < board.size() && board[i + 2][j] == "." && board[i + 1][j] == "p")
    {
        cout << "D gg" << endl;
        return true;
    }
    else if(direction == 'L' && (j - 2) >= 0 && board[i][j - 2] == "." && board[i][j - 1] == "p")
    {
        cout << "L gg" << endl;
        return true;
    }
    else if(direction == 'R' && (j + 2) < board.size() && board[i][j + 2] == "." && board[i][j + 1] == "p")
    {
        cout << "R gg" << endl;
        return true;
    }
    return false;

}

int gameFinish(const vector<vector<string>> &board)
{
    int remaining_p = 0;
    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board[i].size(); ++j)
        
        {
            if (board[i][j] == "p")
            {
                remaining_p++;
                // check up
                if (i - 2 >= 0 && board[i - 2][j] == "." && board[i - 1][j] == "p") return -1;
                // check down
                if (i + 2 < board.size() && board[i + 2][j] == "." && board[i + 1][j] == "p") return -1;
                // check right 
                if (j + 2 < board.size() && board[i][j + 2] == "." && board[i][j + 1] == "p") return -1;
                // check left
                if (j - 2 >= 0 && board[i][j - 2] == "." && board[i][ j- 1] == "p") return -1; 
            }
        }
    }
    return remaining_p;
}

// move function
bool move(vector<vector<string>> &board, const string &command)
{
    int i, j;
    const int size = board.size();
    if(isValidCommand(size, command) == true) //if the command is valid
    {
        j = (command[0] - 'a'); //conversion to integer
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
    

    string temp = board[i][j];
    cout << "i:" << i << " j:" << j << " direction:" << direction << endl;
    if(direction == 'U') //UP
    {
        board[i][j] = board[i-2][j];
        board[i-1][j] = '.';
        board[i-2][j] = temp;
    }
    else if(direction == 'D') //DOWN
    {
        board[i][j] = board[i+2][j];
        board[i+1][j] = '.';
        board[i+2][j] = temp;
    }
    else if (direction == 'L') //LEFT
    {
        board[i][j] = board[i][j-2];
        board[i][j-1] = '.';
        board[i][j-2] = temp;      
    }
    else if (direction == 'R') //RIGHT
    {
        board[i][j] = board[i][j+2];
        board[i][j+1] = '.';
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
    
    return false;
}

void printBoard(const vector<vector<string>> &board)
{
    int row_num = 1;

    cout << "  ";
    for(int i = 0; i < board.size(); ++i)
    {
        cout<<char('a'+i);
    }
    cout<<endl;
    
    for(const vector<string> board_1d: board)
    {
        cout<< row_num <<" ";
        for(const string i: board_1d)
        {
            cout<<i;
        }
        row_num+=1;
        cout<<endl;
    }
}



int main()
{
    vector<vector<string>> board;
    board = createBoard_4();
    printBoard(board);
    while (1)
    {
        string command;
        cout << "Enter Command:";
        cin>>command;
        if (move(board, command))
            break;
        printBoard(board);
    }
    printBoard(board);
    
}