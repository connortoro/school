/* Lab11part2.cpp -  Overloading Functions
 * Author:     Connor Toro
 * Module:     11
 * Project:    Lab 11 part 2
 * Problem statement: Create function that finds number of slices from number of cuts
 *
 * Algorithm:
 *    1. create 4 overloaded action functions, one with an int as parameter, one with 1 double, one with 2 ints, and one with no parameter.
 *    2. in each function print which version was called with what data was passed through as parameter
 *    3. call all 4 functions in main 
 */
 #include <iostream>
 using namespace std;
 
 //Overloaded Functions
 void action()
 {
 	cout << "No parameter version called" << endl;
 }
 
 void action(int one)
 {
 	cout << "One int version called, received " << one << " as parameter" << endl;
 }
 
 void action(double one)
 {
 	cout << "One double version called, received " << one << " as parameter" << endl;
 }
 
 void action(int one, int two)
 {
 	cout << "Two int version called, received " << one << " and " << two << " as parameters" << endl;
 }
 
 int main()
 {
 	//Calling functions
 	action();
 	action(1);
 	action(3.234);
 	action(5, 9);
 }
