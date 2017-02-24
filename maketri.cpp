#include <stdio.h>
#include <math.h>

int main(void) {
	int i, j,range, n, l, r;
	scanf("%d %d %d", &n, &l, &r);
	int arr[n];
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int count = 0;	
	for (range = l; range <= r; range++) {
		for (i = 0; i < (n-1); i++) {
			float area, s;
			for (j = 1; j != i; j++)  {
				s = (range + arr[i] + arr[j])/2.0; 
			    area = sqrt(s*(s-range)*(s-arr[i])*(s-arr[j]));
				if (area > 0.0)
				count ++;
			}
		}
	}
	printf("%d",count);
return 0;
}
				
		
	
