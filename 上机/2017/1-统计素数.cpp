#include<stdio.h>


bool isprime(int x)
{
	for(int i=2;i<=x/2;i++)
		if(x%i==0)
			return false;
	return true;
}


int main()
{
	int n, count, x;
	count = 0;
	scanf("%d", &n);	
	while(n--)
	{
		scanf("%d", &x);	
		if(isprime(x)==true)
			count++;
	}
	
	printf("\n��������Ϊ%d��\n", count);
	return 0;
 } 
