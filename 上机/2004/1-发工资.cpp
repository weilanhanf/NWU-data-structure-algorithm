#include<stdio.h>
#include<string.h> 
#include<algorithm>
#include<math.h> 
using namespace std;

//输入几名职工工资金额，统计最少须领多少个 100 元，50 元，20 元，10 元，
//5 元，2 元，1 元，5 角，2 角，1 角，5 分，2 分，1 分才能实现顺利发放？
//假设职工数 n=5，工资分别为：786.98，1038.76，1053.72，1234.98，1653.33

//要存储0.1实际上存储的是0.99999...造成计算出错 ，将输入的比123.44放大成12344再计算 


const int a[13] = {
	10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1,
};//先放大方便计算 

const double b[13] = {
	100, 50, 20, 10, 5, 2, 1, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01,
};

int p[13]={0};


int main()
{
	int n, num, i;
	double x;
	fill(p, p+13, 0);

	scanf("%d", &n);	
	while(n--)
	{
		num = 0;
		scanf("%lf", &x);
		x = int(x*100);
		while(x!=0)
		{
			i = x / a[num];//除数 
			x -= i * a[num];//余数 
			p[num] += i;
			num++;
		}
//		printf("i=%f, x=%f, int(i)=%d, num=%d, p[%d]=%d\n", i, x, int(i), num, num, p[num]);
	}
	
	
	for(int j=0;j<13;j++)
	{
		if(p[j]!=0) 
			printf("需要%6.2f的%d张\n", b[j], p[j]);
	}
	
	return 0;
}



