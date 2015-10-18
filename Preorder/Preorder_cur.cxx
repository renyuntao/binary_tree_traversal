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

void Preorder_rec(Node *root)
{
	if(root != NULL)
	{
		cout<<root->data<<" ";
		Preorder_rec(root->lchild);
		Preorder_rec(root->rchild);
	}
}

int main()
{
	/*   Constructed binary tree is
	                    1
			   / \
			  2   3
			 /   / \
			4   5   6
			 \
			  7
	*/
	Node *root = generateNode(1);
	root->lchild = generateNode(2);
	root->rchild = generateNode(3);
	root->lchild->lchild = generateNode(4);
	root->lchild->lchild->rchild = generateNode(7);
	root->rchild->lchild = generateNode(5);
	root->rchild->rchild = generateNode(6);
	Preorder_rec(root);
	cout<<endl;
	destroy(&root);
	return 0;
}

