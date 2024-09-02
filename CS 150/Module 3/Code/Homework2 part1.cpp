#include <iostream>
using namespace std ;
//Calculates cost of an uber from 4 variables
// Connor Toro
int main()
{
	//Initilization 
	double airportFee = 2.51 ;
	double upfrontCharge = 3.72 ;
	double distanceCharge = 19.86 ;
	double tip ;
	double total ;
	
	//Processing
	tip = (upfrontCharge + distanceCharge) *.08 ;
	total = airportFee + upfrontCharge + distanceCharge + tip ;
	
	//Output
	cout << "The airport fee is $" << airportFee << endl ; 
	cout << "The upfront charge is $" << upfrontCharge << endl ;
	cout << "The distance charge is $" << distanceCharge << endl ;
	cout << "The tip is $" << tip << endl ;
	cout << "The total is $" << total << endl ;
}
