#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;


//波兰式：a+b*(c-d)+m/c
//输入 +*+a..b..-c..d../m..c..创建一颗二叉树
//二叉树的中序遍历为 a+b*c-d+m/c
//二叉树的先序遍历为 
 

typedef struct BTNode{
	char data;
	struct BTNode *lchild, *rchild;
}BTNode, *BTree;
	
		  
void creatBT(BTree *bt)//创建二叉树 
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


void inTravel(BTree bt)//中序遍历二叉树 
{
	if(bt!=NULL)
	{
		inTravel(bt->lchild);
		printf("%c", bt->data);
		inTravel(bt->rchild);
	}
}

		        
void preTravel(BTree bt)//先序遍历二叉树 
{
	if(bt!=NULL)
	{
		printf("%c", bt->data);
		preTravel(bt->lchild);
		preTravel(bt->rchild);
	}
}


void printTree(BTree bt, int layer)//层级打印二叉树 
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
	printf("波兰式");
	inTravel(bt);
	printf("的先序遍历为：");
	preTravel(bt);
	
	printf("二叉树层级遍历为：\n");
	printTree(bt, 0);
	return 0; 
}
