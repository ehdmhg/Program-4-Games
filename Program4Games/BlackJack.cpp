#include "BlackJack.h"

//Function to shuffle the deck of cards 
//source https://en.cppreference.com/w/cpp/algorithm/random_shuffle for the randon_shuffle functions
void shuffleDeck(vector<Card>& deck) {
    srand(time(0));
    random_shuffle(deck.begin(), deck.end());
}

//using the struct to deal the shuffle cards before looking at the the back of the vector to display the card
Card dealCard(vector<Card>& deck) {
    Card card = deck.back();
    deck.pop_back();
    return card;
}

// Function to calculate the total value of a hand
int handTotal(vector<Card>& hand) {
    int total = 0;
    int numAces = 0;
    //calulating the value of the hand and incrementing the number of aces of the "board"
    for (int i = 0; i < hand.size(); i++) {
        total += hand[i].value;
        if (hand[i].value == 11) {
            numAces++;
        }
    }
    //If total is greater than 21, the program automatically sets the value of the ace to 1 if an ace(s) are present in the total
    while (total > 21 && numAces > 0) {
        total -= 10;
        numAces--;
    }
    return total;
}

// Function to display the cards in a hand
//source https://stackoverflow.com/questions/9158150/colored-output-in-c for the color output
//source: Jacob Pham helped me output special characters for the program. 
void displayHand(vector<Card>& hand) {
    for (int i = 0; i < hand.size(); i++) {
        //checkingg if the symbol is any of these and making them red 
        if (hand[i].suit == '\x03' || hand[i].suit == '\x04') {
            if (hand[i].value == 11) {
                hand[i].value = 10;
                cout << "\033[31m" << hand[i].suit << " " << "J" << "\033[0m" << endl;
            }
            else if (hand[i].value == 12) {
                hand[i].value = 10;
                cout << "\033[31m" << hand[i].suit << " " << "Q" << "\033[0m" << endl;
            }
            else if (hand[i].value == 13) {
                hand[i].value = 10;
                cout << "\033[31m" << hand[i].suit << " " << "K" << "\033[0m" << endl;
            }
            else if (hand[i].value == 14) {
                hand[i].value = 11;
                cout << "\033[31m" << hand[i].suit << " " << "A" << "\033[0m" << endl;
            }
            else {
                cout << "\033[31m" << hand[i].suit << " " << hand[i].value << "\033[0m" << endl;
            }

        }
        // else print it normally 
        else {
            if (hand[i].value == 11) {
                hand[i].value = 10;
                cout << "\033[0m" << hand[i].suit << " " << "J" << endl;
            }
            else if (hand[i].value == 12) {
                hand[i].value = 10;
                cout << "\033[0m" << hand[i].suit << " " << "Q" << endl;
            }
            else if (hand[i].value == 13) {
                hand[i].value = 10;
                cout << "\033[0m" << hand[i].suit << " " << "K" << endl;
            }
            else if (hand[i].value == 14) {
                hand[i].value = 11;
                cout << "\033[0m" << hand[i].suit << " " << "A" << endl;
            }
            else {
                cout << "\033[0m" << hand[i].suit << " " << hand[i].value << endl;
            }

        }
    }
}
//Source: Jacob Pham helped me with setting special characters for C++ to hearts,diamonds,clubs, and spades
void blackjack() {
    char user = ' ';
    ///creating a vector using the struct
    vector<Card> deck;
    //the creating the deck of cards
    char suits[] = { '\x06','\x05', '\x04', '\x03' };//sets the char suits to the 4 suites of cards, spaes, hearts, diamonds, and clubs
    int values[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            Card card;
            card.suit = suits[i];
            card.value = values[j];
            deck.push_back(card);
        }
    }
    //the start of the game 
    cout << "WELCOME TO BLACKJACK" << endl;
    //using the shuffle card function
    shuffleDeck(deck);
    //play the game till the user says N
    while (toupper(user) != 'N') {
        vector<Card> playerHand;//creates the Player's hand using Card vector
        vector<Card> computerHand;//creates the Computer's hand using Card vector
        //adds cards to the user hands and the computer's hands or totals by using then dealCard function and the shuffled deck
        playerHand.push_back(dealCard(deck));
        computerHand.push_back(dealCard(deck));
        playerHand.push_back(dealCard(deck));
        computerHand.push_back(dealCard(deck));
        //loops till the user syas no or they past 21
        while (true) {
            cout << endl << "The Player hand is the following: " << endl;
            //fucntion to display the hand of the user 
            displayHand(playerHand);
            //creating a running total for the user via handTotal fucntion
            int total = handTotal(playerHand);
            //printing the total of the hand at the monment 
            cout << "Total: " << total << endl;
            //If total is greater than 21, the loop breaks and the game is over.
            if (total > 21) {
                break;
            }
            //asking the user if they want another card. If user inputs 'y', loops back to the top and displays the user's hand again.
            //If the user inputs 'n', the loops ends and goes to the next loop
            char choice;
            cout << "Do you want another card? (y/n) ";
            cin >> choice;
            if (choice == 'y') {
                playerHand.push_back(dealCard(deck));
            }
            else {
                break;
            }

        }
        //Source: Jacob Pham helped me with the formatting of the block of code.
        //Checks that the user's total has not gone over or is equal to 21
        int total = handTotal(playerHand);
        if (total <= 21) {
            cout << endl << "The Computer hand is the following: " << endl;
            //Displays the Computer's hand 
            displayHand(computerHand);
            //Setting the total of the Comuuter's hand at the moment 
            int computerTotal = handTotal(computerHand);
            //Prints the total of the Computer's hand at the monment 
            cout << "Total: " << computerTotal << endl;
            //Loops till the computer's hand or total is greater than 17. If total is greater or equal to 17, breaks out of the while loop
            while (handTotal(computerHand) <= 17) {
                computerHand.push_back(dealCard(deck));
                cout << endl << "The Computer hand is the following: " << endl;
                //fucntion to display the hand of the user 
                displayHand(computerHand);
                //printing the total of the hand at the monment 
                computerTotal = handTotal(computerHand);
                //printing the total of the hand at the monment 
                cout << "Total: " << computerTotal << endl;
                //Loops till the computer had is greater than 17 and if its not then  loop
                //if the Computer's total si greater than 21, the loop ends.
                if (computerTotal > 21) {
                    cout << endl << "The computer has gone over 21. PLAYER WINS." << endl;
                    break;
                }
            }
        }
        else if (total > 21) {
            cout << endl << "Bust! PLAYER has gone over 21. COMPUTERS WINS" << endl;
            //asking them if they want to play again
            cout << endl << endl << "Would You like to play again: (Y/N)  ";
            cin >> user;
            // they choose to playing shoot to the top
            if (toupper(user) == 'Y') {
                continue;
            }
            // they choose no then leave the game back to the main menu 
            else if (toupper(user) == 'N') {
                break;
            }
        }

        //Comparing the total of the Computer and Player's hand to make sure both have not gone over 21
        int computerTotal = handTotal(computerHand);
        //if the computer's Total is less than 21, check if the total is greater than player's total. If Computer's hand is greater than the user's, the computer wins based on the rules of blackjack 
        if (computerTotal <= 21) {
            if (computerTotal > total) {
                cout << endl << "COMPUTER WINS" << endl;
            }
        }
        //if the player's total is less than 21, check if the total is greater than computer's hand. If the player's hand is greater than the computer's, the player wins based on the rules of blackjack
        if (total <= 21) {
            if (computerTotal < total) {
                cout << endl << "PLAYER WINS" << endl;
            }
        }
        //checks if the computer and the player have equal totals and/or hands. If the hands are equal, the program displays that the game is a tie. 
        if (computerTotal == total) {
            cout << endl << "PLAYER AND COMPUTER HAVE TIED" << endl;
        }

        //asking the user if they would like to play again
        cout << endl << endl << "Would You like to play again: (Y/N)  ";
        cin >> user;
        // they choose to playing shoot to the top
        if (toupper(user) == 'Y') {
            continue;
        }
        // they choose no then leave the game and go back to the main menu 
        else if (toupper(user) == 'N') {
            break;
        }

    }

}