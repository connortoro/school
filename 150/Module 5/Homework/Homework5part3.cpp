/* Homework5part3.cpp -  Arithmetic Problem
 * Author:     Connor Toro
 * Module:     5
 * Project:    Homework 5 part 3
 * Problem statement: Write a program that can be used to exercise a young student's ability to add numbers
 *
 * Algorithm:
 *    1. use srand with clock creat pseudo-random rand function
 *    2. use rand function to create pseudo random integers between 1 and 999
 *    3. display number and ask user for the total
 	  4. show actual answer versus user input
 */
 #include <iostream>
 #include <ctime>
 #include <iomanip>
 using namespace std;
 
 int main()
 {  
 	//Using clock values to creat pseudo-random rand fucntion
 	srand(time(NULL));
 	
 	//Using rand function to create pseudo-random values between 1 and 999
	int first = rand()%999 + 1;
	int second = rand()%999 + 1;
	int third = rand()%999 + 1;
	int fourth = rand()%999 + 1;
	int total = first + second + third + fourth;
	int input;
	
	//Output
	cout << setw(10) << right << first << endl;	
	cout << setw(10) << right << second << endl;	
	cout << setw(10) << right << third << endl;
	cout << setw(7) << right << "+ " << setw(3) << right << fourth << endl;
	cout << "Total? ";
	cin >> input;
	cout << "Correct Answer: " << total << endl;
	cout << "Your Answer: " << input << endl;
	
 }
