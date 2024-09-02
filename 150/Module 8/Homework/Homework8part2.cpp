/* Homework8part2.cpp -  Stereo System Loan Payoff
 * Author:     Connor Toro
 * Module:     8
 * Project:    Homework 8 part 2
 * Problem statement: Write a program that tracks loan and tell you how many months you have left and how much interest you have paid
 *
 * Algorithm:
 *    1. intialize variables 
 *    2. use while loop, while there is still debt, to calculate interest payment and new debt amount, and tally interest paid and months.
 *    3. output results while formatting money using iomanip
 */
 #include <iostream>
 #include <iomanip>
 using namespace std;
 
 int main()
 {
 	//Constants
 	const double loan = 1000;
 	const double monthlyPayment = 50;
 	const double apr = .18;
 	
 	//Initialization and Declaration
 	double debt = loan;
 	double interest;
 	double interestPaid;
 	int months = 0;
 	
 	//While loop to find interest paid and amount of months needed to pay off debt
 	while (debt > 0)
 	{
 		interest = debt * (apr / 12);
 		debt -= (monthlyPayment - interest);
 		months++;
 		interestPaid += interest;
	}
	
	//Output
	cout << "It will take " << months << " months to pay of your loan and you will pay $" << setprecision(2) << fixed << interestPaid << " in interest" << endl;
	
 }
