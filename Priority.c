/*Write a Cprogram using for Non Preemptive Priority SJF Process Scheduling Algorithm to Implement Follwing
functionality.
a)Accept process number,Arrival Time,Burst Time.
b)Display Gantt Chart.
c)Calculate and Display Average turn around,Waiting Time.*/
#include<stdio.h>
int main()
{
    int P[5],AT[5],BT[5],WT[5],TAT[5],PR[5];
    int n,i,j,temp,sum=0;
    float avg;
    printf("Enter no of process:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter process no:");
        scanf("%d",&P[i]);
        printf("Enter Arrival Time:");
        scanf("%d",&AT[i]);
        printf("Enter Burst Time:");
        scanf("%d",&BT[i]);
        printf("Enter priority:");
        scanf("%d",&PR[i]);
    }
    for(i=0;i<n;i++)
    {
        if(AT[i]==0);
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
            temp=PR[0];
            PR[0]=PR[i];
            PR[i]=temp;
        }
    }
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(PR[i]<PR[j])
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
                temp=PR[i];
                PR[i]=PR[j];
                PR[j]=temp;
            }
        }
    }
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(PR[i]==PR[j])
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
                    temp=PR[i];
                    PR[i]=PR[j];
                    PR[j]=temp;
                }
            }
        }
    }
    printf("After Sorting on Priority:");
    printf("\nPro\tArrival\tBurst\tPriority\n");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t%d\t%d\t%d",P[i],AT[i],BT[i],PR[i]);
    }
    WT[0]=0;
    for(i=0;i<n;i++)
    {
        WT[i+1]=WT[i]+BT[i];
        sum=sum+(WT[i]-AT[i]);
    }
    WT[n]=WT[n-1]+BT[n-1];
    printf("\nSum of Waiting Time is:\t%d",sum);
    avg=sum/n;
    printf("\nAverage Waiting Time is:\t%d",avg);
    sum=0;
    for(i=0;i<n;i++)
    {
        TAT[i]=(WT[i]-AT[i]);
        sum=sum+(WT[i+1]-TAT[i]);
    }
    printf("\nSum of Turnsround Time:\t%d",sum);
    avg=sum/n;
    printf("\nAverage Turnaround Time is:\t%d",avg);
    printf("\nGantt Chart:");
    printf("\n.....................\n");
    for(i=0;i<n;i++)
    {
        printf("|P%d\t",P[i]);
    }
    printf("\n.................................\n");
    for(i=0;i<=n;i++)
    {
        printf("\t%d\t",WT[i]);
    }
}