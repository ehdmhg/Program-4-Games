#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
struct Card {
    char suit;
    int value;
};
void shuffleDeck(vector<Card>& deck);
Card dealCard(vector<Card>& deck);
int handTotal(vector<Card>& hand);
void displayHand(vector<Card>& hand);
void blackjack();