#include<stdio.h>
#include<string.h> 
#include<algorithm>
using namespace std;

//���ַ�ƽ̨�е�����ַ�ƽ̨��
//һ���ַ����е�����һ�������У����������и��ַ�����ͬ����ַ�ƽ̨��
//���������ַ��� S ʱ����� S �г������������ַ�ƽ̨����ʼλ���Լ���
//���ַ���ע���ַ�ƽ̨�п��ܲ�ֹһ�� AAZZZXYTTT

const int maxn=50;


typedef struct platform{
	int pos;
	int len;
	char ch;//����¼�ַ��� 
	platform(){
		len = 0;
		pos = -1;
	}
}plat;


plat p[maxn];
int num=0;


int main()
{
	char str[maxn];
	int i, j;
	gets(str);
	for(i=0;i<strlen(str);i=j)
	{
		p[num].ch = str[i];//�����ַ�������ƽ̨����p ����ʹ����Ϊ1ҲҪ���� 
		p[num].pos = i;
		p[num].len = 1;
		j = i+1;
		while(str[j]==str[i])//��ͬ�����������ƥ�� 
		{
			p[num].len++;
			j++;
		}
		num++;
	}
	
//	for(i=0;i<num;i++)
//		printf("ch=%c, len=%d, pos=%d\n", p[i].ch, p[i].len, p[i].pos);
	
	int k=0;//��k��Ѱ���������ַ�������
	for(i=0;i<num;i++)
		if(p[i].len>k)
			k = p[i].len;
			
	for(i=0;i<num;i++)//��Ϊ�ж��������ͬ���ַ�ƽ̨ 
		if(p[i].len==k)
			printf("�ַ�ƽ̨�ַ�Ϊ%c,����Ϊ%d,��ԭ������ʼλ��Ϊ%d\n", p[i].ch, p[i].len, p[i].pos+1);	
	
	
	return 0;
 } 
