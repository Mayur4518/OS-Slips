/*Write a C Program using FIFO Page Replacement to implement following  [10]  
a) Accept Reference String      
b) Display Page Replacement   
c) Calculate & Display Page Fault */
#include<stdio.h>
int main()
{
	int i,j,n,pages[20],temp[20],f1,f2,frames,pos=0,faults=0;
	printf("Enter no of pages:");
	scanf("%d",&n);
	printf("Enter page reference string");
	for(i=0;i<n;i++)
	{
		scanf("%d",&pages[i]);
	}
	printf("Enter no of frames:");
	scanf("%d",&frames);
	//Initialize frames to -1(indicating empty)
	for(i=0;i<frames;i++)
	{
		temp[i]=-1;
	}
	printf("\nPage Reference String | Frames\n");
	for(i=0;i<n;i++)
	{
		f1=f2=0;
		//check if the page is already in any frame
		for(j=0;j<frames;j++)
		{
			if(temp[j]==pages[i])
			{
				f1=f2=1;
				break;
			}
		}
		//If page is not found in any frame
		if(f1==0)
		{
			//If there is empty frame,insert the page
			for(j=0;j<frames;j++)
			{
			 if(temp[j]==-1)
			 {
			 	temp[j]=pages[i];
			 	f2=1;
			 	faults++;
			 	break;
			 }
			}
		}
		//If no empty frame,apply FIFO replacement
		if(f2==0)
		{
			temp[pos]=pages[i];
			pos=(pos+1)%frames;
			faults++;
		}
		//Display the current status of frames
		printf("\n%2d\t\t",pages[i]);
		for(j=0;j<frames;j++)
		{
			if(temp[j]!=-1)
			{
				printf("%2d",temp[j]);
			}
			else
			{
				printf("-");
			}
		}
	}
	printf("Total Page Faults=%d",faults);
	return 0;
}
