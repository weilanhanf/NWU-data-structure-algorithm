#include<stdio.h>

//https://github.com/weilanhanf/NWU_data_structure_algorithm
//https://www.cnblogs.com/welan/category/1328658.html


int main()
{
	int a[100];
	int num=0;
	
	int x,y;
	for(int i=10;i<=99;i++)
	{
		x = i/10;
		y = i%10;
		if(x*y>x+y)
			a[num++]=i;
	}
	
	int sums=0;
	for(int i=0;i<num;i++)
	{
		sums+=a[i];
	}
	
	printf("%d\n", sums);
	
	return 0;
} 
