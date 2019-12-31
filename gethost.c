#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <readline/readline.h>

int main(int argc, char *argv[])
{

    char help[] = "Please enter a domain:\n";

    char *hostname;

again:
    hostname = readline(help);

    if (strlen(hostname) < 4)
    {
        goto again;
    }

    struct hostent *h;

    h = gethostbyname(hostname);

    if (!h)
    {
        fprintf(stderr, "sorry %s\n", hstrerror(h_errno));
    }
    else
    {
        if (h->h_addrtype == AF_INET6)
        {
            printf("not support ipv6 \n");
        }
        else
        {
            printf("%24s\n", "------------------------");
            printf("|HOST: %-16s|\n", hostname);
            printf("%24s\n", "------------------------");
            int i = 0;
            while (h->h_addr_list[i] != 0)
            {
                printf("|IP[%2d]|%15s|\n", i + 1, inet_ntoa(*(struct in_addr *)h->h_addr_list[i]));
                printf("%24s\n", "------------------------");
                i++;
            }
            printf("\n");
        }
    }

    return 0;
}