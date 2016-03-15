/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<stdio.h>
#include<stdlib.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int count = 0, i = 0, l = 0, j = 0, k = -1, s;
	if (Arr == NULL)
	{
		return NULL;
	}
	for (i = 0; date[i] != '\0'; i++)
	{
		l++;
	}
	for (i = 0; i<len; i++)
	{
		while (date[j] != '\0')
		{
			if (Arr[i].date[j] == date[j])
			{
				j++;
			}
			else
			{
				break;
			}

		}
		if (j == l)
		{
			k = i; break;
		}
	}
	j = 0;
	if (k == -1)
	{
		return count;
	}
	
		for (s = k; s<len; s++)
		{
			j = 0;
			while (date[j] != '\0')
			{
				if (Arr[s].date[j] == date[j])
				{
					j++;
				}
				else
				{
					count++; j = 0; break;
				}
			}


		}
		return count;
	
}