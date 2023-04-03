#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;
int flipCoin();
bool isOpen(char pos);
void printBoard(vector<vector<char>> board);
bool findWinSpot(vector<vector<char>> &board);
bool findCenter(vector<vector<char>>& board);
bool findOppCorner(vector<vector<char>>& board);
bool findCorner(vector<vector<char>>& board);
bool findOpen(vector<vector<char>>& board);
void makeComputerMove(vector<vector<char>>& board);
void makePlayerMove(vector<vector<char>>& board);
char checkStatus(vector<vector<char>>& board);