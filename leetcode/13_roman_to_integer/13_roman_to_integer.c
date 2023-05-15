
/* 
Given a roman numeral, convert it to an integer.

My solution:
	replace subtractives with normal numerals
	convert to int
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char    *replace_subtracts(char *str)
{
    int     i = 0;

    char    *rep[6][2] = {
        {"IV", "IIII"},
        {"IX", "VIIII"},
        {"XL", "XXXX"},
        {"XC", "LXXXX"},
        {"CD", "CCCC"},
        {"CM", "DCCCC"},
    };

    while (i < 6)
    {
        char *pos = strstr(str, rep[i][0]);
        if (pos)
        {
			int diff = strlen(rep[i][1]) - strlen(rep[i][0]);
			if (diff > 0)
			{
				str = realloc(str, strlen(str) + diff + 1);
				pos = strstr(str, rep[i][0]);
			}
            memmove(pos + strlen(rep[i][1]), pos + strlen(rep[i][0]), strlen(pos) - strlen(rep[i][0]) + 1);
            memcpy(pos, rep[i][1], strlen(rep[i][1]));
        }
        i++;
    }
	return (str);
}

int value(char str)
{
    if (str == 'I')
        return (1);
    if (str == 'V')
        return (5);
    if (str == 'X')
        return (10);
    if (str == 'L')
        return (50);
    if (str == 'C')
        return (100);
    if (str == 'D')
        return (500);
    if (str == 'M')
        return (1000);
    return (0);
}

int romanToInt(char * s)
{
    size_t     i = 0;
    int     sum = 0;
	char    *str = malloc(sizeof(char) * (strlen(s) + 1));

	strcpy(str, s);
    str = replace_subtracts(str);
    while (i < strlen(str))
    {
        sum += value(str[i]);
        i++;
    }
	free(str);
    return (sum);
}

int main(void) 
{
    char romanNumeral[] = "MCMXCIV";
    printf("Integer: %d\n", romanToInt(romanNumeral));
    return (0);
}