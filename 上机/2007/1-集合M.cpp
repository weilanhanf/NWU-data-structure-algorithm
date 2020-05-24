#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

//https://github.com/weilanhanf/NWU_data_structure_algorithm
//https://www.cnblogs.com/welan/category/1328658.html


const int maxn = 10000;
int M[100]={0}, p[maxn]={1};
int num=0;


int main()
{
	int i;
	fill(p, p+maxn, 1); 
	p[1] = 0;
	for(i=1;i<=1000;i++)
	{
		if(p[i]==0&&num<100)
		{
			M[num++] = i;
			p[2*i+1] = 0;
			p[3*i+1] = 0;
		}
	
	}

	
	for(i=0;i<100;i++)
		printf("集合M中的第%d个位%d\n", i+1, M[i]);
	
	
	return 0;
 } 
