#include<stdio.h>
#include<process.h>
#include<conio.h>
struct stack
{
int top;
int items[100];
};
void init(struct stack *ps)
{
ps->top=-1;
}
void push(struct stack *ps,char ch)
{
ps->items[++ps->top]=ch;
}
int pop(struct stack *ps)
{ int item = ps->items[ps->top–-]
return item;
}
int main(void)
{
struct stack s1;
int i;
char s[10],ch;
clrscr();
init(&s1);
printf(“enter the string”);
scanf(“%s”,&s);
for(i=0;s[i]!=’\0';i++)
{
push(&s1,s[i]);
}
printf(“\n”);
while(s1.top!=-1)
{
ch=pop(&s1);
printf(“%c”,ch);
}
return 0;
}
