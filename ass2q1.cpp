#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define size 5

struct stack {
   int s[size];
   int top;
} st;
 
int isfull() {
   if (st.top >= size - 1)
      return 1;
   else
      return 0;
}
void push(int item) {
   st.s[st.top++] = item;
}
int isEmpty() {
   if (st.top == -1)
      return 1;
   else
      return 0;
}
int pop() {
   int item;
   item = st.s[st.top--];
   return (item);
}
void display() {
   int i;
   if (isEmpty())
      printf("\nStack Is Empty");
   else {
      for (i = st.top; i >= 0; i--)
         printf("\n%d", st.s[i]);
   }
}
 
int main() {
   int item, choice;
   char c;
   st.top = -1;
   do {
      printf("Enter \n1.Push \n2.Pop \n3.Display \n");
      printf("\nEnter Your Choice");
      scanf("%d", &choice);
      switch (choice) {
      case 1:
         printf("\nEnter The item to be pushed");
         scanf("%d", &item);
         if (isfull())
            printf("\nStack is Full");
         else
            push(item);
         break;
      case 2:
         if (isEmpty())
            printf("\nEmpty stack");
         else {
            item = pop();
            printf("\nThe popped element is %d", item);
         }
         break;
      case 3:
         display();
         break;
      default: printf("Invalid choice");
	  }
      printf("\nEnter 'y' or 'Y'To Continue");
      c = getche();
   } while (c == 'Y' || c == 'y');
 
return 0;
}

