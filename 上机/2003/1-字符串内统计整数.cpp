#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

//1. ����һ���ַ������������ֺͷ������ַ����� A123X456Y7A��302ATB567BC��
//��ӡ�ַ���������������ָ�����������ַ�������������ɵ���������ͳ�ƹ���
//���ٸ�������


const int maxn = 100;


bool isNumber(char ch)
{
	if(ch<='9'&&ch>='0')
		return true;
	else 
		return false;
}

char a[maxn][maxn];//�ö�ά����ͳ�� 
int row=0, col=0;


int main()
{
	char str[maxn];
	int i, j, len;
	gets(str);
	
	len = strlen(str);
	memset(a, 0, maxn*maxn);
	
	for(i=0;i<len;i++)//����ж� 
	{
		while(i<len&&isNumber(str[i])==true)//�������������ڶ�ά������ 
			a[row][col++] = str[i++];
		row++;
		col = 0; 
	}
	
	for(i=0;i<row;i++)
		if(strlen(a[i])>0)//��ӡ���� 
		{
			for(j=0;j<strlen(a[i]);j++)
				printf("%c", a[i][j]);	
			printf("\n");
		}
		
	return 0;
}
