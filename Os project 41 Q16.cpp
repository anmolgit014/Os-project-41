/*
Q16. Consider the following set of processes that arrive at time 0, with the length of the CPU burst
given in milliseconds:
Process		Burst time
  P1			24
  P2			03
  P3			03
Consider time quanta as 2ms. Write a C program and calculated average waiting time using Round-
Robin Scheduling Algorithm.
*/

#include<stdio.h>
#include<conio.h>
int main()
{
	int c;
	
	printf("\t\t Program to calculate average wait time \n");
	printf("\t\t -------------------------------------- \n");
	printf("\t\t using Round-Robin Scheduling Algorithm \n");
	printf("\t\t -------------------------------------- \n");
	x:    //Used later for goto in case of wrong choice value..
	printf("\n# Enter 1 to enter custom processes else 0 to view default case:  ");
	scanf("%d",&c);
	if(c==0)
	{
		int n=3;
		int p[n];
		p[0]=24;
		p[1]=3;
		p[2]=3;
		int t=2;
		printf("\nProcess \t Burst-time \n");
		for(int i=0;i<n;i++)
		{
			printf("  P%d \t\t    %d \n",i+1,p[i]);	
		}
		printf("Time slice: %d\n",t);
		printf("Arrival time is 0 for all..\n\n");
		int pp=n;
		int w=0;
		while(1)
		{
			for(int i=0;i<n;i++)
			{
				if(p[i]>0)
				{
					p[i]=p[i]-t;
					w=w+(pp-1)*t;
									printf("-");	

					if(p[i]<=0)
					{
						w=w+p[i]*(pp-1);
						pp=pp-1;			
					}
				}
			}
			if(pp==0)
				break;
			printf(".");
		}
		float wt=(float)w/n;
		printf("\n\nAverage wait time %f",(wt));
	}
	else if(c==1)
	{
		int n;
		printf("Enter number of processes: ");
		scanf("%d",&n);
		int p[n];
		for(int i=0;i<n;i++)
		{
			printf("Enter burst time for P%d: ",i+1);
			scanf("%d",&p[i]);
		}
		int t;
		printf("Enter time quanta: ");
		scanf("%d",&t);
		printf("\nProcess \t Burst-time \n");
		for(int i=0;i<n;i++)
		{
			printf("  P%d \t\t    %d \n",i+1,p[i]);	
		}
		printf("Time slice: %d\n",t);
		printf("Arrival time is 0 for all..\n\n");
		int pp=n;
		int w=0;
		while(1)
		{
			for(int i=0;i<n;i++)
			{
				if(p[i]>0)
				{
					p[i]=p[i]-t;
					w=w+(pp-1)*t;
									
					if(p[i]<=0)
					{
						w=w+p[i]*(pp-1);
						pp=pp-1;			
					}
				}
			}
			if(pp==0)
				break;
		}
		float wt=(float)w/n;
		printf("\n\nAverage wait time %f",(wt));		
	}
	else
		goto x;		//To take choice again..
	return 0;
}
