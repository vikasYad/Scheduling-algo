#include<stdio.h>
int main()
{
  int count,j,n;
  int t,remain;
  int flag=0,tq=10;
  int wt=0,turn_around_time=0,at[10],bt[10],rt[10];
  printf("\n\nEnter the Total number of Process:\t ");
  scanf("%d",&n);
  remain=n;
  for(count=0;count<n;count++)
  {
    printf("Enter Arrival Time and Burst Time for Process %d :",count+1);
    scanf("%d",&at[count]);
    scanf("%d",&bt[count]);
    rt[count]=bt[count];
  }
  printf("Enter Time Quantum:%d\t",tq);
 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  for(t=0,count=0;remain!=0;)
  {
    if(rt[count]<=tq && rt[count]>0)
    {
      t+=rt[count];
      rt[count]=0;
      flag=1;
    }
    else if(rt[count]>0)
    {
      rt[count]-=tq;
      t+=tq;
    }
    if(rt[count]==0 && flag==1)
    {
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,t-at[count],t-at[count]-bt[count]);
      wt+=t-at[count]-bt[count];
      turn_around_time+=t-at[count];
      flag=0;
    }
    if(count==n-1)
      count=0;
    else if(at[count+1]<=t)
      count++;
    else
      count=0;
  }
  printf("\nAverage Waiting Time= %f\n",wt*1.0/n);
  printf("Avg Turnaround Time = %f",turn_around_time*1.0/n);
 
  return 0;
}
