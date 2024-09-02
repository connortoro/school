/* Homework15part2.cpp -  Letter and Word Counter
* Author:     Connor Toro
* Module:     15
* Project:    Homework 15
* Problem statement: Write a program that will read in multiple lines of text from the user and display a list of all the letters 
                     that occur in the text, along with the number of times each letter occurs, and a count of the number of words 
					 in the text
*
* Algorithm:
*    1. create count function which takes string vecotr and char as params. iterate through each char in each string of the vector,
        if char matches the char passed through the function incremenet the counter, then return the final count
	 2. in main, prompt for input of strings, adding each string into a vector, if strings last index is a period stop input
	 3. find amount of words by incrementing by one for each newline created and also by searching through strings and incrementing
	    for every space in string
	 4. show user number of words entered, then loop through each letter in the alphabet calling the count function and printing 
	    number of times char appears, unless the number is zero.
  
*/
#include <iostream>
#include <vector>
using namespace std;

//prototype
int count(vector<string> strings, char x);

int main()
{
	//Initialization
	int wordCount = 0;
	int amountChars;
	string input;
	vector<string> strings;
	
	//Input, stop when string end with a period
	cout << "Enter several lines of text to analyze. When done, end a line with a period: " << endl;
	while(input[input.length() - 1] != '.')
	{
		getline(cin, input);
		strings.push_back(input);
		//Incrementing word count for new line
		wordCount++;
		
		//Incremeneting word count for each space in the string entered
		for(int i = 0; i < input.length(); i++)
		{
			if (input[i] == ' ')
			{
				wordCount++;
			}
		}
	}
	
	cout << "There are " << wordCount << " words in the text." << endl;
	
	//Looping through all letters and calling count function to see how many times it appears
	for(int i = 0; i < 26; i++)
	{
		char tempChar = (char)('A' + i);
		amountChars = count(strings, tempChar);
		
		//if char doesn't appear dont print total
		if(amountChars > 0)
		{
			cout << tempChar << ": " << amountChars << endl;
		}
	}
}

//Searches through each character in each string of vector, tallying them and returning total
int count(vector<string> strings, char x)
{
	int charCount = 0;
	
	for(string str : strings)
	{
		for (char c : str)
		{
			c = toupper(c);
			if(c == x)
			{
				charCount++;
			}
		}
	}
	return charCount;
}
