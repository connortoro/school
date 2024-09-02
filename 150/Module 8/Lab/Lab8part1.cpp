/* Lab8part1.cpp -  Print Triangles
 * Author:     Connor Toro
 * Module:     8
 * Project:    Lab 8 
 * Problem statement: Write a program that asks the user to enter the size of a triangle to print (an integer from 1 to 20), 
                      then create the triangle by printing a series of lines consisting of asterisks
 *
 * Algorithm:
 *    1. Prompt for size of triangle in while loop that repeats until exited (when enter 0)
 *    2. Validate input with if else, and exit if input is 0
 *    3. use for loop to setup ascending rows, then a nested for loop inside to print astericks in each ascending row
 	  4. use another for loop to setup descending rows, then another nested for loop to print astericks in descending rows
 */
 #include <iostream>
 using namespace std;
 
 int main()
 {
 	while (true)
 	{
 		//Input
 		cout << "\nPlease enter size of traingle (1-20): ";
 		int size;
 		cin >> size;
 		
 		//Exit if 0
 		if (size == 0)
 		{
 			cout << "Goodbye!" << endl;
 			exit(0);
		}
		//Validating input
		else if (size < 0 || size > 20)
		{
			cout << "Invalid size, retry." << endl;
		}
		else
		{
			//Prints ascending part of triangle
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j <= i; j++)
				{
					cout << "*";
				}
				cout << endl;
			}
			
			//Prints descending part of traignle
			for (int i = 1; i < size; i++)
			{
				for (int j = i; j < size; j++)
				{
					cout << "*";
				}
				cout << endl;
			}
		}
	}
 }
