#include<iostream>
#include<stack>
using std::endl;
using std::cout;

struct Node
{
	int data = 0;
	Node *lchild = NULL;
	Node *rchild = NULL;
};

Node* generateNode(int value)
{
	Node *newNode = new Node;
	newNode->data = value;
	return newNode;
}

void destroy(Node **root)
{
	if((*root) != NULL && (*root)->lchild != NULL)
		destroy(&(*root)->lchild);
	if((*root) != NULL && (*root)->rchild != NULL)
		destroy(&(*root)->rchild);
	free(*root);
	*root = NULL;
}

/**************** Recursive Traversal *******************/
void inOrder(Node *root)     
{
	if(root != NULL)
	{
		inOrder(root->lchild);
		cout<<root->data<<" ";
		inOrder(root->rchild);
	}
}
/******************************************************/

int main()
{
	Node *root = generateNode(1);
	root->lchild = generateNode(2);
	root->rchild = generateNode(3);
	root->lchild->lchild = generateNode(4);
	root->lchild->lchild->rchild = generateNode(7);
	root->rchild->lchild = generateNode(5);
	root->rchild->rchild = generateNode(6);
	inOrder(root);
	cout<<endl;
	destroy(&root);
	return 0;
}
