#include<stdio.h>
#include<string.h>

#define MAX 100

struct stack{
	
	char data[MAX];
	int top;
};

void init(struct stack* s){

 	s->top = -1;
}


int IsEmpty(struct stack* s)
{
	return(s->top == -1);
}

int isFull(struct stack* s)
{
	return(s->top == MAX -1);
}
void push( struct stack* s, char x)
{
	if(isFull(s)) printf("Stack is full\n");
	else s->data[++s->top] = x;
}

void pop(struct stack* s)
{	
	if(IsEmpty(s)) printf("Stack is empty\n");
	else s->top--;
}


int main()
{
	struct stack S;
	char string[MAX];
	int N,i;
	int count = 0;
	
	init(&S);
	printf("Enter the comment statement you want to check\n");
	scanf("%s", string);
	
	N = strlen(string);
	
	for(i = 0; i < N-1; i++){
		 if(string[i] == '/' && string[i+1] == '*'){
		 	push(&S,string[i]);
			push(&S,string[i+1]);
		}
		 if(string[i] == '*' && string[i+1] == '/'){
		 	if(!IsEmpty(&S)){
		 		pop(&S);
				pop(&S);
			}
			else count = 1;
			
		}	
	}
	
	if(IsEmpty(&S)&& count == 0) printf("The comment statement is valid\n");
	else if(IsEmpty(&S)&&count == 1) printf("The comment statement is not  valid\n");
	else if(!IsEmpty(&S)) printf("The comment statement is not valid\n");
return 0;
}
	


