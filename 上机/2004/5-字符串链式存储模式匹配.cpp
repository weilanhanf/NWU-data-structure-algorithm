#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;


typedef struct Node
{
	struct Node *next;
	char data;
}Node, *Strlink; 

const int maxn = 20;


Strlink creatStrlink(char str[])
//β�巨���� 
{
	Strlink L;
	Node *r, *q;
	int len, i;
	L = new Node;
	L->next = NULL;
	r = L;
	len = strlen(str);
	
	for(i=0;i<len;i++)
	{
		q = new Node;
		q->data = str[i];
		q->next = NULL;
		r->next = q;
		r = q;
	}
	return L;
}


void travel(Strlink L)
//�������� 
{
	Node *q;
	q = L->next;
	while(q!=NULL)
	{
		printf("%c", q->data);
		q = q->next;
	}
	printf("\n");
 } 
 
 
Node* strLinkMatch(Strlink s, Strlink t)
{
	Node *q,*p, *m, *n;
	p = s->next; m = p;
	q = t->next; n = q;
	
	
	if(q==NULL)//�մ���������ƥ�� 
		return p;
	
	while(n!=NULL&&m!=NULL)
	{
		if(m->data==n->data)
		{
			m = m->next;
			n = n->next;
		}
		else//ƥ��ʧ�ܣ�ģʽ��ָ����ƣ�����ƥ�� 
		{
			p = p->next;
			m = p;
			n = q;	
		}
	}
	
	if(n==NULL)//��ʱ˵���Ӵ��Ѿ�ƥ�����
		return p;
	else
		return NULL;
}


int main()
{
	Strlink S, T;
	Node *k=NULL; 
	char s[maxn], t[maxn];

	gets(s);
	gets(t);
	
	S = creatStrlink(s);
	T = creatStrlink(t);
	
	k = strLinkMatch(S, T);
	if(k!=NULL)
		printf("ƥ�����\n");
	else 
		printf("ƥ��ʧ��\n");
	
	
	return 0;
}
