#include <stdio.h>
#include <locale.h>
#include <libintl.h>
#include <string.h>
#include <config.h>

#define _(STRING) gettext(STRING)

int main()
{
	setlocale(LC_ALL, "");
    	bindtextdomain(PACKAGE, ".");
    	textdomain(PACKAGE);
	printf(_("Pick a number from 1 to 100.\n"));
	int l = 0;
	int r = 100;
	int m;
	char ans[64];
	while(r - l > 1)
	{
		m = (l + r) / 2;
		printf(_("Is your number is greater than %d?\n"), m);
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
	printf(_("Your number is %d\n"), r);
	return 0;
}
