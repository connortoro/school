/* Lab6.cpp -  Train Trip
 * Author:     Connor Toro
 * Module:     6
 * Project:    Lab 6
 * Problem statement: present the user with menus of options to purchase tickets for a train trip, determine how many tickets they 
   want to purchase, and present a purchase summary and total cost to the user.
 *
 * Algorithm:
 *    1. intialize variables and constants
 *    2. prompt for destination input as int and use if else statement to destination string and fare prices
 *    3. promt for fare type and use if/else statement to get cost and save the fare type string
 	  4. promt for amount of tickets and use if/else to make sure the number is between 1 and 10, and if zero exit program normally
 	  5. calculate total cost of order using saved data from user input
 	  6. output results
 */
 #include <iostream>
 using namespace std;
 
 int main()
 {
 	//Constants
 	const string DEST_LOS_ANGELES = "Los Angeles",
 				 DEST_SANTA_MARIA = "Santa Maria",
 				 DEST_SAN_FRANCISCO = "San Franscisco";
 				 
	const string FARE_TYPE_CHILD = "Child",
				 FARE_TYPE_ADULT = "Adult",
				 FARE_TYPE_SENIOR = "Senior";
				 
	//Initialization
	double child_fare = 0.0,
		   adult_fare = 0.0,
		   senior_fare = 0.0;
	
	double fare_cost;
	double total_cost;
	int city_number;
	int fare_number;
	int amount_tickets;
	string fare_type;
	string destination;
	
	//Input (using if/else statements to store and use applicable data)
	cout << "   **** CHOOSE A DESTINATION ****\n" << endl;
	cout << "          1 - "  << DEST_LOS_ANGELES << endl;
	cout << "          2 - " << DEST_SANTA_MARIA << endl;
	cout << "          3 - " << DEST_SAN_FRANCISCO << "\n" << endl;
	cout << "    Enter your destination (1-3): ";
	cin >> city_number;
	
	if (city_number == 1)
	{
		destination = DEST_LOS_ANGELES;
		child_fare = 25;
		adult_fare = 41;
		senior_fare = 28;
	}
	else if (city_number == 2)
	{
		destination = DEST_SANTA_MARIA;
		child_fare = 36;
		adult_fare = 58;
		senior_fare = 42;
	}
	else if (city_number ==3)
	{
		destination = DEST_SAN_FRANCISCO;
		child_fare = 45;
		adult_fare = 86;
		senior_fare = 61;
	}
	else
	{
		cout << "Not a valid destination, retry." << endl;
		exit(1);
	}
	
	cout << "\n\n    Fares to " << destination << " are:\n" << endl;
	cout << "        1 - " << FARE_TYPE_CHILD << " (" << child_fare << ")" << endl;
	cout << "        2 - " << FARE_TYPE_ADULT << " (" << adult_fare << ")" << endl;
	cout << "        3 - " << FARE_TYPE_SENIOR << " (" << senior_fare << ")\n" << endl;
	cout << "  Enter your ticket type (1-3): ";
	cin >> fare_number;
	
	if (fare_number == 1)
	{
		fare_cost = child_fare;
		fare_type = FARE_TYPE_CHILD;
	}
	else if (fare_number == 2)
	{
		fare_cost = adult_fare;
		fare_type = FARE_TYPE_ADULT;
	}
	else if (fare_number == 3)
	{
		fare_cost = senior_fare;
		fare_type = FARE_TYPE_SENIOR;
	}
	else 
	{
		cout << "Not a valid fare type, retry." << endl;
		exit(2);
	}
	
	cout << "How many tickets would you like to purchase (1-10): ";
	cin >> amount_tickets;
	
	if (amount_tickets < 0 || amount_tickets > 10)
	{
		cout << "Not a valid number of tickets, retry." << endl;
		exit(3);
	}
	else if (amount_tickets == 0)
	{
		exit(0);
	}
	
	//Calculation
	total_cost = fare_cost * amount_tickets;
	
	//Output
	cout << "\n\nThe total for " << amount_tickets << " " << fare_type << " tickets to " << destination << " is $" << total_cost << endl;
	
	
	
	
	
	
 }
