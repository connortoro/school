/* Main.cpp -  Testing Book Class
 * Author:     Connor Toro
 * Module:     13
 * Project:    Homework 13
 * Problem statement: test book class
 *
 * Algorithm:
 *    1. create 4 book objects using different constructors, and set there data
 *    2. create printBook class which takes book object as param and formats and prints data using getters
 *    3. print out books using printBook() and tally on each page and cost to total, print as well
 	  
 */
#include <iostream>
#include <iomanip>
#include "Book.h"

void printBook(Book);

int main()
{
	//Declaration
	int pagesTotal;
	double costTotal;

	//Creating Book Objects
	Book book1;
	book1.setTitle("Gone With the Wild");
	book1.setAuthor("Mitchell Margaret");
	book1.setPages(1532);
	book1.setCost(45.91);
	Book book2;
	book2.setTitle("Harry Potter In Hawaii");
	book2.setAuthor("J. K. Roller");
	book2.setPages(811);
	book2.setCost(19.24);
	Book book3("Miserable", "Stephen Kong", 1047, 37.25);
	Book book4("Huckleberry Funn", "Mark Twang", 370, 14.71); 

	//Calculating Total
	pagesTotal = book1.getPages() + book2.getPages() + book3.getPages() + book4.getPages();
	costTotal = book1.getCost() + book2.getCost() + book3.getCost() + book4.getCost();

	//Output
	cout << "            Title                 Author         Pages     Cost" << endl;
	cout << "  -----------------------  -------------------  -------  --------" << endl;
	printBook(book1);
	printBook(book2);
	printBook(book3);
	printBook(book4);
	cout << "                                               ========  ========" << endl;
	cout << setw(48) << right << "TOTAL     " << setw(7) << right << pagesTotal << setw(9) << right << setprecision(2)
		 << fixed << costTotal << endl;

	
	
}

//Takes book object and prints formatted data using getters
void printBook(Book book)
{
	cout << "  " << setw(25) << left << book.getTitle() << setw(21) << left << book.getAuthor() << setw(7) << right
		 << book.getPages() << setw(8) << right << setprecision(2) << fixed << book.getCost() << endl;
}