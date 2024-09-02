#include <iostream>
using namespace std;

int main()
{
	bool valid = false;
	double spent;

	while(!valid)
	cout << "Enter rent value: ";
	cin >> spent;

	if (spent < 0 || spent > 10000)
	{
		cout << "Amount must be between 0 and 10,000, retry..." << endl;
	}
	else
	{
		valid = true;
	}
}
