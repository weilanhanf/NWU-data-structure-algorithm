#include<stdio.h>
#include<string.h>


int a[4];


int main()
{
	for(int i=100;i<=999;i++)
	{
		int count, x, t;
		x = i;
		count = 0;//��¼i�İ���6�ĸ��� 
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
	printf("��һ��6���ָ���:%d ����:%d ����:%d\n", a[1], a[2], a[3]);
	
	return 0;
 } 
