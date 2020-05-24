#include<stdio.h>

//https://github.com/weilanhanf/NWU_data_structure_algorithm
//https://www.cnblogs.com/welan/category/1328658.html


bool isPrime(int x)//判断是否为素数 
{
	for(int i=2;i<=x/2;i++)
		if(x%i==0)
			return false;
	return true;
}


bool isAbsolutePrime(int x)
{
	if(isPrime(x)==true)
	{
		int y, num, t;
		int a[10]={0};
		y=0; num=0;
		
		while(x!=0)//将x放置在a数组中 
		{
			a[num++] = x%10;
			x /= 10;
		}
		
		//如果x=123， 则y=321 
		t=1;
		while(num>=0)//求y 
		{
			y += a[--num]*t;
			t *= 10;
		}

		if(isPrime(y)==true)
			return true;
	}
	
	return false;
}

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	for(int i=m;i<=n;i++)
		if(isAbsolutePrime(i))
			printf("%d\n", i);
		
	
	return 0;
}
