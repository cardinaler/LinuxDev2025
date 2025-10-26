#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   // read, write, close
#include <fcntl.h>    // open, O_RDONLY, O_WRONLY, etc.
#include <errno.h>    // errno
#include <string.h>   // strerror

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Help: prog <infile> <outfile>");
        return 1;
    }

    int infile = open(argv[1], O_RDONLY);
    if (infile < 0) {
        printf("Error while opening infile");
        return 2;
    }

    int outfile = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outfile < 0) {
        printf("Error while opening oufile");
        if(close(infile) < 0)
        {
        	printf("Error when closing infile\n");
                return 4;
        }
        return 3;
    }

    char buff[4096];
    int bread, bwritten;

    while ((bread = read(infile, buff, sizeof(buff))) > 0) {
        int totalWritten = 0;
        while (totalWritten < bread) {
            bwritten = write(outfile, buff + totalWritten, bread - totalWritten);
            if (bwritten < 0) {
                printf("Error while writing in outfile\n");
		if(close(infile) < 0)
        	{
            		printf("Error when closing infile\n");
        	        return 4;
        	}
        	if(close(outfile) < 0)
        	{
                 	printf("Error when closing outfile\n");
            		return 7;
        	}
		if(remove(argv[2]) != 0)
        	{
                	printf("Error when remove outfile\n");
                	return 5;
        	}
	

                return 6;
            }
            totalWritten += bwritten;
        }
    }

    if (bread < 0) {
        printf("Error while reading infile\n");
        if(close(infile) < 0)
        {
            printf("Error when closing infile\n");
            return 4;
        }
        if(close(outfile) < 0)
        {
            printf("Error when closing outfile\n");
            return 7;
        }

	if(remove(argv[2]) != 0)
	{
		printf("Error when remove outfile\n");
		return 5;
	}
        return 8;
    }

    if(close(infile) < 0)
    {
	    printf("Error when remove infile\n");
	    if(remove(argv[2]) != 0)
            {
            	printf("Error when remove outfile\n");
                return 5;
            }

	    return 4;
    }
    if(close(outfile) < 0)
    {
	    printf("Error when remove outfile\n");
	    if(remove(argv[2]) != 0)
            {
                printf("Error when remove outfile\n");
                return 5;
            }

	    return 7;
    }
    if(remove(argv[1]) != 0)
    {
	    printf("Error while deleting infile\n");
	    if(remove(argv[2]) != 0)
            {
                printf("Error when remove outfile\n");
                return 5;
            }
	    return 9;
    }

    return 0;
}
