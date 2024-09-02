/* Homework15part1.cpp -  Weather Patterns
* Author:     Connor Toro
* Module:     15
* Project:    Homework 15
* Problem statement: Store and print table using 2d array
*
* Algorithm:
*    1. Create printReport function which takes 2d array and int rows as params, loop through rows, then columns to print temperatures,
		adding each row up the total and printing the avg at the end of the row
	 2. then loop through columns, then rows to add up all of the months to the sum var and then print avg.
	 3. intialize 2d array in main and call function
  
*/
#include <iostream>
#include <iomanip>
using namespace std;

void printReport(int temps[][12], int rows);

int main()
{
	int temps[][12] = {{68, 69,	70,	73,	75,	79,	83,	84,	83,	79,	73,	68}, {39, 42, 50, 62, 72, 80, 85, 84, 76, 65, 54, 44}, 
	                   {73, 74,	75,	78,	81,	84,	85,	86,	85,	82,	78,	76}, {47, 51, 55, 59, 65, 70, 75, 75, 69, 60, 51, 46}};	
	
	printReport(temps, 12);
	
}

void printReport(int array[][12], int rows)
{
	double sum;
	string names[4] = {"Los Angeles", "New York", "Miami", "Seattle"};
	cout << " City	      Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec  Avg" << endl;
	
	for(int i = 0; i < rows; i++)
	{
		sum = 0;
		cout << setw(15) << left << names[i];
		
		for(int j = 0; j < 12; j++)
		{
			cout << array[i][j] << "  ";
			sum += array[i][j];
		}
		cout << setprecision(1) << fixed << (sum / 12) << endl;
	}
	cout << setw(15) << left << "Avg";
	
	for(int k = 0; k < 12; k++)
	{
		sum = 0;
		for(int l = 0; l < rows; l++)
		{
			sum += array[l][k];
		}
		cout << setprecision(1) << fixed << (sum / rows) << "  ";
	}
	
}
