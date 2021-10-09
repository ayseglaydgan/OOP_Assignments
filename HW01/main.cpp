 #include<iostream>
 #include<vector>
 #include<string>

using namespace std;


vector<vector<int>> create_2d_vector(int value);
void create_2d_vector(int value,vector<vector<int>> &board);

int main()
{
    
    // cout<<"Hello World"<<endl;
    // int arr[10];

    // vector< int >vec_arr;
    // vector<string>vec_arr2;

    // vec_arr2.push_back("Hello");
    // vec_arr2.push_back("World");
    // //push_back adds the element inside of it at the end of vector
    // vec_arr.push_back(5);
    // vec_arr.push_back(4);
    // vec_arr.push_back(3);
    // vec_arr.push_back(1);
    // vec_arr.pop_back();

    // cout<<vec_arr.size()<<endl;
    // cout<<"String size"<<endl<<vec_arr2.size()<<endl;

    // for (int i = 0; i < vec_arr.size(); ++i)
    // {
    //     cout<<vec_arr[i]<<endl;
    // }

    // for (const int integer:vec_arr)
    // {
    //     cout<<integer<<endl;
    // }

    // for (const auto str: vec_arr2)
    // {
    //     cout<<str<<endl;
    // }

    // int c_arr[5][5];
    // c_arr[0][0] = 10;
    // vector< vector<int> > vec_2d;

    // // vector<int> domates;
    // // vec_2d.push_back(vector<int>());

    // // vec_2d.push_back(vector<int>());
    // // vec_2d[0].push_back(4545);
    // // cout << vec_2d[0][0] << endl;

    // for (int i = 0; i < 4; ++i)
    // {
    //     vec_2d.push_back(vector<int>());
    //     for (int j = 0; j < 4; ++j)
    //     {
    //         vec_2d[i].push_back(0);
    //     }
        
    // }

    // for ( int i = 1; i < vec_2d.size(); ++i)
    // {
    //     for (int j = 0; j < vec_2d[i].size(); ++j)
    //     {
    //         vec_2d[i][j] = 5;

    //     }
    //     cout<<endl;
    // }

    // for (vector<int> integer_vec:vec_2d)
    // {
    //     integer_vec.push_back(19);
    //     for (const int integer_element:integer_vec)
    //     {
    //         cout<<integer_element;
    //     }
    //     cout<<endl;
    // }

    // cout << endl << endl;

    // for (const int i : vec_2d[0])
    // {
    //     cout << i;
    // }
    // cout << endl;

//    vector<vector<int>>board = create_2d_vector(5);
    vector<vector<int>>board;
    create_2d_vector(5,board);
   for(const vector<int>iterator:board)
   {
       for(const int num:iterator)
       {
           cout<<num;
       }
       cout<<endl;
   }
}

vector<vector<int>> create_2d_vector(int value)
{
    vector<vector<int>> board;
    for (int i = 0; i < value; ++i)
    {
        board.push_back(vector<int>());
        for (int j = 0; j < value; ++j)
        {
            board[i].push_back(0);
        }
        
    }
    return board;

}
// void create_2d_vector(int value,vector<vector<int>> &board)
// {
//     for (int i = 0; i < value; ++i)
//     {
//         board.push_back(vector<int>());
//         for (int j = 0; j < value; ++j)
//         {
//             board[i].push_back(0);
//         }
        
//     }

// }


