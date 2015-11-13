/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

char removeSpaces(char *str) 
{
	int iterator = 0,count=0;
	if (str == "" || str == nullptr)
		return '\0';
	while (str[iterator] != '\0')
	{
		if (str[iterator] != ' ')
		{
			str[count] = str[iterator];
			count++;
		}
		iterator++;
	}
	str[count] = '\0';
}