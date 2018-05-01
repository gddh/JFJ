#include "valgrind.h" 

int		main(void)
{
	char *p;
	char *pp;
	char *ppp;

	p = (char *)malloc(sizeof(char) * (strlen("abcd") + 1));
	pp = (char *)malloc(sizeof(char) * (strlen("abcdefg") + 1));
	ppp = (char *)malloc(sizeof(char) * 3);
	strcpy(p, "abcd");
	strcpy(pp, "abcdefg");
	strcpy(ppp, "hi");
	free(p);
	leaks();
}
