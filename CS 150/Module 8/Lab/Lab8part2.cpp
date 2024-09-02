/* Lab8part2.cpp -  Divi
 * Author:     Connor Toro
 * Module:     8
 * Project:    Lab 8 
 * Problem statement: Write a program that asks the user to enter the size of a triangle to print (an integer from 1 to 20), 
                      then create the triangle by printing a series of lines consisting of asterisks
 *
 * Algorithm:
 *    1. Prompt for whole number input as string in while loop that repeats until exited (when enter 0)
 *    2. Initalize input as string, char for converting string indexes into ints, and sum value to 0
 *    3. use a for loop that loops through the length of the string, converting each string index into a char then into an int, then add value to the sum
 	  4. use if else to determine if number is divisble by 9 by using modulo on the sum of the digits, or exit if sum is 0
 */
 #include <iostream>
 using namespace std;
 
 int main()
 {
 	//Main loop
 	while (true)
 	{
		//Input and intialization
	 	cout << "Please enter a whole number: ";
	 	string inputNumber;
	 	char charAtIndex;
	 	cin >> inputNumber;
	 	int sum = 0;
	 	
	 	//Loop through string adding digits to the sum
	 	for (int i = 0; i < inputNumber.length(); i ++)
	 	{
	 		charAtIndex = inputNumber[i];
	 		sum += charAtIndex - '0';
		}
		
		//determining if number is divisble by 9 using sum, or exit if sum is zero
		if (sum == 0)
		{
			cout << "Goodbye!" << endl;
			exit(0);
		}
		else if ((sum % 9) == 0)
		{
			cout << inputNumber << " is divisble by 9 as its digits add to " << sum << endl;	
		}
		else
		{
			cout << inputNumber << " is not divisble by 9 as its digits add to " << sum << endl;	
		}
	}
 }
