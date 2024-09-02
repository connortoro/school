/* SearchComparisons.cpp - Compare linear vs. binary search algorithm performance
 * Author:     Connor Toro
 * Module:     16
 * Project:    Lab 1
 * Problem statement:  Create an vector of 1000 double values stored in
 *    ascending order.  Call a function which uses a linear search algorithm
 *    to locate one of the values in the vector array and return a count of
 *    the number of comparisons it makes until it finds the specified value.
 *    Call another function that uses a binary search algorithm to locate
 *    the same value in the array and return a count of the number of comparisons
 *    it makes.  Display the two counts on the screen.
 *
 * Discussion:
 *    Run the program using 1,000 elements, then run again using 100,000 elements.
 *    Notice that the numbers for linear search go up 100 times, but the numbers
 *    for the binary search go up by less than two times!
 *
 * Algorithm:
 	1. create linearSearch function, takes array int size and double key. loop through arrays elements incrementing comparisons each 
 	   time, if the key matches the array at that index, stop looking and return comparisons
    2. create binarySearch function which takes array, int size, and double key. create low and high ints and set them to the low
       and high indexes for the array. in a while loop while low < high increment comparisons and set midpoint to the middle of low
       and high. if array at midpoint index is equal to key, return comparisons and exit loop, if it is greater than the key, set
       high to midpoint - 1. otherwise set low to midpoint + 1. outside of loop return comparisons.
 */

#include <iostream>
#include <ctime>
using namespace std ;

// Prototypes for two functions, one does a linear search, the other a binary search
int linearSearch(const double[], int, double) ;
int binarySearch(const double[], int, double) ;

// constants
const int ARRAY_SIZE = 100000;                    // elements in the array

int main()
{
    // Create a vector of 1000 double values in ascending order
    double array_to_search[ARRAY_SIZE] ;
    array_to_search[0] = 0.0 ;

    srand(time(0)) ;
    double divisor = static_cast<double>(RAND_MAX) ;
    for (int i = 1 ; i < ARRAY_SIZE ; i++)
    {
        array_to_search[i] = array_to_search[i - 1] +
                               (static_cast<double>(rand())  / divisor) ;
    }

    // Run test cases for elements 271, 499, 749, and at 999.  Also run a test case
    // for one more than the last element in the array.
    // The element 499 will be the midpoint, the element 749 will be at 3/4 of
    // the array size, and the element 999 will be the last element in the array
    int max = ARRAY_SIZE - 1 ;                    // last index in array
    for (int test = 1 ; test <= 5 ; test++)
    {
        double key = 0.0 ;                        // the target number
        string description = "" ;
        switch (test)
        {
            // A random value in the first half of the array
            case 1:  key = array_to_search[271] ;
                     description = "Element #271" ;
                     break ;
            // The midpoint
            case 2:  key = array_to_search[max / 2] ;
                     description = "Element #" + to_string(max / 2) + " - midpoint" ;
                     break ;
            // A random element in the second half (at position which 3/4 of the array size)
            case 3:  key = array_to_search[max * 3 / 4] ;
                     description = "Element #" + to_string(max * 3 / 4) + " - 3/4 point" ;
                     break ;
            // The last element in the array
            case 4:  key = array_to_search[max] ;
                     description = "Element #" + to_string(max) + " - last element" ;
                     break ;
            // An value that isn't in the array
            default: key = array_to_search[max] + 1.0 ;
                     description = "not present" ;
                     break ;
        }

        cout << "Looking for " << key << " (" << description << ")" << endl
             << "   Linear search comparisons: "
             << linearSearch(array_to_search, ARRAY_SIZE, key) << endl
             << "   Binary search comparisons: "
             << binarySearch(array_to_search, ARRAY_SIZE, key) << endl << endl ;
    }
}

/* linearSearch performs a linear search on an array of doubles (sorted or not)
 *   looking for a specific target or key.  Return the total number of comparisons
 *   made, whether or not the key is found.
 */
int linearSearch(const double search_array[], int size, double key)
{
    int comparisons = 0 ;

    /******* Complete the logic to perform a linear search *****/
    for(int i = 0; i <= size; i++)
    {
    	comparisons++;
    	
    	if(key == search_array[i])
    	{
    		break;
		}
	}

    return comparisons ;
}

/* Perform a binary search for a specific key, returning the number
 *    of comparisons made whether the target is found
 */
int binarySearch(const double search_array[], int size, double key)
{
    int comparisons = 0 ;
    int low = 0 ;
    int high = size - 1 ;
    int midpoint = 0 ;

    /********** Complete the logic to perform a binary search ************/
    while(low < high)
    {
    	comparisons++;
		midpoint = (low + high) / 2.0;
		
		if(search_array[midpoint] == key)
		{
			return comparisons;
			break;
		}
		else if(search_array[midpoint] > key)
		{
			high = midpoint - 1;
		}
		else
		{
			low = midpoint + 1;
		}
			
	}

    // Return the number of comparisons made
    return comparisons ;
}










