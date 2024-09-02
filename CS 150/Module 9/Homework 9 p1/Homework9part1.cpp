/* Homework9part1.cpp -  Popular baby names
 * Author:     Connor Toro
 * Module:     9
 * Project:    Homework 9 part 1
 * Problem statement: Prompt for a name and see if that name is in a list of the 1,000 most common boy or girl names.
 *
 * Algorithm:
 *    1. Initialize input_file ifstream object, as well as input name and read name strings, ranks and birth amount ints, and match booleans 
 *    2. create main while loop that is exited upon entering "quit", that prompts for user inputed name to be ranked, intialize ranks to 1 and matches to false
 *    3. open girl names file, scan through each name, scanning and saving birth amount, and checking if names match. 
 		 if match, output rank and birth amount , and set match bool to true. then increment rank by 1 if no match and go to next name
 	  4. close file and do step 3 for boy names. if both girlMatch and boyMatch are false tell user no matches were found.
 */
 #include <iostream>
 #include <fstream>
 using namespace std;
 
 int main()
 {
 	//Declaring variables and ifstream object
 	ifstream input_file;
 	string inputName;
 	string readName;
 	int amountBirths;
 	int girlRank;
 	int boyRank;
 	bool girlMatch;
 	bool boyMatch;
 	
 	//Main loop
 	while (true)
 	{
 		//Input
 		cout << "Please enter a name to rank(or \"quit\" to quit): ";
 		cin >> inputName;
 		
 		//Initializing ranks and match booleans
 		girlRank = 1;
 		boyRank = 1;
 		girlMatch = false;
 		boyMatch = false;
 		
 		//exit case
 		if (inputName == "quit")
 		{
 			cout << "Goodbye!" << endl;
			exit(0); 	
		}
		
		//Opening girl names, scanning through them and checking if match, also saving birth amounts
		input_file.open("GirlNames2020.txt");
		while (input_file >> readName)
		{
			input_file >> amountBirths;
			if (readName == inputName)
			{
				cout << inputName << " is ranked " << girlRank << " among girls with " << amountBirths << " registered births." << endl;
				girlMatch = true;
			}
			girlRank++;
		}
		input_file.close();
		
		//Opening boy names, scanning through them and checking if match, also saving birth amounts
		input_file.open("BoyNames2020.txt");
		while (input_file >> readName)
		{
			input_file >> amountBirths;
			if (readName == inputName)
			{
				cout << inputName << " is ranked " << boyRank << " among boys with " << amountBirths << " registered births." << endl;
				boyMatch = true;
			}
			boyRank++;
		}
		input_file.close();
		
		//no matches case
		if (!girlMatch && !boyMatch)
		{
			cout << "No matches were found" << endl;
		}
		
	}
 	
 }
