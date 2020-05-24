#include<stdio.h>

//https://github.com/weilanhanf/NWU_data_structure_algorithm
//https://www.cnblogs.com/welan/category/1328658.html


int a[101]={0};

int main()
{
	int x;
	while(scanf("%d",&x)!=EOF&&x!=0)
	{
		a[x]++;
	}
	
	int k=-1, maxn=-1;
	for(int i=1;i<=100;i++)
	{
		if(a[i]>maxn)
		{
			maxn = a[i];
			k = i;
		}
	}
	
	for(int i=1;i<=100;i++)
		if(a[i]!=0)
			printf("%d - %d个\n", i, a[i]);
		
	printf("出现最多%d-%d个\n", k, maxn);	
	
	
	return 0;
}
