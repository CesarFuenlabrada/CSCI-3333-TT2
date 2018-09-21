#include "trendtracker.h"
#include <iostream>
using namespace std;

Trendtracker::Trendtracker(string filename)
{
	string hashtag;						// Variable used to store an individual hashtag from the file provided.
	ifstream file;						// Variable used to access the file provided.
	
	// Open the file in order to access its information.
	file.open(filename);				

	
	while (file >> hashtag)
	{
		// Place an individual hashtag into Vector E. Some situations may have to be considered (ex. when the first element is being added.)
		// Attempt to place the hashtags in order.
		// Try by pushing back an empty Entry. Then search for the string from the parameter in vector E. Try using linear search to find the string. 
		// If the string is found, do not add it. Search until the string from the parameter is 
		Entry* New = new Entry();
		New->hashtag = hashtag;
		E.push_back(*New);
	}
	// Close the file.
	file.close();
}

int Trendtracker::size()
{
	return E.size();
}

void Trendtracker::tweeted(string ht)
{
	// Adds 1 to the total number times a hashtag has been tweeted.
	// If the hashtag does not exist in TrendTracker, does nothing.
	//
	// Must run in O(log(n)) time.

	// Create the binary search algorithm to look for the hashtag and add increment its popularity by 1.
	// Set up the corresponding variables.
	int left = 0;
	int right = E.size() - 1;
	int middle = (left + right) / 2;

	// Create the loop in order to find the corresponding hashtag from the parameter.
	// The condition must be that the left indicator does not match the right indicator.
	// The middle should always be maintained as the half of the sum of both ends.
	// A comparison should be made between the parameter variable and the middle index's element.
	// The corresponding side should shift to the middle location +/- 1 depending on situation.

	while (left <= right)
	{
		// Condition that states whether the hashtag is located on the left side of vector E.
		if (ht < E.at(middle).hashtag)
		{
			right = middle - 1;
			middle = (left + right) / 2;
		}

		// Condition that states whether the hashtag is located on the right side of vector E.
		else if (ht > E.at(middle).hashtag)
		{
			left = middle + 1;
			middle = (left + right) / 2;
		}

		// If the hashtag is found, increment its popularity by one.
		else if (ht == E.at(middle).hashtag)
		{
			++E.at(middle).pop;
			
			// At this point, check with "top three trends" vector S to see if this hashtag needs to be added.
			// Keep in mind that vector S holds the indices of the most tweeted entries.
			// If it is found, compare the popularity starting from the most popular to the least.
			// This will only happen before there are 3 elements. Once 3 are reached, we must compare instead of add.
			if (S.size() < 3)
			{
				// When there is nothing in vector S, simply add the index into the vector.
				if (S.size() == 0)
					S.push_back(middle);
				
				// Implement a for loop to look for the index provided by the "middle" variable.
				// If it is found, do not add it again. Simply exit the function.
				else
				{
					for (int i = 0; i < 3; i++)
						if (S.at(i) == middle)
							return;

					// This will execute if the "middle" value wasn't found in vector S.
					S.push_back(middle);
				}
			}

			// If there are already 3 elements in vector S, use the middle variable to compare and keep the highest
			 // popularity entries.
			else
			{
				// Compare middle with the 3 existing elements in vector S.
				// Compare the 3 elements to make sure they're in order.
				if (E.at(S.at(0)).pop < E.at(S.at(middle)).pop)
				{

				}
			}
				return;
			
		}

		// This will only execute if the hashtag wasn't found using binary search.
		else
			return;
	}

}

int Trendtracker::popularity(string name)
{
	unsigned int i = 0;

	//Loop through the vector to try and find the given name in the parameter. Else, exit the loop and return -1.
	for (i = 0; i < E.size(); i++)
	{

		Entry* H = &E.at(i);
		if (H->hashtag == name)
			return H->pop;
	}

	return -1;
}

string Trendtracker::top_trend()
{
	// Get the first element from vector S, access it's instance variable that holds the hashtag, and return it.
	return E.at(S.at(0)).hashtag;
}

void Trendtracker::top_three_trends(vector<string> &T)
{
	// Try to initialize vector T.
	while (T.size() < 3)
		T.push_back("");
}