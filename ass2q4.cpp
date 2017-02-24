#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define size 100
struct stack
{
int top;
char item[size];
}s;
void push(struct stack*s,char x);
int pop(struct stack*s);
int pre(char x);
main()
{
int i,k=0,l;
char temp,ch,infix[size],prefix[size];
s.top=-1;
printf("enter the infix expression:\n");
scanf("%s",infix);
l=strlen(infix);
for(i=0;i<l;i++)//string reversal
{
push(&s,infix[i]);
}
for(i=0;i<l;i++)
{
infix[i]=pop(&s);
}
i=0;
while((ch=infix[i++])!='\0')
{
if(ch==')')
push(&s,ch);
else if(isalnum(ch))
prefix[k++]=ch;
else if(ch=='(')
{
while((s.item[s.top])!=')')
{
prefix[k++]=pop(&s);
}
temp=pop(&s);
}
else
{
while(pre((s.item[s.top]))> pre(ch))
prefix[k++]=pop(&s);
push(&s,ch);
}
}
while(s.top!=-1)
{
    prefix[k++]=pop(&s);
}
for(i=0;i<l;i++)//prefix reversal
{
push(&s,prefix[i]);
}
for(i=0;i<l;i++)
{
prefix[i]=pop(&s);
}
printf("the prefix expression is:\n");
printf("%s",prefix);
}
int pre(char x)
{
switch(x)
{
case ')':return 1;
case '-':
case '+':return 2;
case '*':
case '/':return 3;
default :return 0;
}
}
void push(struct stack*s,char x)
{
if(s->top==size-1)
printf("stack overflow");
else
{
s->item[++s->top]=x;
}
}
int pop(struct stack*s)
{
if(s->top==-1)
return 0;
else
return s->item[s->top--];
}

