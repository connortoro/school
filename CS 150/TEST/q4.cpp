#include <iostream>
#include <vector>
#include<fstream>
using namespace std;

void swap(vector<string> &vec, int x, int y)
{
    string temp = vec[x];
    vec[x] = vec[y];
    vec[y] = temp;
}

void selectionSort(vector<string> &vec)
{
	int smallest;
    
    for(int j = 0; j < vec.size() - 1; j ++)
    {
    	smallest = j;
    	
    	for(int k = j + 1; k <= vec.size() - 1; k++)
    	{
    		if(vec[smallest] > vec[k])
    		{
    			smallest = k;
			}
		}
		
		swap(vec, j, smallest);
	}
}

void printVector(vector<string> vec)
{
	for(int i = 0; i < vec.size(); i ++)
	{
		cout << vec[i] << " ";
	}
}

int main()
{
	string readWord;
	vector<string> vec;
	
	ifstream input_file;
	input_file.open("words.txt");
	
	while(input_file >> readWord)
	{
		vec.push_back(readWord);
	}

	printVector(vec);
	selectionSort(vec);
	cout << endl;
	printVector(vec);
	
	
}
