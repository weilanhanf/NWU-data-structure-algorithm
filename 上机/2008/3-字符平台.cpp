#include<stdio.h>
#include<string.h>

//https://github.com/weilanhanf/NWU_data_structure_algorithm
//https://www.cnblogs.com/welan/category/1328658.html


using namespace std;


typedef struct plat{
	char ch;
	int pos;
	int n;
	plat()
	{
		pos=0;
		n=0;
	}
}plat;


plat p[100];
int num=0;


int main()
{
	char str[100];
	int len;
	gets(str);
	len = strlen(str);
	
	for(int i=0;i<len;i++)
	{
		if(i==0)//��һ���ַ��ص�ռһ���ַ�ƽ̨ 
		{
			p[num].ch = str[i];
			p[num].pos = i;
			p[num].n++;
		}
		else//Ҫ�ж��������ַ��Ƿ���ͬ�� 
		{
			if(str[i]==str[i-1])//�����ͬ�ַ�ƽ̨���ȼ�1
			{
				p[num].n++;	
			}	
			else//����ͬ����һ���ַ�ƽ̨
			{
				num++;
				p[num].ch = str[i];
				p[num].pos = i;
				p[num].n++;	
			}
		}
	}
	
	int k=0;
	for(int i=0;i<=num;i++)//�ҳ������ַ�ƽ̨�ĳ��� 
		if(p[i].n>k)
			k=p[i].n;
	
	
	for(int i=0;i<=num;i++)
		if(p[i].n==k)
			printf("%c %d %d\n", p[i].ch, p[i].pos, p[i].n);
	
	return 0;
}
