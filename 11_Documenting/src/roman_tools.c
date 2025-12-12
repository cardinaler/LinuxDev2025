#include "const.h"
#include "roman_tools.h"
#include <string.h>

/** @page roman_tools
 * @section TOOLS_DESCRIPTION
 * In roman_tools.c there is a functions for easily switching between roman and decimal systems.
 *
 * When working, functions uses a pre-generated table of Roman numbers.
 * Table presented in const.h.
 *
 * @section AUTHORS
 * Касумов Руслан / Kasumov Ruslan
 */


/** @file roman_tools.c
 * @copydetails roman_tools
 */

/**
 * Convert decimal number to roman.
 * @param n is decimal number.
 */
char *dec_to_roman(int n)
{
	if(n <= romans_amount && n >= 1)
	{
		return roman_table[n - 1];
	}
	else
	{
		return "";
	}
}
/** Convert roman number to decimal
 * @param s is a string that represent roman number 
 */
int roman_to_dec(char *s)
{
	for(int n = 0; n < romans_amount; ++n)
	{
		if(strcmp(s, roman_table[n]) == 0)
		{	
			return n;
		}
	}
	return -1;
}
