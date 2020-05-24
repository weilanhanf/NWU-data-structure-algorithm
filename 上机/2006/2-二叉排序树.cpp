#include<stdio.h> 

//https://github.com/weilanhanf/NWU_data_structure_algorithm
//https://www.cnblogs.com/welan/category/1328658.html


typedef struct BSTNode{
	char data;
	struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;


void insert(BSTree *bst, char ch)//插入节点 
{
	if(*bst==NULL)
	{
		BSTNode *q;
		q = new BSTNode;
		q->data = ch;
		q->lchild = NULL; q->rchild = NULL; 
		*bst = q;
	}
	else
	{
		if(ch>(*bst)->data)
			insert(&((*bst)->rchild), ch);
		else if(ch<(*bst)->data)
			insert(&((*bst)->lchild), ch);
	}
}


void creatBST(BSTree *bst)//创建二叉排序树 
{
	char ch;
	*bst=NULL;
	while((ch=getchar())!=NULL&&ch!='@')
	{
		insert(bst, ch);
	}
}


void reversePrint(BSTree bst)//逆序输出 
{
	if(bst!=NULL)
	{
		reversePrint(bst->rchild);
		printf("%c", bst->data);
		reversePrint(bst->lchild);
	}
}


void printLayer(BSTree bst, int layer)//层级输出 
{
	if(bst!=NULL)
	{
		printLayer(bst->rchild, layer+1);
		for(int i=0;i<layer;i++)
			printf("\t");
		printf("%c\n", bst->data);
		printLayer(bst->lchild, layer+1);
	}
 } 


int main()
{
	BSTree bst;
	bst = new BSTNode;
	creatBST(&bst);
	printf("逆序输出：");
	reversePrint(bst);

	printf("\n树状输出：\n");
	printLayer(bst, 0);
		
	return 0;
}
