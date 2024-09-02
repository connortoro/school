/* Lab8part3.cpp -  Multiples of 9's
 * Author:     Connor Toro
 * Module:     8
 * Project:    Lab 8 
 * Problem statement: Write a separate program which prompts for and reads an int between 0 and 9 from the user, then calculates and displays 
                      another number which is the number entered by the user multiplied by 9
 *
 * Algorithm:
 *    1. Initialize input number, first digit, second digit, and result as ints. then intializing input as string as a string.
 *    2. setup main loop that loops until sentinel value (-1) is input. then validate input is 0-9
 *    3. if input is 0 output special case, otherwise perform algorithm finding both digits, adding them together into a string, then converting the string back into an int
 	  4. output results
 */
 #include <iostream>
 #include <string>
 using namespace std;
 
 int main()
 {
 	//Initialization
 	int inputNumber, firstDigit, secondDigit, result;
 	string inputNumberAsString;
 	
 	//Main loop, exit if input is -1
 	while (true)
 	{
 		//Input
 		cout << "Please enter a whole number between 0 and 9, or -1 to exit: ";
 		cin >> inputNumber;
 		
 		//Sentinel case
 		if (inputNumber == -1)
 		{
 			cout << "Goodbye!" << endl;
			exit(0);	
		}
		//Validating input
		else if (inputNumber < 0 || inputNumber > 9)
		{
			cout << "Invalid number, retry." << endl;
		}
		//Special case if 0
		else if (inputNumber == 0)
		{
			cout << "0 times 9 is 0" << endl;
		}
		//Finding multiple of 9 using given algorithm, converting to string then to int
		else
		{
			firstDigit = inputNumber - 1;
			secondDigit = 9 - firstDigit;
			inputNumberAsString = to_string(firstDigit) + to_string(secondDigit);
			result = stoi(inputNumberAsString);
			cout << inputNumber << " times 9 is " << result << endl;
		}
	}
 }
