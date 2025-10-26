#include <string.h>
#include <dlfcn.h>

typedef int (*rem_type)(char*);

int remove(char* filename)
{
	if(strstr(filename, "PROTECT"))
	{
		return 0;
	}
	
	rem_type original_rem = (rem_type)(dlsym(RTLD_NEXT, "unlink"));
	return original_rem(filename);
	
}
