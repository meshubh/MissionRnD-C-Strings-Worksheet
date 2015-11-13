/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/

char KthIndexFromEnd(char *str, int K)
{
	int iterator = 0,len=0;
	while (str[iterator] != '\0')
	{
		len++;
		iterator++;
	}
	if (len==0)
		return '\0';
	else
	{
		return str[len - 1 - K];
	}
}