/* Lab11part3.cpp -  Print a word a specified number of times
 * Author:     Connor Toro
 * Module:     11
 * Project:    Lab 11 part 3
 * Problem statement: Create function that prints a word a specified number of times
 *
 * Algorithm:
 *    1. create: void getStrings(string &first, string &second, string &third) which uses getline to prompt for the user to input 3 strings and
 		 saves them to string variables in main using reference parameters.
 *    2. create: void sortStrings(string &low, string &mid, string &high) which uses branching if/else statements to deduce which order the 
 		 strings should be in lexicographically, and swaps them into the right order using a placeholder swap string variable
 *    3. in main while loop, call getStrings and exit if any of the strings input were "quit". otherwise call sortStrings and print the
 		 sorted strings onto the console.
 */
#include <iostream>
using namespace std;

//Prototypes
void getStrings(string &first, string &second, string &third);
void sortStrings(string &low, string &mid, string &high);

//Temporary swap variable
string temp;

int main()
{
	//Initializing Strings
	string string1, string2, string3;
	
	while(true)
	{
		//Getting string input
		getStrings(string1, string2, string3);
		
		//Sentinel Case
		if (string1 == "quit" || string2 == "quit" || string3 == "quit")
		{
			cout << "Goodbye!" << endl;
			exit(0);
		}
		else
		{
			//Sorting and outputting strings
			sortStrings(string1, string2, string3);
			cout << string1 << ", " << string2 << ", " << string3 << endl << endl;
		}
	}
	
	
}

//Gets 3 strings and stores them to variables in main using reference params
void getStrings(string &first, string &second, string &third)
{
	cout << "Please enter string 1: ";
	getline(cin, first);
	cout << "Please enter string 2: ";
	getline(cin, second);
	cout << "Please enter string 1: ";
	getline(cin, third);
}

//Sorting strings lexicographically using reference params
void sortStrings(string &low, string &mid, string &high)
{
	if (low <= mid && mid <= high)          // 1 2 3
    {
        
    }
    else if (low <= high && high <= mid)    // 1 3 2
    {
        temp = mid;
        mid = high;
        high = temp;
    }
    else if (mid <= low && low <= high)     // 2 1 3
    {
        temp = low;
        low = mid;
        mid = temp;
    }
    else if (high <= low && low <= mid)    // 2 3 1
    {
        temp = low;
        low = high;
        high = temp;
        temp = mid;
        mid = high;
        high = temp;
    }
    else if (mid <= high && high <= low)      // 3 1 2
    {
        temp = low;
        low = mid;
        mid = temp;
        temp = mid;
        mid = high;
        high = temp;
    }
    else                                    // 3 2 1
    {
    	temp = low;
        low = high;
        high = temp;
    }
}
 
