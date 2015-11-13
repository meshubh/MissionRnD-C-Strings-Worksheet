/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.
*/
#include <stdio.h>
int put_in_string(int, char[], int, int);
int pow(int a);
void number_to_str(float number, char *str, int afterdecimal)
{
	if (afterdecimal >= 0)
	{
		int  int_num, multiplier, dec_part, pos, fin_len, new_int_num;
		double dec_num;
		int_num = number;
		if (number < 0)
		{
			str[0] = '-';
			new_int_num = (-1)*int_num;
			pos = put_in_string(new_int_num, str, 1, 0);
		}
		else
			pos = put_in_string(int_num, str, 0, 0);
		dec_num = number - int_num;
		if (dec_num != 0)
		{
			multiplier = pow(afterdecimal);
			dec_part = dec_num*multiplier;
			if (dec_part < 0)
				dec_part = (-1)*dec_part;
			str[pos] = '.';
			fin_len = put_in_string(dec_part, str, pos + 1, afterdecimal);
			str[fin_len] = '\0';
		}
		else
			str[pos] = '\0';
	}
}
int put_in_string(int num, char string[], int start, int d_len)
{
	int count = 0, i = start, j, k = start, t_count, point;
	t_count = start;
	char temp;
	while (num > 0)
	{
		string[i++] = (num % 10) + '0';
		num = num / 10;
		count++;
		t_count++;
	}
	point = t_count;
	for (j = count - 1; j >= count / 2; j--)
	{
		temp = string[point - 1];
		string[point - 1] = string[k];
		string[k] = temp;
		k++;
		point--;
	}
	if (count < d_len)
	{
		while (count < d_len)
		{
			string[i++] = '0';
		}
	}
	count = 0;
	return i;
}
int pow(int p)
{
	int i, result = 1;
	for (i = 1; i <= p; i++)
		result = result * 10;
	return result;
}