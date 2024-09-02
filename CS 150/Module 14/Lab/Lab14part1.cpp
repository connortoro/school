/* Lab14part1.cpp - Fibonacci
 * Author:     Connor Toro
 * Module:     14
 * Project:    Lab 14
 * Problem statement: Create Fibonacci array and print reversed
 *
 * Algorithm:
 *    1. create fillFibonacci which takes array and int length as input, fills array to legnth - 1 index with fibonacci ints, storing the last two 
 		 number in the sequence and adding them together to get the current number
 *    2. create show reverse, which takes string heading array and int size as params, prints heading than loops through array from
         back to front printing contents.
 *    3. create and array of size 15 and call fillFibonacci then call showReverse to print it.
 	  
 */
#include <iostream>
using namespace std;

//Prototypes
void fillFibonacci(int array[], int size);
void showReverse(string heading, int array[], int size);

int main()
{
	int array[15];
	fillFibonacci(array, 15);
	showReverse("Heres the reversed array: ", array, 15);
	
}

//fills array w/ fibonacci seq
void fillFibonacci(int array[], int size)
{
	if (size == 1)
	{
		array[0] = 0;
	}
	else
	{
		int lastNum = 1, lastLastNum = 0, temp;
		array[0] = 0;
		array[1] = 1;
		
		for(int i = 2; i < size; i ++)
		{
			array[i] = lastNum + lastLastNum;
			temp = lastNum;
			lastNum += lastLastNum;
			lastLastNum = temp;
		}
	}
}

//Prints elements starting from last to first
void showReverse(string heading, int array[], int size)
{
	cout << heading << endl;
	
	for (int i = size - 1; i >= 0; i--)
	{
		cout << array[i] << ", ";
	}
}
