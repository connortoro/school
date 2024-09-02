/* Homework4part3.cpp -  Shows sin cos and tan of a inputed angle
 * Author:     Connor Toro
 * Module:     4
 * Project:    Homework 4 Part 3
 * Problem statement: take user input in degrees and output sin cos and tan using cmath fucntions
 *
 * Algorithm:
 *    1. prompt user for angle in degrees 
 *    2. convert degrees into radians to use in cmath trig fucntions
 *    3. display the results of the sin cos and tan fucntions 
 */
 
 #include <iostream>
 #include <cmath>
 using namespace std;
 
 int main() 
 {
 	//Declaration & Initialization
 	int degrees;
 	double radians;
 	const double M_PI = 3.14159265358979323846;
 	
 	//Input
 	cout << "Please enter the value of an angle(in degrees): ";
 	cin >> degrees;
 	
 	//Calculation (degrees ---> radians)
 	radians = (M_PI * degrees) / 180;
 	
 	//Output
 	cout << "The sine of " << degrees << " degrees is " << sin(radians) << endl;
 	cout << "The cosine of " << degrees << " degrees is " << cos(radians) << endl;
 	cout << "The tangent of " << degrees << " degrees is " << tan(radians) << endl;
 }
