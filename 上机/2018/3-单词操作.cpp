#include<stdio.h>
#include<string.h>


bool isalpha(char ch)
{
	if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
		return true;
	return false;
}

bool islower(char ch)
{
	if(ch>='a'&&ch<='z')
		return true;
	return false;	
}


void upper(char &ch)
{
	if(ch>='a'&&ch<='z')
		ch -= 32;
}


int main()
{
	char str[100];
	gets(str);
	
	int len = strlen(str);
	int m,n;
	m=0; n=len-1;
	
	while(str[m]==' '||str[n]==' ')//ȥ����β����ո� 
	{
		if(str[m]==' ')
			m--;		
		if(str[n]==' ')
			n--;
	}		

	int count=0;
	for(int i=m;i<=n;i++)
	{
		if(i==m&&isalpha(str[i]))//����ĸ��д 
		{
			if(islower(str[i]))
				upper(str[i]);
			count++;
		}
		else
		{
			if(str[i]=='\'')
				count++;
			
			if(str[i-1]==' '&&isalpha(str[i]))//ǰһ������Ϊ�ո���һ������Ϊ��ĸ������+1 
			{
				if(islower(str[i]))
					upper(str[i]);
				count++; 
			}
		}
		
	}
	printf("%s����%d������\n", str, count);	
	
	return 0;
 } 
