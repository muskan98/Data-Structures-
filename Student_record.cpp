#include <stdio.h>
#include <string.h>

struct stud_rec {
	char name[10];
	int rollNo;
	int m1;
	int m2;
}st[3], temp;


int main(void)  {
	int n = 3,i,j;
	
	for (i = 0; i < n; i++)  {
		printf("enter name, roll no. and marks of both subjects of student %d \n", (i+1));
		scanf("%s %d %d %d", st[i].name, &st[i].rollNo, &st[i].m1, &st[i].m2);
	}
	printf("enter roll no. of student to be searched\n");
	int search;
	scanf("%d",&search);
	for (i = 0; i < n; i++)  {
		if (st[i].rollNo == search)
		printf("%s\n",st[i].name);
}
	for (i = 1; i < n; i++) {
	      for (j = 0; j < n - i; j++) {
         if (strcmp(st[j].name, st[j + 1].name) > 0) {
            temp = st[j];
            st[j] = st[j + 1];
            st[j + 1] = temp;
         }
      }
    }
	printf("sorted array of students on basis of name is :");
	for (i = 0; i < n; i++)  {
		printf("%s\n", st[i].name);
	}
		int percent[n];
	
	printf("students who scored more than 60% marks are : \n");
		for (i = 0; i < n; i++)  {
		percent[i] = (st[i].m1 + st[i].m2) / 2;
		if (percent[i] > 60)
		printf("%s\n",st[i].name);
	}
return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
