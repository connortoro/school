/* Lab9.cpp -  Grocery List
 * Author:     Connor Toro
 * Module:     9
 * Project:    Lab 9
 * Problem statement: read a grocery.txt, format and write it to an output file
 *
 * Algorithm:
 *    1. Open input files and output files, opening grocery.txt into the input_file object, then validate they were succesful
 *    2. Output header to the output file
 *    3. use a while loop with getline to store the item description, then store quantity price and unit variables, using a dummy getline
 	  4. tally on the cost of item to totalCost and output each item's formatted data into the output file, each loop writing one item's data
	  5. output   
 */
 #include <iostream>
 #include <iomanip>
 #include <fstream>
 using namespace std;
 
 int main()
 {
 	//Constants
 	const string INPUT_FILE_NAME = "grocery.txt";
 	const string OUTPUT_FILE_NAME = "output.txt";
 	
 	//Opening file streams and txt files
 	ifstream input_file;
 	ofstream output_file;
 	input_file.open(INPUT_FILE_NAME);
 	output_file.open(OUTPUT_FILE_NAME);
 	
 	//Validating opening of files
 	if (!input_file)
 	{
 		cout << "Could not open " << INPUT_FILE_NAME << " -- aborting..." << endl;
		exit(1);	
	}
	if (!output_file)
	{
		cout << "Could not open " << OUTPUT_FILE_NAME << " -- aborting..." << endl;
		exit(2);
	}
	
	//Outputting header to output file
	output_file << "  ***************** My Grocery List **************" << endl 
			    << "                                     Est.    Item" << endl
			    << "  ---------Item-------  Qnty  Unit  Unit-$   Total" << endl;
	
	//Initializing constants to be read
	string description, unit, dummy;
	int quantity;
	double price;
	double totalCost = 0;
	
	//Getting data from grocery.txt 
	while (getline(input_file, description))
	{
		input_file >> quantity;
		input_file >> price;
		getline(input_file, dummy);
		getline(input_file, unit);
		totalCost += (quantity * price);
		
		//Outputting each Items formatted data to output file
		output_file << "  " << setw(22) << left << description << setw(4) << right << quantity << "  " 
					<< setw(4) << left << unit << "  " << setw(6) << right << setprecision(2) << fixed << price
					<< "  " << setw(5) << right << setprecision(2) << fixed << (price * quantity) << endl;
		//cout << description << " " << price << " " << quantity << " " << unit << endl;
	}
	
	//Outputting final cost to output file
	output_file << "                                          -------" << endl
				<< "  " << setw(22) << left << "Grocery Total" << setw(25) << right << setprecision(2) << fixed << totalCost << endl;
	
	//Closing output and input files			
	input_file.close();
	output_file.close();
	
	
 }
