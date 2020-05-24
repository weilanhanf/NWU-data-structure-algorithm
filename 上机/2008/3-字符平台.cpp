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
		if(i==0)//第一个字符必当占一个字符平台 
		{
			p[num].ch = str[i];
			p[num].pos = i;
			p[num].n++;
		}
		else//要判断连续的字符是否相同， 
		{
			if(str[i]==str[i-1])//如果相同字符平台长度加1
			{
				p[num].n++;	
			}	
			else//不相同新增一个字符平台
			{
				num++;
				p[num].ch = str[i];
				p[num].pos = i;
				p[num].n++;	
			}
		}
	}
	
	int k=0;
	for(int i=0;i<=num;i++)//找出最大的字符平台的长度 
		if(p[i].n>k)
			k=p[i].n;
	
	
	for(int i=0;i<=num;i++)
		if(p[i].n==k)
			printf("%c %d %d\n", p[i].ch, p[i].pos, p[i].n);
	
	return 0;
}
