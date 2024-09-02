/* Homework11part4.cpp -  Random Numbers
 * Author:     Connor Toro
 * Module:     11
 * Project:    Homework 11 part 4
 * Problem statement: write a function that prints random numbers
 *
 * Algorithm:
 *    1. create function: void printRandom(int low, int high, int num), which prints random numbers to console using rand function with ctime,
 		loops through num amount of times using numbers from low to high.
 *    2. if low is less than zero, print error msg. if low is equal to or greater than high, print error msg. if num is less than one, print error msg.
 	  3. call function in main method to test cases 
 */
#include <iostream>
#include <ctime>
using namespace std;



void printRandom(int low, int high, int num);

int main()
{
	//setting up random function
	srand(time(0));
	
	//calling random fucntion
	printRandom(100, 200, 25);
	printRandom(1, 6, 40);
	printRandom(-6, 6, 10);
	printRandom(10, 10, 10);
	printRandom(20, 30, -2);
}

void printRandom(int low, int high, int num)
{
	//Validation
	if (low < 0)
	{
		cout << "Cannot use negative number for low value..." << endl;
	}
	else if (high <= low)
	{
		cout << "Low value cannot be equal to or greater than the high value...." << endl;
	}
	else if (num < 1)
	{
		cout << "Invalid amount of numbers..." << endl;
	}
	else
	{
		//Printing nums
		for(int i = 1; i < num; i++)
		{
			cout << ((rand() % (high - low + 1)) + low) << " ";
		}
		cout << endl;
	}

}

 
