#include<stdio.h>
#include<stdlib.h>
int main()
{
	int N,t,k=0;
	scanf("%d %d",&t,&N);
	int players[N];
	int n=N;
	while(N--)
	{
		int tmp;
		scanf("%d",&tmp);
		players[k++]=tmp;
	}

	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum += players[i];
	}

	int av=sum/t;
	// printf("%d\n",sum );
	int currSum=0,nextSum=0;
	// int i;
	int res[t];
	int K=0;
	int T=t;
	for(int i=0;i<n;i++)
	{
		currSum+=players[i];
		if(i<n-1)
		{
			nextSum = currSum+players[i+1];
		}

		// insert into result array, decrement partitions
		if(abs(av-currSum)<abs(av-nextSum))
		{
			// printf("%d ",currSum);
			res[K++]=currSum;
			T--;
			currSum=0;
		}

		//when only one partition is left, fill all the remaining elements
		if(T==1)
		{
			int remSum=0;
			for(int j=i+1;j<n;j++)
			{
				remSum+=players[j];
			}
			res[K++]=remSum;
		}

	}

	// for(int i=0;i<t;i++)
	// {
	// 	printf("%d ",res[i]);
	// }

	int max=0;
	for(int i=0;i<t;i++)
	{
		if(res[i]>max)
			max=res[i];
	}

	printf("\n%d", max);
	
	return 0;
}