/* Homework4part2.cpp -  Show user result of floor ciel and abs functions
 * Author:     Connor Toro
 * Module:     4
 * Project:    Homework 4 Part 2
 * Problem statement: Show user result of floor ciel and abs functions from a given double input
 *
 * Algorithm:
 *    1. promt user for floating point number and store in double
 *    2. output result of floor ciel and abs math fucntions
 */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	//Declaration
	double floatingPointInput;
	
	//Input
	cout << "Please enter a floating-point number: ";
	cin >> floatingPointInput;
	
	//Output
	cout << "The floor value of your number is " << floor(floatingPointInput) << endl;
	cout << "The ceiling value of your number is " << ceil(floatingPointInput) << endl;
	cout << "The absolute value of your number is " << abs(floatingPointInput) << endl;
}
