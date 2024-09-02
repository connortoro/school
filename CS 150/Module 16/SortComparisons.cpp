/* SortComparisons.cpp - Compare selection and bubble sorting algorithm performance
 * Author:     Connor Toro
 * Module:     16
 * Project:    Lab 2
 * Problem statement:  Create two identical vectors of 500 double values stored in
 *    random order.  Use a selection sort function and determine the number of
 *    comparisons and the number of swaps required.  Do the same thing using a
 *    bubble sort.  Use each of the (now sorted) vectors to determine the same
 *    thing.
 * Discussion:
 *    * Passing vectors by reference (default is by value)
 *    * Subtracting number of passes from inner loop of bubble sort
 *    * Increase number of passes by 10 -> increases results by 100
 *    * Selection sort does same work with or not vector is sorted
 *    * On unsorted vector, number of swaps for bubble sort is horrible
 *    * Bubble sort goes from worse performer to best performer when
 *      vector is already sorted.
 *    * Use of typedef to change vector from ints to doubles
 *      -- Don't forget to change initialization of vector when changing
 *         from ints to doubles.
 *
 * Algorithm
 	1. create swap function, which takes vector by reference, and two int indexes, create temp variable and set it to value at index x,
 	   set value at index x to index y, then set index y value to temp variable.
 	2. create selectionSort, takes vector, int comparisons passes and swaps, in outer loop: loop through all indexes and set small
 	   index to current index, then check all indexes after than in inner for loop checking if each index is smaller and setting
 	   smallest one to smallest index variable. once inner loop finishes, swap current index with smallest index, and repeat for 
 	   all indexes, incrementing counters at the proper places.
 	3. create bubbleSort, takes vector and int comparisons passes and swaps. create bool done = false, while not done: set done to 
 	   true and increment passes, loop through indexes starting at 0 and ending at vector.size() - passes. increment passes and 
 	   if current index is greater than index + 1, call swap function and swap the two in vector, while incrementing swaps and 
 	   setting done to false, repeat.
 */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
using namespace std ;

typedef int base_type ;                        // change to double...

// Prototypes for functions (vectors must be passed by reference)
void swap(vector<base_type> &, int, int) ;
void selectionSort(vector<base_type> &, int &, int &, int &) ;
void bubbleSort(vector<base_type> &, int &, int &, int &) ;
void showResults(string, int, int, int) ;

// constants
const int VECTOR_SIZE = 5000 ;                 // elements in the array

int main()
{
    // Create two vector of 500 double values in random order
    // First will be used by selection sort, the second by bubble sort
    vector<base_type> vector1(VECTOR_SIZE) ;
    vector<base_type> vector2(VECTOR_SIZE) ;

    srand(time(0)) ;
    for (int i = 0 ; i < VECTOR_SIZE ; i++)
    {
        vector1[i] = vector2[i] = rand() ;

        // When using doubles, use a number between 0 and 999
        // vector1[i] = vector2[i] = 1000.0 * rand() / RAND_MAX ;
    }

    int comparisons = 0,
        swaps = 0,
        passes = 0 ;
    cout << setw(40) << " " << "Compares   Swaps   Passes" << endl ;

    // Use the selection sort on vector 1 and print the results
    selectionSort(vector1, comparisons, swaps, passes) ;
    showResults("Selection sort on unsorted array", comparisons, swaps, passes) ;

    // Use the bubble sort on vector2 and print the results
    bubbleSort(vector2, comparisons, swaps, passes) ;
    showResults("Bubble sort on unsorted array", comparisons, swaps, passes) ;

    // Use the sorted vectors to compare the unsorted/sorted numbers
    selectionSort(vector1, comparisons, swaps, passes) ;
    showResults("Selection sort on sorted array", comparisons, swaps, passes) ;

    // Use the bubble sort on vector2 and print the results
    bubbleSort(vector2, comparisons, swaps, passes) ;
    showResults("Bubble sort on sorted array", comparisons, swaps, passes) ;

    // Print the first few values of each vector
    cout << "\nThe first 50 values of vector1" << endl ;
    for (int i = 0 ; i < 50 ; i++)
    {
        cout << vector1[i] << " " ;
    }

    cout << "\n\nThe first 50 values of vector2" << endl ;
    for (int i = 0 ; i < 50 ; i++)
    {
        cout << vector2[i] << " " ;
    }
    cout << endl << endl ;

    exit(0) ;
}

/* Swap two elements in a vector */
void swap(vector<base_type> &vector_to_sort, int x, int y)
{
    /******************* Complete this function *******************/
    base_type temp = vector_to_sort[x];
    vector_to_sort[x] = vector_to_sort[y];
    vector_to_sort[y] = temp;
}

/* Selection sort makes continuous passes, putting the smallest element in the
 * first element in element 0, then the next smallest in element 2, etc.
 */
void selectionSort(vector<base_type> &vector_to_sort, int &comparisons,
                   int &swaps, int &passes)
{
    comparisons = 0;
    swaps = 0;
    passes = 0;
    int smallest;
    
    //going through all indexes
    for(int j = 0; j < vector_to_sort.size() - 1; j ++)
    {
    	passes++;
    	smallest = j;
    	
    	//going through all indexes after outer loop index, and finding smallest index
    	for(int k = j + 1; k < vector_to_sort.size() - 1; k++)
    	{
    		comparisons++;
    		if(vector_to_sort[smallest] > vector_to_sort[k])
    		{
    			smallest = k;
			}
		}
		
		//swapping current index with smallest index found
		swaps++;
		swap(vector_to_sort, j, smallest);
	}

}

/* Bubble sort makes continuous passes, swapping neighboring elements to
 * put them in order.  Continue passes until there are no more swaps.
 */
void bubbleSort(vector<base_type> &vector_to_sort, int &comparisons,
                int &swaps, int &passes)
{
	comparisons = 0;
	swaps = 0;
	passes = 0;
	bool done = false;
	
	while (!done)
	{
		passes++;
		done = true;
		
		//looping through indexes
		for(int j = 0; j < vector_to_sort.size() - passes; j++)
		{
			comparisons++;
			
			//swaps to adjacent indexes if smaller one is larger
			if(vector_to_sort[j] > vector_to_sort[j + 1])
			{
				done = false;
				swaps++;
				swap(vector_to_sort, j, j + 1);
			}
		}
	}
	return;
}

// Display the results of running a sorting algorithm
void showResults(string description, int comparisons, int swaps, int passes)
{
    cout << setw(40) << left << description
         << setw(8) << right << comparisons
         << setw(8) << swaps
         << setw(8) << passes
         << endl ;
}






