/* Lab11part1.cpp -  The Lazy Caterer's Sequence
 * Author:     Connor Toro
 * Module:     11
 * Project:    Lab 11 part 1
 * Problem statement: Create function that finds number of slices from number of cuts
 *
 * Algorithm:
 *    1. create lazy function which returns 1 if input is zero, and returns the sum of the number plus all integers below it if not 1
 *    2. initialize input int and prompt for input in main while loop, exit loop on sentinel case (-1), and validate that the number is within bounds in if / else
 *    3. if input is between 0 and 20 use the lazy function to output resulting number of slices that can be created  
 */
 #include <iostream>
 using namespace std;
 
 int sum;
 
 //Function calculates pieces from cuts
 long long lazy (int cuts)
 {
 	if (cuts == 0)
 	{
 		return 1;	
	}
	else
	{
		sum = 1;
		while (cuts > 0)
		{
			sum += cuts;
			cuts --;
		}
		return sum;	
	} 
 }
 
 
 
 int main ()
 {
	int input;
	
	while (true)
	{
		//Input
		cout << "Enter a number between 0 and 20 (or -1 to exit): ";
		cin >> input;
		
		//Sentinel value
		if (input < 0)
		{
			cout << "Goodbye!" << endl;
			exit(0);
		}
		//Validation
		else if (input > 20)
		{
			cout << "Invalid input, retry." << endl;
		}
		//Output
		else
		{
			cout << "With " << input << " cuts, you can create " << lazy(input) << " pieces." << endl;
		}
	}
 }
