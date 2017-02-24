#include <stdio.h>
#include <ctype.h>
#define size 50

typedef struct stack {
	int top;
	int arr[size];
} stack;
int isEmpty(stack *s) {
	if (s->top == -1)
	return 1;
	else
return 0;
}
void push(stack *s, int item) {
   s->arr[++s->top] = item;
}
int isfull(stack *s) {
   if (s->top >= size - 1)
      return 1;
   else
      return 0;
}
int isoperand(char sym) {
	if('A'<sym<'Z'||'a'<sym<'z')
	return 1;
return 0;
}
int prcd(char symbol) {
	switch(symbol) {
		case '+':
		        case '-':
		        return 2;
		break;
		case '*':
		        case '/':
		        return 4;
		break;
		case '$':
		        case '^':
		        return 6;
		break;
		case '#':
		        case '(':
		        case ')':
		        return 1;
		break;
	}
}
int pop(stack *s) {
	int x = s->arr[s->top--];
	return x;
}	
int top(stack *p) {
	return (p->arr[p->top]);
}
void init(stack *s) {
s->top = -1;
}
void convert(char infi[], char post[])  {
	stack s;
	char k, x;
	int i,j=0;
	init(&s);
	for (i = 0; infi[i] != '\0'; i++)  {
		k = infi[i];
		if (isalnum(k))
			post[j++] = k;
		else if(k =='(')
			push(&s, '(');	
		else if(k == ')')
			while((x = pop(&s)) != '(')
				post[j++] = x;
		else  {
            while(precedence(k)<=precedence(top(&s)) && !isEmpty(&s))
			{	x = pop(&s);
				post[j++] = x;;
			}
			push(&s, k);
		}
	}
	while(!isEmpty(&s))
    {
        x=pop(&s);
        post[j++]=x;
    }
     post[j]='\0';
}
int main(void) {
	char infi[size],pre[size];
    printf("Enter an infix expression ");
    scanf("%s",infi);
	convert(infi,pre);
    printf("\nPostfix expression: %s",post);
return 0;    
}
int main(void) {
	printf("")
}	

