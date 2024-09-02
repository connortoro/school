/* Homework14part1.cpp -  Girls soccer team
* Author:     Connor Toro
* Module:     14
* Project:    Homework 14
* Problem statement: read txt file to arrays and print report
*
* Algorithm:
*    1. create ifstream object and open players.txt
     2. declare input string goals and assists variables as well as initialize count int to 0
     3. create names, goals, and assists arrays of size 20;
     4. in while loop read in first name into inputString and add it to names[count], then read it last name and concatenate it onto
        names[count] with a space seperating them. then read in goals and assists into their arrays at index count, then increment count
	 5. close input file and print header for columnar report
	 6. loop through the arrays for count number of times printing the data from them in a formatted report, calculating performance
	    as assists + (3 * goals)
*   
  
*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	//Opening input file
	ifstream input_file;
	input_file.open("Players.txt");
	
	//Declarationg & Initialization
	string inputString;
	int count = 0;
	string names[20];
	int goals[20];
	int assists[20];
	
	//Reading data from the array
	while(input_file >> inputString)
	{
		names[count] = inputString;
		input_file >> inputString;
		names[count] += " " + inputString;
		
		input_file >> goals[count];
		input_file >> assists[count];
		
		//Incrementing to get index
		count++;
	}
	input_file.close();
	
	//Output
	cout << "Name                   Goals Assists Performance" << endl;
	for(int i = 0; i < count; i++)
	{
		cout << setw(20) << left << names[i] << setw(8) << right << goals[i] << setw(8) << right << assists[i] << setw(8) << right
		     << (assists[i] + (3 * goals[i])) << endl;
	}
	
}
