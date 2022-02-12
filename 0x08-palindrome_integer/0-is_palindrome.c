#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * is_palindrome - Entry point
 *
 * @n: is the number to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
    unsigned long r;
    unsigned long add = 0;
    unsigned long temp;
    temp = n;

    while(n > 0)
    {
        r = n % 10;
        add = (add * 10) + r;
        n = n / 10;
    }

    if(temp == add)
        return 1;
    else
        return 0;
}
