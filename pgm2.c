#include <stdio.h>
#include <conio.h>
#define MAX 100
void strrep(char s[], char p[], char r[], char f[])
{
int i, j, k, m, t, found;
i = j = k = m = t = found = 0;
while (s[i] != '\0')
{
if (s[i] == p[j])
{
i++;
j++;
if (p[j] == '\0') /* pattern completely matched */
{
for (k = 0; r[k] != '\0'; k++, t++)
f[t] = r[k];
found = 1;
j = 0;
}
}
else
{
if (j == 0)
{
f[t++] = s[i++];
}
else
{
/* copy the matched portion from pattern start again */
for (m = 0; m < j; m++, t++)
f[t] = s[i - j + m];
f[t++] = s[i++];
j = 0;
}
}
}
f[t] = '\0'; /* terminate final string */
if (found == 1)
{
printf("\nResultant string is: ");
puts(f);
}
else
{
printf("\nPattern not found in main string.\n");
}
}
void main()
{
char s[MAX], p[MAX], r[MAX], f[MAX];
clrscr();
printf("Enter the main string:\n");
gets(s);
printf("Enter the pattern string:\n");
gets(p);
printf("Enter the replace string:\n");
gets(r);
strrep(s, p, r, f);
getch();
}