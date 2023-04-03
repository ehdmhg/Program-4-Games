#include "Hangman.h"
void Hangman() {
	ifstream inFile;
	inFile.open("words.txt"); //opens the text file that contains the word bank the program will pick from
	if (!inFile.is_open()) { //Validates that the program can open the text file. 
		cout << "File did not open" << endl;
		exit(0);
	}
	string word;				//variable used to hold each word in text file from words.txt
	int numGuesses;				//variable used to hold amount of guesses allowed. The number of guesses should be equal to the length of the word. 
	char guess = ' ';			//variable used to hold user's guess
	vector<string> inputList;	//vector used to hold all the words from the text file
	int randomPick;				//variable used to pick a random word based on the 6,000+ words in the text file
	srand(time(0));
	string hidden = "_";		//string to replace every char from word chosen with _
	string hiddenWord;			//string to hold the hidden word chosen
	bool foundLetter = false;	//bool variable used to see if the user's guess is found in the chosen word
	bool userStatus = false;	//bool variable used to see if user won or lost the game.  
	int index = 0;				//checks each index of the word chosen to see if there is a match between the user's guess and the word chosen.
	while (inFile >> word) { //while loop to continue inputting words into InputList until eof or 
							//text file contains non-string.
		inputList.push_back(word);
	}
	randomPick = rand() % (inputList.size());//sets randomPick to be a random number or position from inputList
	cout << "Welcome to HANGMAN!! Your word is ";
	for (int i = 0; i < inputList[randomPick].size(); i++) {//For loop appends "_"  to hiddenWord so hiddenWord is 
															//equal to the length of word chosen
		hiddenWord = hiddenWord + hidden;
	}
	numGuesses = inputList[randomPick].length();//sets numGuesses equal to the length of random word chosen from the text file. 
	cout << hiddenWord << endl;
	cout << "You have " << numGuesses << " guesses to start with! Good luck!" << endl;
	//cout << inputList[randomPick] << endl;
	while (numGuesses != 0 && userStatus != true) {//The function/Hangman game will end if user has no more guesses or if the user has won the game. 
		cout << "Enter your guess: ";
		cin >> guess;
		//while loop block took inspiration from source: https://github.com/ankitgoel2001/Hangman/blob/master/Hangman.cpp
		while (index < inputList[randomPick].length()) {//Checks to see if the chosen word contains the letter the user chose. 
														//The program will not subtract from the remaining number of guesses if guess is correct
			if (guess == inputList[randomPick].at(index)) {
					hiddenWord[index] = guess;
					cout << "Nice guess! You have " << numGuesses << " guesses remaining. Your current word is " << hiddenWord << endl;
					cout << endl;
					foundLetter = true;//sets foundLetter to true since letter was found.
			}
			index++;
		}
		index = 0;//resets index for different letters. 

		if (foundLetter== false){//if user's input was not found in chosen word, the program outputs invalid guess and subtracts a guess
			numGuesses = numGuesses - 1;
			cout << "Sorry! The letter is not in the word. You have " << numGuesses << " guesses remaining. Your current word is " << hiddenWord << endl;
			cout << endl;
		}
		
		for(int i = 0; i < hiddenWord.length(); i++) {//checks to see if the hidden word is completely filled with letters or is still hidden
			if (hiddenWord.at(i) == '_') {//if the loop finds a single case of '_', then that means the user has won fully causing the break out of the for loop
				userStatus = false;
				break;
			}
			else{//if the loop finds no case of '_', then that means the user has filled out all the words and has won the game. 
				userStatus = true;
			}
		} 
		foundLetter = false;//resets the variable to check different letters. 
	}
	if (userStatus == true) {//Prints a victory message. 
		cout << "Congraulations! You WIN!! The word was " << inputList[randomPick] << endl;
	}
	else if (userStatus == false) {//Prints a defeat message. 
		cout << "Sorry. You ran out of guesses. The word chose was " << inputList[randomPick] << endl;
	}

	inFile.close();
}