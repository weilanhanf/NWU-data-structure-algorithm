#include<stdio.h> 

//https://github.com/weilanhanf/NWU_data_structure_algorithm
//https://www.cnblogs.com/welan/category/1328658.html


typedef struct BSTNode{
	char data;
	struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;


void insert(BSTree *bst, char ch)//����ڵ� 
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


void creatBST(BSTree *bst)//�������������� 
{
	char ch;
	*bst=NULL;
	while((ch=getchar())!=NULL&&ch!='@')
	{
		insert(bst, ch);
	}
}


void reversePrint(BSTree bst)//������� 
{
	if(bst!=NULL)
	{
		reversePrint(bst->rchild);
		printf("%c", bst->data);
		reversePrint(bst->lchild);
	}
}


void printLayer(BSTree bst, int layer)//�㼶��� 
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
	printf("���������");
	reversePrint(bst);

	printf("\n��״�����\n");
	printLayer(bst, 0);
		
	return 0;
}
