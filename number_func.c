#include "main.h"

/**
* number_to_string - change the int to string.
* @num: the number
* @str: a string pointer
*/

void number_to_string(long num, char *str)
{
int i, x = 0;
long n = num;
char letter[] = {"0123456789"};
i = 0;

if (n == 0)
str[i++] = '0';

if (str[0] == '-')
x = 1;

while (n)
{
if (n < 0)
str[i++] = letter[-(n % 10)];
else
str[i++] =  letter[n % 10];
n /= 10;
}
if (x)
str[i++] = '-';

str[i] = '\0';
revers_str(str);
}

/**
* revers_str - reverse a string.
* @str: a pointer to string.
*/

void revers_str(char *str)
{
char dest;
int x, i = 0;
x = _strlen(str) - 1;

while (i < x)
{
dest = str[i];
str[i++] = str[x];
str[x--] = dest;
}
}
