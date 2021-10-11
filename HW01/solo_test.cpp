#include<iostream>
#include<vector>

using namespace std;
vector< vector<string> > create_board_4()
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
void print_board(const vector<vector<string>> &board)
{
    cout << "  ";
    for(int i = 0; i < board.size(); ++i)
    {
        cout<<char('a'+i);
    }
    cout<<endl;
    
    int counter = 1;
    for(const vector<string> board_1d: board)
    {
        cout<< counter <<" ";
        for(const string i: board_1d)
        {
            cout<<i;
        }
        counter+=1;
        cout<<endl;
    }
}




int main()
{
    vector<vector<string>> board;
    board = create_board_4();
    print_board(board);
    while (1)
    {
        int i, j, direction;
        cout<<"Enter i and enter j"<<endl;
        cin>>i>>j;
        cout<<"Enter direction"<<endl;
        cin>>direction;
        move(board,i,j,direction);
        cout<<"-----------------"<<endl;
        print_board(board);
    }
    
}