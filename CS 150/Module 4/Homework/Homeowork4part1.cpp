/* Homework4part1.cpp -  Find volume and surface area of a sphere
 * Author:     Connor Toro
 * Module:     4
 * Project:    Homework 4 Part 1
 * Problem statement: calculate volume and surface are of sphere from given radius user input
 *
 * Algorithm:
 *    1. promt user for radius of sphere and store it in a double
 *    2. use radius to calculate volume and surface area and store them in doubles
 *    3. display the results
 */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	//Declaration and Initialization
	const double M_PI = 3.14159265358979323846;
	double radius , volume , surfaceArea;
	
	//Input
	cout << "Enter the radius of a sphere: ";
	cin >> radius;
	
	//Calculation
	volume = (4 / 3) * M_PI * pow(radius, 3);
	surfaceArea = 4 * M_PI * pow(radius, 2);
	
	//Output
	cout << "Your sphere's volume is " << volume << endl;
	cout << "Your sphere's surface area is " << surfaceArea << endl;
	
	return 0;
}
