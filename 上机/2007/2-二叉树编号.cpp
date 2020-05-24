#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;


//https://github.com/weilanhanf/NWU_data_structure_algorithm
//https://www.cnblogs.com/welan/category/1328658.html

typedef struct BTNode
{
	struct BTNode *Lchild, *Rchild;
	char Data;
	int Num;
}BTNode, *BTree;

int num=1;


void preCreatBTree(BTree *bt)
//���򴴽������� 
{
	char ch;
	ch = getchar();
	if(ch==' ')
		*bt = NULL;
	else
	{
		BTNode *p = new BTNode;
		p->Data = ch;
		*bt = p;
		preCreatBTree(&((*bt)->Lchild));
		preCreatBTree(&((*bt)->Rchild));
	}
}


void layerPrint(BTree bt, int layer)
//��״��ӡ 
{
	if(bt!=NULL)
	{
		layerPrint(bt->Rchild, layer+1);
		for(int i=0;i<layer;i++)
			printf("   ");
		printf("%c,%d\n", bt->Data, bt->Num);
		layerPrint(bt->Lchild, layer+1);
	}
}


void setNumber(BTree bt)
//��һ��ʼ����������ţ�ÿ�����ı�Ŵ��������Һ��ӵı�ţ�ͬһ���������Һ����У������ӵı��С�����Һ��ӵı��
//Ҫ�ú������ 
{
	if(bt!=NULL)
	{
		setNumber(bt->Lchild);
		setNumber(bt->Rchild);
		bt->Num = num++;
	}	
}


int main()
{
	BTree bt;
	preCreatBTree(&bt);
	setNumber(bt);
	printf("�㼶��ӡ��\n"); 
	layerPrint(bt, 0);
	
	
	return 0;
 } 
