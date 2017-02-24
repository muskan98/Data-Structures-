#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Stack
{
    char* array;
    int top;
    int size;
    int capacity;
};
void createStack(struct Stack* stack,unsigned c)
{
    stack->capacity=c;
    stack->array=(char*)malloc(sizeof(char)*(stack->capacity));
    stack->size=0;
    stack->top=-1;
}
int isEmpty(struct Stack* stack)
{
    if(stack->size==0)
        return 1;
    return 0;
}
int isFull(struct Stack* stack)
{
    if(stack->size==stack->capacity)
        return 1;
    return 0;
}
void push(struct Stack* stack,char item)
{
    if(isFull(stack))
        return;
    stack->size++;
    stack->array[++stack->top]=item;
    return;
}
char pop(struct Stack* stack)
{
    if(isEmpty(stack))
    {
        return CHAR_MIN;
    }
    stack->size--;
    return stack->array[stack->top--];
}
int checkComments(char expr[])
{ int i;
    struct Stack s;
    createStack(&s, 10);
    int flag=0;
    for( i=0;expr[i];i++)
    {
        if(expr[i]=='/' && expr[i+1]=='*' && flag==0)
        {
            push(&s,'{');
            i=i+1;
            flag=1;
        }
        else if(expr[i]=='*' && expr[i+1]=='/' && flag==1)
        {
            if(pop(&s)!='{')
                return 0;
            i=i+1;
            flag=0;
        }
        else if(expr[i]=='*' && expr[i+1]=='/' && flag==0)
        {
                return 0;

        }
    }
    if(isEmpty(&s))
        return 1;
    return 0;
}
int main()
{
    char expr[100];
    printf("Enter expression containing comments: ");
    fgets(expr,100,stdin);
    if(checkComments(expr))
        printf("Comment is valid\n");
    else
        printf("Comments is not valid.\n");
}

