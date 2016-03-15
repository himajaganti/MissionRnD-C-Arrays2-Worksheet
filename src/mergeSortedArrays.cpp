/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
char *older();
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int older(char *str, char *str1)
{
	int dd, mm, yyyy, dd2, mm2, yyyy2;
	dd = ((int)((str[0] - 48) * 10)) + ((int)(str[1] - 48));
	mm = ((int)((str[3] - 48) * 10)) + ((int)(str[4] - 48));
	yyyy = (((int)((str[6] - 48) * 1000)) + ((int)((str[7] - 48) * 100)) + ((int)((str[8] - 48) * 10)) + ((int)(str[9] - 48)));
	dd, mm, yyyy;
	dd2 = ((int)((str1[0] - 48) * 10)) + ((int)(str1[1] - 48));
	mm2 = ((int)((str1[3] - 48) * 10)) + ((int)(str1[4] - 48));
	yyyy2 = (((int)((str1[6] - 48) * 1000)) + ((int)((str1[7] - 48) * 100)) + ((int)((str1[8] - 48) * 10)) + ((int)(str1[9] - 48)));
	if ((yyyy == yyyy2) && (dd == dd2) && (mm == mm2))
	{
		return 0;
	}

	if ((yyyy == yyyy2) && (mm == mm2))

	{
		if (dd < dd2)
			return 1;
		else
			return 2;
	}
	if ((yyyy == yyyy2))

	{
		if (mm < mm2)
			return 1;
		else return 2;
	}

	if (yyyy < yyyy2)
	{
		return 1;
	}
	else return 2;

}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {


	int i = 0, j = 0, k = 0, l = 0, s = 0, flag = 0, m, tem = 0;
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
	i = 0; j = 0;
	while (i != ALen)
	{
		while (j != BLen)
		{
			m = older(A[i].date, B[j].date);
			if (m == 0)
			{
				temp[s] = A[i]; s++; i++;
				temp[s] = B[j]; s++; j++; break;
			}
			if (m == 2)
			{
				temp[s] = B[j]; s++; j++;

			}
			if (m == 1)
			{
				temp[s] = A[i]; s++; i++; break;
			}
		}
		if ((j == BLen) && (i != ALen))
		{
			while (i != ALen)
			{
				temp[s] = A[i]; i++; s++;
			}
		}


	}

if (j != BLen)
{
	while (j != BLen)
	{
		temp[s] = B[j]; j++; s++;
	}
}
return temp;
}
