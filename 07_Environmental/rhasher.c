#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <rhash.h>

#ifdef USE_READLINE
#include <readline/readline.h>
#endif

int main()
{
#ifdef USE_READLINE
	printf("readline is using now\n");
#else
	printf("getline is using now\n");
#endif
	char *s;
	size_t len = 0;
	rhash_library_init();
	char buffer[64];
#ifdef USE_READLINE
	while(s = readline(""))
	{
#else
	while(getline(&s, &len, stdin) != -1)
	{
#endif
		char *hash_alg = strtok(s, " ");
		char *msg = strtok(NULL, " \n");
		char out[128];
		if(hash_alg == NULL || msg == NULL)
		{
			fprintf(stderr, "Error occured\n");
			continue;
		}	
		int hex = isupper(hash_alg[0]);
		int res = 0;
		int hash;
		if (strcmp(hash_alg, "MD5") == 0 || strcmp(hash_alg, "md5") == 0)
        		hash = RHASH_MD5;
    		else if (strcmp(hash_alg, "SHA1") == 0 || strcmp(hash_alg, "sha1") == 0)
        		hash = RHASH_SHA1;
    		else if (strcmp(hash_alg, "TTH") == 0 || strcmp(hash_alg, "tth") == 0)
        		hash = RHASH_TTH;
    		else 
		{
        		fprintf(stderr, "Hash algorithm: \"%s\" error.\nUse: SHA1, MDA5 or TTH \n", hash_alg);
        		continue;
    		}		
		if(msg[0] != '"')
		{	

			res = rhash_file(hash, msg, buffer);
		}
		else
		{
			msg = msg + 1;
			res = rhash_msg(hash, msg, strlen(msg), buffer);
		}
		if(res < 0)
		{
			fprintf(stderr, "Hash error\n");
			continue;
		}
		if(hex)
		{
			rhash_print_bytes(out, buffer, rhash_get_digest_size(hash), RHPR_HEX);

		printf("HEX: %s (\"%s\") = %s\n", rhash_get_name(hash), msg, out);
		}
		else
		{
			rhash_print_bytes(out, buffer, rhash_get_digest_size(hash), RHPR_BASE64);
		printf("BASE64: %s (\"%s\") = %s\n", rhash_get_name(hash), msg, out);
		}



	}

	return 0;
}
