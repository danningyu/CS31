//CS31 Project 7
//Danning Yu, 305087992
//Adapted from PigSkeleton code given on CCLE.

#include <iostream>
#include <cassert>
#include <string>
#include "Die.h"
#include "Player.h"
#include "Pig.h"
#include "Board.h"

void clearScreen();
bool handleComputerPlay(cs31::Pig & game);
void display(cs31::Pig & game, std::string message = "", bool checkForGameOver = false);

int main()

{
	using namespace std;
	using namespace cs31;
	Die d; //declaring objects for testing
	Player p;
	Board b;
	Pig game;

	//test code for die
	for (int i = 0; i < 50; i++) {
		d.roll();
		int a = d.getValue();
		assert(a <= 6 && a >= 1);
	}

	//test code for plyaer
	assert(p.getScore() == 0); //starting score is 0
	assert(p.getTotal() == 0); //starting total is 0
	assert(p.roll(2) == 2); //should return 2
	assert(p.getScore() == 2); //current score should be 2
	assert(p.getTotal() == 0); //current total should be 0 because turn not ended
	assert(p.roll(4) == 4); //rolling a 4 should return a 4
	assert(p.getScore() == 6); //total score should be a 6
	assert(p.getTotal() == 0); //total score should still be 0
	p.endTurn();
	assert(p.getTotal() == 6); //total score should be 6 now
	assert(p.getScore() == 0); //score should be 0 (should have been moved to total)
	assert(p.roll(3) == 3); //rolling a 3 should return a 3
	assert(p.getTotal() == 6); //total should be unchanged
	p.endTurn();
	assert(p.getTotal() == 9); //6+3=9
	assert(p.getScore() == 0); //score should be reset
	assert(p.roll(3) == 3);
	assert(p.roll(1) == 1); //should return 1 for rolling a 1
	assert(p.getScore() == 0); //if rolled a 1, score should be set to 0
	p.endTurn();
	assert(p.getTotal() == 9); //score should be unchanged because 1 was rolled

	//test code for board
	assert(b.getComputerScore() == 0); //starting value should be 0
	assert(b.getComputerTotal() == 0); //starting value should be 0
	assert(b.getHumanScore() == 0); //starting value should be 0
	assert(b.getHumanTotal() == 0); //starting value should be 0
	assert(b.getRolledValue() == 0); //starting value should be 0
	assert(b.isGameOver() == false); //game should not be over at first
	assert(b.isHumanTurn() == true); //should start out with human's turn
	assert(b.isHumanWinner() == false); //human should not be winner at first
	b.setRolledValue(4); //set rolled value to 4
	assert(b.getRolledValue() == 4); //rolled value should be 4
	b.setHumanScore(10);
	assert(b.getHumanScore() == 10); //human score should be set to 10
	b.setHumanScore(15);
	assert(b.getHumanScore() == 15); //check if human score is updated	
	b.setHumanTotal(12);
	assert(b.getHumanTotal() == 12); //check if human total is updated	
	b.setComputerScore(5);
	assert(b.getComputerScore() == 0); //computer score should still be 0 because currently not the computer's turn
	b.setComputerTotal(13);
	assert(b.getComputerTotal() == 0); //computer total should still be 0 because currently not the computer's turn
	b.setComputerTurn(); //make it the computer's turn
	b.setComputerScore(6);
	assert(b.getComputerScore() == 6); //computer score should be set to 5
	b.setComputerScore(10);
	assert(b.getComputerScore() == 10); //check if computer score is updated
	b.setComputerTotal(14);
	assert(b.getComputerTotal() == 14); //check if computer total is updated
	b.setHumanScore(16);
	assert(b.getHumanScore() == 15); //human score should stay the same because not the human's turn
	b.setHumanTotal(13);
	assert(b.getHumanTotal() == 12); //human total should stay the same because not the human's turn
	b.setGameOver(true);
	b.setComputerScore(4);
	assert(b.getComputerScore() == 10); //computer score should not be updated because game is over
	b.setComputerTotal(4);
	assert(b.getComputerTotal() == 14); //computer total should not be updated because game is over
	b.setHumanScore(3);
	assert(b.getHumanScore() == 15); //human score should stay the same because game is over
	b.setHumanTotal(3);
	assert(b.getHumanTotal() == 12); //human score should stay the same because game is over

	//test code for pig
	assert(game.determineGameOutcome() == Pig::GAMEOUTCOME::GAMENOTOVER);
	assert(game.getHuman().getScore() == 0); //starting human score should be 0
	assert(game.getHuman().getTotal() == 0); //starting human total should be 0
	assert(game.getComputer().getScore() == 0); //starting computer score should be 0
	assert(game.getComputer().getTotal() == 0); //starting computer total should be 0
	game.humanPlay(2);
	assert(game.getHuman().getScore() == 2); //score should be updated
	assert(game.getHuman().getTotal() == 0); //total should still be 0
	game.humanPlay(3);
	assert(game.getHuman().getScore() == 5); //score should be updated
	game.humanEndTurn();
	assert(game.getHuman().getTotal() == 5); //total should be updated because turn is over
	assert(game.getHuman().getScore() == 0); //score should be reset to 0	
	assert(game.determineGameOutcome() == Pig::GAMEOUTCOME::GAMENOTOVER); //game should not be over yet
	assert(game.isGameOver() == false); //game should not be over yet
	game.computerPlay(4); //repeat the tests above for the computer
	assert(game.getComputer().getScore() == 4); //score should be updated
	assert(game.getComputer().getTotal() == 0); //total should still be 0
	game.computerPlay(5);
	assert(game.getComputer().getScore() == 9); //score should be updated
	game.computerEndTurn();
	assert(game.getComputer().getTotal() == 9); //total should be updated because turn is over
	assert(game.getComputer().getScore() == 0); //score should be reset to 0
	assert(game.determineGameOutcome() == Pig::GAMEOUTCOME::GAMENOTOVER); //game should not be over yet
	assert(game.isGameOver() == false); //game should not be over yet
	game.humanPlay(6);
	game.humanPlay(6);
	game.humanPlay(6);
	game.humanPlay(6);
	game.humanPlay(2);
	assert(game.getHuman().getScore() == 26); //score should be 26 at this point
	assert(game.isGameOver() == false); //game should not be over yet because total was not updated yet
	game.humanEndTurn();
	assert(game.getHuman().getTotal() == 31); //total should be updated because turn is over
	assert(game.determineGameOutcome() == Pig::GAMEOUTCOME::HUMANWONGAME); //human won game because their score is 31
	assert(game.determineGameOutcome() != Pig::GAMEOUTCOME::COMPUTERWONGAME); //computer should not have won game
	assert(game.isGameOver() == true); //game should be over
	game.computerPlay(5); //rolling after game is over...should not change anything
	game.computerPlay(5);
	game.computerPlay(5);
	game.computerPlay(6);
	assert(game.getComputer().getScore() == 0); //score should still be 0 (due to previous reset due to endturn)
	game.computerEndTurn();
	assert(game.getComputer().getTotal() == 9); //total should still be 9
	assert(game.isGameOver() == true); //game should still be over
	assert(game.determineGameOutcome() == Pig::GAMEOUTCOME::HUMANWONGAME); //outcome should not be changed

	//test the computer winning the game
	Pig game1;
	game1.humanPlay(6);
	game1.humanEndTurn();
	game1.computerPlay(6);
	game1.computerPlay(6);
	game1.computerPlay(6);
	game1.computerPlay(6);
	game1.computerPlay(6);
	game1.computerPlay(6);
	assert(game1.isGameOver() == false); //game should not be over yet
	assert(game1.determineGameOutcome() == Pig::GAMEOUTCOME::GAMENOTOVER); //game should not be over yet
	game1.computerEndTurn();
	assert(game1.determineGameOutcome() == Pig::GAMEOUTCOME::COMPUTERWONGAME); //computer should win game

	Pig game2; //now test both computer and player have scores of >=30 - human should win
	game2.humanPlay(6);
	game2.humanPlay(6);
	game2.humanPlay(6);
	game2.humanPlay(6);
	game2.humanPlay(6);
	game2.humanPlay(6);
	assert(game2.isGameOver() == false); //game should not be over yet
	assert(game2.determineGameOutcome() == Pig::GAMEOUTCOME::GAMENOTOVER); //game should not be over yet
	game2.humanEndTurn();
	game2.computerPlay(6);
	game2.computerPlay(6);
	game2.computerPlay(6);
	game2.computerPlay(6);
	game2.computerPlay(6);
	game2.computerPlay(6);
	game2.computerEndTurn();
	assert(game2.isGameOver() == true); //game should not be over now
	assert(game2.determineGameOutcome() == Pig::GAMEOUTCOME::HUMANWONGAME); //human should win game
	cout << "All tests passed!" << endl;
	return 0;
}

bool handleComputerPlay(cs31::Pig & game){
	using namespace std;
	bool result(false);
	if (!game.isGameOver())
	{
		int computer = game.computerPlay();
		cout << "computer rolled:" << computer << endl;
		if (computer == 1)
		{
			result = true;
		}
	}
	return(result);
}

void display(cs31::Pig & game, std::string message, bool checkForGameOver){
	using namespace std;
	// add this if statement...
	if (!game.isGameOver() || game.determineGameOutcome() == cs31::Pig::COMPUTERWONGAME)
	{
		cout << game.display(message) << endl;
	}

	if (checkForGameOver)
	{
		game.isGameOver();
	}
}
///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	COORD upperLeft = { 0, 0 };
	DWORD dwCharsWritten;
	FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
		&dwCharsWritten);
	SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
	using namespace std;
	static const char* term = getenv("TERM");
	if (term == nullptr || strcmp(term, "dumb") == 0)
	{
		cout << endl << endl << endl << endl << endl << endl << endl << endl;;
	}
	else
	{
		static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
		cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
	}
}

#endif