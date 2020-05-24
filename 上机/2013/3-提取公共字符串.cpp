#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;


const int maxn=100;
int dp[maxn][maxn];


int main()
{
	char str[maxn];
	int num=0;
	char str1[maxn], str2[maxn];
	gets(str1+1);
	gets(str2+1);
	int len1, len2;
	len1 = strlen(str1+1);
	len2 = strlen(str2+1);
	
	//边界值初始化 
	for(int i=0;i<len1;i++)
		dp[i][0] = 0;
	for(int j=0;j<len2;j++)
		dp[0][j] = 0;
		
	//状态方程 
	for(int i=1;i<len1;i++)
		for(int j=1;j<len2;j++)
		{
			if(str1[i]==str2[j])
				dp[i][j] = dp[i-1][j-1]+1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		} 
	
	
	printf("最大公共部分长度为：%d\n", dp[len1-1][len2-1]); 
	
	//打印dp数组 
//	for(int i=0;i<len1;i++)
//	{
//		for(int j=0;j<len2;j++)
//			printf("%3d", dp[i][j]);
//		printf("\n");
//	}
	
	//查找公共部分，并放在str数组中 
	num = dp[len1-1][len2-1];
	for(int i=len1-1;i>=0;i--)
	{
		for(int j=len2-1;j>=0;j--)
			if(str1[i]==str2[j]&&dp[i][j]==num)
			{
				num--;
				str[num] = str1[i];
			}
	}
	
	printf("公共部分为：%s",str);
	
 } 
