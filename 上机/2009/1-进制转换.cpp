#include<stdio.h>
#include<algorithm>

using namespace std;

//https://github.com/weilanhanf/NWU_data_structure_algorithm
//https://www.cnblogs.com/welan/category/1328658.html


int main()
{
	
	int N, B;
	scanf("%d %d", &N, &B);
	
	char a[10];//可能需要存储字符 
	int num=0;
	
	int t;
	while(N!=0)
	{
		t = N%B;
		if(t>=10)
			a[num++] = t-10+'A';
		else if(t<10)
			a[num++] = t+'0';
		
		N /= B;
	} 
	
	reverse(a, a+num);
	if(num>0)
		printf("%s", a);
	else
		printf("0");
	
	return 0;
}
 
