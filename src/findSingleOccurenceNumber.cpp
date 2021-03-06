/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
int findSingleOccurenceNumber(int *A, int len)
{
	int i, max, *b, count = 0;
	if ((A == NULL))
	{
		return -1;
	}
	max = A[0];
	
	for (i = 0; i<len; i++)
	{
		if (A[i]>max)
		{
			max = A[i];
		}
	}
	b = (int *)calloc(300, sizeof(int));

	for (i = 0; i<len; i++)
	{
		b[A[i]]++;
	}

	i = 0;
	for (i = 0; i <= max; i++)
	{
		if (b[i] == 1)
		{
			count = i;
		}
	}

	return count;
}