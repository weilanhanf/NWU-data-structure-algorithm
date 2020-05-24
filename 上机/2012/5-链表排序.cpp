#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;


typedef struct Node{
	char id[100];
	char name[100];
	int age;
	struct Node *next;
}Node, *Linklist;


void creatLinklist(Linklist L, int n)//β�巨����������, n����� 
{
	L->next = NULL;
	Node *q, *r;
	r = L;
	for(int i=0;i<n;i++)
	{
		q = new Node;
		scanf("%s %s %d", q->id, q->name, &q->age);
		q->next = NULL;
		r->next = q;
		r = r->next;
	}
}


double calAverAge(Linklist L)//����������ƽ��ֵ 
{
	Node *r;
	r = L->next;
	int count;
	double res, sums;
	
	sums=0; count=0;
	while(r!=NULL)
	{
		count++;
		sums+=r->age;
		r = r->next;
	}
	res = sums/count;
	return res;
}


int cmp(Node *p, Node *q)
//��ѧ�������ְ����ֵ���Ƚ�
//���p->name<q->name�����ظ��������p->name>q->name��������
//���p->name==q->name,��һ���Ƚ�ѧ��id
//���p->id<q->id�����ظ��������p->id>q->id��������
//�����ܴ�������������ͬ����ѧ����ͬ 
{
	int res;
	res = strcmp(p->name, q->name);
	if(res!=0)
		return res;
	else//���������ͬ������id�Ƚ�
	{
		int idcmp = strcmp(p->id, q->id);
		return idcmp;
	} 
}


void selcetSort(Linklist L) 
//�����������������ѡ������ 
{
	Node *p, *q, *m;
	for(p=L->next;p->next!=NULL;p=p->next)
	{
		m = p;
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(cmp(q, m)<0)
				m = q;
		}
		
		if(m!=p)
		{
			swap(p->age, m->age);
			swap(p->name, m->name);
			swap(p->id, m->id);
		}
			
	}
}



int main()
{
	Linklist L;
	L = new Node;
	int N;
	
	printf("������ѧ��������"); 
	scanf("%d", &N); 
	
	creatLinklist(L, N);
	double aver = calAverAge(L);
	printf("ƽ������Ϊ��%.2f\n", aver);
	
	Node *r;
	r = L->next;
	printf("ѧ������Ϊ��\n"); 
	while(r!=NULL)
	{
		printf("%s %s %d\n", r->id, r->name, r->age);
		r = r->next;
	}
	
	selcetSort(L);
	r = L->next;
	printf("ѧ��������������С��������Ϊ��\n"); 
	while(r!=NULL)
	{
		printf("%s %s %d\n", r->id, r->name, r->age);
		r = r->next;
	}
	
	return 0;
} 
