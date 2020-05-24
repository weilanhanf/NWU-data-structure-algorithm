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
//先序创建二叉树 
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
//树状打印 
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
//从一开始进行连续编号，每个结点的编号大于其左右孩子的编号，同一个结点的左右孩子中，其左孩子的编号小于其右孩子的编号
//要用后序遍历 
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
	printf("层级打印：\n"); 
	layerPrint(bt, 0);
	
	
	return 0;
 } 
