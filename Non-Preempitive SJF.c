/*Write a Cprogram using for Non Preemptive SJF Process Scheduling Algorithm to Implement Follwing
functionality.
a)Accept process number,Arrival Time,Burst Time.
b)Display Gantt Chart.
c)Calculate and Display Average turn around,Waiting Time.*/
#include<stdio.h>
int main()
{
    int P[5],AT[5],BT[5],TAT[5],WT[5];
    int n,i,j,temp,sum=0;
    float avg;
    printf("Enter no of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Process Number:");
        scanf("%d",&P[i]);
        printf("Enter Arrival Time:");
        scanf("%d",&AT[i]);
        printf("Enter Burst Time:");
        scanf("%d",&BT[i]);
    }
    for(i=0;i<n;i++)
    {
        if(AT[i]==0)
        {
            temp=P[0];
            P[0]=P[i];
            P[i]=temp;
            temp=AT[0];
            AT[0]=AT[i];
            AT[i]=temp;
            temp=BT[0];
            BT[0]=BT[i];
            BT[i]=temp;
        }
    }
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(BT[i]>BT[j])
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
    printf("After Sorting on Burst Time");
    printf("\nPro\tArrival\tBurst\n");
    for(i=0;i<n;i++)
    {
        printf("\n\t%d\t%d\t%d",P[i],AT[i],BT[i]);
    }
    WT[0]=0;
    
    for(i=0;i<n;i++)
    {
        WT[i+1]=WT[i]+BT[i];
        sum=sum+(WT[i]-AT[i]);
    }
    WT[n]=WT[n-1]+BT[n-1];
    printf("\nWaiting Time is %d",sum);
    avg=(float)sum/(float)n;
    printf("Average Waiting Time is %f",avg);
    sum=0;
    for(i=0;i<n;i++)
    {
        TAT[i]=WT[i]-AT[i];
        sum=sum+(WT[i+1]-TAT[i]);
    }
    printf("\nSum of Turnaround Time is \t%d",sum);
    avg=(float)sum/(float)n;
    printf("\nAverage Turnaround Time is %f",avg);
    printf("\nGantt Chart:");
    printf("\n.................................\n");
    for(i=0;i<n;i++)
    {
        printf("|P\t%d\t",P[i]);
    }
    printf("\n....................................\n");
    for(i=0;i<=n;i++)
    {
        printf("\t%d\t",WT[i]);
    }
}
