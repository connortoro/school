/* Homework5part1.cpp -  Art supplies
 * Author:     Connor Toro
 * Module:     5
 * Project:    Homework 5 part 1
 * Problem statement: Show cost of art supplies in formatted output
 *
 * Algorithm:
 *    1. set const values for cost of supplies, and set values for amount of supplies
 *    2. calculate cost of all supplies
 *    3. display the results in formatted output
 */
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//Declaration & Initialization
	const double pencilCost = 15.10;
	const double padCost = 36.25;
	const double eraserCost = 4.72;
	
	double amountPencils = 26;
	double amountPads = 60;
	double amountErasers = 6;
	
	double pencilTotal;
	double padTotal;
	double eraserTotal;
	double total;
	
	//Calculation
	pencilTotal = pencilCost * amountPencils;
	padTotal = padCost * amountPads;
	eraserTotal = eraserCost * amountErasers;
	total = pencilTotal + padTotal + eraserTotal;
	
	//Output
	cout << "        Item                    Quantity          Unit Price               Total" << endl;
	cout << setw(20) << left << "Graphite Pencil Sets" << setw(20) << right << amountPencils << setw(20) << right << setprecision(2) << fixed << pencilCost << setw(20) << right << setprecision(2) << fixed << pencilTotal << endl;
	cout << setw(20) << left << "Sketch Pads" << setw(20) << right << setprecision(0) << amountPads << setw(20) << right << setprecision(2) << fixed << padCost << setw(20) << right << setprecision(2) << fixed << padTotal << endl;
	cout << setw(20) << left << "Packs of Erasers" << setw(20) << right << setprecision(0) << amountErasers << setw(20) << right << setprecision(2) << fixed << eraserCost << setw(20) << right << setprecision(2) << fixed << eraserTotal << endl;
	cout << setw(80) << right << "========" << endl;
	cout << setw(20) << left << "Total" << setw(60) << right << total << endl;
}

