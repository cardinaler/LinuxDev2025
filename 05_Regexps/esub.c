#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAXG 10
#define BUFSZ 8192

int main(int c, char *argv[])
{
    if (c != 4)
    {
        fprintf(stderr, "Help: <regexp> <subs> <string>\n");
        return 1;
    }

    regex_t re;
    regmatch_t m[MAXG];
    if (regcomp(&re, argv[1], REG_EXTENDED))
    {
        fprintf(stderr, "regexp problem\n");
        return 1;
    }

    if (regexec(&re, argv[3], MAXG, m, 0))
    {
        printf("%s\n", argv[3]);
        regfree(&re);
        return 0;
    }

    int gcount = 0;
    for (int i = 1; i < MAXG; i++)
        if (m[i].rm_so != -1)
            gcount = i;

    char out[BUFSZ];
    int pos = 0;

    memcpy(out, argv[3], m[0].rm_so);
    pos = m[0].rm_so;

    for (int i = 0; argv[2][i]; i++)
    {
        if (argv[2][i] == '\\')
        {
            i++;
            if (!argv[2][i])
                break;
            if (argv[2][i] == '\\')
            {
                out[pos++] = '\\';
            }
            else if (argv[2][i] >= '1' && argv[2][i] <= '9')
            {
                int g = argv[2][i] - '0';
                if (g > gcount || m[g].rm_so == -1)
                {
                    fprintf(stderr, "error: no such group \\%d\n", g);
                    regfree(&re);
                    return 1;
                }
                int len = m[g].rm_eo - m[g].rm_so;
                memcpy(out + pos, argv[3] + m[g].rm_so, len);
                pos += len;
            }
            else
            {
                out[pos++] = argv[2][i];
            }
        }
        else
        {
            out[pos++] = argv[2][i];
        }
    }

    strcpy(out + pos, argv[3] + m[0].rm_eo);

    puts(out);
    regfree(&re);
    return 0;
}
