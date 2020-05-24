#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>

using namespace std;


int a[6] = {100, 50, 20, 10, 5, 1};


int main()
{
	int z;
	scanf("%d", &z);
	
//	for(int i=0;i<=z/100;i++)
//		for(int j=0;j<=1;j++)
//			for(int m=0;m<=2;m++)
//				for(int n=0;n<=1;n++)
//					for(int x=0;x<=1;x++)
//						for(int y=0;y<=4;y++)
//							if(i*100+j*50+m*20+n*10+x*5+y*1==z)
//								printf("%d张100元 %d张50元 %d张20元 %d张10元 %d张5元 %d张1元\n", i, j, m, n, x, y);
//	
	
	for(int i=0;i<=z/100;i++)
		for(int j=0;j<=z/50;j++)
			for(int m=0;m<=z/20;m++)
				for(int n=0;n<=z/10;n++)
					for(int x=0;x<=z/5;x++)
						for(int y=0;y<=z/1;y++)
							if(i*100+j*50+m*20+n*10+x*5+y*1==z)
								printf("%d张100元 %d张50元 %d张20元 %d张10元 %d张5元 %d张1元\n", i, j, m, n, x, y);
	
	
	
	printf("最少张数：\n");
	int k=0;
	while(z!=0)
	{
		printf("%d张%d元 ", z/a[k], a[k]);
		z %= a[k];
		k++;
	} 
	
	
	return 0; 
}
