#include<iostream>
#include<vector>

using namespace std;

// create fourth shape and return
vector< vector<string> > createBoard_4()
{
    vector<vector<string>> foo = 
    {
        {" "," ","p","p","p"," "," "},
        {" "," ","p","p","p"," "," "},
        {"p","p","p","p","p","p","p"},
        {"p","p","p",".","p","p","p"},
        {"p","p","p","p","p","p","p"},
        {" "," ","p","p","p"," "," "},
        {" "," ","p","p","p"," "," "}
    };
return foo;
}

// move function
void move(vector<vector<string>> &board, int i, int j, int direction)
{
    string temp;
    temp = board[i][j];
    if(direction == 1) //UP
    {
        board[i][j] = board[i-2][j];
        board[i-1][j] = '.';
        board[i-2][j] = temp;
    }
    else if(direction == 2) //DOWN
    {
        board[i][j] = board[i+2][j];
        board[i+1][j] = '.';
        board[i+2][j] = temp;
    }
    else if (direction == 3) //LEFT
    {
        board[i][j] = board[i][j-2];
        board[i][j-1] = '.';
        board[i][j-2] = temp;      
    }
    else if (direction == 4) //RIGHT
    {
        board[i][j] = board[i][j+2];
        board[i][j+1] = '.';
        board[i][j+2] = temp;        
    }

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
        int i, j, direction;
        cout<<"Enter i and enter j"<<endl;
        cin>>i>>j;
        cout<<"Enter direction"<<endl;
        cin>>direction;
        move(board,i,j,direction);
        cout<<"-----------------"<<endl;
        printBoard(board);
    }
    
}