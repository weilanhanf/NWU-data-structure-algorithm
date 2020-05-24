#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

//1. 输入一个字符串，内有数字和非数字字符。如 A123X456Y7A，302ATB567BC，
//打印字符串中所有连续（指不含非数字字符）的数字所组成的整数，并统计共有
//多少个整数。


const int maxn = 100;


bool isNumber(char ch)
{
	if(ch<='9'&&ch>='0')
		return true;
	else 
		return false;
}

char a[maxn][maxn];//用二维数组统计 
int row=0, col=0;


int main()
{
	char str[maxn];
	int i, j, len;
	gets(str);
	
	len = strlen(str);
	memset(a, 0, maxn*maxn);
	
	for(i=0;i<len;i++)//逐个判断 
	{
		while(i<len&&isNumber(str[i])==true)//如果是数字则放在二维数组中 
			a[row][col++] = str[i++];
		row++;
		col = 0; 
	}
	
	for(i=0;i<row;i++)
		if(strlen(a[i])>0)//打印数字 
		{
			for(j=0;j<strlen(a[i]);j++)
				printf("%c", a[i][j]);	
			printf("\n");
		}
		
	return 0;
}
