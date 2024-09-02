/* Homework7part2.cpp -  Take the Train
 * Author:     Connor Toro
 * Module:     7
 * Project:    Homework 7 part 2
 * Problem statement: Write a program that finds cheapest way to purchase train tickets
 *
 * Algorithm:
 *    1. intialize variables and prompt for int input of days on train
 *    2. validate input then calculate different rates with trip amount input
 *    3. display results and then use if/else to find cheapest rate
 */
 #include <iostream>
 #include <iomanip>
 using namespace std;
 
 int main()
 {
 	//Initialization and constants
 	int trips;
 	double singleRate;
 	double packRate;
 	const double monthlyRate = 61.85;
 	const double singleCost = 5.40;
 	const double tenPackCost = 36.50;
 	const double additionalSingleCost = 4.25;
 	
 	//Input and validation
 	cout << "Please enter number of trips (1-20) you will be taking for the month: ";
 	cin >> trips;
 	
 	if (trips < 1 || trips > 20)
 	{
 		cout << "Invalid number of trips, retry." << endl;
 		exit(1);
	}
	
	//Calculating rates
	singleRate = trips * singleCost;
	packRate = ((trips / 10) * tenPackCost) + ((trips % 10) * additionalSingleCost);
	packRate = (packRate < 36.50) ? 36.50 : packRate;
	
	//Output cost of all strategies
	cout << "Buying " << trips << " single " << (trips > 1 ? "tickets" : "ticket") << " would cost you " << setprecision(2) << fixed << singleRate << endl;
	cout << "Buying " << ((trips / 10) < 1 ? 1 : (trips / 10)) << " ten " << ((trips / 10) > 1 ? "packs" : "pack") << " and " << (trips < 10 ? 0 : (trips % 10)) 
	     << " additional tickets would cost you " << setprecision(2) << fixed << packRate << endl;
	cout << "Buying the monthly pass would cost you " << setprecision(2) << fixed << monthlyRate << endl;
	
	//Finding cheapest strategy
	cout << "Your best option is buying ";
	if (singleRate < packRate && singleRate < monthlyRate)
	{
		cout << "single tickets" << endl;
	}
	else if (packRate < singleRate && packRate < monthlyRate)
	{
		cout << "the ten pack plus additional tickets" << endl;
	}
	else
	{
		cout << "the monthly pass" << endl;
	}
 	
	
	
	
 }
 
