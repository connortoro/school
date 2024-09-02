/* Book.cpp -  Book class functions
 * Author:     Connor Toro
 * Module:     13
 * Project:    Homework 13
 * Problem statement: write functions for book class
 *
 * Algorithm:
 *    1. create default constructor which sets nums to 0 and string to empty string
 *    2. create full contructor, use setters to set data
 *    3. create setters and getters for all instance variables
 	  
 */
#include "Book.h"
using namespace std;

//Constructors
Book::Book()
{
	setTitle("");
	setAuthor("");
	setPages(0);
	setCost(0);
}
Book::Book(string title, string author, int pages, double cost)
{
	setTitle(title);
	setAuthor(author);
	setPages(pages);
	setCost(cost);
}

//Setters
void Book::setTitle(string newTitle)
{
	title = newTitle;
}
void Book::setAuthor(string newAuthor)
{
	author = newAuthor;
}
void Book::setPages(int newPages)
{
	pages = newPages;
}
void Book::setCost(double newCost)
{
	cost = newCost;
}

//Getters
string Book::getTitle()
{
	return title;
}
string Book::getAuthor()
{
	return author;
}
int Book::getPages()
{
	return pages;
}
double Book::getCost()
{
	return cost;
}