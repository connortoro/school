/* Homework11part3.cpp -  Fibonacci Sequences
 * Author:     Connor Toro
 * Module:     11
 * Project:    Homework 11 part 3
 * Problem statement: 
 *
 * Algorithm:
 *    1. create function with heading:	void fibonacci(int seq), that prints fibonacci sequence "seq" numbers long
 *    2. function prints first two sequences in their own statements, and if seq is higher than 2 than it adds the previous two numbers
 		 together and prints the result, it then updates the two last number variables using temp variable and loops back repeating that
 		 until the seq number has been hit
 	  3. in main create while loop that prompts for input exits if input is 0, otherwise it calls the fibonacci function using input as param.
 */
#include <iostream>
using namespace std;

//Declaration
int lastNum, lastLastNum, temp, input;
 
 //Prototype
void fibonacci(int seq);

int main()
{
	//Main loop
	while(true)
	{
		//Input
		cout << "Enter a number from 1 to 25 (or 0 to exit): ";
		cin >> input;
		
		//Sentinel Case
		if (input == 0)
		{
			cout << "Goodbye!" << endl;
			exit(0);
		}
		else
		{
			//Calling function
			fibonacci(input);
		}
	}
}

//Fibonacci printing function 
void fibonacci(int seq)
{
	//Validation
	if (seq < 0 || seq > 25)
	{
		cout << "Invalid input, retry" << endl;
		return;
	}
	else if (seq == 1)
	{
		cout << "That Fibonacci sequence is: 0" << endl;
	}
	else if (seq == 2)
	{
		cout << "That Fibonacci sequence is: 0, 1" << endl;
	}
	else
	{
		cout << "That Fibonacci sequence is: 0, 1, ";
		lastNum = 1;
		lastLastNum = 0;
		
		for (int i = 2; i < seq; i++)
		{
			cout << (lastNum + lastLastNum) << ", ";
			temp = lastNum;
			lastNum += lastLastNum;
			lastLastNum = temp;
		}
		cout << endl;
	}
}
  
