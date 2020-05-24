#include<stdio.h> 


int main()
{
	double sal, res, tax;//需要用double类型 
	
	scanf("%lf", &sal);
	if(sal<1600)
		tax = 0;
	else if(sal>=1600&&sal<=2500)
		tax = (sal-1600)*0.05;
	else if(sal>2500&&sal<=3500)
		tax = 900*0.05 + (sal-2500)*0.1;
	else if(sal>2500&&sal<=4500)
		tax = 900*0.05 + 1000*0.1 + (sal-2500)*0.15;
	else if(sal>=4500)
		tax = 900*0.05 + 1000*0.1 + 2000*0.15 + (sal-4500)*0.2;
	
	res = sal-tax;
	printf("税后工资为：%.2f\n", res);
	
	return 0;
}
