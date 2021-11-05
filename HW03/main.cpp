#include <iostream>
#include <vector>
#include "solo_test.h"

using namespace std;

PegSolitaire newGame();
void continueGame(PegSolitaire game);
int selectActiveGame(vector<PegSolitaire>& games);

bool isCinFail();

int main()
{
    cout << "Welcome to Peg Solitaire!" << endl;
    PegSolitaire game;
    int selected;
    vector<PegSolitaire> games;

    while(1)
    {
        cout << "-------------- MENU -------------- " << endl;
        cout << "1- Start New Game" << endl;
        cout << "2- Continue Game" << endl;
        cout << "3- Exit" << endl;
        cout << "-----------------------------------" << endl;
        int choice;
        
        cout << "Enter choice:";
        cin >> choice;

        if (isCinFail())
            continue;

        switch(choice)
        {
            case 1:
                    game = newGame();
                    games.push_back(game);
                    cout << "Games size:" << games.size() << endl;
                    continueGame(game);
                    break;
            case 2:
                    cout << "Games size:" << games.size() << endl;
                    selected = selectActiveGame(games);
                    continueGame(games[selected]);
                    break;
            case 3:
                    return 0;
            default:
                    cout << "Invalid choice!" << endl;
                    break;
        }
    }
    
    


    // PegSolitaire game(type, player);
    
    // //If game is not finished, continue to play
    // if (game.getIsGameFinish() == false)
    // {
    //     continueGame(game);
    // }
    



    cout << "Buraya kadar gelebildim mi?" << endl;
    return 0;
}

PegSolitaire newGame()
{
    int player_type = 0;
    int table_type = 0;

    while (table_type <= 0 || table_type > 6)
    {
        cout << "Choose Game Table Type (1-6)" << endl;
        cout << "Enter command:";
        cin >> table_type;

        // fix invalid input (ex: string enterd instead of integer)
        if (isCinFail())
            continue;
        if (table_type <= 0 || table_type > 6)
            cout << "Invalid input!" << endl;
        
    }

    cout << "You selected " << table_type << ". board" << endl;

    while (player_type != 1 && player_type != 2)
    {
        cout << "Choose Player Type" << endl
            << "1-Human" << endl
            << "2-Computer" << endl;
        cout << "Enter Command:";
        cin >> player_type;

        // fix invalid input (ex: string enterd instead of integer)
        if (isCinFail())
            continue;

        if (player_type != 1 && player_type != 2)
            cout << "Invalid input!" << endl;
    }

    if (player_type == 1)
        cout << "You selected Human" << endl;
    else
        cout << "You selected Computer" << endl;

    PegSolitaire game(table_type, player_type);

    return game;
}

void continueGame(PegSolitaire game)
{
    game.printBoard();

    int isGameActive = 0;
    while (isGameActive == 0)
    {
        if (game.getPlayer() == 1) // player
        {
            string command;
            cout << "Enter Command:";

            // take whole line
            // used for (SAVE FILE.txt or LOAD FILE.txt)
            getline(cin, command);
            game.setCommand(command);
            isGameActive = game.play(PegSolitaire::Cell(1,1,GAME::BLANK));
        }
        else if (game.getPlayer() == 2) // computer
            isGameActive = game.playGame();

        // set the command human or computer, does not matter.
        // set with PegSolitare private string data member
        
    }

    game.printBoard();
}


int selectActiveGame(vector<PegSolitaire> &games)
{
    int selected;
    cout << "All Games List:" << endl;
    for (int i = 0; i < games.size(); ++i)
    {
        cout << "GAMES[" << i << "]:";
        if (games[i].getIsGameFinish() == false)
        {
            cout << "ACTIVE" << endl;
        }
        else
        {
            cout << "PASSIVE" << endl;
        }
        
    }
    while(1)
    {
        cout << "Choice a game:";
        cin >> selected;

        if (isCinFail())
            continue;
        
        if (selected < 0 || selected >= games.size())
        {
            cout << "Invalid input!" << endl;
            continue;
        }
        

        if (games[selected].getIsGameFinish() == false)
        {
            cout << "You choice " << selected << ". game" << endl;
            return selected;
        }
        else
            cout << "You can choise this game. This game is passive" << endl;  
    }
    
}


bool isCinFail()
{
    // fix invalid input (ex: string enterd instead of integer)
    if (cin.fail())
    {
        cerr << "Your input is invalid" << endl;
        cin.clear();
        cin.ignore(100, '\n');
        return true;
    }
    return false;
}
