/* Lab4part2.cpp -  Monetary Conversions
 * Author:     Connor Toro
 * Module:     4
 * Project:    Lab 4 Part 1
 * Problem statement: uses user input USD and shows converted value of five currencies
 *
 * Algorithm:
 *    1. promt user for input of USD as int
 *    2. calculate exchange to other currencies using exchange const
 *    3. display the results
 */
 
 #include <iostream>
 using namespace std;
 
 int main()
 {
 	//Declaration & Initialization
 	const double dollarToEuro = 0.94;
 	const double dollarToYen = 135.39;
 	const double dollarToYuan = 6.69;
 	const double dollarToRupee = 78.47;
 	const double dollarToPeso = 19.91;
 	const double dollarToCanadian = 1.29;
 	int usd;
 	
 	//Input
 	cout << "Please enter an amount of money (in USD): ";
 	cin >> usd;
 	
 	//Output
 	cout << "$" << usd << " USD is worth " << (usd * dollarToEuro) << " Euros" << endl;
 	cout << "$" << usd << " USD is worth " << (usd * dollarToYen) << " Yen" << endl;
 	cout << "$" << usd << " USD is worth " << (usd * dollarToYuan) << " Yuan" << endl;
 	cout << "$" << usd << " USD is worth " << (usd * dollarToRupee) << " Rupees" << endl;
 	cout << "$" << usd << " USD is worth " << (usd * dollarToPeso) << " Pesos" << endl;
 	cout << "$" << usd << " USD is worth " << (usd * dollarToCanadian) << " Canadian dollars" << endl;
 }
