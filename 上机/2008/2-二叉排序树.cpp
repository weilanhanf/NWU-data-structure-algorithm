#include<stdio.h>
#include<stack>

//https://github.com/weilanhanf/NWU_data_structure_algorithm
//https://www.cnblogs.com/welan/category/1328658.html


using namespace std;

typedef struct BSTNode
{
	char data;
	struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;


stack<char> st;


void insert(BSTree *bst, char ch)
{
	if(*bst==NULL)
	{
		BSTNode *q;
		q = new BSTNode;
		q->lchild = NULL; q->rchild = NULL;
		q->data = ch;
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
	*bst = NULL; 
	scanf("%c", &ch);
	while(ch!='@')
	{
		insert(bst, ch);
		scanf("%c", &ch);
	}
}


void inTravel(BSTree bst)//放在栈中 
{
	if(bst!=NULL)
	{
		inTravel(bst->lchild);
		st.push(bst->data);
//		printf("%c", bst->data);
		inTravel(bst->rchild);
	}
}


void reverseTravel(BSTree bst)//直接逆序输出 
{
	if(bst!=NULL)
	{
		reverseTravel(bst->rchild);
		printf("%c", bst->data);
		reverseTravel(bst->lchild);	
	}	
} 


int main()
{
	BSTree bst;
	bst = new BSTNode;
	creatBST(&bst);
	inTravel(bst);
	
	while(st.empty()==false)//逐个弹出栈顶元素 
	{
		printf("%c", st.top());
		st.pop();
	}
	
	printf("\n");
	reverseTravel(bst);
	
	return 0;
}
