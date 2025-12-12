/** @mainpage Guess your number prog
 * @copydetails prog
 * @copydetails roman_tools
 * @copydetails help
 */



#include <stdio.h>
#include <locale.h>
#include <libintl.h>
#include <string.h>
#include <config.h>
#include "roman_tools.h"
#define _(STRING) gettext(STRING)

/** @page prog
 * @section DESCRIPTION
 * This is the program that will play game with you. First it will ask you to choose number and then it will ask you questions to guess your number.
 */

/** @file prog.c
 * @copydetails prog
 */

/** @page help
 * @section USAGE
 * ./prog [-r]
 *
 * If -r flag is specified, then program will work with romans number system.
 * @section ИНСТРУКЦИЯ 
 * ./prog [-r]
 *
 * Если флаг -r задан, тогда программа будет работать в римской системе счисления.
 */

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");
    	bindtextdomain(PACKAGE, ".");
    	textdomain(PACKAGE);
	int roman_sys = 0;
	if(argc == 2 && strcmp(argv[1], "-r") == 0)
	{
		roman_sys = 1;
	}
	else if(argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0))
	{
		printf(_("Usage: ./prog [-r]\n"));
		printf(_("If -r flag is specified, then program will work with romans number system"));
		return 0;
	}
	if(roman_sys)
	{
		printf(_("Pick a number from %s to %s.\n"), dec_to_roman(1), dec_to_roman(100));
	}
	else
	{
		printf(_("Pick a number from 1 to 100.\n"));
	}

	int l = 0;
	int r = 100;
	int m;
	char ans[64];
	while(r - l > 1)
	{
		m = (l + r) / 2;
		if(roman_sys)
		{	
			printf(_("Is your number is greater than %s?\n"), dec_to_roman(m));
		}
		else
		{	
			printf(_("Is your number is greater than %d?\n"), m);
		}
		printf("(YES / NO):");
		if (!fgets(ans, sizeof(ans), stdin)) 
		{
			printf("\n");
			printf(_("ERROR. Input closed\n"));
			return 1;
		}
		ans[strlen(ans) - 1] = '\0';
		if(strcmp(ans, "YES") == 0)
		{
			l = m;
		}
		else if(strcmp(ans, "NO") == 0)
		{
			r = m;
		}
		else
		{
			printf(_("Wrong format for answer!\n"));
		}
	}
	if(roman_sys)
	{
		printf(_("Your number is %s\n"), dec_to_roman(r));
	}
	else
	{
		printf(_("Your number is %d\n"), r);
	}

	return 0;
}
