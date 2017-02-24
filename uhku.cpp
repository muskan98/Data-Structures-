# include <stdio.h>
# include <string.h>
# define MAX 20
void infixtoprefix(char infix[20],char prefix[20]);
void reverse(char array[30]);
char pop();
void push(char symbol);
int isOperator(char symbol);
int prcd(symbol);
int top=-1;
char stack[MAX];
main() {
	char infix[20],prefix[20],temp;
	printf("Enter infix operation: ");
	gets(infix);
	infixtoprefix(infix,prefix);
	reverse(prefix);
	puts((prefix));
}
//--------------------------------------------------------
void infixtoprefix(char infix[20],char prefix[20]) {
	int i,j=0;
	char symbol;
	stack[++top]='#';
	reverse(infix);
	for (i=0;i<strlen(infix);i++) {
		symbol=infix[i];
		if (isOperator(symbol)==0) {
			prefix[j]=symbol;
			j++;
		} else {
			if (symbol==')') {
				push(symbol);
			} else if(symbol == '(') {
				while (stack[top]!=')') {
					prefix[j]=pop();
					j++;
				}
				pop();
			} else {
				if (prcd(stack[top])<=prcd(symbol)) {
					push(symbol);
				} else {
					while(prcd(stack[top])>=prcd(symbol)) {
						prefix[j]=pop();
						j++;
					}
					push(symbol);
				}
				//end for else
			}
		}
		//end for else
	}
	//end for for
	while (stack[top]!='#') {
		prefix[j]=pop();
		j++;
	}
	prefix[j]='\0';
}
////--------------------------------------------------------
void reverse(char array[30]) // for reverse of the given expression {
	int i,j;
	char temp[100];
	for (i=strlen(array)-1,j=0;i+1!=0;--i,++j) {
		temp[j]=array[i];
	}
	temp[j]='\0';
	strcpy(array,temp);
	return array;
}
//--------------------------------
char pop() {
	char a;
	a=stack[top];
	top--;
	return a;
}
//----------------------------------
void push(char symbol) {
	top++;
	stack[top]=symbol;
}
//------------------------------------------
int prcd(symbol) // returns the value that helps in the precedence {
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
//-------------------------------------------------
int isOperator(char symbol) {
	switch(symbol) {
		case '+':
		        case '-':
		        case '*':
		        case '/':
		        case '^':
		        case '$':
		        case '&':
		        case '(':
		        case ')':
		        return 1;
		break;
		default:
		        return 0;
		// returns 0 if the symbol is other than given above
	}
}


Infix to prefix implementation in c : with Pointer
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define MAX 50
struct infix
{
	char target[MAX] ;
	char stack[MAX] ;
	char *s, *t ;
	int top, l ;
} ;
 
void initinfix ( struct infix * ) ;
void setexpr ( struct infix *, char * ) ;
void push ( struct infix *, char ) ;
char pop ( struct infix * ) ;
void convert ( struct infix * ) ;
int priority ( char c ) ;
void show ( struct infix ) ;
 
void main( )
{
	struct infix q ;
	char expr[MAX] ;
	clrscr( ) ;
	initinfix ( &q ) ;
	printf ( "\nEnter an expression in infix form: " ) ;
	gets ( expr ) ;
	setexpr ( &q, expr ) ;
	convert ( &q ) ;
	printf ( "The Prefix expression is: " ) ;
	show ( q ) ;
	getch( ) ;
}
/* initializes elements of structure variable */
void initinfix ( struct infix *pq )
{
	pq -> top = -1 ;
	strcpy ( pq -> target, "" ) ;
	strcpy ( pq -> stack, "" ) ;
	pq -> l = 0 ;
}
/* reverses the given expression */
void setexpr ( struct infix *pq, char *str )
{
	pq -> s = str ;
	strrev ( pq -> s ) ;
	pq -> l = strlen ( pq -> s ) ;
	*( pq -> target + pq -> l ) = '\0' ;
	pq -> t = pq -> target + ( pq -> l - 1 ) ;
}
/* adds operator to the stack */
void push ( struct infix *pq, char c )
{
	if ( pq -> top == MAX - 1 )
		printf ( "\nStack is full.\n" ) ;
	else
	{
		pq -> top++ ;
		pq -> stack[pq -> top] = c ;
	}
}
/* pops an operator from the stack */
char pop ( struct infix *pq )
{
	if ( pq -> top == -1 )
	{
		printf ( "Stack is empty\n" ) ;
		return -1 ;
	}
	else
	{
		char item = pq -> stack[pq -> top] ;
		pq -> top-- ;
		return item ;
	}
}
/* converts the infix expr. to prefix form */
void convert ( struct infix *pq )
{
	char opr ;
	while ( *( pq -> s ) )
	{
		if ( *( pq -> s ) == ' ' || *( pq -> s ) == '\t' )
		{
			pq -> s++ ;
			continue ;
		}
		if ( isdigit ( *( pq -> s ) ) || isalpha ( *( pq -> s ) ) )
		{
			while ( isdigit ( *( pq -> s ) ) || isalpha ( *( pq -> s ) ) )
			{
				*( pq -> t ) = *( pq -> s ) ;
				pq -> s++ ;
				pq -> t-- ;
			}
		}
		if ( *( pq -> s ) == ')' )
		{
			push ( pq, *( pq -> s ) ) ;
			pq -> s++ ;
		}
		if ( *( pq -> s ) == '*' || *( pq -> s ) == '+' || *( pq -> s ) == '/' || *( pq -> s ) == '%' || *( pq -> s ) == '-' || *( pq -> s ) == '$' )
		{
			if ( pq -> top != -1 )
			{
				opr = pop ( pq ) ;
				while ( priority ( opr ) > priority ( *( pq -> s ) ) )
				{
					*( pq -> t ) = opr ;
					pq -> t-- ;
					opr = pop ( pq ) ;
				}
				push ( pq, opr ) ;
				push ( pq, *( pq -> s ) ) ;
			}
			else
				push ( pq, *( pq -> s ) ) ;
				pq -> s++ ;
		}
		if ( *( pq -> s ) == '(' )
		{
			opr = pop ( pq ) ;
			while ( opr != ')' )
			{
				*( pq -> t ) = opr ;
				pq -> t-- ;
				opr = pop ( pq ) ;
			}
			pq -> s++ ;
		}
	}
	while ( pq -> top != -1 )
	{
		opr = pop ( pq ) ;
		*( pq -> t ) = opr ;
		pq -> t-- ;
	}
	pq -> t++ ;
}
/* returns the priotity of the operator */
int priority ( char c )
{
	if ( c == '$' )
		return 3 ;
	if ( c == '*' || c == '/' || c == '%' )
		return 2 ;
	else
	{
		if ( c == '+' || c == '-' )
			return 1 ;
		else
			return 0 ;
	}
}
/* displays the prefix form of given expr. */
void show ( struct infix pq )
{
	while ( *( pq.t ) )
	{
		printf ( " %c", *( pq.t ) ) ;
		pq.t++ ;
	}
}
