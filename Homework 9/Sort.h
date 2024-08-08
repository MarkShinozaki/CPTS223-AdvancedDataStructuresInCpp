#ifndef SORT_H
#define SORT_H

/**
 * Several sorting routines.
 * Arrays are rearranged with smallest item first.
 */

#include <vector>
#include <functional>
#include <iostream>	// HW9

using namespace std;

// HW9: Following function added to output given array
template <typename Comparable>
void printVector (vector<Comparable> & a)
{
  cout << "A =";
  for (int i = 0; i < a.size(); i++)
    cout << " " << a[i];
  cout << endl;
}

/**
 * Simple insertion sort.
 */
template <typename Comparable>
void insertionSort( vector<Comparable> & a )
{
	// HW9: Add counter and initialize
	int count = 0;
	
    for( int p = 1; p < a.size( ); ++p )
    {
        Comparable tmp = std::move( a[ p ] );

        int j;
        for( j = p; j > 0 && tmp < a[ j - 1 ]; --j ) {
        	
        	// HW9: If made it into the loop body, then must have done 'tmp < a[j-1]' comparison
        	count++;
        	
            a[ j ] = std::move( a[ j - 1 ] );
        }
        
        // HW9: If exited loop, and j>0, then must have done 'tmp < a[j-1]' comparison
        if (j > 0) count++;
        
        a[ j ] = std::move( tmp );
    }
    
    // HW9: Output comparison count for insertionSort
    cout << "insertionSort comparisons = " << count << endl;
}


/**
 * Internal insertion sort routine for subarrays
 * that is used by quicksort.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void insertionSort( vector<Comparable> & a, int left, int right )
{
    for( int p = left + 1; p <= right; ++p )
    {
        Comparable tmp = std::move( a[ p ] );
        int j;

        for( j = p; j > left && tmp < a[ j - 1 ]; --j )
            a[ j ] = std::move( a[ j - 1 ] );
        a[ j ] = std::move( tmp );
    }
}



/**
 * Shellsort, using Shell's (poor) increments.
 */
template <typename Comparable>
void shellsort( vector<Comparable> & a )
{
    for( int gap = a.size( ) / 2; gap > 0; gap /= 2 )
        for( int i = gap; i < a.size( ); ++i )
        {
            Comparable tmp = std::move( a[ i ] );
            int j = i;

            for( ; j >= gap && tmp < a[ j - gap ]; j -= gap )
                a[ j ] = std::move( a[ j - gap ] );
            a[ j ] = std::move( tmp );
        }
}

/**
 * Standard heapsort.
 */
template <typename Comparable>
void heapsort( vector<Comparable> & a )
{
    for( int i = a.size( ) / 2 - 1; i >= 0; --i )  /* buildHeap */
        percDown( a, i, a.size( ) );
    for( int j = a.size( ) - 1; j > 0; --j )
    {
        std::swap( a[ 0 ], a[ j ] );               /* deleteMax */
        percDown( a, 0, j );
    }
}

/**
 * Internal method for heapsort.
 * i is the index of an item in the heap.
 * Returns the index of the left child.
 */
inline int leftChild( int i )
{
    return 2 * i + 1;
}

/**
 * Internal method for heapsort that is used in
 * deleteMax and buildHeap.
 * i is the position from which to percolate down.
 * n is the logical size of the binary heap.
 */
template <typename Comparable>
void percDown( vector<Comparable> & a, int i, int n )
{
    int child;
    Comparable tmp;

    for( tmp = std::move( a[ i ] ); leftChild( i ) < n; i = child )
    {
        child = leftChild( i );
        if( child != n - 1 && a[ child ] < a[ child + 1 ] )
            ++child;
        if( tmp < a[ child ] )
            a[ i ] = std::move( a[ child ] );
        else
            break;
    }
    a[ i ] = std::move( tmp );
}


/**
 * Internal method that merges two sorted halves of a subarray.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * leftPos is the left-most index of the subarray.
 * rightPos is the index of the start of the second half.
 * rightEnd is the right-most index of the subarray.
 */
template <typename Comparable>
int merge( vector<Comparable> & a, vector<Comparable> & tmpArray, // HW9: Returns int count of comparisons
            int leftPos, int rightPos, int rightEnd )
{
	// HW9: Add counter and initialize
	int count = 0;
	
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    // Main loop
    while( leftPos <= leftEnd && rightPos <= rightEnd )
    { // HW9
    	
    	// HW9: About to do comparison, so increment counter
    	count++;
    
        if( a[ leftPos ] <= a[ rightPos ] )
            tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );
        else
            tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );
    } // HW9

    while( leftPos <= leftEnd )    // Copy rest of first half
        tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );

    while( rightPos <= rightEnd )  // Copy rest of right half
        tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );

    // Copy tmpArray back
    for( int i = 0; i < numElements; ++i, --rightEnd )
        a[ rightEnd ] = std::move( tmpArray[ rightEnd ] );
    
    // HW9: Output comparison count for insertionSort
    return count;
}

/**
 * Internal method that makes recursive calls.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
int mergeSort( vector<Comparable> & a,	// HW9: Returns int count of total comparisons
                vector<Comparable> & tmpArray, int left, int right )
{
	// HW9: Add counter and initialize
	int count = 0;
	
    if( left < right )
    {
        int center = ( left + right ) / 2;
        count += mergeSort( a, tmpArray, left, center );		// HW9: increment comparison counter
        count += mergeSort( a, tmpArray, center + 1, right );	// HW9: increment comparison counter
        count += merge( a, tmpArray, left, center + 1, right );	// HW9: increment comparison counter
    }
    return count;	// HW9: Return total count of comparisons for this call
}

/**
 * Mergesort algorithm (driver).
 */
template <typename Comparable>
void mergeSort( vector<Comparable> & a )
{
	// HW9: Add counter and initialize
	int count;
		
    vector<Comparable> tmpArray( a.size( ) );

    count = mergeSort( a, tmpArray, 0, a.size( ) - 1 );	// HW9: Retain total comparisons
    
    // HW9: Output total comparisons
    cout << "mergeSort comparisons = " << count << endl;
}


/**
 * Return median of left, center, and right.
 * Order these and hide the pivot.
 */
template <typename Comparable>
const Comparable & median3( vector<Comparable> & a, int left, int right )
{
    int center = ( left + right ) / 2;
    
    if( a[ center ] < a[ left ] )
        std::swap( a[ left ], a[ center ] );
    if( a[ right ] < a[ left ] )
        std::swap( a[ left ], a[ right ] );
    if( a[ right ] < a[ center ] )
        std::swap( a[ center ], a[ right ] );

        // Place pivot at position right - 1
    std::swap( a[ center ], a[ right - 1 ] );
    return a[ right - 1 ];
}

/**
 * Internal quicksort method that makes recursive calls.
 * Uses median-of-three partitioning and a cutoff of 10.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void quicksort( vector<Comparable> & a, int left, int right )
{
	// HW9: Following 2 lines added to output beginning of quickSort
	cout << "quicksort(A," << left << "," << right << "):\n  Initial ";
	printVector (a);
	    
    if( left + 3 <= right )
    {
        const Comparable & pivot = median3( a, left, right );
        
        // HW9: Following line added to output chosen pivot
        cout << "  pivot = " << pivot << endl;;

            // Begin partitioning
        int i = left, j = right - 1;
        for( ; ; )
        {
            while( a[ ++i ] < pivot ) { }
            while( pivot < a[ --j ] ) { }
            if( i < j )
                std::swap( a[ i ], a[ j ] );
            else
                break;
        }

        std::swap( a[ i ], a[ right - 1 ] );  // Restore pivot
        
        
        // HW9: Following 3 lines added to output result of partitioning
        cout << "  Partitioned ";
        printVector (a);
        cout << endl;

        quicksort( a, left, i - 1 );     // Sort small elements
        quicksort( a, i + 1, right );    // Sort large elements
    }
    else  // Do an insertion sort on the subarray
    {
        insertionSort( a, left, right );
        
        // HW9: Following 3 lines added to output results of insertionSort
        cout << "  After insertionSort(A," << left << "," << right << ") ";
        printVector (a);
        cout << endl;
    }
}

/**
 * Quicksort algorithm (driver).
 */
template <typename Comparable>
void quicksort( vector<Comparable> & a )
{
    quicksort( a, 0, a.size( ) - 1 );
}

#endif
