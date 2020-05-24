#include<stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	
	double res=0;
	for(int i=0;i<N;i++)
		res = (res+1)/2;
	printf("原来有%6.3f斗酒\n",res); 
	
	int i=0; 
	while(res!=0)
	{
		i++;
		printf("第%d遇店加一斗，剩下%6.3f\n", i, res*2);
		printf("第%d遇花喝一斗，剩下%6.3f\n", i, res*2-1);
		res = res*2-1; 
	}
	
	
	return 0;
 } 
