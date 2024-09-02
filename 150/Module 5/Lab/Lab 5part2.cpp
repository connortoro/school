/* Lab5part2.cpp -  Format a Budget Report
 * Author:     Connor Toro
 * Module:     5
 * Project:    Lab 5 part 2
 * Problem statement: format a monthly budget report with four expense items and an expense amount for each item
 *
 * Algorithm:
 *    1. declare variables and data
 *    2. calculate total cost
 *    3. format report output using iomanip fucntions
 */
 #include <iostream>
 #include <iomanip>
 using namespace std;
 
 int main()
 {
 	//Declaration & Initialization
 	string d1 = "Apartment";
 	string d2 = "Food";
 	string d3 = "Utilities and Gas";
 	string d4= "Miscellaneous";
 	
 	double c1 = 1497.82;
 	double c2 = 325.00;
 	double c3 = 270.00;
 	double c4 = 91.40;
 	double total = c1 + c2 + c3 + c4;
 	
 	string dashes;
 	dashes.assign("-------------------------------");
 	
 	//Output
 	cout << setw(22) << left << "    Item" << setw(9) << left << "Expense" << endl;
 	cout << dashes << endl;
 	cout << setw(21) << left << d1 << "$" << setw(9) << right << setprecision(2) << fixed << c1 << endl;
 	cout << setw(21) << left << d2 << "$" << setw(9) << right << setprecision(2) << fixed << c2 << endl;
 	cout << setw(21) << left << d3 << "$" << setw(9) << right << setprecision(2) << fixed << c3 << endl;
 	cout << setw(21) << left << d4 << "$" << setw(9) << right << setprecision(2) << fixed << c4 << endl;
 	cout << setw(31) << right << "==========" << endl;
 	cout << setw(21) << left << "   (Total)" << "$" << setw(9) << right << setprecision(2) << fixed << total << endl;
 }
