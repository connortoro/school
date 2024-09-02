/* Date.cpp -  Defines Function for Date Class
 * Author:     Connor Toro
 * Module:     13
 * Project:    Lab 13
 * Problem statement: write functions for date class
 *
 * Algorithm:
 *    1. define constructor, calling checkdates and if it returns false then set values to the default
 *    2. create setter functions for month day and year, calling checkDates() function and if it return false, set values to default
 *    3. create checkDates function which uses branching if/else to check if the date passed to the function is valid, return true if
 		 valid and false if not valid
 	  
 */
#include "Date.h"
//#include <iostream>
//#include <iomanip>
using namespace std;

//Constructor
Date::Date(int month, int day, int year)
{
	setMonth(month);
	setDay(day);
	setYear(year);
	
	if (!checkDates())
	{
		setMonth(1);
		setDay(1);
		setYear(2000);
	}
}

//Setters
void Date::setMonth(int newMonth)
{
	month = newMonth;
	if (!checkDates())
	{
		setMonth(1);
		setDay(1);
		setYear(2000);
	}	
} 
void Date::setDay(int newDay)
{
	day = newDay;
	if (!checkDates())
	{
		setMonth(1);
		setDay(1);
		setYear(2000);
	}
}
void Date::setYear(int newYear)
{
	year = newYear;
	if (!checkDates())
	{
		setMonth(1);
		setDay(1);
		setYear(2000);
	}	
} 

//Check
bool Date::checkDates()
{
	if (month > 12 || month < 1)
	{
		return false;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day < 1 || day > 30)
		{
			return false;
		}
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day < 1 || day > 31)
		{
			return false;
		}
	}
	else if (month == 2)
	{
		if (day < 1 || day > 29)
		{
			return false;
		}
	}
	else if (year < 1900 || year > 2099)
	{
		return false;
	}
	else
	{
		return true;
	}
}

 
