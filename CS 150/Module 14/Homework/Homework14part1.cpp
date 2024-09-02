/* Homework14part1.cpp -  Rempve Elements
* Author:     Connor Toro
* Module:     14
* Project:    Homework 14
* Problem statement: Remove Elements from a Message
*
* Algorithm:
*    1. create remove() which takes char array and count & remove_index ints. replace elemenent at remove_index with the element one index higher
		moving up the array doing that until you reach the end(count) return the new count of the array
	 2. create update() which takes char array, char amount, and int index as params. updates element at index by adding it to array at index
	 3. create showarray() which takes a string heading, char array, and int count as params. print heading to the console, then iterate through
	    the array printing each element.
*   
  
*/
#include <iostream>
using namespace std;

//Prototypes
int remove(char array[], int count, int remove_index);
void update(char array[], char amount, int index);
void showArray(string heading, char array[], int count);

int main()
{
	//Initialization
	char message[7] = {'t', 'Q', 'b', ')', 'f', '+', '5'};
	int count = sizeof(message) / sizeof(char);
	
	//Testing Functions
	showArray("Array: ", message, count);
	count = remove(message, count, 3);
	update(message, -14, 1);
	count = remove(message, count, 0);
	count = remove(message, count, 2);
	update(message, -55, 1);
	count = remove(message, count, count - 1);
	showArray("Array: ", message, count);
}

//Removes char at index, returns new length count
int remove(char array[], int count, int remove_index)
{
	if (count == 0 || remove_index >= count)
	{
		return count;
	}
	else
	{
		for (int i = remove_index; i < count; i++)
		{
			array[i] = array[i + 1];
		}
		array[count - 1] = 0;
		return count - 1;
	}
}

//Adds value to char at index
void update(char array[], char amount, int index)
{
	array[index] += amount;
}

//prints array
void showArray(string heading, char array[], int count)
{
	cout << heading << endl;
	
	for(int i = 0; i < count; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
