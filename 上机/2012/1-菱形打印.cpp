#include<stdio.h>

int main()
{
	int N;
	scanf("%d", &N);

	for(int i=1;i<=N/2+1;i++)//���Ǵ��м�һ�� 
	{
		for(int j=1;j<=N/2+1-i;j++)
			printf("  ");
		for(int j=1;j<=2*i-1;j++)
			printf("* ");
		printf("\n");		
	}	
	
	for(int i=N/2+2;i<=N;i++)//�°�������� 
	{
		for(int j=N/2+2;j<=i;j++)
			printf("  ");
		for(int j=1;j<=(N-i+1)*2-1;j++)
			printf("* ");
		printf("\n");
	}
	
	
	return 0;
}
