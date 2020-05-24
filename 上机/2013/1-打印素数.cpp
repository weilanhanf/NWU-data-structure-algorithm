#include<stdio.h>

//https://github.com/weilanhanf/NWU_data_structure_algorithm
//https://www.cnblogs.com/welan/category/1328658.html


bool isprime(int x)
{
	for(int i=2;i<=x/2;i++)
		if(x%i==0)
			return false;
	return true;
}



int main()
{
	int N;
	scanf("%d", &N);
	for(int i=2;i<=N;i++)
	{
		if(isprime(i)==true)
			printf("%d ", i); 
	}
	
	
	return 0;	
 } 
