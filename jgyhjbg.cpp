#include <stdio.h>

int main(void) {
	int t;
	scanf("%d",&t);
	while(t--) {
	int n;
	scanf("%d",&n);	
	int arr[n];
	int i, j;
	int ct = 0;
	for (i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
	}
	int last = -1;
	for (i = 0; arr[i] == 1; i++) 
	last = i;
	
	if (last != (n-1)) {
		for (j = (last + 1); j < n; j++) {
			if (arr[j] == 1)
			ct += 100;
			else
			ct += 1100;
		}
	}
	printf("%d\n",ct);
}
return 0;
}
	
