#include<stdio.h>
#include<string.h>

bool isnum(char ch)
{
	if(ch>='0'&&ch<='9')
		return true;
	return false;
}


bool isalpha(char ch)
{
	if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
		return true;
	return false;
}


char str[50];

int main()
{
	while(gets(str)!=NULL)
	{
		int len=strlen(str);
		bool flag=true;
		for(int i=0;i<len;i++)
		{
			if(i==0&&(isalpha(str[i])==false)&&str[i]!='_')
			{
				flag = false;
				break;
			}
			else if((isalpha(str[i])==false)&&str[i]!='_'&&isnum(str[i])==false)
			{
				flag = false;
				break;
			}
		}
		if(flag==true)
			printf("yes\n");
		else if(flag==false)
			printf("no\n");
					
	}	
	
	return 0;
}
