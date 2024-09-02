/* Lab4part1.cpp -  Calculate miles-per-gallon
 * Author:     Connor Toro
 * Module:     4
 * Project:    Lab 4 Part 1
 * Problem statement: calculates mpg from user input of tank capacity and miles driven on a tank
 *
 * Algorithm:
 *    1. promt user for input of miles driven on a tank and gallons held in tank
 *    2. calculate mpg from those values
 *    3. display the results
 */
 
 #include <iostream>
 using namespace std;
 
 int main()
 {
 	//Declaration
 	int tankCapacity;
 	int milesDriven;
 	double mpg;
 	
 	//Input
 	cout << "Please enter the number of gallons your car holds: ";
 	cin >> tankCapacity;
 	cout << "Please enter the number of miles that can be driven on a tank of gas: ";
 	cin >> milesDriven;
 	
 	//Calculation
 	mpg = milesDriven / ((double) tankCapacity);
 	
 	//Output
 	cout << "Your car gets " << mpg << " miles-per-gallon" << endl;
 }

