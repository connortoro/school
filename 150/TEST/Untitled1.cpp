#include <iostream>
using namespace std;
int x = 1, y = 2;
void sort(int &first, int &second)
{
	x = second;
	y = first;
}

int main()
{
	sort(x, y);
	cout << x << " " << y << endl;
	
}
