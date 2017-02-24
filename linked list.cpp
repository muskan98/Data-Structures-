#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* link;
};
struct node* head;
void Insert (int x) {
	struct node* temp = (node*)malloc(sizeof(struct node));	
	temp->data = x; 
	temp->link = head;
	head = temp; 
	}

void Print() {
	struct node* temp = head;
	printf("list is ");
	while (temp != NULL) {
		printf("%d",temp->data);
		temp = temp->link;
	}
	printf("\n");
}


int main()  {
	head = NULL;
	int n,i,x;
	scanf("%d",&n);
	for (i = 0; i < n; i++) {
		scanf("%d",&x);
		Insert(x);
		Print();
	}
return 0;
}
