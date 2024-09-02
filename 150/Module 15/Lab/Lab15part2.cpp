/* Lab15part2.cpp - Linear Search
 * Author:     Connor Toro
 * Module:     15
 * Project:    Lab 15
 * Problem statement: Write a program that performs a linear search on an array of numbers.
 *
 * Algorithm:
 *    1. creat linearSearch function which takes int array, int size, and int target as params
 *    2. in function, set pointer to beggining of array, and loop through array moving the pointer up and checking if target equals
         value at pointer, if it does increment the count variable, after searching return count.
 *    3. in main, create array of size 100 and use for loop to populate it with random values between 1 and 20 using rand function
      4. pprompt user for input int while loop for number to check, and call the linearSearch function using that number, 
	     and show user result (exiting if 0 is input)
      5. loop through numbers 1-20 calling linearSearch function and displaying results for each number in columns. tallying each 
         onto total, then print total
 	  
 */
 
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

//Prototype
int linearSearch(int array[], int size, int target);

int main()
{
	//Setting up rand function with time
	srand(time(NULL));
	
	//Initialization
	int array[100];
	int input;
	int total = 0;
	
	//Filling array with random numbers
	for(int i = 0; i < 100; i ++)
	{
		array[i] = rand() % 20 + 1;
	}
	
	while(true)
	{
		//Input
		cout << "Enter a number (1 - 20), or 0 to quit: ";
		cin >> input;
		
		//Sentinel case
		if (input == 0)
		{
			break;
		}
		//Calling search function and displaying results
		cout << input << " was found " << linearSearch(array, 100, input) << " time(s) in the array" << endl;
	}
	
	//Showing results for all numbers possible in array
	cout << "Target    Count" << endl;
	for(int i = 0; i < 20; i ++)
	{
		cout << setw(6) << right << (i + 1) << setw(6) << right << linearSearch(array, 100, (i + 1)) << endl;
		total += linearSearch(array, 100, (i + 1));
	}
	cout << setw(12) << right << total << endl;
	
	
	
}

int linearSearch(int array[], int size, int target)
{
	int count = 0;
	
	//Setting pointer to beggining of array
	int * pointer = array;
	
	//Looping through array moving pointer and checking values
	for(int i = 0; i < size; i++)
	{
		if(*(pointer + i) == target)
		{
			count++;
		}
	}
	return count;
}
