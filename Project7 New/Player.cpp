#include "Player.h"
#include <iostream>

namespace cs31{
    
    Player::Player() : mDie( 6 ), mScore( 0 ), mTotal( 0 ){ //6 sided die, start with 0 score, 0 total       
    }
    
    // TODO: roll the die and adjust the score for the current round
    // accordingly
    // when the amount is zero, the Die should be rolled for random play
    // when the amount is not zero, we are trying to cheat for testing
    // purposes.  in that case, this method should force a specific roll
    // amount.
    int Player::roll(int amount){
		using namespace std;
		int num = 0;
		if (amount == 0) { //random roll
			mDie.roll();
			num = mDie.getValue();
		}
		else
			num = amount; //cheated roll
		if (num == 1) {
			mScore = 0; //no score received
		}
		else {
			mScore = mScore + num; //update score
		}
		 // cerr << "Current score is " << mScore << endl;
		return num;
    }
    
    // TODO: add the current score into the running total since the turn ended
    //       reset the current score to 0 for the next round of play
    void Player::endTurn(){
		using namespace std;
		mTotal = mTotal + mScore;
		 // cerr << "Current total is" << mTotal << endl;
		mScore = 0;
    }
    int Player::getTotal( ) const {
		return mTotal;
    }
    int  Player::getScore( ) const {
		return mScore;
    }
}