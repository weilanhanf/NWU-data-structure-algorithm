#include<stdio.h>

const int maxn=1000;


int main()
{
	int n;
	int coin[6]={1, 5, 10, 20, 50, 100};//纸币面值 
	int dp[6][maxn]={0};//方案数组 
	
	scanf("%d", &n);//输入金额最大为1000；
	
	//边界值初始化 
	for(int i=0;i<6;i++)//当输入金额为0的时候，排列方案为0种 
		dp[i][0] = 0;
	for(int j=0;j<=n;j++)//当只能用价值为1的纸币时，方案为1种 
		dp[0][j] = 1; 
	
	//状态方程 
	for(int i=0;i<6;i++)
		for(int j=1;j<=n;j++)
		{
			if(coin[i]>j)
				dp[i][j] = dp[i-1][j];
			else if(coin[i]<j)
				dp[i][j] = dp[i-1][j] + dp[i][j-coin[i]];
			else if(coin[i]==j)
				dp[i][j] = dp[i-1][j] + 1;	
		} 
	
	//打印方案数组 
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<=n;j++)
			printf("%3d ", dp[i][j]);
		printf("\n");	
	}
	
	printf("金额为%d时，组合方案为%d种\n", n, dp[5][n]);
	
	return 0;
}
