#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>

using namespace std;


const int maxn=100;

typedef struct bign
//����һ������ 
{
	int d[maxn];
	int len;
	bign(){
		len = 0;
		fill(d, d+maxn, 0);
	}
}bign;



bign generate(char str[])
//����һ��������str=123,����Ϊ321 
{
	bign res;
	int len;
	len = strlen(str);
	reverse(str, str+len);
	
	res.len = len;
	for(int i=0;i<len;i++)
		res.d[i] = str[i]-'0';
	return res;	
}


bool compare(bign a, bign b)
//a>b����1��a<b����-1��a=b����0 
{
	if(a.len>b.len)
		return 1;
	else if(a.len<b.len)
		return -1;
	else if(a.len==b.len)
	{
		for(int i=a.len-1;i>=0;i--)
			if(a.d[i]>b.d[i])
				return 1;
			else if(a.d[i]<b.d[i])
				return -1;
	}
	return 0;
}


bign add(bign a, bign b)
//������� 
{
	bign c;
	int carry, temp;
	carry = 0;//Ϊ��λֵ 
	temp = 0;
	
	if(compare(a, b)==-1)
	 //��֤A>B 
		swap(a, b);
	
	for(int i=0;i<a.len||i<b.len;i++)//���λ��� 
	{
		temp = a.d[i]+b.d[i]+carry;
		carry = (a.d[i]+b.d[i])/10;
		c.d[c.len++] = temp%10;
	}
	if(carry>0)//���һλ��λ 
		c.d[c.len++] = carry;
	return c;
}


void printfBign(bign c)
{
	if(c.len==0)//���cΪ0 
		printf("0");
	else
	{
		for(int i=c.len-1;i>=0;i--)
			printf("%d", c.d[i]);
	}
	printf("\n");
 } 


int main()
{
	char A[maxn], B[maxn];
	bign a, b, c;
	
	gets(A);
	gets(B);
	
	a = generate(A);
	b = generate(B);
	
	c = add(a, b);
	printfBign(c);
	
	return 0;
}
