#include <stdio.h>
#include <string.h>

struct employee {
	char code[3];
	char fName[20];
	char mName[10];
	char lName[20];
	int sal;
}emp[3];

int main(void) {
	int n = 3,i,j;
	strcpy(emp[0].code, "E01");
	strcpy(emp[1].code, "E02");
	strcpy(emp[2].code, "E03");
	
	for (i = 0; i < n; i++)  {
		printf("enter first name, middle name, last name and salary in INR of employee %d \n", (i+1));
		scanf("%s %s %s %d",emp[i].fName, emp[i].mName, emp[i].lName, &emp[i].sal);
	}
		for (i = 0; i < n; i++)  {
		printf("\n%s\n%s\n%s\n%s\n%d\n", emp[i].code ,emp[i].fName, emp[i].mName, emp[i].lName, emp[i].sal);
	}
	
	int max = emp[i].sal;
	for (i = 1; i < n; i++)
  {
    if (emp[i].sal > max)
    {
       max = emp[i].sal;
    }
  }
  printf("\nhighest salary is %d",max);
return 0;
}
