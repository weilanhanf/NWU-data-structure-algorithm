#include<stdio.h>

//https://github.com/weilanhanf/NWU_data_structure_algorithm
//https://www.cnblogs.com/welan/category/1328658.html



int main()
{
	double x, y, z;
	x = 1.0/20;
	y = 1.0/30;
	z = x*4.0/5 + y*9.0/10;
	int n;
	scanf("%d", &n);
	
	for(int i=1;i<=n;i++)
	{
		if(z*i + (n-i)*x>=1.0)
		//甲乙合作完了，剩下的由甲完成，因为甲的效率高，保证时间最短 
		{
			printf("甲乙合作%d天\n", i);
			printf("合作干了%.2f，甲干剩下的%.2f,一共为%.2f\n", z*i, (n-i)*x, z*i + (n-i)*x);
			break;
		}
	}
	
	return 0;
}
