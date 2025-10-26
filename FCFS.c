/*Writr a C program using FCFS Process Scheduling Algorithm to implement following functionality.
a)Accept Process Number,Arrival Time,Burst Time.
b)Display Gant Chart.
c)Calculate & Display Average turn around,Waiting Time.
*/
#include<stdio.h>
int main()
{
	int P[5],AT[5],BT[5],WT[5],TAT[5];
	int n,i,j,temp,sum=0;
	float avg;
	printf("Enter number of process\n");
	scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	printf("Enter Processes:");
    	scanf("%d",&P[i]);
    	printf("Enter Arrival time for process:");
    	scanf("%d",&AT[i]);
    	printf("Enter Burst time for process:");
    	scanf("%d",&BT[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(AT[i]>AT[j])
			{
				temp=P[i];
				P[i]=P[j];
				P[j]=temp;
				temp=AT[i];
				AT[i]=AT[j];
				AT[j]=temp;
				temp=BT[i];
				BT[i]=BT[j];
				BT[j]=temp;
			}
		}
	}
	printf("\nAfter Sorting on Arrival Time:");
	printf("\nProcesses\tArrival Time\tBurst Time\n");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\n",P[i],AT[i],BT[i]);
	}
	WT[0]=0;
	for(i=0;i<n;i++)
	{
		WT[i+1]=WT[i]+BT[i];
		sum=sum+(WT[i]-AT[i]);
	}
	WT[n]=WT[n-1]+BT[n-1];
	printf("\nWaiting Time is\t%d",sum);
	avg=(float)sum/(float)n;
	printf("\nAverage Waiting Time is %f",avg);
	sum=0;
	for(i=0;i<n;i++)
	{
		TAT[i]=(WT[i]-AT[i]);
		sum=sum+(WT[i+1]-TAT[i]);
	}
	printf("\nSum of Turnaround Time is\t%d",sum);
	avg=(float)sum/(float)n;
	printf("\nAverage Turnsround Time is %f",avg);
	printf("\nGantt Chart:");
	printf("\n...............................\n");
	for(i=0;i<n;i++)
	{
		printf("|P\t%d\t",P[i]);
	}
	printf("\n.................................\n");
	for(i=0;i<=n;i++)
	{
		printf("\t%d\t",WT[i]);
	}
}
