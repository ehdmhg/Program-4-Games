// Program4Games.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Name: Ethan Dang
//Due Date: 2nd April 2023
//Program 4 Games project
#include <iostream>
#include "Craps.h"
#include "Hangman.h"
#include "TicTacToe.h"
#include "BlackJack.h"
using namespace std;

int main()
{
    char user = ' ';
    char user2 = ' ';
    while (toupper(user) != 'Q') { //The loop ends when the user inputs that they want to quit the game. 
        cout << "Games List" << endl;
        cout << "B - Blackjack" << endl;
        cout << "C - Craps" << endl;
        cout << "H - Hangman" << endl;
        cout << "T - TicTacToe" << endl;
        cout << "Q - Quit" << endl;
        cout << "What game would you like to play? ";
        cin >> user;
        if (toupper(user) == 'Q') {
            break;
        }
        else if (toupper(user) == 'B') {//If user's input is B, runs blackjack game program. 
                blackjack();
        }
        else if(toupper(user) == 'C') { //code for CRAPS Game
            bool status = false;
            double amount = 50.00;//sets amount to starting net worth of $50.00.
            double bet = 0.0;
            char goAgain = ' ';
            cout << "WELCOME TO CRAPS!" << endl;
            while (toupper(goAgain) != 'N') { 
                cout << "Your net worth is: $" << setprecision(2) << fixed << amount << ". " << "Please enter your bet: ";
                cin >> bet;
                if (bet > amount) { //Validates that the bet is not higher than the amount or bank the user has
                    cout << "Your net worth is only: $" << setprecision(2) << fixed << amount << ". Please adjust your bet: ";
                    cin >> bet;
                }
                status = playingCraps(); //Sets status to true if the user wins or to false if the user loses 
                                        //based on the completion of the playingCraps() function
                amount = betAmount(amount, bet, status);//Subtracts or adds bet from amount based on if status is true or false. 
                cout << "Would you like to go again? Y or N ";
                cin >> goAgain;
            }
            cout << "Thank you for playing. Your winnings are: " << setprecision(2) << fixed << amount << endl;
        }
        else if (toupper(user) == 'H') {
            while (toupper(user2) != 'N') {
                Hangman();
                cout << "Would you like to play again? ";
                cin >> user2;
            }
        }
        else if (toupper(user) == 'T') {
            vector<vector<char>> board;
            bool status = false;
            char winLoss = ' ';
            char again = ' ';//determines if the user wants to keep playing or not
            int goFirst;//determines if the user or computer goes first
            int spots = 9;//number of positions on the board
            
            while (toupper(again) != 'N') {//until the user wants to quit, TicTacToe keep running
                board = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
                cout << endl;
                cout << "Welcome To TicTacToe!" << endl;
                cout << "Here is the board!: " << endl;
                printBoard(board);
                goFirst = flipCoin();
                while (status != true && spots != 0) {//until the game is decided, the board updates with each move
                    if (goFirst == 0) {
                        makeComputerMove(board);
                        goFirst = 1;
                        spots = spots - 1;
                    }
                    else {
                        makePlayerMove(board);
                        goFirst = 0;
                        spots = spots - 1;
                    }
                    printBoard(board);
                    winLoss = checkStatus(board);
                    if (winLoss == 'C') {
                        cout << "Computer Wins! An incredible game!" << endl;
                        status = true;
                    }
                    else if (winLoss == 'P') {
                        cout << "You Win! Congraulations!" << endl;
                        status = true;
                    }
                }
                if (spots == 0 && status == false) {
                    cout << "Unforunately, the game is a draw." << endl;
                }
                spots = 9; //resets the amount of spots after the game is done.
                cout << "Would you like to play again Y or N?: ";
                cin >> again;
                if (toupper(again) == 'Y') {
                    status = false;
                    spots = 9;

                }
            }

            
        }
        else {
            cout << "Game not Available at this time" << endl;
        }
    }
    if (user == 'Q' || user == 'q') {
        cout << "Have a good day!" << endl;
    }
}