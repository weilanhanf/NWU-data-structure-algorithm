#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;


//����ʽ��a+b*(c-d)+m/c
//���� +*+a..b..-c..d../m..c..����һ�Ŷ�����
//���������������Ϊ a+b*c-d+m/c
//���������������Ϊ 
 

typedef struct BTNode{
	char data;
	struct BTNode *lchild, *rchild;
}BTNode, *BTree;
	
		  
void creatBT(BTree *bt)//���������� 
{
	char ch;
	scanf("%c", &ch);
	if(ch=='.')
		*bt = NULL;
	else
	{
		BTNode *q;
		q = new BTNode;
		q->data = ch;
		q->lchild = NULL; q->rchild = NULL;
		*bt = q; 
		creatBT(&((*bt)->lchild));
		creatBT(&((*bt)->rchild));
	}
}


void inTravel(BTree bt)//������������� 
{
	if(bt!=NULL)
	{
		inTravel(bt->lchild);
		printf("%c", bt->data);
		inTravel(bt->rchild);
	}
}

		        
void preTravel(BTree bt)//������������� 
{
	if(bt!=NULL)
	{
		printf("%c", bt->data);
		preTravel(bt->lchild);
		preTravel(bt->rchild);
	}
}


void printTree(BTree bt, int layer)//�㼶��ӡ������ 
{
	if(bt!=NULL)
	{
		printTree(bt->rchild, layer+1);
		for(int i=0;i<layer;i++)
			printf("\t");
		printf("%c\n", bt->data);
		printTree(bt->lchild, layer+1);
	}
} 



int main()
{
	BTree bt;
	creatBT(&bt);
	printf("����ʽ");
	inTravel(bt);
	printf("���������Ϊ��");
	preTravel(bt);
	
	printf("�������㼶����Ϊ��\n");
	printTree(bt, 0);
	return 0; 
}
