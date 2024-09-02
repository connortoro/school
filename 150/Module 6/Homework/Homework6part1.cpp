/* Homework6part1.cpp -  Predict a Child's Height
 * Author:     Connor Toro
 * Module:     6
 * Project:    Homework 6 part 1
 * Problem statement: Predict a child's height, given their gender and height of their parents.
 *
 * Algorithm:
 *    1. intialize variables and prompt for input of heights and gender
 *    2. use if else statement to figure out which equation to use for height prediction then round result
 *    3. output predicted height in feet and inches using integer division and modulo
 */
 #include <iostream>
 #include <cmath>
 using namespace std;
 
 int main()
 {
 	//Initialization
 	string gender;
 	int fatherHeightInches;
 	int fatherHeightFeet;
 	int motherHeightInches;
 	int motherHeightFeet;
 	double childHeight;
 	int fatherHeight;
 	int motherHeight;
 	int childHeightInt;
 	//Input
 	cout << "Please enter gender of child (male or female): ";
 	cin >> gender;
 	cout << "Please enter height of father (feet): ";
	cin >> fatherHeightFeet;
	cout << "Please enter height of father (inches): ";
	cin >> fatherHeightInches;
	cout << "Please enter height of mother (feet): ";
	cin >> motherHeightFeet;
	cout << "Please enter height of mother (inches): ";
	cin >> motherHeightInches;
	
	//Processing
	fatherHeight = (fatherHeightFeet * 12) + fatherHeightInches;
	motherHeight = (motherHeightFeet * 12) + motherHeightInches;
	
	if (gender == "male")
	{
		childHeight = ((motherHeight * (13.0 / 12)) + fatherHeight) / 2;
	} 
	else if (gender == "female")
	{
		childHeight = ((fatherHeight * (12.0 / 13)) + motherHeight) / 2;
	}
	else
	{
		cout << "Invalid Gender";
	}
	childHeightInt = round(childHeight);
	
	//Output
	cout << "The predicted height of the child is " << (childHeightInt / 12) << " feet " << (childHeightInt % 12) << " inches";
	 
 }
 
 
 
 
 
 
 
 
