#include <iostream>
#include <vector>
using namespace std;

void showVector(vector<int> vector)
{
	int high, low;
	double sum = 0;
	
	
	high = vector[0];
	low = vector[0];
	
	for(int i = 0; i < vector.size(); i++)
	{
		sum += vector[i];
		
		if(high < vector[i])
		{
			high = vector[i];
		}
		if(low > vector[i])
		{
			low = vector[i];
		}
	}
	cout << "The vector has size " << (vector.size()) << ", the lowest value is " << low << ", and the highest is " << high
		     << " with an average of " << (sum / vector.size()) << endl;
}

int main()
{
	vector<int> vec;
	
	for (int i = 1; i <= 100; i++)
	{
		vec.push_back(i);
	}
	
	showVector(vec);
	
	for(int i = 101; i <= 200; i++)
	{
		vec.push_back(i);
	}
	
	showVector(vec);
}
