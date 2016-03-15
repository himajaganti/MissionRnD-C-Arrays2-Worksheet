/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<stdio.h>
#include<stdlib.h>

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {

	int i = 0, j = 0, k = 0, l = 0, s = 0,flag=0;
	struct transaction *temp;
	temp = (struct transaction *)malloc(11 * sizeof(struct transaction));
	for (i = 0; i<11; i++)
	{
		for (j = 0; j<12; j++)
		{
			temp[i].date[j] = '\0';
			temp[i].description[j] = '\0';
			temp[i].amount = 0;
		}
	}
	if ((A == NULL) || (B == NULL))
	{
		return NULL;
	}
	for (i = 0; i<ALen; i++)
	{
		l = 0;
		for (k = 0; A[i].date[k] != '\0'; k++)
		{
			l++;
		}
		for (j = 0; j<BLen; j++)
		{
			k = 0;
			while (A[i].date[k] != '\0')
			{
				if (A[i].date[k] == B[j].date[k])
				{
					k++;
				}
				else
				{
					break;

				}
			}
			if (k == l)
			{
				temp[s] = B[j]; s++; flag = 1; break;
			}

		}
	}
	
	if (flag == 0)
	{
		return NULL;
	}
	
	return temp;

}
