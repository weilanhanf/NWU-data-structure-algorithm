#include<stdio.h>


int main()
{
	double x, y, z;
	x = 1.0/20;
	y = 1.0/30;
	z = x*4.0/5 + y*9.0/10;
	int n;
	scanf("%d", &n);
	
	for(int i=1;i<=n;i++)
	{
		if(z*i + (n-i)*x>=1.0)
		//���Һ������ˣ�ʣ�µ��ɼ���ɣ���Ϊ�׵�Ч�ʸߣ���֤ʱ����� 
		{
			printf("���Һ���%d��\n", i);
			printf("��������%.2f���׸�ʣ�µ�%.2f,һ��Ϊ%.2f\n", z*i, (n-i)*x, z*i + (n-i)*x);
			break;
		}
	}
	
	return 0;
}
