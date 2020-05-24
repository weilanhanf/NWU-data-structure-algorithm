#include<stdio.h>
#include<string.h>


int a[4];


int main()
{
	for(int i=100;i<=999;i++)
	{
		int count, x, t;
		x = i;
		count = 0;//记录i的包含6的个数 
		while(x!=0)
		{
			t = x%10;
			x /= 10;
			if(t==6)
				count++;
		}
		if(count!=0)
			a[count]++;			
	}
	printf("含一个6数字个数:%d 两个:%d 三个:%d\n", a[1], a[2], a[3]);
	
	return 0;
 } 
