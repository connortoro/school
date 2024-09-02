/* Lab7.cpp -  Car Rental Quote
 * Author:     Connor Toro
 * Module:     7
 * Project:    Lab 7
 * Problem statement: Write a program that determines the total price to rent a car based on certain parameters 
   which the user will enter from their keyboard
 *
 * Algorithm:
 *    1. Declare constants and variables and prompt user for input of size color and days
 *    2. Store and modulate appliable data based on input, using if else and switch statements
 *    3. calculate 2 rates, 1 with weekly and daily, and 1 with rounding the weeks up
 	  4. figure out which of the 4 output scenarios needs to be used using if else (only weekly, only daily, hybrid, and weekly rounded up)
 	  5. output results using some iomanip stuff
 */
 #include <iostream>
 #include <iomanip>
 #include <cmath>
 using namespace std;
 
 int main()
 {
 	//Initialization
 	string carSize;
 	string carColor;
 	int daysToRent;
 	int colorChoice;
 	double dailyRate;
 	double weeklyRate;
 	double rate1;
 	double rate2;
 	
 	//Constants
 	const double ecoDaily = 25.50;
 	const double ecoWeekly = 120.50;
 	const double fullDaily = 37.40;
 	const double fullWeekly = 216.85;
 	
 	//Enumerated list for color choice
 	enum CarColor {WHITE = 1, BLACK, RED};
 	
 	//User Input
 	cout << "\nWhich car size would you like? (full/economy): ";
 	cin >> carSize;
 	cout << "How may days would you like to rent the car for?: ";
 	cin >> daysToRent;
 	cout << "Please choose car color:" << endl << endl
 		 << "    " << WHITE << " - White" << endl
 		 << "    " << BLACK << " - Black" << endl
 		 << "    " << RED << " - Red" << endl;
 	cin >> colorChoice;
 	
 	//Storing applicable rates bases on input
 	if (carSize == "full")
 	{
 		dailyRate = fullDaily;
		weeklyRate = fullWeekly;
		carSize = "full-sized";	
	}
	else if (carSize == "economy")
	{
		dailyRate = ecoDaily;
		weeklyRate = ecoWeekly;
	}
	else
	{
		cout << "Invalid car size, retry." << endl;
		exit(1);
	}
	
	switch (colorChoice)
	{
		case WHITE:
			carColor = "White";
			break;
		case BLACK:
			carColor = "Black";
			break;
		case RED:
			carColor = "Red";
			dailyRate = (ceil(dailyRate * 115)) / 100;
			weeklyRate = (ceil(weeklyRate * 115)) / 100;
			break;
		default:
			cout << "Invalid color option, retry." << endl;
			exit(2);
	}
	
	//Calculating both rates
	rate1 = ((daysToRent / 7) * weeklyRate) + ((daysToRent % 7) * dailyRate);
	rate2 = ((daysToRent / 7) + 1) * weeklyRate;
	
	// Output (finding applicable scenario first)	
	cout << "\n\nQuote for a " << carColor << " " << carSize << " car for " << daysToRent << (daysToRent > 1 ? " days" : " day") << endl;
	
	if (daysToRent < 7 && rate1 < rate2)
	{
		cout << daysToRent <<  (daysToRent > 1 ? " days" : " day") << " at $" << setprecision(2) << fixed << dailyRate 
		     << "/day, total $" << setprecision(2) << fixed << rate1 << endl;
	}
	else if ((daysToRent % 7) == 0 && rate1 < rate2)
	{
		cout << (daysToRent / 7) <<  ((daysToRent / 7) > 1 ? " weeks" : " week") << " at $" 
		     << setprecision(2) << fixed << weeklyRate << "/wk, total $" << setprecision(2) << fixed << rate1 << endl;
	}
	else if (rate1 < rate2)
	{
		cout << (daysToRent / 7) << ((daysToRent / 7) > 1 ? " weeks" : " week") << " at $" << setprecision(2) << fixed << weeklyRate << "/wk and " 
		     << (daysToRent % 7) << ((daysToRent % 7) > 1 ? " days" : " day") << " at $" << setprecision(2) << fixed << dailyRate
			 << "/day, total $" << setprecision(2) << fixed << rate1 << endl; 
	}
	else
	{
		cout << ((daysToRent / 7) + 1) << " weeks at $" << setprecision(2) << fixed << weeklyRate << "/wk, total $" << setprecision(2) << fixed << rate2 << endl;
	}
	
	
	
	
 	
 	
 	
 	
 	
 	
 	
 }
