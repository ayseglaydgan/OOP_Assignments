#include <iostream>
#include <vector>
#include "solo_test.h"

using namespace std;

PegSolitaire newGame();
void continueGame(PegSolitaire& game);
int selectActiveGame(const vector<PegSolitaire>& games);
bool isCinFail();

int main()
{
    cout << "Welcome to Peg Solitaire!" << endl;
    int selected = -1;
    vector<PegSolitaire> games;

    while(1)
    {
        cout << "-------------- MENU -------------- " << endl;
        cout << "1- Start New Game" << endl;
        cout << "2- Continue Game" << endl;
        cout << "3- Exit" << endl << endl;
        cout << "Available Commands in game ->" << endl << "SAVE/LOAD <filename> || EXIT || Regular Solotest Commands (A5-U)" << endl;
        cout << endl << "-----------------------------------" << endl;
        int choice;
        
        cout << "Enter choice:";
        cin >> choice;

        // if cin fails, then the user has entered an invalid input
        if (isCinFail())
            continue;

        switch(choice)
        {
            case 1:
                    // game = newGame();
                    games.push_back(newGame());
                    // get last added element from vector
                    // because with this, it will efect the
                    // right game. Without doing this, it is effecting
                    // wrong game. And does not change expected game.
                    continueGame(games[ games.size() - 1 ]);
                    break;
            case 2:
                    selected = selectActiveGame(games);
                    if (selected == -1)
                    {
                        break;
                    }
                    
                    continueGame(games[selected]);
                    break;
            case 3:
                    cout << "Goodbye sir! I hope I get high grade :)" << endl; 
                    return 0;
            default:
                    cout << "Invalid choice!" << endl;
                    break;
        }
    }
    
    
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

void continueGame(PegSolitaire& game)
{
    game.printBoard();

    cin.ignore();
    bool isGamePending = false;
    while (isGamePending == false)
    {
        if (game.getPlayer() == 1) // player
        {
            string command;
            cout << "Enter Command:";

            // take whole line
            // used for (SAVE FILE.txt or LOAD FILE.txt)
            getline(cin, command);
            game.setCommand(command);
            isGamePending = game.play(PegSolitaire::Cell(1,1,GAME::BLANK));
        }
        else if (game.getPlayer() == 2) // computer
            isGamePending = game.playGame();  
    }

    game.printBoard();
}


int selectActiveGame(const vector<PegSolitaire> &games)
{
    if (games.size() == 0)
    {
        cerr << "There is no even one game yet" << endl;
        return -1;
    }
    
    int selected = -1;
    int passive_num = 0;
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
            passive_num++;
            cout << "PASSIVE" << endl;
        }
        
    }
    
    if (passive_num == games.size())
    {
        cerr << "There is no active game. " << "First, start a new game." << endl;
        return -1;
    }
    
    while(1)
    {
        cout << "Choice a game:";
        cin >> selected;

        if (isCinFail())
            continue;
        
        if (selected < 0 || selected >= games.size())
        {
            cout << "Invalid index!" << endl;
            continue;
        }
        

        if (games[selected].getIsGameFinish() == false) // if game is active
        {
            cout << "You choice " << selected << ". game" << endl;
            return selected;
        }
        else // if game is passive
            cout << "You can't choise this game. This game is passive" << endl;  
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
