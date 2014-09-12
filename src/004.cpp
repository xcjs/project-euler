#include <iostream>
#include <sstream>
#include <string>		// This should already be included in sstream.
#include <algorithm>	// This provides a handy reverse() method for this particular problem.
#include <cmath>

using namespace std;

/*
	Project Euler #4 - Largest palindrome product	

	A palindromic number reads the same both ways. The largest palindrome made 
	from the product of two 2-digit numbers is 9009 = 91 × 99.

	Find the largest palindrome made from the product of two 3-digit numbers.
*/

int main()
{
	// Arithmetic Variables ---------------------------------------------------/

	const unsigned ceiling = 999;
	unsigned factor1 = ceiling;
	unsigned factor2 = ceiling;

	unsigned product = 0;

	const unsigned lowerBound = 100;

	unsigned result = 0;

	// String Manipulation / Palindrome Variables -----------------------------/

	ostringstream converter;
	string ordered;
	string reveresed;

	// Begin Processing -------------------------------------------------------/

	while(factor1 >= lowerBound && factor2 >= lowerBound)
	{
		product = factor1 * factor2;

		converter << product;

		ordered = converter.str();

		// Reset the ostringstream.
		converter.clear();
		converter.str("");

		reverse(ordered.begin(), ordered.end());
		reveresed = ordered;
		reverse(ordered.begin(), ordered.end());

		if(ordered == reveresed && product > result)
		{
			result = product;
		}

		// New loop preparation.
		if(factor1 == ceiling && factor2 == ceiling)
		{
			factor2--;
		}
		else
		{
			if(factor1 == factor2)
			{
				factor1 = ceiling;
				factor2--;
			}
			else
			{
				factor1--;
			}
		}
	}

	cout << result << endl;
	
	return 0;
}
