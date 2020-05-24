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


void creatLinklist(Linklist L, int n)//尾插法创建新链表, n个结点 
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


double calAverAge(Linklist L)//遍历链表求平均值 
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
//对学生的名字按照字典序比较
//如果p->name<q->name，返回负数，如果p->name>q->name返回正数
//如果p->name==q->name,进一步比较学生id
//如果p->id<q->id，返回负数，如果p->id>q->id返回正数
//不可能存在两人名字相同并且学号相同 
{
	int res;
	res = strcmp(p->name, q->name);
	if(res!=0)
		return res;
	else//如果名字相同，则按照id比较
	{
		int idcmp = strcmp(p->id, q->id);
		return idcmp;
	} 
}


void selcetSort(Linklist L) 
//根据姓名对链表进行选择排序 
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
	
	printf("请输入学生个数："); 
	scanf("%d", &N); 
	
	creatLinklist(L, N);
	double aver = calAverAge(L);
	printf("平均年龄为：%.2f\n", aver);
	
	Node *r;
	r = L->next;
	printf("学生链表为：\n"); 
	while(r!=NULL)
	{
		printf("%s %s %d\n", r->id, r->name, r->age);
		r = r->next;
	}
	
	selcetSort(L);
	r = L->next;
	printf("学生链表按照姓名从小到大排列为：\n"); 
	while(r!=NULL)
	{
		printf("%s %s %d\n", r->id, r->name, r->age);
		r = r->next;
	}
	
	return 0;
} 
