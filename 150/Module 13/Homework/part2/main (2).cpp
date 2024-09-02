/* Book.cpp -  Book class functions
 * Author:     Connor Toro
 * Module:     13
 * Project:    Homework 13
 * Problem statement: write functions for book class
 *
 * Algorithm:
 *    1. create monthlyexpense structure which has 5 double values for different expenses
 *    2. create input function, which takes string as param of what you are inputting, and gets input until input is valid
 *    3. create print function which takes two doubles and a strin and prints a formatted line on the budget report
	  4. create two monthlyexpense objects, one with given budget values, and one the user will input with the input() function
	  5. calculate totals of each object
	  6. call input function to prompt for input and save returned data to given variable in the object
      7. print header, then use print function with each variable on each object to print formatted report
 	  
 */

#include <iostream>
#include <iomanip>
using namespace std;

//Creating structure
struct MonthlyExpense
{
	double rent, transportation, books, food, misc;
};

//Function Prototypes
double input(string);
void print(double, double, string);

int main() 
{
	//Instantiating Objects
 	MonthlyExpense budget = {1125.00, 180.00, 65.00, 730.00, 390.00};
	MonthlyExpense spent;

	//Inputting values into spent Object
	spent.rent = input("rent");
	spent.transportation = input("transportation");
	spent.books = input("books");
	spent.food = input("food");
	spent.misc = input("misc");

	//Calculating Totals
	double budgetTotal, spentTotal;
	budgetTotal = budget.rent + budget.transportation + budget.books + budget.food + budget.misc;
	spentTotal = spent.rent + spent.transportation + spent.books + spent.food + spent.misc;

	//Ooutput
	cout << endl;
	cout << "Category              Budget      Spent    Difference" << endl;
	print(budget.rent, spent.rent, "Rent & Housing");
	print(budget.transportation, spent.transportation, "Transportation");
	print(budget.books, spent.books, "Books & Supplies");
	print(budget.food, spent.food, "Food");
	print(budget.misc, spent.misc, "Misc");
	cout << endl;
	print(budgetTotal, spentTotal, "Totals");
}

//Prompts for input of amount spent
double input(string type)
{
	double spent = 0;
	cout << "Enter " << type <<  " value: ";
	cin >> spent;

	while (spent < 0 || spent > 10000)
	{
		cout << "value must be between 0 and 10,000" << endl;
		cout << "Enter " << type <<  " value: ";
		cin >> spent;
	}
	return spent;

		
}

//Prints formatted report line
void print(double budget, double spent, string type)
{
	cout << setw(22) << left << type << "$" << setw(8) << right << setprecision(2) << fixed << budget << "  $" 
		 << setw(8) << right << setprecision(2) << fixed << spent << "  $" << setw(8) << right << setprecision(2) << fixed
		 << (budget - spent) << endl;
}