#include<stdio.h>
#include<string.h>

//https://github.com/weilanhanf/NWU_data_structure_algorithm
//https://www.cnblogs.com/welan/category/1328658.html


int change(char ch)
{
	int x=0;
	if(ch<='9'&&ch>='0')
		x = ch-'0';
	else if(ch>='A'&&ch<='Z')
		x = ch-'A'+10;

	return x;
}

int SixthToTen(char str[], int len)
{
	int sums=0, carry=1;
	for(int i=len-1;i>=0;i--)
	{
		sums += change(str[i])*carry;
		carry *= 16;
	}
	return sums;
}


int main()
{
	char str[10];
	gets(str);
	int len=strlen(str);
	int n = SixthToTen(str, len);
	
	printf("%s转换为十进制为%d\n", str, n);
	
	return 0;
 } 
