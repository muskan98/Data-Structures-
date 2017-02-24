#include <stdio.h>
#include <string.h>

int main(void) {
	char str[100];
	scanf(" %[^\n]s", str);        // '\n' is a delimiter i.e. scanf will only stop reading input on occurence of new line & not before that
									// ^ makes '\n' a delimiter
									// if we only write  %[\n]s , then scanf will only read new line characters
	int len = strlen(str), i;
	for (i = 0; i < len; i++ )  {
		if (str[i] != ' ')
		printf("%c", (str[i] + 2));
		else
		printf(" ");
	}
return 0;
}
