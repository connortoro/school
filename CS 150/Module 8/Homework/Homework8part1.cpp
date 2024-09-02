/* Homework8part1.cpp -  Grading Summary
 * Author:     Connor Toro
 * Module:     8
 * Project:    Homework 8 part 1
 * Problem statement: Write a program to read from the user a list of exam scores and output results
 *
 * Algorithm:
 *    1. intialize variables 
 *    2. use a while loop for entering grades, if negative number is input exit loop
 *    3. use if else statement in while loop to find corresponding grade and update tally
 	  4. calculate percentages and output results, with special message for no grades case
 */
 #include <iostream>
 #include <iomanip>
 using namespace std;
 
 int main()
 {
 	//Intialization and Declaration
	int input = 0, numGrades = 0, numAs = 0, numBs = 0, numCs = 0, numDs = 0, numFs = 0;
	double percentAs, percentBs, percentCs, percentDs, percentFs;
	
	//Introduction Message
	cout << "  ********** Grade Counter **********" << endl;
	cout << "  Enter each grade on a separate line" << endl;
	cout << "  (A negative grade will end entry)\n" << endl;
	
	//Loop for entering grades which updates tallys and ends if negative number is inputed
	while (numGrades >= 0)
	{
		cout << "Enter Grade #" << (numGrades + 1) << ": ";
		cin >> input;
		
		if (input < 0)
		{
			break;
		}
		else if (input > 100)
		{
			cout << "Invalid grade, retry." << endl;
		}
		else if (input >= 90)
		{
			numAs++;
			numGrades++;
		}
		else if (input >= 80)
		{
			numBs++;
			numGrades++;
		}
		else if (input >= 70)
		{
			numCs++;
			numGrades++;
		}
		else if (input >= 60)
		{
			numDs++;
			numGrades++;
		}
		else 
		{
			numFs++;
			numGrades++;
		}
	}
	
	//calculating percentages to clean up cout statement
	percentAs = ((double) numAs / numGrades) * 100;
	percentBs = ((double) numBs / numGrades) * 100;
	percentCs = ((double) numCs / numGrades) * 100;
	percentDs = ((double) numDs / numGrades) * 100;
	percentFs = ((double) numFs / numGrades) * 100;
	
	//Output using iomanip to format percent, and special case for no grades entered
	if (numGrades == 0)
	{
		cout << "No grades were entered" << endl;
	}
	else
	{
		cout << "Total number of grades is " << numGrades << endl;
		cout << "Number of A's = " << numAs << " which is" << setw(6) << setprecision(1) << fixed << percentAs << "%" << endl;
		cout << "Number of B's = " << numBs << " which is" << setw(6) << setprecision(1) << fixed << percentBs << "%" << endl;
		cout << "Number of C's = " << numCs << " which is" << setw(6) << setprecision(1) << fixed << percentCs << "%" << endl;
		cout << "Number of D's = " << numDs << " which is" << setw(6) << setprecision(1) << fixed << percentDs << "%" << endl;
		cout << "Number of F's = " << numFs << " which is" << setw(6) << setprecision(1) << fixed << percentFs << "%" << endl;
	}
	
	
 }
