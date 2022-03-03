#include <iostream>
#include <string>
#include <vector>
#include "BoardGame2d.h"
#include "PegSolitaire.h"
#include "EightPuzzle.h"
#include "Klotski.h"

using namespace std;
using namespace HW05_AysegulAydogan;

// take 2 objects from each class and play them
void playGamesInVector();

void testBoardGame2dFunctions(BoardGame2d *game);

int main()
{   
    // uncomment this for testing games in vector
    playGamesInVector();

    // uncomment this for testing pegSolitaire functions
    // testBoardGame2dFunctions(new PegSolitaire());

    // uncomment this for testing eightPuzzle functions
    // testBoardGame2dFunctions(new EightPuzzle());

    // uncomment this for testing klotski functions
    // testBoardGame2dFunctions(new Klotski());

}

void playGamesInVector()
{
    cout << "****************************************" << endl;
    cout << "Welcome to 6 game in a row test!" << endl;
    cout << "Each game will appear. Order is: Peg - Peg - EightPuzzle - EightPuzzle - Klotski - Klotski" << endl;
    cout << "****************************************" << endl;
    vector<BoardGame2d *> games = {new PegSolitaire, new PegSolitaire, new EightPuzzle(), new EightPuzzle(), new Klotski(), new Klotski()};
    BoardGame2d::playVector(games);

}

void testBoardGame2dFunctions(BoardGame2d *game)
{
    cout << "****************************************" << endl;
    cout << "Welcome to " << game->getName() << " test!" << endl;
    cout << "****************************************" << endl;

    cout << "Test board score function" << endl;
    cout << "Expected: -1 (since my boardScore functions returns -1 if game is not finished)" << endl;
    cout << "Actual: " << game->boardScore() << endl;
    cout << endl;

    cout << "Test end game function" << endl;
    cout << "Expected: 0 (false) (since my endGame functions returns false if game is not finished)" << endl;
    cout << "Actual: " << game->endGame() << endl;
    cout << endl;

    cout << "Test print function" << endl;
    cout << "This test will clear terminal window. So when you press any key. It will executed" << endl;
    int garbage;
    cin >> garbage;
    game->print();
    cout << endl;

    cout << "Test overloaded << operator function" << endl;
    cout << "This test will clear terminal window. So when you press any key. It will executed" << endl;
    cin >> garbage;
    cout << game << endl;
    cout << endl;

    cout << "Test print finish message function" << endl;
    cout << "This function is different for all games." << endl;
    cout << "Expected: You won message!" << endl;
    cout << "Actual: "; game->printFinishMessage(); cout << endl;

    cout << "I will not test playUser(command), playUser(), playAuto(), playAutoAll() functions" << endl;
    cout << "Because they can easily tested in playVector testing function" << endl;
    cout << endl;

    cout << "Thanks for using this test" << endl;
    cout << "****************************************" << endl;
    cout << "Have a good day sir!" << endl;
    cout << "****************************************" << endl;

}