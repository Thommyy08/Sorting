// sorting.cpp : Defines the entry point for the console application.
// An array with n random elements will be created and sorted using different algorithms
// The runtime of the different algorithms will be timed

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// TODO Check if char is permitted in C++
//gnuqsort(char *base_ptr, int total_elems, int size, int(*cmp)());

// Initialize the values array and calculate the number of elements in the array "divide the total size of the array by the size of the array element"
int values[100000];
int length = sizeof(values) / sizeof(int);

int cmpfunc(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}



int main()
{
	// Initializa random number generator seed (time) and n
	std::srand(std::time(0));
	int n;

	// Fill array with random variables
	for (n = 0; n < length; n++)
	{
		values[n] = std::rand();
	}

	// Optional printing of the generated array before sorting
	//printf("Before sorting the list is: \n");
	//for (n = 0; n < length; n++)
	//{
	//	printf("%d ", values[n]);
	//}


	// Start of timer
	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	//qsort
	qsort(values, length, sizeof(int), cmpfunc);

	//timsort

	//P3

	//P plus

	// End of timer
	high_resolution_clock::time_point t2 = high_resolution_clock::now();


	// Optional printing of the array after sorting
	//printf("\nAfter sorting the list is: \n");
	//for (n = 0; n < length; n++)
	//{
	//	printf("%d ", values[n]);
	//}

	//Calculate execution time
	auto duration = duration_cast<microseconds>(t2 - t1).count();
	
	printf("\nTime needed for sorting: %d microseconds ", duration);

    return 0;
}

