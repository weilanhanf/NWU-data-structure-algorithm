#include<stdio.h>
#include<string.h>


const int maxn=1001;
int p[maxn]={0}, prime[maxn]={0};
int num=0;


void primeTable()
//��1000���ڵ�����������������prime[0-num]�� 
{
	for(int i=2;i<maxn;i++)
	{
		if(p[i]==0)//p[i]==0��ʾiΪ���� 
		{
			prime[num++] = i;//������i��������prime 
			for(int j=i*2;j<maxn;j+=i)
			//���iΪ��������ôi����������2*i,3*i...���������� 
			{
				p[j] = 1;// //p[i]==1��ʾi�������� 
			 } 
		}
		
	}
}


bool isPrime(int x)
//�ж�һ�����Ƿ�Ϊ���� 
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
	
	if(isPrime(x)==false)//���x����Ͳ���������ֱ�ӷ��� 
	{
		printf("no\n");
		return 0;
	}
		
	
	int k;
	bool flag=false;
	for(int i=0;i<num-1;i++)//�ҵ�����prime[i],ʹ��prime[i]>=x��Ȼ��x��ߵ������ſ����������� 
		if(prime[i]<x&&prime[i+1]>=x)
		{
			k = i;
			break;
		}
	
	int a[100]={0};//����a��������x������ 
	int m, sums, t;
	for(int i=k;i>=0;i--)//��ÿһ��prime[i]������ƶ������Ƿ��������������������Ϊx 
	{
		sums=x;
		t=i;
		m=0;
		while(t>=0&&sums>prime[t])//��sums������ǰt��ָ������prime[t] 
		{
			a[m] = prime[t];
			sums -= prime[t];
			t--; m++;
		}
		if(t>=0&&prime[t]==sums)//���ǡ���ҵ��򷵻� 
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
