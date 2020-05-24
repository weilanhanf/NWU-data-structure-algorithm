#include<stdio.h>
#include<string.h>


const int maxn=1001;
int p[maxn]={0}, prime[maxn]={0};
int num=0;


void primeTable()
//求1000以内的所有素数，并放在prime[0-num]中 
{
	for(int i=2;i<maxn;i++)
	{
		if(p[i]==0)//p[i]==0表示i为素数 
		{
			prime[num++] = i;//把素数i放入数组prime 
			for(int j=i*2;j<maxn;j+=i)
			//如果i为素数，那么i的整数倍，2*i,3*i...都不是素数 
			{
				p[j] = 1;// //p[i]==1表示i不是素数 
			 } 
		}
		
	}
}


bool isPrime(int x)
//判断一个数是否为素数 
{
	for(int i=0;i<num;i++)
		if(prime[i]==x)
			return true;
	return false;
 } 


int main()
{
	int x;
	scanf("%d", &x);
	primeTable();
	
	if(isPrime(x)==false)//如果x本身就不是素数，直接返回 
	{
		printf("no\n");
		return 0;
	}
		
	
	int k;
	bool flag=false;
	for(int i=0;i<num-1;i++)//找到素数prime[i],使得prime[i]>=x，然后x左边的素数才可能满足条件 
		if(prime[i]<x&&prime[i+1]>=x)
		{
			k = i;
			break;
		}
	
	int a[100]={0};//数组a来存放组成x的素数 
	int m, sums, t;
	for(int i=k;i>=0;i--)//从每一个prime[i]往左个移动，看是否满足连续的素数满足和为x 
	{
		sums=x;
		t=i;
		m=0;
		while(t>=0&&sums>prime[t])//用sums减掉当前t所指的素数prime[t] 
		{
			a[m] = prime[t];
			sums -= prime[t];
			t--; m++;
		}
		if(t>=0&&prime[t]==sums)//如果恰好找到则返回 
		{
			a[m] = prime[t];
			flag = true;
			m++;
			break;
		}
		else if(t>=0&&prime[t]>sums)
			flag=false;
	}
	
	
	if(flag==false)
			printf("no\n");
	else if(flag==true)
	{
		printf("yes: ");
		sums = 0;
		for(int i=0;i<m;i++)
		{
			printf("%d", a[i]);
			sums += a[i];
			if(i!=m-1)
				printf("+");
			else
				printf("=%d\n", sums);
		}
	}
	
	return 0;
}
