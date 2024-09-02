/* Homework5part2.cpp -  Strings
 * Author:     Connor Toro
 * Module:     5
 * Project:    Homework 5 part 2
 * Problem statement: Use string fucntions to create and manipulate name
 *
 * Algorithm:
 *    1. use concat and append function to create name string
 *    2. use toupper at string indexes to uppercase name
 *    3. use find function to find first and last spaces in name string
 	  4. use substr function to isolate and print middle name
 	  5. use erase fucntion to erase middle name using space indexes 
 */
 #include <iostream>
 #include <cctype>
 using namespace std;
 
 int main()
 {
 	// create lowercase name 
 	string name = "connor";
 	name += " jacob";
 	name.append(" toro");
 	cout << "My name in lower case: " <<name << endl;
 	
 	// capitalize char at proper indexes
 	name[0] = toupper(name[0]);
 	name[7] = toupper(name[7]);
 	name[13] = toupper(name[13]);
 	cout << "My name capitalized: " << name << endl;
 	
 	//find indexes of spaces in name 
 	int firstSpace = name.find(" ");
 	cout << "the first space in the name is at index " << firstSpace << endl;
 	int lastSpace = name.rfind(" ");
 	cout << "the last space in the name is at index " << lastSpace << endl;
 	
 	//use indexes to isolate middle name
	string middleName = name.substr((firstSpace + 1), (lastSpace - (firstSpace + 1)));
	cout << "My middle name is: \"" << middleName << "\"" << endl;
	
	//use indexes to cut out middle name
	name.erase(firstSpace, (lastSpace - firstSpace));
	cout << "My shortened name is: \"" << name << "\"" << endl;
 }
