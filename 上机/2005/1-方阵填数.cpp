#include<stdio.h>


const int maxn=101;
int a[maxn][maxn]={0};
int num=1;

//13 14 15 16 1
//12 23 24 17 2
//11 22 25 18 3
//10 21 20 19 4
// 9  8  7  6 5


int main()
{
	int n;
	scanf("%d", &n);
	
	int i=1, j=n;
	int k=1;
	a[i][j] = k;
	
	while(k<n*n)
	{
		while((i+1<=n)&&(a[i+1][j]==0))
			a[++i][j] = ++k;
		while((j-1>=1)&&(a[i][j-1]==0))
			a[i][--j] = ++k;
		while((i-1>=1)&&(a[i-1][j]==0))
			a[--i][j] = ++k;
		while((j+1<=n)&&(a[i][j+1]==0))
			a[i][++j] = ++k;
	}
	
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%3d", a[i][j]);
		printf("\n");
	}
		
	
	
 } 
