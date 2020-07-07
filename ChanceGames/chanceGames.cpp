// chanceGames.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "aDie.h"
#include "aCoin.h"
#include "aDeckOfCards.h"
#include "randomBase.h"
void dice(int gameType);
void coin(int gameType);
void deck();
using namespace std;

int main()
{
	int userSelection;

	/********************************* Menu *********************************/
	cout << "Menu:" << endl;
	cout << "1 : dice roll" << endl;
	cout << "2 : coin flip" << endl;
	cout << "3 : deck pull" << endl;
	cout << "4 : quit" << endl;
	cin >> userSelection;
	cout << endl;

	switch (userSelection)
	{
	case 1:
		dice(userSelection);
		break;
	case 2:
		coin(userSelection);
		break;
	case 3:
		deck();
		break;
	case 4:
		return 0;
	default:
		cout << "Selection not valid, try again" << endl;
		main();
		break;
	}
}


void dice(int gameType)
{
	unsigned int numberOfRolls;
	unsigned int seed;
	aDie objDice1, objDice2; //creates two objects dice1 and dice2 containing seed(int) and roll()
	vector<int> rollList1(7, 0); //creates a vector of length 7 filled with the value 0
	vector<int> rollList2(7, 0); //creates a vector of length 7 filled with the value 0
	vector<int> rollSum(13, 0); //creates a vector of length 13 filled with the value 0
	vector<int> rollProduct(37, 0); //creates a vector of length 37 filled with the value 0
	int temp1, temp2;

	/********************************* Grabs user input *********************************/
	cout << "This is a dice rolling simulator" << endl << endl;
	do //Runs once and then loops if an invalid entry occurs
	{
		cout << "Please enter number of rolls (0 - 65535): ";
		cin >> numberOfRolls;
	} while (numberOfRolls > 65535 || numberOfRolls < 0);

	do //Runs once and then loops if an invalid entry occurs
	{
		cout << "Please enter a seed (0 - 65535): ";
		cin >> seed;
	} while (seed > 65535 || seed < 0);
	cout << endl;

	objDice1.seed(seed); //defines the seed to be used for the dice

	/******************************* Rolls dice and adds value to list *******************************/
	for (size_t i = 1; i <= numberOfRolls; i++)
	{
		temp1 = objDice1;
		temp2 = objDice2;
		rollSum[temp1 + temp2]++;
		rollProduct[temp1 * temp2]++;
		rollList1[temp1]++;
		rollList2[temp2]++;
	}

	/*********************************** Prints Dice 1 Results ***********************************/
	cout << "|****** Rolls for Dice 1 ******|" << endl;
	for (size_t i = 1; i <= 6; i++)
	{
		cout << i << " ---- " << rollList1[i] << endl;
	}

	/*********************************** Prints Dice 2 Results ***********************************/
	cout << endl << "|****** Rolls for Dice 2 ******|" << endl;
	for (size_t i = 1; i <= 6; i++)
	{
		cout << i << " ---- " << rollList2[i] << endl;
	}

	/*********************************** Prints Dice 1 Histogram ***********************************/
	cout << endl << "|****** Histogram for Dice 1 ******|";
	objDice1.calculate(rollList1);
	objDice1.print(rollList1, gameType);

	/*********************************** Prints Dice 2 Histogram ***********************************/
	cout << endl << "|****** Histogram for Dice 2 ******|";
	objDice1.calculate(rollList2);
	objDice1.print(rollList2, gameType);

	/*********************************** Prints Sum Histogram ***********************************/
	cout << endl << "|****** Histogram for Sum of Rolls ******|";
	objDice1.calculate(rollSum);
	objDice1.print(rollSum, gameType);

	/*********************************** Prints Product Histogram ***********************************/
	cout << endl << "|****** Histogram for Product of Rolls ******|";
	objDice1.calculate(rollProduct);
	objDice1.print(rollProduct, gameType);

	system("Pause"); //Requires key press to close program
	cout << endl;
	main();
}


void coin(int gameType)
{
	unsigned int numberOfFlips;
	unsigned int seed;
	aCoin objCoin;
	vector<int> flipList(3, 0); //creates a vector of length 3 filled with the value 0
	cout << "This is a coin flipping simulator" << endl << endl;
	do //Runs once and then loops if an invalid entry occurs
	{
		cout << "Please enter number of flips (0 - 65535): ";
		cin >> numberOfFlips;
	} while (numberOfFlips > 65535 || numberOfFlips < 0);

	do //Runs once and then loops if an invalid entry occurs
	{
		cout << "Please enter a seed (0 - 65535): ";
		cin >> seed;
	} while (seed > 65535 || seed < 0);
	cout << endl;

	objCoin.seed(seed); //defines the seed to be used for the dice

	/******************************* Flips coin and adds value to list *******************************/
	for (size_t i = 1; i <= numberOfFlips; i++)
	{
		int result = objCoin;
		if (result == 1)
			flipList[1]++;
		else
			flipList[2]++;
	}

	/*********************************** Prints coin Results ***********************************/
	cout << "|****** Flips for Coin ******|" << endl;
	cout << "H ---- " << flipList[1] << endl;
	cout << "T ---- " << flipList[2] << endl;

	/*********************************** Prints Coin Histogram ***********************************/
	cout << endl << "|****** Histogram for Coin ******|";
	objCoin.calculate(flipList);
	objCoin.print(flipList, gameType);

	system("Pause"); //Requires key press to close program
	cout << endl;
	main();
}

void deck()
{
	int N = 5;
	aDeckOfCards deck; //creates object of a deck of cards
	deck.shuffle(); //shuffles the deck created

	/*********************************** Deal Out Hands ***********************************/
	vector <string> hand1 = deck.drawWithoutReplacement(N);
	vector <string> hand2 = deck.drawWithoutReplacement(N);
	vector <string> hand3 = deck.drawWithoutReplacement(N);
	vector <string> hand4 = deck.drawWithoutReplacement(N);

	//cout << "|****** Deck ******|" << endl;
	//decks.PrintDeck();

	/*********************************** Prints Hands ***********************************/
	cout << "|****** Hand 1 ******|" << endl;
	deck.PrintHand(hand1);
	cout << endl << "|****** Hand 2 ******|" << endl;
	deck.PrintHand(hand2);
	cout << endl << "|****** Hand 3 ******|" << endl;
	deck.PrintHand(hand3);
	cout << endl << "|****** Hand 4 ******|" << endl;
	deck.PrintHand(hand4);

	system("Pause"); //Requires key press to close program
	cout << endl;
	main();
}