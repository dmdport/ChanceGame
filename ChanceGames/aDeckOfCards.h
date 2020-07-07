#ifndef ADECKOFCARDS_H
#define ADECKOFCARDS_H
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;
class aDeckOfCards
{
public:
	aDeckOfCards(); //creats the deck of cards
	void shuffle(); //allows for the deck to be shuffled
	operator string(); //returns aCard()
	string aCard(); //allows 1 card to be drawn
	vector<string> drawWithoutReplacement(int); //draw cards withoupt replacement
	vector<string> drawWithReplacement(int); //draw cards with replacement
	void PrintDeck() const; //prints out the whole deck
	void PrintHand(vector<string> hand) const; //prints out the hand
private:
	string deck[52]; //sets up an array of strings with a length of 52
	int position; //used for position to pull from
};
#endif
