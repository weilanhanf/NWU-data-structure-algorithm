#include<stdio.h>
#include<string.h>

//https://github.com/weilanhanf/NWU_data_structure_algorithm
//https://www.cnblogs.com/welan/category/1328658.html


int main()
{
	char str[100];
	gets(str);
	int a[5]={0};
	for(int i=0;i<strlen(str);i++)
	{
		switch(str[i])
		{
			case 'a':
			case 'A':
				{
					a[0]++; break;
				}
				
			case 'e':
			case 'E':
				{
					a[1]++; break;
				}
				
			case 'i':
			case 'I':
				{
					a[2]++; break;
				}
				
			case 'o':
			case 'O':
				{
					a[3]++; break;
				}
				
			case 'u':
			case 'U':
				{
					a[4]++; break;
				}
		}
	}
	
	printf("%c: %d\n", 'a', a[0]);
	printf("%c: %d\n", 'e', a[1]);
	printf("%c: %d\n", 'i', a[2]);
	printf("%c: %d\n", 'o', a[3]);
	printf("%c: %d\n", 'u', a[4]);
	
	
	return 0;
 } 
