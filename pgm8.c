#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
char ssn[10];
char name[20];
char dept[10];
char desg[10];
char sal[10];
char phno[11];
struct node *llink;
struct node *rlink;
};
typedef struct node NODE;
NODE *first = NULL;
void create()
{
NODE *temp, *nn;
int i, n;
printf("\nEnter the number of employees: ");
scanf("%d", &n);
for (i = 1; i <= n; i++)
{
nn = (NODE *)malloc(sizeof(NODE));
printf("\nEnter SSN, Name, Dept, Designation, Salary, PhNo:\n");
scanf("%s%s%s%s%s%s", nn->ssn, nn->name, nn->dept, nn->desg, nn->sal, nn->phno);
nn->rlink = NULL;
nn->llink = NULL;
if (first == NULL)
{
first = nn;
}
else
{
temp = first;
while (temp->rlink != NULL)
temp = temp->rlink;
temp->rlink = nn;
nn->llink = temp;
}
}
printf("\nDLL created successfully!\n");
}
void insert_end()
{
NODE *temp, *nn;
nn = (NODE *)malloc(sizeof(NODE));
printf("\nEnter SSN, Name, Dept, Designation, Salary, PhNo:\n");
scanf("%s%s%s%s%s%s", nn->ssn, nn->name, nn->dept, nn->desg, nn->sal, nn->phno);
nn->rlink = NULL;
if (first == NULL)
{
nn->llink = NULL;
first = nn;
return;
}
temp = first;
while (temp->rlink != NULL)
temp = temp->rlink;
temp->rlink = nn;
nn->llink = temp;
printf("\nNode inserted at end successfully.\n");
}
void insert_front()
{
NODE *nn;
nn = (NODE *)malloc(sizeof(NODE));
printf("\nEnter SSN, Name, Dept, Designation, Salary, PhNo:\n");
scanf("%s%s%s%s%s%s", nn->ssn, nn->name, nn->dept, nn->desg, nn->sal, nn->phno);
nn->llink = NULL;
nn->rlink = first;
if (first != NULL)
first->llink = nn;
first = nn;
printf("\nNode inserted at front successfully.\n");
}
void delete_front()
{
NODE *temp;
if (first == NULL)
{
printf("\nList is empty. Cannot delete.\n");
return;
}
temp = first;
if (first->rlink == NULL)
{
first = NULL;
}
else
{
first = first->rlink;
first->llink = NULL;
}
printf("\nDeleted Employee: %s %s\n", temp->ssn, temp->name);
free(temp);
}
void delete_end()
{
NODE *temp;
if (first == NULL)
{
printf("\nList is empty. Cannot delete.\n");
return;
}
temp = first;
if (temp->rlink == NULL)
{
printf("\nDeleted Employee: %s %s\n", temp->ssn, temp->name);
free(temp);
first = NULL;
return;
}
while (temp->rlink != NULL)
temp = temp->rlink;
printf("\nDeleted Employee: %s %s\n", temp->ssn, temp->name);
temp->llink->rlink = NULL;
free(temp);
}
void display()
{
NODE *temp;
int count = 0;
if (first == NULL)
{
printf("\nList is empty.\n");
return;
}
temp = first;
printf("\nContents of the Doubly Linked List:\n");
printf("SSN\tName\tDept\tDesg\tSal\tPhNo\n");
printf("-----------------------------------------------\n");
while (temp != NULL)
{
printf("%s\t%s\t%s\t%s\t%s\t%s\n", temp->ssn, temp->name, temp->dept, temp->desg, temp->sal, temp->phno);
temp = temp->rlink;
count++;
}
printf("-----------------------------------------------\n");
printf("Total number of employees = %d\n", count);
}
void main()
{
int ch;
clrscr();
do
{
printf("\n==== DOUBLY LINKED LIST MENU ====\n");
printf("1. Create DLL (End Insertion)\n");
printf("2. Insert at Front\n");
printf("3. Insert at End\n");
printf("4. Delete at Front\n");
printf("5. Delete at End\n");
printf("6. Display\n");
printf("7. Exit\n");
printf("Enter your choice: ");
scanf("%d", &ch);
switch (ch)
{
case 1:
create();
break;
case 2:
insert_front();
break;
case 3:
insert_end();
break;
case 4:
delete_front();
break;
case 5:
delete_end();
break;
case 6:
display();
break;
case 7:
printf("\nExiting program...\n");
break;
default:
printf("\nInvalid choice! Try again.\n");
}
} while (ch != 7);
getch();
}