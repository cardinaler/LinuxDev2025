#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int m, n, s;
	m = 0;
	n = 0;
	s = 1;
	if(argc == 1)
	{
		printf("%s\n", "help");
	}
	if(argc > 1)
	{
		n = atoi(argv[1]);
		if(argc > 2)
		{
			m = n;
			n = atoi(argv[2]);
			if(argc > 3)
			{
				s = atoi(argv[3]);
			}
		}
	}
	for(int i = m; i < n; i += s)
	{
		printf("%d\n", i);
	}
	return 0;
}

