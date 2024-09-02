/* Homework12.cpp -  Passenger Flights
 * Author:     Connor Toro
 * Module:     12
 * Project:    Homework 12
 * Problem statement: Create GasTank class
 *
 * Algorithm:
 *    1. Create GasTank class with level and capacity double instance variables
 *    2. Initialize defult and min capacity constants
 *    3. Create getters and setters for level and capacity, as well as declaring prototypes
 	  4. Create constructor with default level of 0 and default Capacity as constant
 	  5. Create GasTank destructor
 	  6. create calcFill() which returns the level / capacity as a double
 	  7. create showInfor() which prints current level and capacity as well as calling the calcFill() function and returning that
 	  8. create objects and test functions in main method
 */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Constants
const static double DEFAULT_CAPACITY = 30.0, MINIMUM_CAPACITY = 4.0;

class GasTank
{
	private:
		double capacity, level;
	
	public:
		
		// Prototypes
		GasTank(double, double);
		~GasTank();
		double calcFill();
		void showInfo();
		
		//Setters
		void setCapacity(double newCapacity)
		{
			if (newCapacity <= MINIMUM_CAPACITY)
			{
				capacity = MINIMUM_CAPACITY;
			}
			else
			{
				capacity = newCapacity;
			}
		}
		void setLevel(double newLevel)
		{
			if (newLevel <= 0)
			{
				level = 0;
			}
			else if (newLevel >= capacity)
			{
				level = capacity;
			}
			else
			{
				level = newLevel;
			}
		}
		
		//Getters
		double getCapacity()
		{
			return capacity;
		}
		double getLevel()
		{
			return level;
		}
};

//Constructor
GasTank::GasTank(double newLevel = 0, double newCapacity = DEFAULT_CAPACITY)
{
	cout << "Recieved level: " << newLevel << " and capacity: " << newCapacity << endl;
	setCapacity(newCapacity);
	setLevel(newLevel);
}

//Desctructor
GasTank::~GasTank()
{}

double GasTank::calcFill()
{
	return (level / capacity);
}

//Prints object info
void GasTank::showInfo()
{
	cout << "The current level is " << setprecision(1) << fixed << level << "/" << setprecision(1) << fixed << capacity << " or %"
		 << setprecision(0) << round(calcFill() * 100) << endl; 
}

int main()
{
	//Creating and testing Class Objects
	GasTank tank1;
	tank1.showInfo();
	GasTank tank2(13.5);
	tank2.showInfo();
	GasTank tank3(0, 58);
	tank3.showInfo();
	GasTank tank4(18.6, 45.2);
	tank4.showInfo();
	
	cout << endl;
	GasTank tank5(-2, -234);
	tank5.showInfo();
	GasTank tank6(40, 30);
	tank6.showInfo();
}









