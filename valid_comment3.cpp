#include <stdio.h>
#include <string.h>

int main(void)  {
	char str[100];
	scanf("%[^\n]s",str);
	int l = strlen(str);
	int i;
	int ct1 = 0, ct2 = 0;
		if (str[0] =='/' && str[1] == '*' && str[l-2] =='*' && str[l-1] == '/')
		{	
	for (i = 0; i < l; i++) {
		if (str[i] =='/' && str[i+1] == '*')
		ct1++;
		else if (str[i] =='*' && str[i+1] == '/')
		ct2++;
		else
		continue;
	}}
	if (ct1 == ct2)
	printf("valid comment");
	else
	printf("invalid comment");
return 0;
}
	
