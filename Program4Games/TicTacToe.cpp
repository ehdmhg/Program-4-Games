#include "TicTacToe.h"
int flipCoin() {//Determines if the player or computer goes first. 
	srand(time(0));
	return (rand() % 2);
}
bool isOpen(char pos) {//Validates if the position parameter is open
	char checkPos = pos;
	if (checkPos != 'X' && checkPos != 'O') {
		return true;
	}
	else {
		return false;
	}
}
void printBoard(vector<vector<char>> board) {//Prints the board
	for (int r = 0; r < 3; r++) {//This for loop prints the rows of TicTacToe
		for (int c = 0; c < 3; c++) {//the for loop will print out the columns of each row in the TicTacToe board
			cout << setw(3) << board[r][c];
		}
		cout << endl;
	}
}
bool findWinSpot(vector<vector<char>> &board) {//Checks to see if there is a spot the player or computer needs to win, and the computer fills in that spot
	for (int r = 0; r < 3; r++) {//checks each row of the board
		//The if else blocks are for if the Machine or Player needs 1 place to win, the Machine will fill that spot
		if (board[r][0] == board[r][1] && isOpen(board[r][2])) {//if the third column of the row is open, and the first and second column of the row have the same char,
			//the Computer will fill column 3 of the row
			board[r][2] = 'O';
			return true;
		}
		else if (board[r][0] == board[r][2] && isOpen(board[r][1])) {//if the second column of the row is open, and the first and third columns of the row have the same char,
			//the Computer will fill column 2 of the row
			board[r][1] = 'O';
			return true;
		}
		else if (board[r][1] == board[r][2] && isOpen(board[r][0])) {//if the first column of the row is open, and the second and third columns of the row have the same char,
			//the Computer will fill column 1 of the row
			board[r][0] = 'O';
			return true;
		}
	}
	for (int c = 0; c < 3; c++) {//checks each column of the board
		//the if else blocks are for if the Machine or player needs 1 place to win, the Machine will fill that spot. These if-else blocks check the columns of the board
		if (board[0][c] == board[1][c] && isOpen(board[2][c])) {//if the third row of the column is open, and the first and second rows of the column have the same char, 
			//the Computer will fill row 3 of the column
			board[2][c] = 'O';
			return true;
		}
		else if (board[0][c] == board[2][c] && isOpen(board[1][c])) {//If the second row of the column is opne, and the first and third rows of the column have the same char,
			//the computer will fill row 2 of the column
			board[1][c] = 'O';
			return true;
		}
		else if (board[1][c] == board[2][c] && isOpen(board[0][c])) {
			board[0][c] = 'O';
			return true;
		}
	}
}
bool findCenter(vector<vector<char>>& board) {
	if (board[1][1] != 'X' && board[1][1] != 'O') {
		board[1][1] = 'O';
		return true;
	}
	else {
		return false;
	}
}
bool findOppCorner(vector<vector<char>>& board) {//if the player chose a corner, the computer chooses a corner diagnonally across.
	if (board[0][0] == 'X' && isOpen(board[2][2])) {
		board[2][2] = 'O';
		return true;
	}
	else if (board[0][2] == 'X' && isOpen(board[2][0])) {
		board[2][0] = 'O';
		return true;
	}
	else if (board[2][0] == 'X' && isOpen(board[0][2])) {
		board[0][2] = 'O';
		return true;
	}
	else if (board[2][2] == 'X' && isOpen(board[0][0])) {
		board[0][0] = 'O';
		return true;
	}
	else {
		return false;
	}
}
bool findCorner(vector<vector<char>>& board) {//finds an available corner to pick
	if (isOpen(board[0][0]) == true) {
		board[0][0] = 'O';
		return true;
	}
	else if (isOpen(board[0][2]) == true) {
		board[0][2] = 'O';
		return true;
	}
	else if (isOpen(board[2][0]) == true) {
		board[2][0] = 'O';
		return true;
	}
	else if (isOpen(board[2][2]) == true) {
		board[2][2] = 'O';
		return true;
	}
	else {
		return false;
	}
}
bool findOpen(vector<vector<char>>& board) {//Finds the first available space to pick
	bool found = false;
	while (found == false) {
		for (int r = 0; r < 3; r++) {
			for (int c = 0; c < 3; c++) {
				if (isOpen(board[r][c]) == true) {
					board[r][c] = 'O';
					found = true;
				}
			}
		}
	}
	if (found == true) {
		return true;
	}
	else if (found == false) {
		return false;
	}
}
void makeComputerMove(vector<vector<char>>& board) {
	cout << "Computer's Move: \n\n";
	if (findWinSpot(board) == true) {
		return;
	}
	else if (findCenter(board) == true) {
		return;
	}
	else if (findOppCorner(board) == true) {
		return;
	}
	else if (findCorner(board) == true) {
		return;
	}
	else if (findOpen(board) == true) {
		return;
	}
	else {
		cout << "Draw" << endl;
	}
}
void makePlayerMove(vector<vector<char>>& board) {//Asks the user what move they would like to make
	char pos;
	bool posTaken = false;
	bool playerMove = false;
	cout << "Player's move. What position would you like to play?  ";
	cin >> pos;
	cout << endl;
	while (playerMove != true) {//Checks each row and column to see if it is open. If the position is open and the user picked the position, fill that position with 'X'.
		if (posTaken == false) {
			for (int r = 0; r < 3; r++) {
				if (pos == board[r][0] && isOpen(board[r][0])) {
					board[r][0] = 'X';
					playerMove = true;
				}
				else if (pos == board[r][1] && isOpen(board[r][1])) {
					board[r][1] = 'X';
					playerMove = true;
				}
				else if (pos == board[r][2] && isOpen(board[r][2])) {
					board[r][2] = 'X';
					playerMove = true;
				}
				else {
					posTaken = true;
				}
			}
			for (int c = 0; c < 3; c++) {
				if (pos == board[0][c] && isOpen(board[0][c])) {
					board[0][c] = 'X';
					playerMove = true;
				}
				else if (pos == board[1][c] && isOpen(board[1][c])) {
					board[1][c] = 'X';
					playerMove = true;
				}
				else if (pos == board[2][c] && isOpen(board[2][c])) {
					board[2][c] = 'X';
					playerMove = true;
				}
				else {
					posTaken = true;
				}
			}
		}
		else if (posTaken == true) {
			cout << "That position has already been filled. Please pick another:  ";
			cin >> pos;
			posTaken = false;
		}
	}
}
char checkStatus(vector<vector<char>>& board) {
	bool computer = false;//Status of Computer's victory is set to false
	bool player = false;//Status of Player's victory is set to false
	char status = ' ';//Determines if player or computer won;
	for (int r = 0; r < 3; r++) {//Checks if the computer or player won horziontally
		if (board[r][0] == 'O' && board[r][0] == board[r][1] && board[r][1] == board[r][2]) {//if the row is comprised of 'O', the computer won and breaks the for loop
			computer = true;
			break;
		}
		else if (board[r][0] == 'X' && board[r][0] == board[r][1] && board[r][1] == board[r][2]) {//if the row is comprised of 'X', then the player won and breaks the for loop 
			player = true;
			break;
		}
	}
	for (int c = 0; c < 3; c++) {//Checks if the computer or player won vertically;
		if (board[0][c] == 'O' && board[0][c] == board[1][c] && board[1][c] == board[2][c]) {
			computer = true;
			break;
		}
		else if (board[0][c] == 'X' && board[0][c] == board[1][c] && board[1][c] == board[2][c]) {
			player = true;
			break;
		}
	}
	//The if else blocks check to see if the player or computer won diagonally
	if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
		computer = true;
	}
	else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
		player = true;
	}
	else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
		computer = true;
	}
	else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
		player = true;
	}
	if (computer == true) {//If the computer won, status is set to C so the program can print that the computer won
		status = 'C';
		return status;
	}
	else if (player == true) {//If the user won, status is set to P so the program can print that the user won
		status = 'P';
		return status;
	}
}