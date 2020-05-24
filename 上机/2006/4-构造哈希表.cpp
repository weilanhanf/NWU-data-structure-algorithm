#include<stdio.h>
#include<string.h>


const int maxn=10;
const int n=13;//��ϣ���� 


typedef struct record{
	int sign;
	char a[maxn];
	record()
	{
		sign=0;
	}
}record;


int calHashRes(char a[])
//��ϣ����ΪH(x)=i/2,���� i Ϊ�ؼ����еĵ�һ����ĸ����ĸ���е����
{
	int res;
	res = (a[0]-'A'+1)/2;
	return res;
}


double calSuccTimes(char s[maxn][maxn], record hashTable[])
//ƽ�����ҳɹ����� 
{
	double res;
	
	int sums, count, k;
	sums=0;
	for(int i=0;i<9;i++)
	{
		k = calHashRes(s[i]);
		count = 1;
		while(strcmp(hashTable[k].a, s[i])!=0)
		{
			k = (k+1)%13;
			count++;
		}
		sums += count;
	}
	
	res = sums/9;//���ҳɹ�ʱ����Ԫ�ظ��� 
	
	return res;
}


double calUnSuccTimes(record hashTable[])
//ƽ�������ҳɹ����� 
{
	double res;
	
	int sums, count, k;
	sums = 0;
	for(int i=0;i<n;i++)
	{
		k = i;		
		count = 1;
		while(hashTable[k].sign!=0)
		{
			k = (k+1)%n;
			count++;
		}
		sums += count;
	}
	res = sums/n;//���ҳɹ�ʱ���Ա�
	 
	return res;
}




int main()
{
	record hashTable[n];
	int k;
	char s[maxn][maxn] = {
	"Jan","Feb","Apr","May","Jun","Jul","Aug","Sep","Oct"
	};
	
	//����hash�� 
	for(int i=0;i<9;i++)
	{
		k = calHashRes(s[i]);
		while(hashTable[k].sign!=0)
			k = (k+1)%n;//����̽����ɢ����Ϊ��ͻ���� 
		if(hashTable[k].sign==0)
		{
			strcpy(hashTable[k].a, s[i]);
			hashTable[k].sign=1;	
		}	
	}	
	
	//��ӡ��ϣ�� 
	for(int i=0;i<13;i++)
	{
		if(hashTable[i].sign!=0)
			printf("%d-%s\n", i, hashTable[i].a);
	}
	
	double succTimes=calSuccTimes(s, hashTable);
	double unsuccTimes=calUnSuccTimes(hashTable);
	
	printf("�Ƚϳɹ�����Ϊ��%.2f\n", succTimes);
	printf("�Ƚ�ʧ�ܴ���Ϊ��%.2f\n", unsuccTimes);
	
	return 0;
}

