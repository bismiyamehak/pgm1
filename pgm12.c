#include <stdio.h>
#include <conio.h>
#define MAX 10
void display(int a[MAX])
{
int i, ch;
do
{
printf("\n1. Display all");
printf("\n2. Filtered Display (Non-empty slots)");
printf("\nEnter your choice: ");
scanf("%d", &ch);
switch (ch)
{
case 1:
printf("\nThe hash table is:\n");
for (i = 0; i < MAX; i++)
printf("%d --> %d\n", i, a[i]);
break;
case 2:
printf("\nThe hash table (non-empty slots):\n");
for (i = 0; i < MAX; i++)
{
if (a[i] != -1)
printf("%d --> %d\n", i, a[i]);
}
break;
default:
printf("\nInvalid choice!\n");
}
} while (ch <= 2);
}
int create(int num)
{
int key;
key = num % 10; /* Hash function H(K) = K mod m */
return key;
}
void linearprob(int a[MAX], int key, int num)
{
int flag = 0, i, c = 0;
if (a[key] == -1)
a[key] = num;
else
{
printf("\nCollision Detected at index %d...!!!\n", key);
for (i = 0; i < MAX; i++)
{
if (a[i] != -1)
c++;
}
if (c == MAX)
{
printf("\nHash table is full!\n");
return;
}
printf("\nCollision avoided successfully using LINEAR PROBING.\n");
for (i = key + 1; i < MAX; i++)
{
if (a[i] == -1)
{
a[i] = num;
flag = 1;
break;
}
}
i = 0;
while ((i < key) && (flag == 0))
{
if (a[i] == -1)
{
a[i] = num;
flag = 1;
break;
}
i++;
}
}
}
void main()
{
int a[MAX], num, key, i;
int ch;
clrscr();
printf("\n*** Collision Handling by Linear Probing ***\n");
for (i = 0; i < MAX; i++)
a[i] = -1;
do
{
printf("\nEnter a 4-digit employee key: ");
scanf("%d", &num);
key = create(num);
linearprob(a, key, num);
printf("\nDo you wish to continue? (1 = Yes / 0 = No): ");
scanf("%d", &ch);
} while (ch);
display(a);
getch();
}