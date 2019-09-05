//
//  Pig.h
//  Pig
//
//

#ifndef PIG_H
#define PIG_H
#include <string>
#include "Player.h"
#include "Board.h"

namespace cs31{
    // CS 31 students have been provided this class to represent
    // a Pig Game.  Each Game is made up of a Board and two Players.
    // CS 31 students need to complete the TODO portions of this class
    class Pig{
    public:
        Pig();
        enum GAMEOUTCOME { HUMANWONGAME, COMPUTERWONGAME, GAMENOTOVER };
        
        // stringify this game by stringifying this game's Board
        std::string display( std::string msg = "" );
        
        // let the human player toss the die, returning the value rolled
        // if a non-zero amount is passed, we are trying to cheat for
        // testing purposes and force a particular rolled value
        int  humanPlay( int amount = 0 );
        // mark that the human's turn has ended either from stopping or rolling a 1
        void humanEndTurn( );
        
        // let the human player toss the die, returning the value rolled
        // if a non-zero amount is passed, we are trying to cheat for
        // testing purposes and force a particular rolled value
        int  computerPlay( int amount = 0 );
        // when keepRolling returns true, the computer will roll again
        bool computerKeepRolling() const;
        // mark that the computer's turn has ended either from stopping or rolling a 1
        void computerEndTurn();
        
        // what is the game's result?
        GAMEOUTCOME  determineGameOutcome( ) const;
        // is the game over?
        bool isGameOver();
		Player getHuman();
		Player getComputer();
    private:
        Player mHuman;                        // this game's Human Player
        Player mComputer;                     // this game's Computer Player
        Board  mBoard;                        // this game's Board        
        const int SCORENECESSARYTOWIN = 30;   // how many points are required to win?
    };    
}
#endif
