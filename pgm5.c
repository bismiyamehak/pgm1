#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int op1, op2, res, i, top = -1, s[20];
/* ---------- Stack Functions ---------- */
void push(int ele)
{
top++;
s[top] = ele;
}
int pop()
{
    int ele;
ele = s[top];
top--;
return ele;
}
/* ---------- Postfix Evaluation ---------- */
void eval()
{
char postfix[30], ch;
top = -1; // reset stack
printf("\nEnter the postfix expression: ");
scanf("%s", postfix);
for (i = 0; postfix[i] != '\0'; i++)
{
ch = postfix[i];
if (isdigit(ch))
push(ch - '0');
else
{
op2 = pop();
op1 = pop();
switch (ch)
{
case '+':
res = op1 + op2;
break;
case '-':
res = op1 - op2;
break;
case '*':
res = op1 * op2;
break;
case '/':
res = op1 / op2;
break;
case '%':
res = op1 % op2;
break;
case '^':
res = pow(op1, op2);
break;
default:
printf("\nInvalid operator encountered!");
return;
}
push(res);
}
}
printf("\nResult of Postfix Expression = %d\n", pop());
}
/* ---------- Tower of Hanoi ---------- */
void tow(int n, char src, char tmp, char dest)
{
if (n == 1)
{
printf("\nMove disk 1 from %c to %c", src, dest);
return;
}
tow(n - 1, src, dest, tmp);
printf("\nMove disk %d from %c to %c", n, src, dest);
tow(n - 1, tmp, src, dest);
}
/* ---------- Main Menu ---------- */
void main()
{
int ch, n;
clrscr();
do
{
printf("\n===== STACK APPLICATIONS =====\n");
printf("1. Evaluation of Postfix Expression\n");
printf("2. Tower of Hanoi\n");
printf("3. Exit\n");
printf("Enter your choice: ");
scanf("%d", &ch);
switch (ch)
{
case 1:
eval();
break;
case 2:
printf("\nEnter number of disks: ");
scanf("%d", &n);
tow(n, 'S', 'T', 'D');
break;
case 3:
printf("\nExiting program...\n");
break;
default:
printf("\nInvalid choice! Try again.\n");
}
} while (ch != 3);
getch();
}