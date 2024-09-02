/* Homework9part2.cpp -  Deduplication
 * Author:     Connor Toro
 * Module:     9
 * Project:    Homework 9 part 2
 * Problem statement: Write a program that reads a file of numbers of type int and outputs all of those numbers 
 					  to another file, but without any duplicate numbers
 *
 * Algorithm:
 *    1. intialize input/output objects, inputNumber/lastNumber/ and counter ints, and file name strings
 *    2. prompt for input of output and input files, then open the files using input and validate that they opened succesfully
 *    3. scan in first number from input file and print it to output file, saving that number to the lastName variable
 	  4. use a while loop to scan through remaining numbers in input file incrementing input count, if the last number is the same 
	     as current input number then don't write it in, just increment duplicate counter
	  5. if number is not same as last number, then write it to output file, update last number variable and increment output counter.
	  6. Close input /output files and output results
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	//Initializing input/output objects
	ifstream input_file;
	ofstream output_file;
	
	//Declaration / Initialization
	string input_file_name;
	string output_file_name;
	int inputNumber;
	int lastNumber;
	int inputCount = 1;
	int outputCount = 0;
	int duplicateCount = 0;
	
	//Input
	cout << "Enter input file name or full path: ";
	cin >> input_file_name;
	cout << "Enter output file name or full path: ";
	cin >> output_file_name;
	
	//Opening txt documents
	input_file.open(input_file_name);
	output_file.open(output_file_name);
	
	//Validation
	if (!input_file)
	{
		cout << "Could not open " << input_file_name << " -- aborting..." << endl;
		exit(1);
	}
	if (!output_file)
	{
		cout << "Could not open " << output_file_name << " -- aborting..." << endl;
		exit(2);
	}
	
	//Scanning and outputting first number
	input_file >> inputNumber;
	lastNumber = inputNumber;
	output_file << inputNumber << endl;
	
	//Scanning through rest of file, checking if duplicate and outputting if not, while incrementing applicable counters
	while (input_file >> inputNumber)
	{
		inputCount++;
		if (lastNumber == inputNumber)
		{
			duplicateCount++;
		}
		else
		{
			outputCount++;
			output_file << inputNumber << endl;
			lastNumber = inputNumber;
		}
	}
	
	//closing files
	input_file.close();
	output_file.close();
	
	//Output
	cout << "There were " << inputCount << " number input, " << outputCount << " output, and " << duplicateCount << " duplicates." << endl;
	
	
}
