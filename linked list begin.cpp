#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* link;
};
struct node* head;   // if head not declared as a global variable then declare head in main() and pass it as a pointer to Insert() anf Print() both so as to access its variables
                      // check this video last few mins : https://www.youtube.com/watch?v=cAZ8CyDY56s&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=6

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
		printf("%d ",temp->data);
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
