#include<string.h>
#include<stdio.h>

//https://github.com/weilanhanf/NWU_data_structure_algorithm
//https://www.cnblogs.com/welan/category/1328658.html


// ����n��ӡ����n��ͼ�Σ�
//   A
//  B*B
//  C***C
// D*****D
//E*******E
// D*****D
//  C***C
//   B*B
//    A


int main()
{
	int i, j;
	int n;
	scanf("%d", &n);
	for(i=1;i<=n;i++)//������ 
	{
		for(j=n-i;j>=1;j--)
			printf(" ");
		
		for(j=1;j<=2*i-1;j++) 
		{
			if(j==1||j==2*i-1)//ֻ���ڴ���һ���жϣ�����Ƿ�Ϊ��ĸ�����ַ�
				printf("%c", i-1+'A');
			else
				printf("*");				
		}
		printf("\n");
	}
	
	int t, k;//kΪ�ܹ���Ҫ��ӡ���� 
	t = n+1;
	if(n%2==1)
		k = n*2-1;
	else
		k = n*2;
	
	
	for(i=t;i<=k;i++)//������ 
	{
		for(j=1;j<=i-n;j++)
			printf(" ");
		
		for(j=1;j<=(k-i+1)*2-1;j++)
		{
			if(j==1||j==(k-i+1)*2-1)//ֻ���ڴ���һ���жϣ�����Ƿ�Ϊ��ĸ�����ַ�
				printf("%c", k-i+'A');
			else
				printf("*");	
		}		
		printf("\n");	
	}	
	
	
	return 0;
 } 
 
 
 
 
 
 
 
 
 
 
