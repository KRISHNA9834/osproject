#include<stdio.h>
#include<conio.h>
void main()
{
 int arrive[100],brust[100],brust_store[100];
 int t = 3;
 int waiting[100],turnaround[100],completion[100];
 int i,j,smallest,starting_process=0,time,n;
 double avg=0,tt=0,end;
 printf("\nEnter the number of Processes: ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
   printf("\nEnter arrival time of process %d : ",i+1);
   scanf("%d",&arrive[i]);
 }
 for(i=0;i<n;i++)
 {
   printf("\nEnter burst time of process %d : ",i+1);
   scanf("%d",&brust[i]);
 }
 for(i=0;i<n;i++)
 {
 	brust_store[i]=brust[i];
 }
  brust[99]=9999;
 
 for(time=0;starting_process!=n;time++)
 {
  smallest=99;
  for(i=0;i<n;i++)
  {
   if(arrive[i]<=time && brust[i]<brust[smallest] && brust[i]>0 )
   smallest=i;
  }
    brust[smallest]--;
  if(brust[smallest]==0)
  {
   starting_process++;
   end=time+1;
   completion[smallest] = end;
   time=time+3;
   waiting[smallest] = end - arrive[smallest] - brust_store[smallest];
   turnaround[smallest] = end - arrive[smallest];
  }
 }
 
 printf("_________________________________________________________________________________________\n");
 printf("|  pid\t | burst| arrival|\t waiting\t|\tturnaround\t| completion\t|\n");
 printf("|________|______|________|______________________|_______________________|_______________|\n");
 for(i=0;i<n;i++)
 {
   printf("\n|  P%d\t |  %d\t|  %d\t |\t   %d\t\t|\t   %d\t\t| \t%d\t|",i+1,brust_store[i],arrive[i],waiting[i],turnaround[i],completion[i]);
   avg = avg + waiting[i];
   tt = tt + turnaround[i];
 }
  printf("\n|________|______|________|______________________|_______________________|_______________|\n");
 printf("\n\nAverage waiting time = %lf\n",avg/n);
 printf("Average Turnaround time = %lf",tt/n);
 getch();
}
