/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31

char ** commonWords(char *str1, char *str2)
{
	char **output;
	output = (char **)malloc(SIZE * sizeof(char *));

	for (int index = 0; index<SIZE; index++)
	{
		output[index] = (char*)malloc(SIZE * sizeof(char));
	}
	int iterator = 0, iterator1, count1 = 0, count2 = 0, iterator2 = 0, count = 0, iterator3 = 0, iterator4 = 0, iterator5 = 0, iterator6 = 0, cpy_it = 0;
	if (str1 == "" || str1 == nullptr || str2 == "" || str2 == nullptr)
		return NULL;
	else
	{
		while (str1[iterator] != '\0')
		{
			iterator1 = iterator;
			cpy_it = iterator;
			while (str1[iterator1] != ' '  && str1[iterator1] != '\0')
			{
				count1++;
				iterator1++;
			}
			while (str2[iterator2] != '\0')
			{
				iterator6 = iterator2;
				while (str2[iterator6] != ' ' && str2[iterator6] != '\0')
				{
					count2++;
					iterator6++;
				}
				if (count1 == count2  && count1 != 0 && count2 != 0)
				{
					for (iterator3 = iterator2; iterator3 < iterator2 + count1; iterator3++)
					{
						if (str1[cpy_it] == str2[iterator3])
						{
							count++;
							cpy_it++;
						}
						else
							break;
					}
					if (count == count1)
					{
						for (iterator4 = 0; iterator4 < count1; iterator4++)
						{
							output[iterator5][iterator4] = str1[iterator];
							iterator++;
						}
						output[iterator5][iterator4] = '\0';
						iterator5++;
						iterator4 = 0;
					}
				}
				iterator2 = iterator6 + 1;
				count2 = 0;
				count = 0;
			}
			iterator = iterator1 + 1;
			count1 = 0;
			count2 = 0;
			count = 0;
			iterator2 = 0;
			iterator6 = 0;
		}
	}
	if (iterator5 == 0)
		return NULL;
	else
		return output;
}