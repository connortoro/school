/* Homework6part2.cpp -  Calorie Counter Revisited
 * Author:     Connor Toro
 * Module:     6
 * Project:    Homework 6 part 2
 * Problem statement: Predict a child's height, given their gender and height of their parents.
 *
 * Algorithm:
 *    1. intialize variables and constants and prompt for input of weight and activity
 *    2. calculate calories, then use if else and activity input to modulate calories
 *    3. output calories burned for each acitivty and total cals
 */
#include <iostream>
using namespace std;

int main()
{
	//Constants
	double conversionFactor = 0.0175;
	int runningMet = 10;
	int basketballMet = 8;
	int sleepingMet = 1;
	double poundsToKilo = 1 / 2.2;
	
	//Input
    cout << "Please enter your weight in pounds: ";
    double weightPounds;
    cin >> weightPounds;
    double weightKilos;
    weightKilos = weightPounds * poundsToKilo;
    
    cout << "How active are you?" << endl;
    cout << "1 - Sedentary" << endl;
    cout << "2 - Somewhat active (exercises occasionally) " << endl;
    cout << "3 - Active (exercises 3-4 times a week)" << endl;
    cout << "4 - Highly Active (exercises every day)" << endl;
    int activityInput;
    cin >> activityInput;
    
    //Processing
    double runningCals;
    runningCals = conversionFactor * runningMet * weightKilos * 30;
    double basketballCals;
    basketballCals = conversionFactor * basketballMet * weightKilos * 30;
    double sleepingCals;
    sleepingCals = conversionFactor * sleepingMet * weightKilos * 360;

	if (activityInput == 1)
	{
		runningCals *= .8;
		basketballCals *= .8;
		sleepingCals *= .8;
	}
	else if (activityInput == 3)
	{
		runningCals *= 1.2;
		basketballCals *= 1.2;
		sleepingCals *= 1.2;
	}
	else if (activityInput == 4)
	{
		runningCals *= 1.35;
		basketballCals *= 1.35;
		sleepingCals *= 1.35;
	}
    
    double totalCals;
    totalCals = runningCals + sleepingCals + basketballCals;
    
    //Output
    cout << "After running at 6mph for 30 minutes you have burned " << runningCals << " calories" << endl;
    cout << "After playing basketball for 30 minutes you have burned " << basketballCals << " calories" << endl;
    cout << "After sleeping for 6 hours you have burned " << sleepingCals << " calories" << endl;
    cout << "You have burned a total of " << totalCals << " calories" << endl;
    

    return 0;
}
