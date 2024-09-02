/* Homework11part1.cpp -  Printing Triangles
 * Author:     Connor Toro
 * Module:     11
 * Project:    Homework 11 part 1
 * Problem statement: Create function that prints triangles
 *
 * Algorithm:
 *    1. setup triangle fucntion that takes width as a parameter and uses for loop to setup ascending rows, 
 		 then a nested for loop inside to print astericks in each ascending row. then use another for loop 
		 to setup descending rows, then another nested for loop to print astericks in descending rows 
 *    2. in main, create main while loop that prompts for input of size of triangle and checks if input is valid,
 		 exits if input is zero, and calls the print triangle function if size is valid.
 */
 #include <iostream>
 using namespace std;
 
 void triangle(int width);
 
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
			triangle(size);
		}
	}
 }
 
 void triangle(int width)
 {
  	 //Prints ascending part of triangle
			for (int i = 0; i < width; i++)
			{
				for (int j = 0; j <= i; j++)
				{
					cout << "*";
				}
				cout << endl;
			}
			
			//Prints descending part of traignle
			for (int i = 1; i < width; i++)
			{
				for (int j = i; j < width; j++)
				{
					cout << "*";
				}
				cout << endl;
			}	 	
 }
