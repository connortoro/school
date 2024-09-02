/* Homework11part2.cpp -  Converting Temperatures
 * Author:     Connor Toro
 * Module:     11
 * Project:    Homework 11 part 2
 * Problem statement: Create function that converts C to F and F to C
 *
 * Algorithm:
 *    1. create fucntion convert which takes double degrees and char scale as input
 *    2. if input is F, convert fahrenheit to celsius and print results, is input is C convert celsius to Fahrenheit and print results
 	  3. call function in main method
 */
 
#include <iostream>
using namespace std;

double convertedDegrees;

void convert(double degrees, char scale);

int main()
{
	//Calling function
	convert(100.0, 'C');
    convert(32.0, 'F');  
    convert(-40, 'C');
    convert(0, 'X');
}

//function converts C or F into the other
void convert(double degrees, char scale)
{
	if (toupper(scale) == 'F')
	{
		convertedDegrees = (5 * (degrees - 32)) / 9;
		cout << degrees << " Fahrenheit is " << convertedDegrees << " Celsius" << endl;
	}
	else if (toupper(scale) == 'C')
	{
		convertedDegrees = ((9.0 / 5) * degrees) + 32;
		cout << degrees << " Celsius is " << convertedDegrees << " Fahrenheit" << endl;
	}
	//Invalid case
	else
	{
		cout << "Invalid scale character..." << endl;
	}
}
