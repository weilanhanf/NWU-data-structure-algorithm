#include<stdio.h>
#include<string.h> 

//https://github.com/weilanhanf/NWU_data_structure_algorithm
//https://www.cnblogs.com/welan/category/1328658.html


typedef struct LNode{
	int data;
	struct LNode *next;
}LNode, *Linklist;


void creatLinklist(Linklist L, char str[])//尾插法创建二进制链表 
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


void travel(Linklist L)//遍历链表 
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
//要找到最后一个为0的链表节点，将该节点的值改为1，该节点的后继结点变为0；
//如果链表中节点值全为1，则需要新建一个节点插入首部 
{
		LNode *r, *q;
		q = L; r = q;
		while(r!=NULL)
		{
			if(r->data==0)
				q = r;//q指向最后一个值为0的节点 
			r = r->next; 
		}
		 
		if(q==L)//链表节点全是1 ，新建一个节点插入首部 
		{
			LNode *m;
			m = new LNode;
			m->next = q->next;
			q->next = m;
			q = m;			
		}
		
		q->data = 1;
		r = q->next;
		while(r!=NULL)//修改值为0 
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
	printf("加1前：");
	travel(L);
	cal(L);
	printf("加1后：");
	travel(L);
	
	return 0;
}
