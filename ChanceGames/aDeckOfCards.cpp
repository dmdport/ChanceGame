#include "aDeckOfCards.h"

aDeckOfCards::aDeckOfCards() //Constructor that generates a deck of cards without jokers
{
	int k = 0;
	string faces[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	string suits[4] = { "H", "D", "C", "S" };
	for (size_t i = 0; i < sizeof(faces) / sizeof(faces[0]); i++)
	{
		for (size_t j = 0; j < sizeof(suits) / sizeof(suits[0]); j++)
		{
			deck[k] = faces[i] + "-" + suits[j];
			k++;
		}
	}
	position = 0;
	srand(time(0));
}

void aDeckOfCards::shuffle() //shuffles the deck by swapping random positions of the deck 100 times
{
	for (size_t i = 0; i <= 100; i++) //loops 100 times, swapping positions of deck array with each loop
	{
		int position1 = rand() % 52;
		int position2 = rand() % 52;
		string temp1 = deck[position1];
		string temp2 = deck[position2];
		deck[position1] = temp2;
		deck[position2] = temp1;
	}
	position = 0;
}

aDeckOfCards::operator string() //converstion operator returing aCard()
{
	return aDeckOfCards::aCard();
}

string aDeckOfCards::aCard() //allows only 1 card to be returned
{
	shuffle();
	position++;
	return deck[position];
}

vector<string> aDeckOfCards::drawWithoutReplacement(int number) //without replacement
{
	vector<string> hand;
	int loop = position;
	for (int i = loop; i <= loop + number; i++) //loops through dealing out a variable amount of cards
	{
		if (i >= 52) //checks to make sure cards still exist in the deck
		{
			cout << "****Out of cards****" << endl;
			break;
		}
		string temp1 = deck[i];
		hand.push_back(temp1);
		position++;
	}
	return hand;
}

vector<string> aDeckOfCards::drawWithReplacement(int number) //with replacement
{
	vector<string> hand;
	for (int i = 1; i <= number; i++)
	{
		int random = rand() % 52;
		string temp1 = deck[random];
		hand.push_back(temp1);
	}
	return hand;
}

void aDeckOfCards::PrintDeck() const //prints out the deck of cards, used for testing
{
	for (size_t i = 0; i < sizeof(deck) / sizeof(deck[0]); i++)
	{
		cout << deck[i] << " ";
	}
	cout << endl;
}

void aDeckOfCards::PrintHand(vector<string> hand) const //prints out the deck of cards
{
	for (int i = 1; i <= hand.size() - 1; i++)
	{
		cout << hand[i] << " ";
	}
	cout << endl << endl;
}