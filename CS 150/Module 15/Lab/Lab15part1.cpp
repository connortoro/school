/* Lab15part1.cpp - Famous Students Vector
 * Author:     Connor Toro
 * Module:     15
 * Project:    Lab 15
 * Problem statement: create vector of structs
 *
 * Algorithm:
 *    1. create structure containing string name and major, double gpa, and int years, then create vector of structs
 *    2. create objects of struct and fill with data of students
 *    3. use push_back, pop_back, and insert functions to change vector
      4. iterate through vector and print each students data out
 	  
 */
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//Creating structure
struct Student
{
	string name;
	string major;
	double gpa;
	int years;
};

int main()
{
	//Creating vector of student structs
	vector<Student> students;
	
	//Creating student structs objects
	Student isaac{"Isaac Newton", "Physics", 4.0, 1};
	Student jane{"Jane Goodall", "Anthropology", 3.9, 2};
	Student carlos{"Carlos Santana", "Music", 3.8, 2};
	Student kamehameha{"Kamehameha", "Leadership", 3.8, 1};
	Student jim{"Jim Thorpe", "Athletics/Acting", 3.7, 2};
	
	//Adding students to vector
	students.push_back(isaac);
	students.push_back(jane);
	students.push_back(carlos);
	students.push_back(kamehameha);
	students.push_back(jim);

	//Deleting last student struct from vecotr
	students.pop_back();
	
	//Creating and adding new student to end of vecotr
	Student grace{"Grace Hopper", "Mathematics", 3.8, 1};
	students.push_back(grace);
	
	//Creating and inserting student into vector
	Student dorothy = {"Dorothy Vaughn", "Mathematics", 4.0, 3};
	students.insert(students.begin() + 3, dorothy);

    
    //Formatted output of all members in vector and all data in each object
    for(int i = 0; i < students.size(); i++)
    {
    	cout << setw(17) << left << students[i].name << setw(17) << left << students[i].major << setw(6) << left << setprecision(1)
    	<< fixed << students[i].gpa << setw(6) << left << students[0].years << endl;
	}

	
}
