#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
char usn[11];
char name[20];
char branch[10];
char sem[10];
char phno[10];
struct node *link;
};
typedef struct node NODE;
NODE *first = NULL;
void create()
{
int i, n;
NODE *nn;
printf("\nEnter number of students: ");
scanf("%d", &n);
for (i = 1; i <= n; i++)
{
nn = (NODE *)malloc(sizeof(NODE));
printf("\nEnter details for student %d\n", i);
printf("USN Name Branch Sem PhNo:\n");
scanf("%s %s %s %s %s", nn->usn, nn->name, nn->branch, nn->sem, nn->phno);
nn->link = first;
first = nn;
}
}
void insert_front()
{
NODE *nn;
nn = (NODE *)malloc(sizeof(NODE));
printf("\nEnter details to insert at front\n");
printf("USN Name Branch Sem PhNo:\n");
scanf("%s %s %s %s %s", nn->usn, nn->name, nn->branch, nn->sem, nn->phno);
nn->link = first;
first = nn;
printf("\nNode inserted at front successfully.\n");
}
void delete_front()
{
NODE *temp;
if (first == NULL)
{
printf("\nList is empty — cannot delete.\n");
return;
}
temp = first;
first = first->link;
printf("\nDeleted student record: %s %s\n", temp->usn, temp->name);
free(temp);
}
void insert_end()
{
NODE *nn, *temp;
nn = (NODE *)malloc(sizeof(NODE));
printf("\nEnter details to insert at end\n");
printf("USN Name Branch Sem PhNo:\n");
scanf("%s %s %s %s %s", nn->usn, nn->name, nn->branch, nn->sem, nn->phno);
nn->link = NULL;
if (first == NULL)
{
first = nn;
}
else
{
temp = first;
while (temp->link != NULL)
temp = temp->link;
temp->link = nn;
}
printf("\nNode inserted at end successfully.\n");
}
void delete_end()
{
NODE *temp, *prev;
if (first == NULL)
{
printf("\nList is empty — cannot delete.\n");
return;
}
if (first->link == NULL)
{
printf("\nDeleted student record: %s %s\n", first->usn, first->name);
free(first);
first = NULL;
return;
}
temp = first;
while (temp->link != NULL)
{
prev = temp;
temp = temp->link;
}
printf("\nDeleted student record: %s %s\n", temp->usn, temp->name);
free(temp);
prev->link = NULL;
}
void display()
{int c = 0;
NODE *temp;
if (first == NULL)
{
printf("\nList is empty.\n");
return;
}
temp = first;
printf("\nContents of the SLL:\n");
printf("USN\tName\tBranch\tSem\tPhNo\n");
printf("-----------------------------------------\n");
while (temp != NULL)
{
printf("%s\t%s\t%s\t%s\t%s\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
temp = temp->link;
c++;
}
printf("-----------------------------------------\n");
printf("Total number of nodes = %d\n", c);
}
void main()
{
int ch;
clrscr();
do
{
printf("\n==== SINGLY LINKED LIST MENU ====\n");
printf("1. Create SLL (Front Insertion)\n");
printf("2. Insert at Front\n");
printf("3. Delete at Front\n");
printf("4. Insert at End\n");
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
delete_front();
break;
case 4:
insert_end();
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