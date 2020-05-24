#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

 
 
//甲、乙、丙、丁四人共有糖若干块，甲先拿出一些糖分给另外三人，使他们
//三人的糖数加倍；乙拿出一些糖分给另外三人，也使他们三人的糖数加倍；丙、
//丁也照此办理，此时甲、乙、丙、丁四人各有 16 块，编程求出四个人开始各有
//糖多少块



int main()
{
	int sums, i, j;
	int a[4];
	fill(a, a+4, 16);//最后每个人都有16块糖果 
	
	for(i=3;i>=0;i--)
	{
		sums = 0;
		for(j=0;j<4;j++)
		{
			if(j!=i)//分别找到另外三个人，糖果减半 
			{
				sums += a[j] / 2;
				a[j] /= 2;
			}
		}
		a[i] += sums;
	 } 
	 
	 
	for(i=0;i<4;i++)
		printf("%d ", a[i]); 
	
	return 0;
 } 
