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
}