#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;


typedef struct BSTNode
{
	char data;
	struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;


void insert(BSTree *bst, char ch)
//�������ڵ� 
{
	if(*bst==NULL)
	{
		BSTNode *p = new BSTNode;
		p->data = ch;
		p->rchild = p->lchild = NULL;
		*bst = p;
	}
	else if((*bst)->data > ch)
		insert(&((*bst)->lchild), ch);
	else if((*bst)->data < ch)
		insert(&((*bst)->rchild), ch);
}


void creatBST(BSTree *bst, char str[])
//�������������� 
{
	int len=strlen(str);
	*bst = NULL;
	for(int i=0;i<len-1;i++)
		insert(bst, str[i]);
}



void inTravel(BSTree bst)
//������� 
{
	if(bst!=NULL)
	{
		inTravel(bst->lchild);
		printf("%c", bst->data);
		inTravel(bst->rchild);
	}
}


int main()
{
	char str[20];
	BSTree bst;
	gets(str);
	creatBST(&bst, str);
	inTravel(bst);
	
	return 0;
 } 
