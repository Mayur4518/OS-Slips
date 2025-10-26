/* Write a C Program using Optimal Page Replacement to implement following  
a) Accept Reference String      
b) Display Page Replacement   
c) Calculate & Display Page Fault */
#include<stdio.h>
int findoptimal(int pages[],int temp[],int n,int current,int frames)
{
	int pos=-1,farthest=current,i;
	for(i=0;i<frames;i++)
	{
		int j;
		for(j=current;j<n;j++)
		{
			if(temp[i]==pages[j])
			{
				if(j>farthest)
				{
			    	farthest=j;
			    	pos=i;
			    }
			    	break;
			}
		}
		if(j==n)//If a page is not going to be used again
	  return i;
	}
	return(pos==-1)?0:pos;
	//If all pages will be used,replace the farthest one
}
int main()
{
	int i,j,n,frames,pages[30],temp[20],f1,f2,faults=0;
	printf("Enter number of pages:");
	scanf("%d",&n);
	printf("Enter the page reference String:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&pages[i]);
	}
	printf("Enter number of frames:");
	scanf("%d",&frames);
	//Initialize frame to -1(indicating empty)
	for(i=0;i<frames;i++)
	{
		temp[i]=-1;
	}
	printf("\nPage Reference String | Frames\n");
	for(i=0;i<n;i++)
	{
		f1=f2=0;
		//Check if the page is already in one of the frames
    	for(j=0;j<frames;j++)
    	{
		if(temp[j]==pages[i])
		{
			f1=f2=1;
			break;
		}
	}
	//If the page is not in the frame,find where to place it
	if(f1==0)
	{
		//Find an empty frame to place the page
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
	//If no empty frame,use the optimal page replacement stratogy
	if(f2==0)
	{
		int pos=findoptimal(pages,temp,n,i+1,frames);
		temp[pos]=pages[i];
		faults++;
	}
	//Display the current status of frames
	printf("\n%2d\t\t",pages[i]);
	for(j=0;j<frames;j++)
	{
		if(temp[j]!=-1)
		   printf("\n%2d",temp[j]);
		else
		   printf("-");
	}
}
	printf("\nTotal Page Faults:%d\n",faults);
return 0;
}

