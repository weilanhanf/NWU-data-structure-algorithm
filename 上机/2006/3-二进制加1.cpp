#include<stdio.h>
#include<string.h> 

//https://github.com/weilanhanf/NWU_data_structure_algorithm
//https://www.cnblogs.com/welan/category/1328658.html


typedef struct LNode{
	int data;
	struct LNode *next;
}LNode, *Linklist;


void creatLinklist(Linklist L, char str[])//β�巨�������������� 
{
	int len=strlen(str);
	LNode *r, *q;
	L->next = NULL;
	r = L;
	
	for(int i=0;i<len;i++)
	{
		q = new LNode;
		q->data = str[i]-'0';
		q->next = NULL;
		r->next = q;
		r = r->next; 
	}
}


void travel(Linklist L)//�������� 
{
	LNode *r;
	r = L->next;
	while(r!=NULL)
	{
		printf("%d", r->data);
		r = r->next;
	}
	printf("\n");
}


void cal(Linklist L)
//Ҫ�ҵ����һ��Ϊ0������ڵ㣬���ýڵ��ֵ��Ϊ1���ýڵ�ĺ�̽���Ϊ0��
//��������нڵ�ֵȫΪ1������Ҫ�½�һ���ڵ�����ײ� 
{
		LNode *r, *q;
		q = L; r = q;
		while(r!=NULL)
		{
			if(r->data==0)
				q = r;//qָ�����һ��ֵΪ0�Ľڵ� 
			r = r->next; 
		}
		 
		if(q==L)//����ڵ�ȫ��1 ���½�һ���ڵ�����ײ� 
		{
			LNode *m;
			m = new LNode;
			m->next = q->next;
			q->next = m;
			q = m;			
		}
		
		q->data = 1;
		r = q->next;
		while(r!=NULL)//�޸�ֵΪ0 
		{
			r->data = 0;
			r = r->next;
		}
}


int main()
{
	char str[100];
	gets(str);
	Linklist L;
	L = new LNode;
	creatLinklist(L, str);
	printf("��1ǰ��");
	travel(L);
	cal(L);
	printf("��1��");
	travel(L);
	
	return 0;
}
