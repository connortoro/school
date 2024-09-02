/* Date.h -  Header file for date class
 * Author:     Connor Toro
 * Module:     13
 * Project:    Lab 13
 * Problem statement: 
 *
 * Algorithm:
 *    1. create 3 private int variables for month day and year
 *    2. Make prototypes of constructor, setters, and checkDates function
 *    3. create and define getter functions 
 	  
 */
 #ifndef DATE_H
 #define DATE_H
 
 #include <string>
 using namespace std;
 
 class Date 
 {
 	private:
 		int month, day, year;
 		bool checkDates();
 		
 	public:
 		//Constructor
 		Date(int month = 1, int day = 1, int year = 2000);
 		
 		//Prototypes
 		void setMonth(int newMonth);
 		void setDay(int newDay);
 		void setYear(int newYear);
 		
 		//Getters
 		int getMonth() const
 		{ return month; }
 		int getDay()
 		{ return day; }
 		int getYear() const
 		{ return year; }
 };
 
 #endif
