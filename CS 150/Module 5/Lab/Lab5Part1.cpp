/* Lab5part1.cpp -  Art supplies
 * Author:     Connor Toro
 * Module:     5
 * Project:    Lab 5 part 1
 * Problem statement: String Replacement
 *
 * Algorithm:
 *    1. setup constants and intialize string variable
 *    2. prompt for input of string with word hate in it using getline fucntion
 *    3. find starting index of "hate" in sentence, and use that to use replace fucntion to switch hate for like
 */
 #include <iostream>
 #include <iomanip>
 using namespace std;
 
 int main()
 {
 	//Initialization and Declaration
 	string original_string = "";
 	const string hate = "hate";
 	const string like = "really like";
 	
 	//Input / using getline to input a string with spaces
 	cout << "Please type a sentence about something you hate (include the word hate): ";
 	getline(cin, original_string);
 	
 	//Processing & Output / using string functions to change string
 	int start = original_string.find(hate);
 	cout << "The word \"Hate\" begins at index " << start << endl;
 	int length = hate.length();
 	original_string.replace(start, length, like);
 	cout << "It has been changed to: " << original_string << endl;
 	
 	
 }
