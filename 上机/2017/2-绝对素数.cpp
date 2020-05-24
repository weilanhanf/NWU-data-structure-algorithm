#include<stdio.h>

//https://github.com/weilanhanf/NWU_data_structure_algorithm
//https://www.cnblogs.com/welan/category/1328658.html


bool isPrime(int x)//�ж��Ƿ�Ϊ���� 
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
		
		while(x!=0)//��x������a������ 
		{
			a[num++] = x%10;
			x /= 10;
		}
		
		//���x=123�� ��y=321 
		t=1;
		while(num>=0)//��y 
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
