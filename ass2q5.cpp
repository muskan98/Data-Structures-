#include <stdio.h>
#include <conio.h>
#include <process.h>  // for exit() function
#include <math.h>
# define MAX 50

typedef struct stack
{ char data [MAX];
  int top;
}stack;

int empty (stack *p)
{ if (p-> top  == -1)
  return (1);
  else
   return (0);
}

int full (stack *p)
{ if (p->top == MAX-1)
    return (1);
  else
      return (0);
}

void push (stack *p, char x)
{ if(!full (p))
  p->data [++p->top] = x;
   else
 printf ("\n stack is full");
}

int pop (stack *p)
{  char x;
   if (!empty(p))
   {x=p->data[p->top--];
   return (x);
   }
   else
   {printf ("\n stack is empty:");
   return 0;
   }
}

int isdigit(char ch)
{	if(ch>='0' && ch<='9')
	return 1;
	else
	return 0;
}

double oper(char c,double opnd1,double opnd2)
{
	switch(c)
		{case '+': return(opnd1+opnd2);
		case '-': return(opnd1-opnd2);
		case '*': return(opnd1*opnd2);
		case '/': return(opnd1/opnd2);
		case '^': return(pow(opnd1,opnd2));
		default: printf("Invalid operator");
		return 0;
	}
}

double eval(char str[])
{	char c;
	double opnd1,opnd2,val;
	stack stk;
	stk.top=-1;
	int i;
	for(i=0;(c=str[i])!='?';i++)
	{
	if(isdigit(c))
	push(&stk,(double)(c)-'0');
	else
	{
	opnd2=pop(&stk);
	opnd1=pop(&stk);
	val=oper(c,opnd1,opnd2);
	push(&stk,val);
	}
	}
return(pop(&stk));
}

int main(void) {
	char str[MAX];
	int i, j, k;
	char temp;
	printf("\n enter a prefix string: ");
	for(i=0;(str[i]=getchar())!='\n';i++);
	str[i]='?';
	k=i;
	for(i=0,j=k-1; i<=j; i++,j--)  {
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
	}
	printf("\n Result after evaluation is: %f",eval(str));
return 0;
}
