#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}tree;

tree* newNode(int data)
{
	tree* temp=(tree*)malloc(sizeof(tree));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int diameter(tree* root,int * height)
{
	if(root==NULL)
	{
		*height=0;
		return 0;
	}

	int lheight=0;
	int rheight=0;

	int ldia=diameter(root->left,&lheight);
	int rdia=diameter(root->right,&rheight);

	*height=max(lheight,rheight)+1;
	return max(lheight+rheight+1,max(ldia,rdia));
}

int main()
{
	tree* root = NULL;
	root=newNode(1); 
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  root->left->left  = newNode(4); 
  root->left->right = newNode(5); 
  int height=0;
  printf("Diameter of the given binary tree is %d\n", diameter(root,&height)); 
  
  return 0; 
}