#include<stdio.h>
#include<string.h>


const int maxn=10;
const int n=13;//哈希表长度 


typedef struct record{
	int sign;
	char a[maxn];
	record()
	{
		sign=0;
	}
}record;


int calHashRes(char a[])
//哈希函数为H(x)=i/2,其中 i 为关键字中的第一个字母在字母表中的序号
{
	int res;
	res = (a[0]-'A'+1)/2;
	return res;
}


double calSuccTimes(char s[maxn][maxn], record hashTable[])
//平均查找成功长度 
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
	
	res = sums/9;//查找成功时除以元素个数 
	
	return res;
}


double calUnSuccTimes(record hashTable[])
//平均不查找成功长度 
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
	res = sums/n;//查找成功时除以表长
	 
	return res;
}




int main()
{
	record hashTable[n];
	int k;
	char s[maxn][maxn] = {
	"Jan","Feb","Apr","May","Jun","Jul","Aug","Sep","Oct"
	};
	
	//创建hash表 
	for(int i=0;i<9;i++)
	{
		k = calHashRes(s[i]);
		while(hashTable[k].sign!=0)
			k = (k+1)%n;//线性探测再散列作为冲突处理 
		if(hashTable[k].sign==0)
		{
			strcpy(hashTable[k].a, s[i]);
			hashTable[k].sign=1;	
		}	
	}	
	
	//打印哈希表 
	for(int i=0;i<13;i++)
	{
		if(hashTable[i].sign!=0)
			printf("%d-%s\n", i, hashTable[i].a);
	}
	
	double succTimes=calSuccTimes(s, hashTable);
	double unsuccTimes=calUnSuccTimes(hashTable);
	
	printf("比较成功次数为：%.2f\n", succTimes);
	printf("比较失败次数为：%.2f\n", unsuccTimes);
	
	return 0;
}

