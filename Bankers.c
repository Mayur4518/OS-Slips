    #include<stdio.h>
	int i,j,n,p,r,f,temp,s,need[20][20],allocation[20][20],work[10],available[10],max[20][20],safe[20],finish[10];
	void check()
	{
		temp=0,s=0;
		for(i=0;i<p;i++)
		{
			for(j=0;j<r;j++)
			{
				need[i][j]=max[i][j]-allocation[i][j];
			}
		}
		printf("Need Table:\n");
		for(i=0;i<p;i++)
		{
			for(j=0;j<r;j++)
			{
				printf("%d\t",need[i][j]);
			}
			printf("\n");
		}
		for(i=0;i<p;i++)
		{
			finish[i]=0;
		}
		for(i=0;i<r;i++)
		{
			work[i]=available[i];
		}
		while(temp<2)
		{
			for(i=0;i<p;i++)
			{
				for(j=0;j<r;j++)
				{
					if(finish[i]==0&&need[i][j]<=work[j])
					{
						f=1;
					}
					else
					{
						f=0;
						break;
					}
				}
				if(f==1)
				{
					for(j=0;j<r;j++)
					{
						work[j]=work[j]+allocation[i][j];
					}
					finish[i]=1;
					safe[s++]=i;
				}
			}
			temp++;
		}
		f=0;
		for(i=0;i<p;i++)
		{
			if(finish[i]==0)
			{
				f=1;
				break;
			}
		}
		if(f==1)
		{
			printf("\nSystem is in deadlock state..");
		}
		else
		{
			printf("\nSystem is in safe state..");
			printf("\nSafe sequence is");
			for(i=0;i<p;i++)
			{
				printf("P%d\t",safe[i]);
			}
		}
	}
int main()
{
	printf("Enter no of process and resourses:");
	scanf("%d%d",&p,&r);
	printf("Enter Allocation table:");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&allocation[i][j]);
		}
	}
	printf("Enter max table:");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("Enter available vector:");
	for(i=0;i<r;i++)
	{
		scanf("%d",&available[i]);
	}
	check();
}
