#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *a = (char*)malloc(5);
	a[5] = '\0';
	size_t i = 0;
	while (i < 5) a[i++] = ' ';
	printf("'%s'\n", a);
	free(a);
	return 0;
}
