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


int strMatch(char str1[], char str2[])//�ַ���ƥ�䣬�ɹ�Ϊ1��ʧ��Ϊ0 
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
			if(strcmp(w[i].word, str)==0)//ƥ��ɹ����˳� 
			{
				flag = 0;//falg=0��ʾ�ɹ�ƥ�� 
				strcpy(id, w[i].id); 
			}
			else
			{
				wlen = strlen(w[i].word);
				if(abs(wlen-len)>=2)//�������2���϶����ɹ�������ƥ����һ�� 
				{
					flag = 2; 
				}
				else if(abs(wlen-len)==1)//�������1
				{
					int res=0;
					if(wlen>len)//�̴��Ƿ��ڳ����У������res=1������res=0 
						res=strMatch(w[i].word, str);
					else if(len>wlen)
						res=strMatch(str, w[i].word);
						
					if(res==1)//�̴��ڳ�����
						flag=1;//����ҵ�һ��ֻ���һ����ĸ�ĵ��ʣ�Ҳ��Ҫ����ƥ�䣬������ȫ��ͬ�ĵ��� 
					else //���������û�ж̴���������ʵƥ�䣬��face��fae 
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
				else if(abs(wlen-len)==0)//������ͬ����face��facc 
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
			
			if(minn>flag)//ÿ�������ٵĲ�ѯ��� 
				minn = flag;
			if(minn==0)//���ƥ��ɹ���ֱ���˳� 
				break;
		}
		
		if(minn>=2)
		{
			printf("����û�иõ���\n");
			break;	
		}
		else if(minn==1)
			printf("���ʴ���,���Ƿ���������\n"); 
		else if(minn==0)
		{
			printf("ƥ��ɹ�������IDΪ%s\n", id);
			break;
		}
	
	}
	
	return 0;
}
