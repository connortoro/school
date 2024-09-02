/* Lab14part2.cpp - Reverse array
 * Author:     Connor Toro
 * Module:     14
 * Project:    Lab 14
 * Problem statement: Reverse an Array's Elemtns
 *
 * Algorithm:
 *    1. create fillRandom which takes array, size, min and max ints. it uses the rand function and loops through arrays elements assigning
 		 them to random functions between the min and the max parameters
 	  2. create reverseArray which takes array and size ints and loops through the array swapping the the first and last elements using
 	     a temporary variable, than moving up array for the first index and down the array for the last index
 	  3. create printARrayAndTotal, which takes and array and size ints, and a heading string. prints heading than iterates through
 	     array printing each element and adding each element to the sum var. outside of the loop print the last element of the array
 	     and show the total.
 	  4. in main prompt for size of array until valid using a while loop.
 	     use fill random to populate array with random nums, print array, reverse it, print again.
 	  
 */
#include <iostream>
#include <ctime>
using namespace std;

//Prototypes
void fillRandom(int array[], int size, int min, int max);
void reverseElements(int array[], int size);
void printArrayAndTotal(string heading, int array[], int size);

int main()
{	
	//Input and Validation
	int input;
	bool valid = false;
	while(!valid)
	{
		cout << "Please input a number between 10 and 20: ";
		cin >> input;
		
		if (input < 10 || input > 20)
		{
			cout << "Invalid input, retry..." << endl;
		}
		else
		{
			valid = true;
		}
	}
	
	int array[input];
	
	//Calling functions
	fillRandom(array, input, 100, 200);
	printArrayAndTotal("Array: ", array, input);
	reverseElements(array, input);
	printArrayAndTotal(" Reversed Array: ", array, input);
	
	
}
//Using rand function to fill array
void fillRandom(int array[], int size, int min, int max)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % ((max - min) + 1) + min;
	}
}
//reversing
void reverseElements(int array[], int size)
{
	int temp;
	for (int i = 0; i < size / 2; i++)
	{
		temp = array[size - (i + 1)];
		array[size - (i + 1)] = array[i];
		array[i] = temp;
	}
}
void printArrayAndTotal(string heading, int array[], int size)
{
	int total = 0;
	cout << heading;
	for (int i = 0; i < size - 1; i++)
	{
		total += array[i];
		cout << array[i] << ", ";
	}
	cout << array[size - 1] << endl;
	total += array[size - 1];
	cout << "Total: " << total << endl;
	
}
