/* Homework8part3.cpp -  Savings Account Balance
 * Author:     Connor Toro
 * Module:     8
 * Project:    Homework 8 part 3
 * Problem statement: Write a program that calculates the balance of a savings account at the end of a three-month period
 *
 * Algorithm:
 *    1. intialize variables and prompt for beginning balance apr, then calculate monthly percent rate
 *    2. use a for loop to iterate three times through months
 *    3. inside for loop have 2 do while loops to prompt for and validate deposit/withdrawal amounts
 	  4. update balance and calculate interest gained and add it to balance, also tallying on total withdrawals and deposits
 	  5. output results using iomanip formatting
 */
 #include <iostream>
 #include <iomanip>
 using namespace std;
 
 int main()
 {
 	//Initialization and declaration
 	double beginningBalance = 0, apr = 0, deposits = 0, withdrawals = 0, interest = 0, endingBalance = 0, monthlyPercentageRate = 0, withdrawalTotal = 0, depositTotal = 0;
 	bool valid = true;
 	
 	//Input starting numbers
 	cout << "Please enter the beginning balance: ";
 	cin >> beginningBalance;
 	cout << "Please enter the annual interest rate: ";
 	cin >> apr;
 	cout << endl;
 	
 	//Calculating monthly percentage rate
 	monthlyPercentageRate = (apr / 12) / 100;
 	endingBalance = beginningBalance;
 	
 	//For loop which loops through the three months
 	for (int i = 1; i < 4; i++)
 	{
 		//Do while loops used to validate inputs for deposit/withdrawal amounts
 		do
 		{
 			cout << "Enter the deposits for month " << i << ": ";
 			cin >> deposits;
 			
 			if (deposits < 0)
 			{
 				cout << "Invalid deposit amount, retry." << endl;
 				valid = false;
			}
			else
			{
				valid = true;
			}
		
 		} 
 		while (valid == false);
 		endingBalance += deposits;
 		
 		do
 		{
 			cout << "Enter the withdrawals for month " << i << ": ";
			cin >> withdrawals;
			if (withdrawals < 0)
			{
				cout << "Invalid withdrawal amount, retry." << endl;
				valid = false;
			}
			else if (withdrawals > endingBalance)
			{
				cout << "Can't let you overdraw, retry." << endl;
				valid = false;
			}
			else
			{
				cout << endl;
				valid = true;
			}
		}
		while (valid == false);	
		endingBalance -= withdrawals;
		
		//Calculating interest and updating values
		interest += (endingBalance * monthlyPercentageRate);
		endingBalance += (endingBalance * monthlyPercentageRate);
		withdrawalTotal += withdrawals;
		depositTotal += deposits;
	}
	
	//Output
	cout << setw(18) << left << "Beggining Balance:" << setw(10) << right << setprecision(2) << fixed << beginningBalance << endl;
	cout << setw(18) << left << "Total Withdrawals:" << setw(10) << right << setprecision(2) << fixed << withdrawalTotal << endl;
	cout << setw(18) << left << "Total Deposits:" << setw(10) << right << setprecision(2) << fixed << depositTotal << endl;
	cout << setw(18) << left << "Interest:" << setw(10) << right << setprecision(2) << fixed << interest << endl;
	cout << setw(18) << left << "Ending Balance:" << setw(10) << right << setprecision(2) << fixed << endingBalance << endl;
	
	
	
	
	
	
	
 }
