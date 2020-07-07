#include "histogramBase.h"

void histogramBase::calculate(vector<int> vect) //accepts a vector then calculates the value for each X for the histogram. Must be run before print
{
	double largest = *max_element(vect.begin(), vect.end());
	if (largest > 60) //Used when vector value is greater than 60
	{
		valueOfX = largest / 60;
		valueOfX = ceil(valueOfX);
	}
	else //used when vector value is less than 60
		valueOfX = 1;
}

void histogramBase::print(vector<int> vect, int gameType) //accepts a vector and then displays the data in form of a histogram
{
	for (int i = 1; i <= vect.size() - 1; i++) //loops through each position of the vector
	{
		cout << endl;
		printedX = vect[i] / valueOfX; //calculates amount of X's to print
		if (gameType == 1)
			cout << i << " ";
		else if (gameType == 2)
		{
			if (i == 1)
				cout << "H";
			else
				cout << "T";
		}

		if (i < 10) //Used to line up input
		{
			cout << " ";
		}
		for (int x = 1; x <= printedX; x++) //prints X's
		{
			cout << "X";
		}
	}
	if(gameType == 1)
		cout << endl << "Each X is " << valueOfX << " rolls" << endl << endl;
	else
		cout << endl << "Each X is " << valueOfX << " flips" << endl << endl;
}
