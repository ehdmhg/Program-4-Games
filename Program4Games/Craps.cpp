#include "Craps.h"
double betAmount(double amount, double bet, bool status) { //function returns the amount the user has starting the game, and when leaving the craps game. 
	double netWorth = amount;
	if (status == true) { //if the user won, the netWorth is incremented by the amount the user bet 
		netWorth += bet;
	}
	else if (status == false) {//if the user lost, the netWorth is subtracted by the amount the user lost
		netWorth -= bet;
	}
	return netWorth;
}
bool playingCraps() { //function that runs the CRAPS game. 
	int die1, die2, total, newTotal, point;
	bool winLoss = false;
	srand(time(0)); //srand is for randomizing the dice roll every time it is called. This simplfies the code. 
	die1 = rand() % 6 + 1;//ranges from 1 to 6
	die2 = rand() % 6 + 1;//the range is from 1 to 6
	total = die1 + die2;//the total amount of each die roll
	if (total == 7 || total == 11) { //Following the rules of the CRAPS game, the user wins if the dice roll total is 7 or 11.
		cout << "Your roll was " << die1 << " + " << die2 << " = " << total << endl;
		cout << "You won! Congratulations!" << endl;
		winLoss = true;
		return winLoss; //returns winLoss as true since the user won 
	}
	else if (total == 2 || total == 3 || total == 12) { //Following the rules of the CRAPS game, the user loses
														//if the dice roll is equal to 2, 3, or 12. 
		cout << "Your roll was " << die1 << " + " << die2 << " = " << total << endl;
		cout << "You lost. Good luck next time" << endl;
		winLoss = false;
		return winLoss; //returns winLoss as false since the user lost 
	}
	else { 
		point = total;
		cout << endl;
		cout << "\t" << "Point is " << point << endl;
		die1 = rand() % 6 + 1;
		die2 = rand() % 6 + 1;
		newTotal = die1 + die2;
		cout << "\t" << "You rolled: " << die1 << " + " << die2 << " = " << newTotal << endl;
		while (newTotal != point) { //As long as the total of the dice roll doesn't equal to the point, loop runs 
			die1 = rand() % 6 + 1;
			die2 = rand() % 6 + 1;
			newTotal = die1 + die2;
			cout << "\t" << "You rolled: " << die1 << " + " << die2 << " = " << newTotal << endl;
			if (newTotal == 7) {//if newTotal == 7, the user lost the game
				cout << "\t" << "Sorry, but you lost!" << endl;
				winLoss = false;
				return winLoss;
			}
		}
		cout << "You won! Congratulations!" << endl;
		winLoss = true;
		return winLoss; //returns winLoss as true since the user won
	}
}
