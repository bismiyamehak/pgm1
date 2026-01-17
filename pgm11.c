#include <stdio.h>
#include <conio.h>
int a[20][20], q[20], visited[20], reach[20];
int n, i, j, f, r;
void create()
{
int i, j;
printf("\nEnter the number of vertices: ");
scanf("%d", &n);
for (i = 1; i <= n; i++)
{
q[i] = 0;
visited[i] = 0;
reach[i] = 0;
}
printf("\nEnter the adjacency matrix (use 1 for edge, 0 for no edge):\n");
for (i = 1; i <= n; i++)
{
for (j = 1; j <= n; j++)
{
scanf("%d", &a[i][j]);
}
}
}
void bfs(int v)
{
f = 0;
r = 0;
visited[v] = 1;
q[++r] = v;
while (f != r)
{
v = q[++f];
printf("%d ", v);
for (i = 1; i <= n; i++)
{
if (a[v][i] == 1 && visited[i] == 0)
{
visited[i] = 1;
q[++r] = i;
}
}
}
}
void dfs(int v)
{
int i;
reach[v] = 1;
for (i = 1; i <= n; i++)
{
if (a[v][i] && !reach[i])
{
printf("%d ", i);
dfs(i);
}
}
}
void main()
{
int v, ch;
clrscr();
do
{
printf("\n--- MENU ---");
printf("\n1. Create Graph");
printf("\n2. BFS Traversal");
printf("\n3. DFS Traversal");
printf("\n4. Exit");
printf("\nEnter your choice: ");
scanf("%d", &ch);
switch (ch)
{
case 1:
create();
break;
case 2:
printf("\nEnter the starting vertex: ");
scanf("%d", &v);
for (i = 1; i <= n; i++)
{
q[i] = 0;
visited[i] = 0;
}
if ((v < 1) || (v > n))
printf("\nBFS is not possible.\n");
else
{
printf("\nNodes reachable from vertex %d using BFS: ", v);
bfs(v);
}
break;
case 3:
printf("\nEnter the starting vertex: ");
scanf("%d", &v);
for (i = 1; i <= n; i++)
reach[i] = 0;
if ((v < 1) || (v > n))
printf("\nDFS is not possible.\n");
else
{
printf("\nNodes reachable from vertex %d using DFS: %d ", v, v);
dfs(v);
}
break;
case 4:
printf("\nExiting program...\n");
break;
default:
printf("\nInvalid choice!\n");
}
} while (ch != 4);
getch();
}