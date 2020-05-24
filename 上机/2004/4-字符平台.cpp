#include<stdio.h>
#include<string.h> 
#include<algorithm>
using namespace std;

//求字符平台中的最大字符平台：
//一个字符串中的任意一个子序列，若子序列中个字符均相同则称字符平台，
//输入任意字符串 S 时，输出 S 中长度最大的所有字符平台的起始位置以及所
//含字符，注意字符平台有可能不止一个 AAZZZXYTTT

const int maxn=50;


typedef struct platform{
	int pos;
	int len;
	char ch;//仅记录字符， 
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
		p[num].ch = str[i];//将该字符串存入平台数组p ，即使长度为1也要存入 
		p[num].pos = i;
		p[num].len = 1;
		j = i+1;
		while(str[j]==str[i])//相同，则继续进行匹配 
		{
			p[num].len++;
			j++;
		}
		num++;
	}
	
//	for(i=0;i<num;i++)
//		printf("ch=%c, len=%d, pos=%d\n", p[i].ch, p[i].len, p[i].pos);
	
	int k=0;//用k来寻找最大的子字符串长度
	for(i=0;i<num;i++)
		if(p[i].len>k)
			k = p[i].len;
			
	for(i=0;i<num;i++)//因为有多个长度相同的字符平台 
		if(p[i].len==k)
			printf("字符平台字符为%c,长度为%d,在原串的起始位置为%d\n", p[i].ch, p[i].len, p[i].pos+1);	
	
	
	return 0;
 } 
