#include<stdio.h>
#include<string.h> 
#include<algorithm>
#include<math.h> 
using namespace std;

//���뼸��ְ�����ʽ�ͳ������������ٸ� 100 Ԫ��50 Ԫ��20 Ԫ��10 Ԫ��
//5 Ԫ��2 Ԫ��1 Ԫ��5 �ǣ�2 �ǣ�1 �ǣ�5 �֣�2 �֣�1 �ֲ���ʵ��˳�����ţ�
//����ְ���� n=5�����ʷֱ�Ϊ��786.98��1038.76��1053.72��1234.98��1653.33

//Ҫ�洢0.1ʵ���ϴ洢����0.99999...��ɼ������ ��������ı�123.44�Ŵ��12344�ټ��� 


const int a[13] = {
	10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1,
};//�ȷŴ󷽱���� 

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
			i = x / a[num];//���� 
			x -= i * a[num];//���� 
			p[num] += i;
			num++;
		}
//		printf("i=%f, x=%f, int(i)=%d, num=%d, p[%d]=%d\n", i, x, int(i), num, num, p[num]);
	}
	
	
	for(int j=0;j<13;j++)
	{
		if(p[j]!=0) 
			printf("��Ҫ%6.2f��%d��\n", b[j], p[j]);
	}
	
	return 0;
}



