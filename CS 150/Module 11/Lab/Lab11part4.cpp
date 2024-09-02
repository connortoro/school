/* Lab11part4.cpp -  Print a word a specified number of times
 * Author:     Connor Toro
 * Module:     11
 * Project:    Lab 11 part 4
 * Problem statement: Create function that prints a word a specified number of times
 *
 * Algorithm:
 *    1. create repeat function, takes string word and int how_many variables with default values set to "*" and 5 respectively.
 *    2. in repeat, loop through (how_many) times printing word seperated by space, using for loop
 *    3. call function testing different cases in main
 */
#include <iostream>
using namespace std;

//Repeat function
void repeat(string word = "*", int how_many = 5)
{
	for (int i = 0; i < how_many; i++)
	{
		cout << word << " ";
	}
	cout << endl;
}

int main()
{
	//Calling fucntion
	repeat() ;
	repeat( "$" ) ;
	repeat( "Rah", 3) ;
}
 

