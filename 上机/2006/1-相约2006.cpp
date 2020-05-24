#include<stdio.h>
#include<algorithm>

//https://github.com/weilanhanf/NWU_data_structure_algorithm
//https://www.cnblogs.com/welan/category/1328658.html


using namespace std;

const int maxn=2009;

int num=0;
int p[maxn], prime[maxn];//prime��������������� 




void primeTable()//������ 
{
	for(int i=2;i<maxn;i++)
	{
		if(p[i]==0)//p[i]=0˵��i������ 
		{
			prime[num++] = i;//i����������prime���� 
			for(int j=2*i;j<maxn;j+=i) 
			{
				p[j] = 1;//iΪ��������i�ı������������� 
			}
		}
	}
}


void cal(int arr[], int n, int S)
{
	//�����Ƿ�������� 
	int dp[n][S+1]={0};
	
	//�߽�ֵ��ʼ�� 
	for(int i=0;i<n;i++)
		dp[i][0] = 0;
	for(int j=0;j<S+1;j++)
		dp[0][j] = 0;
	dp[0][arr[0]] = 1;
	
	//״̬ת�Ʒ��� 
	for(int i=1;i<n;i++)
		for(int j=1;j<S+1;j++)
		{
			if(arr[i]>j)
				dp[i][j] = 0;
			else
				dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]];
		}

	if(dp[n-1][S]==1)//˵����������
	{
		int i=n-1, k=0;
		int sol[n]={0};	
		while(i>=0)
		{
			if(dp[i][S]==1&&dp[i-1][S]==0)
			//�����ǰi-1�������޷������S����ǰi���������������S����ô˵����i�����϶�Ҫѡ 
			{
				sol[k++] = arr[i];
				S -= arr[i];
			}
			if(S==0)
				break;
			i--;
		}
	
		int sums=0;
		for(int i=0;i<k;i++)
		{
			sums+=sol[i];
			printf("%d", sol[i]);
			if(i<k-1)
				printf("+");
			else
				printf("=%d\n", sums);
		}
	} 
		
}



int main()
{
	int S=2006;
	int sums, n;
	sums=0; n=0;
	primeTable();
	for(int i=0;i<num;i++)
	{
		sums+=prime[i];
		n++;
		if(sums>S)
			break;
	}
	cal(prime, n, S);
	
	
	return 0;
}
