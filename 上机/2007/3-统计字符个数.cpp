#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn = 200;
int a[maxn] = {0};



int main()
{
	char str[maxn];
	int len, i;
	gets(str);
	len = strlen(str);
	fill(a, a+maxn, 0);
	
	for(i=0;i<len;i++)
		a[int(str[i])]++;

	for(i=0;i<maxn;i++)
		if(a[i]!=0)
			printf("%c %d\n", i, a[i]);
				
	return 0;
 } 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
