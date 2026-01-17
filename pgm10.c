#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node
{
int info;
struct node *llink;
struct node *rlink;
} NODE;
NODE *root = NULL;
void inorder(NODE *ptr)
{
if (ptr != NULL)
{
inorder(ptr->llink);
printf("%d ", ptr->info);
inorder(ptr->rlink);
}
}
void preorder(NODE *ptr)
{
if (ptr != NULL)
{
printf("%d ", ptr->info);
preorder(ptr->llink);
preorder(ptr->rlink);
}
}
void postorder(NODE *ptr)
{
if (ptr != NULL)
{
postorder(ptr->llink);
postorder(ptr->rlink);
printf("%d ", ptr->info);
}
}
void create()
{
NODE *nn, *prev, *temp;
int i, n;
printf("\nEnter the number of elements: ");
scanf("%d", &n);
for (i = 1; i <= n; i++)
{
nn = (NODE *)malloc(sizeof(NODE));
printf("Enter element %d: ", i);
scanf("%d", &nn->info);
nn->llink = NULL;
nn->rlink = NULL;
if (root == NULL)
{
root = nn;
}
else
{
temp = root;
while (temp != NULL)
{
prev = temp;
if (nn->info > temp->info)
temp = temp->rlink;
else
temp = temp->llink;
}
if (nn->info < prev->info)
prev->llink = nn;
else
prev->rlink = nn;
}
}
}
NODE *search(NODE *temp, int key)
{
if (temp == NULL)
return NULL;
else if (key < temp->info)
return search(temp->llink, key);
else if (key > temp->info)
return search(temp->rlink, key);
else
return temp;
}
/* Function to delete a node */
NODE *deleteNode(NODE *root, int key)
{
NODE *temp, *succ;
if (root == NULL)
return root;
if (key < root->info)
root->llink = deleteNode(root->llink, key);
else if (key > root->info)
root->rlink = deleteNode(root->rlink, key);
else
{
if (root->llink == NULL)
{
temp = root->rlink;
free(root);
return temp;
}
else if (root->rlink == NULL)
{
temp = root->llink;
free(root);
return temp;
}
succ = root->rlink;
while (succ->llink != NULL)
succ = succ->llink;
root->info = succ->info;
root->rlink = deleteNode(root->rlink, succ->info);
}
return root;
}
void main()
{
int ch, key, elem;
NODE *f;
clrscr();
do
{
printf("\n--- MENU ---\n");
printf("1. Create BST\n");
printf("2. Inorder Traversal\n");
printf("3. Preorder Traversal\n");
printf("4. Postorder Traversal\n");
printf("5. Search Element\n");
printf("6. Delete Element\n");
printf("7. Exit\n");
printf("Enter your choice: ");
scanf("%d", &ch);
switch (ch)
{
case 1:
create();
break;
case 2:
printf("\nInorder Traversal: ");
inorder(root);
break;
case 3:
printf("\nPreorder Traversal: ");
preorder(root);
break;
case 4:
printf("\nPostorder Traversal: ");
postorder(root);
break;
case 5:
printf("\nEnter the key to search: ");
scanf("%d", &key);
f = search(root, key);
if (f == NULL)
printf("Key not found.\n");
else
printf("Key found!\n");
break;
case 6:
printf("\nEnter the element to delete: ");
scanf("%d", &elem);
root = deleteNode(root, elem);
printf("Element deleted (if present).\n");
break;
case 7:
printf("\nExiting program...\n");
break;
default:
printf("Invalid choice.\n");
}
} while (ch != 7);
getch();
}