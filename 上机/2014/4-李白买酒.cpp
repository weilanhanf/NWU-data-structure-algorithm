#include<stdio.h>

//https://github.com/weilanhanf/NWU_data_structure_algorithm
//https://www.cnblogs.com/welan/category/1328658.html


int main()
{
	int N;
	scanf("%d", &N);
	
	double res=0;
	for(int i=0;i<N;i++)
		res = (res+1)/2;
	printf("ԭ����%6.3f����\n",res); 
	
	int i=0; 
	while(res!=0)
	{
		i++;
		printf("��%d�����һ����ʣ��%6.3f\n", i, res*2);
		printf("��%d������һ����ʣ��%6.3f\n", i, res*2-1);
		res = res*2-1; 
	}
	
	
	return 0;
 } 
