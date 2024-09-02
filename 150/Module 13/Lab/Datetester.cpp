/* Datetester.cpp -  Tests Date class
 * Author:     Connor Toro
 * Module:     13
 * Project:    Lab 13
 * Problem statement: 
 *
 * Algorithm:
 *    1. Create 4 printing functions that take date object as param and print formatted date
 *    2. in main, test date class by making multiple objects and printing dates
 	  
 */
#include "Date.h"
//#include "Date.cpp"
#include <iostream>
#include <iomanip>
using namespace std;

//Prototypes
void print1(Date);
void print2(Date);
void print3(Date);
void print4(Date);

int main()
{
	//Testing
	Date date1(1, 5, 2022);
	print1(date1);
	print2(date1);
	print3(date1);
	print4(date1);
	
	Date date2(9, 14, 1970);
	print1(date2);
	print2(date2);
	print3(date2);
	print4(date2);
	
	Date date3(12, 31, 2023);
	print1(date3);
	print2(date3);
	print3(date3);
	print4(date3);
	
	Date date4(4, 31, 2022);
	print1(date4);
	
	Date date5(13, 1, 2022);
	print1(date5);
	
	Date date6(8, 15, 2100);
	print1(date6);	
}

//Printing Fucntion definitions
void print1(Date date)
{
	cout << date.getMonth() << "/" << date.getDay() << "/" << date.getYear() << endl;
}
void print2(Date date)
{
	string month;
	switch (date.getMonth())
	{
		case 1:
			month = "January";
			break;
		case 2:
			month = "February";
			break;
		case 3:
			month = "March";
			break;
		case 4:
			month = "April";
			break;
		case 5:
			month = "May";
			break;
		case 6:
			month = "June";
			break;
		case 7:
			month = "July";
			break;
		case 8:
			month = "August";
			break;
		case 9:
			month = "September";
			break;
		case 10:
			month = "October";
			break;
		case 11:
			month = "November";
			break;
		case 12:
			month = "December";
			break;
			
	}
	cout << month << " " << date.getDay() << ", " << date.getYear() << endl;
}
void print3(Date date)
{
	string month;
	switch (date.getMonth())
	{
		case 1:
			month = "January";
			break;
		case 2:
			month = "February";
			break;
		case 3:
			month = "March";
			break;
		case 4:
			month = "April";
			break;
		case 5:
			month = "May";
			break;
		case 6:
			month = "June";
			break;
		case 7:
			month = "July";
			break;
		case 8:
			month = "August";
			break;
		case 9:
			month = "September";
			break;
		case 10:
			month = "October";
			break;
		case 11:
			month = "November";
			break;
		case 12:
			month = "December";
			break;
	}
	cout << date.getDay() << "." << month << "." << date.getYear() << endl;
}
void print4(Date date)
{
	cout << date.getYear() << "." << setw(2) << setfill('0') << date.getMonth() << "." << setw(2) << setfill('0') << date.getDay() << endl;
}















