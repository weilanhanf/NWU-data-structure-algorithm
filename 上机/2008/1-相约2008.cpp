#include<stdio.h>
#include<algorithm>

//https://github.com/weilanhanf/NWU_data_structure_algorithm
//https://www.cnblogs.com/welan/category/1328658.html



using namespace std;

const int maxn=2009;

int num=0;
int p[maxn], prime[maxn];//prime数组用来存放素数 




void primeTable()//素数表 
{
	for(int i=2;i<maxn;i++)
	{
		if(p[i]==0)//p[i]=0说明i是素数 
		{
			prime[num++] = i;//i是素数放入prime数组 
			for(int j=2*i;j<maxn;j+=i) 
			{
				p[j] = 1;//i为素数，则i的倍数都不是素数 
			}
		}
	}
}



void dpCreat(int arr[], int n, int S)
{
	int dp[n][S+1]={0};
	
	//边界条件 
	for(int i=0;i<n;i++)
		dp[i][0] = 0;
	for(int j=0;j<S+1;j++)
		dp[0][j] = 0;
	dp[0][arr[0]] = 1;
	
	//状态方程 
	for(int i=1;i<n;i++)
		for(int j=1;j<S+1;j++)
		{
			if(arr[i]>j)
				dp[i][j] = dp[i-1][j];
			else if(arr[i]<=j)//选与不选arr[i]只需要满足其一就可 
			{
				int a=dp[i-1][j];
				int b=dp[i-1][j-arr[i]];
				dp[i][j] = a||b;
			}	
		} 
	

	//查找方案 
	if(dp[n-1][S]==1)
	{
		printf("存在方案:\n");
	
		int i = n-1, k=0;
		int sol[maxn] = {0};
		while(i>=0)
		{
			if((dp[i][S]==1)&&(dp[i-1][S]==0))
			{
				sol[k++] = arr[i];
				S -= arr[i];
			}
			if(S==0)
				break;
		 	i--;
		}
		int sums = 0;
		for(int j=0;j<k;j++)
		{
			sums += sol[j];
			printf("%4d ", sol[j]);
		}
	}
	else
		printf("不存在\n"); 
		
}



int main()
{
	int S=2008;
	primeTable();
	
	int sums=0, n=0;
	for(int i=0;i<num;i++)
	{
		sums += prime[i]; 
		n++;
		if(sums>=S)
			break;
	}
	
	dpCreat(prime, n, S);
	
	return 0;
}


