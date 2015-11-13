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
void string_reverse(char[], int);
void str_words_in_rev(char *input, int len)
{
	int iterator = 0, iterator1;
	while (iterator < len)
	{
		iterator1 = iterator;
		while (input[iterator1] != ' ' && input[iterator1] != '\0')
		{
			iterator1++;
		}
		if (iterator != iterator1)
		{

			rev_word(input, iterator1 - 1, iterator);
		}
		iterator = iterator1 + 1;
	}
	string_reverse(input, iterator - 2);
}
void rev_word(char *str, int end, int start)
{
	int iterator, end_copy = end;
	char temp;
	for (iterator = start; iterator <= ((start + end) / 2); iterator++)
	{
		temp = str[iterator];
		str[iterator] = str[end_copy];
		str[end_copy] = temp;
		end_copy--;
	}
}
void string_reverse(char string[], int len)
{
	int cpy_len = len, iterator = 0;
	char temp;
	while (cpy_len > len / 2)
	{
		temp = string[iterator];
		string[iterator++] = string[cpy_len];
		string[cpy_len--] = temp;
	}
}