#include<stdio.h>

const int maxn=1000;


int main()
{
	int n;
	int coin[6]={1, 5, 10, 20, 50, 100};//ֽ����ֵ 
	int dp[6][maxn]={0};//�������� 
	
	scanf("%d", &n);//���������Ϊ1000��
	
	//�߽�ֵ��ʼ�� 
	for(int i=0;i<6;i++)//��������Ϊ0��ʱ�����з���Ϊ0�� 
		dp[i][0] = 0;
	for(int j=0;j<=n;j++)//��ֻ���ü�ֵΪ1��ֽ��ʱ������Ϊ1�� 
		dp[0][j] = 1; 
	
	//״̬���� 
	for(int i=0;i<6;i++)
		for(int j=1;j<=n;j++)
		{
			if(coin[i]>j)
				dp[i][j] = dp[i-1][j];
			else if(coin[i]<j)
				dp[i][j] = dp[i-1][j] + dp[i][j-coin[i]];
			else if(coin[i]==j)
				dp[i][j] = dp[i-1][j] + 1;	
		} 
	
	//��ӡ�������� 
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<=n;j++)
			printf("%3d ", dp[i][j]);
		printf("\n");	
	}
	
	printf("���Ϊ%dʱ����Ϸ���Ϊ%d��\n", n, dp[5][n]);
	
	return 0;
}
