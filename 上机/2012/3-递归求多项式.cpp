#include<stdio.h>


double p(int n, double x)
{
	if(n==0)
		return 1;
	else if(n==1)
		return x;
	else 
		return ((2*n-1)*x-p(n-1, x)-(n-1)*p(n-2, x));
	
}


int main()
{
	int n;
	double x;
	scanf("%d %lf", &n, &x);
	printf("����Ϊ%5.2f�ĵ�%d�׶���ʽֵΪ%5.2f\n", x, n, p(n, x));
	
	return 0;
}
