/* Lab4part3.cpp -  Adjust a Recipe
 * Author:     Connor Toro
 * Module:     4
 * Project:    Lab 4 Part 3
 * Problem statement: Take user input for amount of cookies wanted and adjust recipe accordingly
 *
 * Algorithm:
 *    1. promt user for input of amount of cookies as int
 *    2. divide input by 48 to find ratio of the given recipe to required recipe
 *    3. multiply recipe ingredients by ratio
 *    4. diplay results
 */
 
 #include <iostream>
 using namespace std;
 
 int main()
 {
 	//Declaration & Initialization
 	const double cupsSugar = 1.5;
 	const double cupsButter = 1;
 	const double cupsFlour = 2.75;
 	const int recipeAmount = 48;
 	int amountCookies;
 	double ratio;
 	
 	//Input
 	cout << "How many cookies would you like to make? ";
 	cin >> amountCookies;
 	
 	//Calculation (finds ratio to modify given recipe with)
 	ratio = ((double) amountCookies) / recipeAmount;
 	
 	//Output
 	cout << "To make " << amountCookies << " cookies you will need:" << endl;
 	cout << (ratio * cupsSugar) << " cups of sugar" << endl;
 	cout << (ratio * cupsButter) << " cups of butter" << endl;
 	cout << (ratio * cupsFlour) << " cups of flour" << endl;
 }
 
