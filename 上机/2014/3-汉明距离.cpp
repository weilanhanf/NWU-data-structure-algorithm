#include<stdio.h>
#include<string.h>

const int maxn = 20;


int main()
{
	
	char str1[maxn], str2[maxn];
	int len, num;
	scanf("%s", str1);
	scanf("%s", str2);
	len = strlen(str1);
	num = 0;
	for(int i=0;i<len;i++)
	{
		if(str1[i]!=str2[i])
			num++;
	}
	
	printf("%s��%s�ĺ�������Ϊ%d\n", str1, str2, num); 
	
	return 0;
}
