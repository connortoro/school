/* Lab12.cpp -  Passenger Flights
 * Author:     Connor Toro
 * Module:     12
 * Project:    Lab 12
 * Problem statement: Create plane class
 *
 * Algorithm:
 *    1. Create Plane class with bool inflight, unsigned int passengers and capacity, and description string instance variables
 *    2. create getter and setter functions for all instance varibales
 *    3. create constructor that takes in description and capacity with default values and sets ingflight to false and passengers to 0
 	  4. create fly() function which sets inflight to true, and land() function which sets inflight to false
 	  5. create board(unsigned int) function which adds number passed to passengers variable, if passengers exceeds capacity set passengers to capactiy
 	  6. create disembark(unsigned int) function which subtracts number passed to passengers, if number is below zero then set passengers to 0
 	  7. create show() function which prints current plane status to console.
 	  8. create objects and test functions in main method
 */
#include <iostream>
using namespace std;

unsigned int zero = 0;

class Plane
{
private:
	//Instance Variables
	bool inflight;
	unsigned int passengers;
	unsigned int capacity;
	string description;
	
public:
	
	//Prototypes
	Plane(unsigned int, string);
	void fly();
	void land();
	void board(unsigned int);
	void disembark(unsigned int);
	void show();
	
	//Getters
	bool getInflight()
	{
		return inflight;	
	}
	unsigned int getPassengers()
	{
		return passengers;
	}
	unsigned int getCapacity()
	{
		return capacity;
	}
	string getDescription()
	{
		return description;
	}
	
	//Setters
	void setInflight(bool newInflight)
	{
		inflight = newInflight;
	}
	void setPassengers(unsigned int newPassengers)
	{
		passengers = newPassengers;
	}
	void setCapacity(unsigned int newCapacity)
	{
		capacity = newCapacity;
	}
	void setDescription(string newDescription)
	{
		description = newDescription;
	}
};

//Constructor & other class functions
Plane::Plane(unsigned int newCapacity = 10, string newDescription = "(none)")
{
	setCapacity(newCapacity);
	setDescription(newDescription);
	setInflight(false);
	setPassengers(0);
}

void Plane::fly()
{
	if (inflight == true)
	{
		cout << "Plane is already inflight..." << endl;
	}
	else
	{
		inflight = true;
	}
}

void Plane::land()
{
	if (inflight == false)
	{
		cout << "Plane is already grounded..." << endl;
	}
	else
	{
		inflight = false;
	}
}

void Plane::board(unsigned int boardAmount)
{
	if (inflight == true)
	{
		cout << "You may not board, plane is in flight..." << endl;
	}
	else
	{
		passengers += boardAmount;
		if (passengers > capacity)
		{
			cout << "Plane has reached maximum capacity" << endl;
			passengers = capacity;
		}
	}

}

void Plane::disembark(unsigned int exitAmount)
{
	if (inflight == true)
	{
		cout << "You may not disembark, plane is in flight..." << endl;
	}
	else
	{
		if (exitAmount > passengers)
		{
			passengers = 0;
		}
		else
		{
			passengers -= exitAmount;
		}
	}
}

void Plane::show()
{
	cout << "The " << description << " (cap. " << capacity << ") is " << (inflight ?  "in flight" : "landed")
		 << " with " << (passengers > 0 ? passengers : 0) << " passengers." << endl;
}

int main()
{
	//Creating and using united object
	Plane united(285, "United 737");
	united.board(20);
	united.board(100);
	united.board(131);
	united.fly();
	united.show();
	united.land();
	united.disembark(9999);
	united.show();

	cout << endl << endl;
	
	//Testing functions with test object
	Plane test;
	test.show();
	test.setDescription("Connor's Cessna");
	test.setCapacity(3);
	test.land();
	test.board(20);
	test.disembark(2);
	test.fly();
	test.board(1);
	test.disembark(1);
	test.land();
	test.land();
	test.disembark(test.getPassengers());
	test.show();
}










