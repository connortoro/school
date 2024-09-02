#include <iostream>
using namespace std;
//This program shows some of the ways data types interact in c++ 
// Connor Toro
int main() 
{
	int largest = 2147483647 ;
	cout << "The integer " << largest << " is " << sizeof(largest) << " bytes" << endl ;
	largest += 1 ;
	cout << "Adding one to the largest int gives " << largest << " which is " << sizeof(largest) << " bytes\n" << endl ;
	
	unsigned long long int smallest = 0 ;
	cout << "The unsigned long long int " << smallest << " is " << sizeof(smallest) << " bytes" << endl ;
	smallest -= 1 ;
	cout << "Subtracting one from the unsigned long long int gives " << smallest << " which is " << sizeof(smallest) << " bytes\n" << endl ;
	
	double largeNumber = 1.7e308 ;
	cout << "The double " << largeNumber << " is " << sizeof(largeNumber) << " bytes" << endl ;
	largeNumber *= 2 ;
	cout << "Doubling the double gives " << largeNumber << " which is " << sizeof(largeNumber) << " bytes\n" << endl ;
	
	double divideZero = 5.0 ;
	cout << "The double " << divideZero << " is " << sizeof(divideZero) << " bytes" << endl ;
	divideZero /= 0.0 ;
	cout << "Dividing the double by 0.0 gives " << divideZero << " which is " << sizeof(divideZero) << " bytes\n" << endl ;
	
	int notAnInteger = 9.999999 ;
	cout << "The number 9.999999 has been truncated to " << notAnInteger << " after assigning it to the integer data type\n" << endl ;
	
	cout << "The value of 5 is " << (5) << endl ;
	cout << "The value of '5' is " << ('5') << endl ;
	cout << "The value of \"5\" is " << ("5") << endl ;
	cout << "The value of 5 + 1 is " << 5 + 1 << endl ;
	cout << "The value of '5' + 1 is " << ('5' + 1) << endl ;
	cout << "The value of \"5\" + 1 is " << ("5" + 1) << endl ;
}
