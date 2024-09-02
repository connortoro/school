/* Homework11part1.cpp -  Geometric figure areas and volumes using functions
 * Author:     Connor Toro
 * Module:     11
 * Project:    Homework 11 part 1
 * Problem statement: create program that calculates multiple geometrical equations using functions
 *
 * Algorithm:
 *    1. create: char menu() which prints menu and prompts for input choice, return the choice as an uppercase letter
 *    2. create: void sphere() which prompts for radius and calculates volume and area before outputting results
 	  3. create: void cube() which prompts for side length and calculates volume and area before outputting results
 	  4. create: void pyramid() which prompts for base and height and calculates volume and area before outputting results
 	  5. in main, call menu function and save what it returns as input char. using if/else determine which function should be called 
 	     or exit if 'Q' is entered, display error if input doesn't match choices.
 */
#include <iostream>
#include <cmath>
using namespace std;

//Prototypes
char menu();
void sphere();
void cube();
void pyramid();

//Declaration / constant
char input;
double area, volume, radius, side, height, base;
const double pi = 3.14159265359;

int main()
{
	//Main loop
	while(true)
	{
		input = menu();
		
		//Sentinel
		if (input == 'Q')
		{
			cout << "Goodbye!!!" << endl;
			exit(0);
		}
		else if (input == 'S')
		{
			sphere();
		}
		else if (input == 'C')
		{
			cube();
		}
		else if (input == 'P')
		{
			pyramid();
		}
		//Validation
		else
		{
			cout << "Invalid entry, retry..." << endl;
		}
	}
}

//Prints menu and returns choice
char menu()
{
	cout << "\n  ****** Geometric Figure Calculator ******" << endl << endl;
	cout << "    S - Calculate the area and volume of a Sphere" << endl;
	cout << "    C - Calculate the area and volume of a Cube" << endl;
	cout << "    P - Calculate the area and volume of a Pyramid" << endl;
	cout << "    Q - Quit" << endl << endl;
	cout << "           Enter your choice: ";
	cin >> input;
	cout << endl;
	return toupper(input);
}

//Calculates and outputs sphere
void sphere()
{
	cout << "Please enter the radius of the Sphere: ";
	cin >> radius;
	
	area = 4 * pi * pow(radius, 2);
	volume = (4.0 / 3) * pi * pow(radius, 3);
	
	cout << "A Sphere with radius " << radius << " has a volume of " << volume << " and an area of " << area << endl;
}

//Calculates and outputs Cube 
void cube()
{
	cout << "Please enter the side length of the cube: ";
	cin >> side;

	area = 6 * pow(side, 2);
	volume = pow(side, 3);

	cout << "A Cube with side length " << side << " has a volume of " << volume << " and an area of " << area << endl;
}

//Calculates and outputs Pyramid
void pyramid()
{
	cout << "Please enter base and height of pyramid seperated by a space: ";\
	cin >> base >> height;
	
	area = pow(base, 2) + (2 * base * sqrt((pow(base, 2) / 4) + pow(height, 2)));
	volume = pow(base, 2) * (height / 3);
	
	cout << "A Pyramid with base " << base << " and height " << height << " has a volume of " << volume << " and an area of " << area << endl;
}






















