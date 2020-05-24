#include<stdio.h>
#include<string.h>
#include<math.h>


typedef struct words{
	char id[10];
	char word[10];
}words;


words w[8] = {
	{ "1000", "face"}, { "1001", "head"},
	{ "1002", "hand"}, { "1003", "nose"},
	{ "1004", "ear"}, { "1005", "kneel"},
	{ "1006", "finger"}, { "1007", "leg"},
};


int strMatch(char str1[], char str2[])//字符串匹配，成功为1，失败为0 
{
	int res=0, len1, len2;
	len1 = strlen(str1);
	len2 = strlen(str2);
	
	int i, j, p;
	p = 0;
	i = p; j = 0;
	while(i<len1&&j<len2)
	{
		if(str1[i]==str2[j])
		{
			i++;
			j++;
		}
		else
		{
			p++;
			i = p;
			j = 0;
		}
	}

	if(j>=len2)
		res = 1;
	
	return res;
} 


int main()
{
	char str[10], id[10];
	int len;
	
	while(gets(str)!=NULL)
	{
		
		len = strlen(str);
		int wlen, flag, minn;
		minn = len;
		for(int i=0;i<8;i++)
		{
			if(strcmp(w[i].word, str)==0)//匹配成功，退出 
			{
				flag = 0;//falg=0表示成功匹配 
				strcpy(id, w[i].id); 
			}
			else
			{
				wlen = strlen(w[i].word);
				if(abs(wlen-len)>=2)//长度相差2，肯定不成功，接着匹配下一个 
				{
					flag = 2; 
				}
				else if(abs(wlen-len)==1)//长度相差1
				{
					int res=0;
					if(wlen>len)//短串是否在长串中，如果在res=1，不在res=0 
						res=strMatch(w[i].word, str);
					else if(len>wlen)
						res=strMatch(str, w[i].word);
						
					if(res==1)//短串在长串中
						flag=1;//如果找到一个只相差一个字母的单词，也还要继续匹配，可能完全相同的单词 
					else //如果长串中没有短串，但是其实匹配，如face与fae 
					{
						flag = 0;
						int k=0, j=0;
						while(k<len&&j<wlen)
						{
							if(str[k]==w[i].word[j])
							{
								j++;
								k++;
							}
							else if(str[k]!=w[i].word[j])
							{
								if(k+1<len&&str[k+1]==w[i].word[j])
									k++;
								else if(j+1<wlen&&str[k]==w[i].word[j+1])								
									j++;
								flag++;
							}	
							if(flag>1)
								break;
						}
					}
					
				} 
				else if(abs(wlen-len)==0)//长度相同，如face与facc 
				{
					flag = 0; 
					int k=0,j=0;
					while(k<len&&j<wlen)
					{
						if(str[k]!=w[i].word[j])
							flag++;
						if(flag>1)
							break;
						k++;
						j++;
						
					}
				}
			} 
			
			if(minn>flag)//每次找最少的查询结果 
				minn = flag;
			if(minn==0)//如果匹配成功，直接退出 
				break;
		}
		
		if(minn>=2)
		{
			printf("库中没有该单词\n");
			break;	
		}
		else if(minn==1)
			printf("单词错误,您是否重新输入\n"); 
		else if(minn==0)
		{
			printf("匹配成功，单词ID为%s\n", id);
			break;
		}
	
	}
	
	return 0;
}
