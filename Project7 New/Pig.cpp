#include "Pig.h"
#include <iostream>

namespace cs31{
    Pig::Pig() {      
    }   
    // stringify this Game by stringifying this Game's Board
    std::string Pig::display( std::string msg )
    {
        using namespace std;
        std::string s = mBoard.display();
        s = s + msg;
        
        if (isGameOver())
        {
            if (determineGameOutcome() == HUMANWONGAME)
            {
                s = s + "\n\t\tyou won Pig!\n";
            }
            else
            {
                s = s + "\n\t\tyou lost Pig!\n";
            }
        }
        return( s );
    }
    
    // TODO: let the human player play
    // when the amount is zero, the Die should be rolled for random play
    // when the amount is not zero, we are trying to cheat for testing
    // purposes.  in that case, this method should force a specific roll
    // amount.
    // once you have a rolled amount, inform the board that it is now
    // the human's turn, set the board's rolled value and update the board's
    // human score accordingly
    int Pig::humanPlay(int amount)    {
		int temp = 0;
		if (amount != 0) {
			temp = amount;
	   }
		else {
			temp = mHuman.roll();
		}
		//temp is now set to the rolled value or forced value
		mBoard.setHumanTurn();
		if (amount != 0) {
			mHuman.roll(temp);
		}
		mBoard.setHumanTurn();
		mBoard.setRolledValue(temp);
		mBoard.setHumanScore(temp); //update human score
		return temp;
    }
    // inform the human Player that their turn has ended
    // update the board's human total
    void Pig::humanEndTurn(){		
		mHuman.endTurn();
		mBoard.setHumanTotal(mHuman.getTotal()); //divide by 2? Suspect
        
    }
    
    // TODO: let the computer player play
    // when the amount is zero, the Die should be rolled for random play
    // when the amount is not zero, we are trying to cheat for testing
    // purposes.  in that case, this method should force a specific roll
    // amount.
    // once you have a rolled amount, inform the board that it is now
    // the computer's turn, set the board's rolled value and update the board's
    // computer score accordingly
    int Pig::computerPlay(int amount) {
		int temp = 0;
		if (determineGameOutcome() != GAMEOUTCOME::HUMANWONGAME) {			
			if (amount != 0) {
				temp = amount;
			}
			else {
				temp = mComputer.roll(); //roll called once
			}
			//temp is now set to the rolled value
			mBoard.setComputerTurn();
			if (amount != 0) {
				mComputer.roll(temp);
			} //roll called again - problem!
			mBoard.setComputerTurn();
			mBoard.setRolledValue(temp);
			mBoard.setComputerScore(temp); //update computer score
		}
		return temp;
    }
    
    // when keeprolling returns true, the computer will keep rolling
    // this method implements a 60% chance to keep rolling...
    // unless the score plus the existing total >= SCORENECESSARYTOWIN
    bool Pig::computerKeepRolling() const    {
        bool result( false );
        Die d( 5 );
        d.roll();
        if (d.getValue() >= 3)
        {
            result = true;
        }
        if (mComputer.getScore() + mComputer.getTotal() >= SCORENECESSARYTOWIN)
        {
            // stop...
            result = false;
        }
        return( result );
    }
    
    // inform the computer Player that their turn has ended
    // update the board's computer total
    void Pig::computerEndTurn()   {
        mComputer.endTurn();
        mBoard.setComputerTotal( mComputer.getTotal() );
    }
    
    // TODO: determine the game outcome at this moment
    Pig::GAMEOUTCOME Pig::determineGameOutcome( ) const {
        GAMEOUTCOME result = GAMEOUTCOME::GAMENOTOVER;
		if (mHuman.getTotal() >= SCORENECESSARYTOWIN) {
			result = GAMEOUTCOME::HUMANWONGAME;
		}
		if (result != HUMANWONGAME && mComputer.getTotal() >= SCORENECESSARYTOWIN) {
			result = GAMEOUTCOME::COMPUTERWONGAME;
		}
		return result;
    }
    
    // TODO: determine if the game is over
    // if it has, return true and inform the board that the game is over and
    // inform the board that the Human won or the Computer won, accordingly
    bool Pig::isGameOver(){
		if(mHuman.getTotal() >= 30) {
			return true;
	   }
		if(mComputer.getTotal() >= 30) {
			return true;
		}
		return false; //if neither player won game
    }
	Player Pig::getHuman() { //use this function in main() only to debug
		return mHuman;
	}
	Player Pig::getComputer() { //use this function in main() only to debug
		return mComputer;
	}
}