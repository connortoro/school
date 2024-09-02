/* Book.h -  Header file for book class
 * Author:     Connor Toro
 * Module:     13
 * Project:    Homework 13
 * Problem statement: write header for book class
 *
 * Algorithm:
 *    1. define book header 
 *    2. create private instance variables for strings title and author, integer pages, and double cost
 *    3. create prototypes for setters/getters/constructors
 	  
 */
 
#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
using namespace std;

class Book
{
	private:
		string title, author;
		int pages;
		double cost;
		
	public:
		//Constructors
		Book();
		Book(string title, string author, int pages, double cost);

		//Getters
		string getTitle();
		string getAuthor();
		int getPages();
		double getCost();

		//Setters
		void setTitle(string newTitle);
		void setAuthor(string newAuthor);
		void setPages(int newPages);
		void setCost(double newCost);
};
#endif