#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node
{
int cf;
int xex, yex, zex;
struct node *link;
} NODE;
NODE *p3 = NULL, *p3head = NULL;
NODE *insert(NODE *head, NODE *last, int n)
{
int i;
NODE *nn;
if (head == NULL)
{
head = (NODE *)malloc(sizeof(NODE));
head->link = head; /* header node */
last = head;
}
for (i = 1; i <= n; i++)
{
nn = (NODE *)malloc(sizeof(NODE));
printf("\nEnter the coefficient: ");
scanf("%d", &nn->cf);
printf("Enter the exponents of x, y, z: ");
scanf("%d%d%d", &nn->xex, &nn->yex, &nn->zex);
nn->link = head;
last->link = nn;
last = nn;
}
return last;
}
void display(NODE *last)
{
NODE *temp;
if (last == NULL)
{
printf("\nList is empty\n");
return;
}
temp = last->link->link; /* skip header */
printf("\nPolynomial: ");
while (temp != last)
{
printf("(%dx^%dy^%dz^%d) + ", temp->cf, temp->xex, temp->yex, temp->zex);
temp = temp->link;
}
printf("(%dx^%dy^%dz^%d)", temp->cf, temp->xex, temp->yex, temp->zex);
}
void add(NODE *p1, NODE *p2, int n1, int n2)
{
NODE *nn = NULL, *a, *b;
int i = 0, j = 0;
a = p1->link->link;
b = p2->link->link;
p3head = (NODE *)malloc(sizeof(NODE));
p3head->link = p3head;
p3 = p3head;
while (i < n1 && j < n2)
{
nn = (NODE *)malloc(sizeof(NODE));
nn->link = p3head;
p3->link = nn;
p3 = nn;
if (a->xex == b->xex && a->yex == b->yex && a->zex == b->zex)
{
nn->cf = a->cf + b->cf;
nn->xex = a->xex;
nn->yex = a->yex;
nn->zex = a->zex;
a = a->link;
b = b->link;
i++;
j++;
}
else if (a->xex > b->xex)
{
nn->cf = a->cf;
nn->xex = a->xex;
nn->yex = a->yex;
nn->zex = a->zex;
a = a->link;
i++;
}
else
{nn->cf = b->cf;
nn->xex = b->xex;
nn->yex = b->yex;
nn->zex = b->zex;
b = b->link;
j++;
}
}
while (i < n1)
{
nn = (NODE *)malloc(sizeof(NODE));
nn->link = p3head;
p3->link = nn;
p3 = nn;
nn->cf = a->cf;
nn->xex = a->xex;
nn->yex = a->yex;
nn->zex = a->zex;
a = a->link;
i++;
}
while (j < n2)
{
nn = (NODE *)malloc(sizeof(NODE));
nn->link = p3head;
p3->link = nn;
p3 = nn;
nn->cf = b->cf;
nn->xex = b->xex;
nn->yex = b->yex;
nn->zex = b->zex;
b = b->link;
j++;
}
printf("\nPolynomials added successfully!\n");
}
void eval(NODE *p)
{
int x, y, z, res = 0, xval, yval, zval;
NODE *temp;
printf("\nEnter values of x, y, and z: ");
scanf("%d%d%d", &x, &y, &z);
temp = p->link->link;
while (temp != p)
{
xval = pow(x, temp->xex);
yval = pow(y, temp->yex);
zval = pow(z, temp->zex);
res = res + (temp->cf * xval * yval * zval);
temp = temp->link;
}
xval = pow(x, temp->xex);
yval = pow(y, temp->yex);
zval = pow(z, temp->zex);
res = res + (temp->cf * xval * yval * zval);
printf("\nThe result of the polynomial = %d\n", res);
}
void main()
{
int n1, n2;
NODE *head1 = NULL, *head2 = NULL, *p1 = NULL, *p2 = NULL;
clrscr();
printf("Enter the number of terms of first polynomial: ");
scanf("%d", &n1);
p1 = insert(head1, p1, n1);
display(p1);
eval(p1);
printf("\n\nEnter the number of terms of second polynomial: ");
scanf("%d", &n2);
p2 = insert(head2, p2, n2);
display(p2);
eval(p2);
add(p1, p2, n1, n2);
printf("\n\nFirst Polynomial:");
display(p1);
printf("\n\nSecond Polynomial:");
display(p2);
printf("\n\nSum Polynomial:");
display(p3);
getch();
}