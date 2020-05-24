#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>

//https://github.com/weilanhanf/NWU_data_structure_algorithm
//https://www.cnblogs.com/welan/category/1328658.html


using namespace std;


int main()
{
	int a[100];
	int n, x, num;
	num=0;
	while(scanf("%d", &x)!=EOF&&x!=0)
	{
			a[num++]=x;
	}
	
	printf("输入位置(从1开始)："); 
	scanf("%d", &n);
	
	
	reverse(a+n-1, a+num);
	for(int i=0;i<num;i++)
		printf("%d ", a[i]);
	
	return 0;
 } 
