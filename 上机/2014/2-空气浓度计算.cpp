#include<stdio.h>


//result = ((Imax-Imin)/(Cmax-Cmin))*(C-Cmin)+Imin


double calcu(double Cmax, double Cmin, double Imax, double Imin, double C)
{
	double res;
	res = ((Imax-Imin)/(Cmax-Cmin))*(C-Cmin)+Imin;
	return res;
}


int main()
{
	double res, C;
	scanf("%lf", &C);
	
	if(C>=0&&C<=12.0)
		res = calcu(0, 12.0, 0, 50, C);
	else if(C>=12.1&&C<=35.4)
		res = calcu(12.1, 35.4, 51, 100, C);
	else if(C>=35.5&&C<=55.4)
		res = calcu(35.5, 55.4, 101, 150, C);
	else if(C>=55.5&&C<=150.4)
		res = calcu(55.5, 150.4, 151, 200, C);
	else if(C>=150.5&&C<=250.4)
		res = calcu(150.5, 250.4, 201, 300, C);
	else if(C>=250.5&&C<=350.4)
		res = calcu(250.5, 350.4, 301, 400, C);		
	else if(C>=350.5&&C<=500.4)
		res = calcu(350.5, 500.4, 401, 500, C);		
	
	printf("浓度C为%5.2f时，指数I为%5.2f\n", C, res); 
				
	return 0;
}
