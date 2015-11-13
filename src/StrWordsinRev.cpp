/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void rev_word(char[], int, int);
void str_words_in_rev(char *input, int len)
{
	int iterator=0,iterator1;
	while (input[iterator] != '\0')
	{
		iterator1 = iterator;
		while (input[iterator1] != ' ')
		{
			iterator1++;
		}
		if (iterator != iterator1)
			rev_word(input, iterator1, iterator);
		iterator = iterator1 + 1;
		if (input[iterator] == '\0')
			break;
		else
			iterator++;
	}
}
void rev_word(char *str, int end, int start)
{
	int iterator;
	char temp;
	for (iterator = start; iterator <= (start + end) / 2; iterator++)
	{
		temp = str[iterator];
		str[iterator] = str[end];
		str[end] = temp;
		end--;
	}
}

