#include <stdio.h>
#include <conio.h>
#define MAX 3
int cq[MAX], f = 0, r = -1, c = 0, ele;
void insert()
{
if (c == MAX)
{
printf("\nCIRCULAR QUEUE OVERFLOW\n");
return;
}
printf("\nEnter the value: ");
scanf("%d", &ele);
r = (r + 1) % MAX;
cq[r] = ele;
c++;
printf("Inserted %d successfully!\n", ele);
}
void delete_ele()
{
if (c == 0)
{
printf("\nCIRCULAR QUEUE UNDERFLOW\n");
f = 0;
r = -1;
return;
}
printf("\nElement deleted is %d\n", cq[f]);
f = (f + 1) % MAX;
c--;
}
void display()
{
int i, j;
if (c == 0)
{
printf("\nCIRCULAR QUEUE UNDERFLOW\n");
return;
}
printf("\nContents of Circular Queue:\n");
j = f;
for (i = 1; i <= c; i++)
{
printf("%d\t", cq[j]);
j = (j + 1) % MAX;
}
printf("\n");
}
void main()
{
int ch;
clrscr();
do
{
printf("\n==== CIRCULAR QUEUE MENU ====\n");
printf("1. Insert\n");
printf("2. Delete\n");
printf("3. Display\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &ch);
switch (ch)
{
case 1:
insert();
break;
case 2:
delete_ele();
break;
case 3:
display();
break;
case 4:
printf("\nExiting Program...\n");
break;
default:
printf("\nInvalid choice! Try again.\n");
}
} while (ch != 4);
getch();
}