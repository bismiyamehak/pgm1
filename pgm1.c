#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct day
{
 char *dayName;
 int date;
 int month;
 int year;
 char *activity;
};
struct day *create()
{
 struct day *calendar;
 calendar=(struct day*)malloc(7*sizeof(struct day));
 return calendar;
}
void read(struct day *calendar)
{
 int i;
 char tempName[50],tempDesc[100];
 for(i=0;i<7;i++)
 {
 printf("\n Enter the name of the day:");
 scanf("%s",tempName);
 calendar[i].dayName=(char *)malloc(strlen(tempName)+1);
 strcpy(calendar[i].dayName,tempName);
 printf("Enter the date(1-31):");
 scanf("%d",&calendar[i].date);
 printf("Enter the month(1-12):");
 scanf("%d",&calendar[i].month);
 printf("Enter the year:");
 scanf("%d",&calendar[i].year);
 printf("Enter the activity description for %s:",calendar[i].dayName);
 scanf("%s",tempDesc);
 calendar[i].activity=(char *)malloc(strlen(tempDesc)+1);
 strcpy(calendar[i].activity,tempDesc);
 }
 }
void display(struct day *calendar)
{
 int i;
 printf("\n\n====WEEKLY CALENDAR====\n");
 for(i=0;i<7;i++)
{
 printf("\n Day:%s",calendar[i].dayName);
 printf("\n Date:%02d-%02d-%04d",calendar[i].date,calendar[i].month,calendar[i].year);
 printf("\n Activity:%s",calendar[i].activity);
}
}
void freeMemory(struct day*calendar)
{
 int i;
 for(i=0;i<7;i++)
{
 free(calendar[i].dayName);
 free(calendar[i].activity);
}
free(calendar);
}
int main()
{
 struct day *myCalendar;
 clrscr();
 printf("Please enter the details for each day of the week:\n");
 myCalendar=create();
 read(myCalendar);
 display(myCalendar);
 freeMemory(myCalendar);
 getch();
 return 0;
}
