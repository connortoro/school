/* Homework7part1.cpp -  Geometric Figure Calculator
 * Author:     Connor Toro
 * Module:     7
 * Project:    Homework 7 part 1
 * Problem statement: Write a program that calculates multiple geometric equations
 *
 * Algorithm:
 *    1. intialize variables and prompt for char input for which calculation to be done, or to quit
 *    2. use a switch statement using user input to decide which block to run
 *    3. input needed variables from user and calculate and display information
 */
 #include <iostream>
 #include <cmath>
 #include <iomanip>
 using namespace std; 
 
 int main()
 {
 	//Initialization and declaration
 	char input;
 	double radius;
 	double height;
 	double width;
 	double base;
 	double area;
 	const double M_PI = 3.14159265358979323846;
 	
 	//Input 
 	cout << "  ****** Geometric Figure Calculator ******" << endl << endl;
 	cout << "    C - Calculate the area of a Circle" << endl;
 	cout << "    R - Calculate the area of a Rectangle" << endl;
 	cout << "    T - Calculate the area of a Triangle" << endl;
 	cout << "    Q - Quit" << endl << endl;
 	cout << "           Enter your choice: ";
 	cin >> input;
 	
 	//Find applicable block, prompt for needed data, calculate, and display results (or just quit)
 	switch (toupper(input))
 	{
 		case 'C':
 			cout << "Please enter the area of the circle: ";
 			cin >> radius;
 			area = M_PI * pow(radius, 2);
 			cout << "The area of a circle with radius " << radius << " is " << setprecision(6) << fixed << area << endl;
 			break;
 		case 'R':
 			cout << "Please enter the rectangle's height and width, seperated by a space: ";
 			cin >> height;
 			cin >> width;
 			area = height * width;
 			cout << "The area of a rectangle with height " << height << " and width " << width << " is " << setprecision(6) << fixed << area << endl;
 			break;
 		case 'T':
 			cout << "Please enter the triangle's base and height, seperated by a space: ";
 			cin >> base;
 			cin >> height;
 			area = base * height * .5;
 			cout << "The area of a triangle with base " << base << " and height " << height << " is " << setprecision(6) << fixed << area << endl;
 			break;
 		case 'Q':
 			cout << "Goodbye!" << endl;
 			exit(0);
 		default:
 			cout << "Invalid choice, retry" << endl;
			exit(1);	
	}
		
 }
