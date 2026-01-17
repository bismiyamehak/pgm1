#include <stdio.h>
#include <conio.h>
#define MAX 4
int s[MAX], top = -1, ele, i;
void push(int ele)
{
if (top == MAX - 1)
{
printf("\nStack Overflow\n");
return;
}
top++;
s[top] = ele;
printf("\n%d pushed onto stack\n", ele);
}
int pop()
{
int ele;
if (top == -1)
{
printf("\nStack Underflow\n");
return -1;
}
ele = s[top];
top--;
return ele;
}
void display()
{
int i;
if (top == -1)
{
printf("\nStack is Empty\n");
return;
}
printf("\nStack contents are:\n");
for (i = top; i >= 0; i--)
printf("%d\n", s[i]);
}
void pal()
{
int n, temp, digit, rev = 0, len = 0, i = 1;
top = -1;
printf("\nEnter a number: ");
scanf("%d", &n);
temp = n;
while (n != 0)
{
digit = n % 10;
n = n / 10;
push(digit);
len++;
}
while (len != 0)
{
digit = pop();
if (digit == -1)
break;
rev = rev + (digit * i);
len--;
i = i * 10;
}
if (temp == rev)
printf("\nNumber is a Palindrome\n");
else
printf("\nNumber is Not a Palindrome\n");
}
void main()
{
int ch;
clrscr();
do
{ printf("\n===== STACK MENU =====\n");
printf("1. Push\n");
printf("2. Pop\n");
printf("3. Display\n");
printf("4. Palindrome Check\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &ch);
switch (ch)
{
case 1:
printf("\nEnter the element to be pushed: ");
scanf("%d", &ele);
push(ele);
break;
case 2:
ele = pop();
if (ele != -1)
printf("\nElement deleted is %d\n", ele);
break;
case 3:
display();
break;
case 4:
pal();
break;
case 5:
printf("\nExiting program...\n");
break;
default:
printf("\nInvalid choice! Please try again.\n");
}
} while (ch != 5);
getch();
}