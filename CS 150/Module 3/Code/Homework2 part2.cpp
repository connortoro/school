#include <iostream>
using namespace std ;
//Calculates how many gifts can be purchased, and what the leftover is
// Connor Toro
 int main()
 {
 	double toolCost = 8.92 ;
 	double drawingCost = 16.28 ;
 	double budget = 100 ;
 	
 	int amountTools = budget / toolCost ;
 	int amountDrawings = budget / drawingCost ;
 	
 	double toolChange = budget - (toolCost * amountTools) ;
 	double drawingChange = budget - (drawingCost * amountDrawings) ;
	
	cout << "For tool sets costing $8.92 you can buy " << amountTools << " sets with $" << toolChange << " change." << endl ; 
	cout << "For drawing sets costing $16.28 you can buy " << amountDrawings << " sets with $" << drawingChange << " change." << endl ;
	
 }
