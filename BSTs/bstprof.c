#include <stdio.h>
#include<stdlib.h>

struct nodeType {
	int val;
	struct nodeType * left;  // smaller
	struct nodeType * right; // larger
};

typedef struct nodeType * nodeAddress; //nodeAddress is type nodeType *

nodeAddress createNode(int data);
void freeNode(nodeAddress mainroot);
nodeAddress search(nodeAddress root, int data);
nodeAddress search2(nodeAddress root, int data);
nodeAddress insert(nodeAddress root, int data);
nodeAddress insert2(nodeAddress root, int data);
void inorder(nodeAddress root); 


int main(void)
{
	nodeAddress root = NULL;
	root = insert(root, 15);
	printf("%i\n", root);
	//nodeAddress mainroot = root;
	root = insert(root, 20);
	printf("%i\n", root);
	root = insert(root, 10);
	printf("%i\n", root);
	root = insert(root, 25);
	printf("%i\n", root);
	//inorder(root);

}

nodeAddress createNode(int data)
{
	nodeAddress newNode = malloc(sizeof(struct nodeType)); //this needs to be sizeof(struct nodeType) not sizeof(nodeAddress) since nodeAddress is just a pointer to a struct nodeType
	newNode->val = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}


// void freeNode(nodeAddress root)
// {
	
// }

nodeAddress insert(nodeAddress root, int data) 
{
	if (root == NULL) 
	{
		return createNode(data);
	}

	else if (data < root->val) 
	{
		root->left  = insert(root->left , data);
	}
	else if (data > root->val)
	{ 
		root->right = insert(root->right, data);
	}

	return root;
}

nodeAddress insert2(nodeAddress root, int data) 
{
	if(root==NULL) 
	{return createNode(data);}

	if ( data < root->val ) 
	{ 
		if(root->left) return insert2(root->left, data);
		else root->left = createNode(data);
		return root->left;
	}
	else if ( data > root->val ) 
	{ 
		if(root->right) return insert2(root->right, data);
		else root->right = createNode(data);
		return root->right;
	}
	
	return root;
}

nodeAddress search(nodeAddress root, int data) 
{
	if(root==NULL) return NULL;

	if      ( data < root->val ) 
	{ return search(root->left , data);}
	else if ( data > root->val ) 
	{ return search(root->right, data);}
	else                        
	{ return root;}
}

nodeAddress search2(nodeAddress root, int data) 
{
	return root?((data==root->val)? root : (  ( data < root->val )? search2(root->left , data): search2(root->right, data)  ) ): NULL;
}


void inorder(nodeAddress root) 
{
	if( root->left )  
	{
		inorder(root->left);      
	}
	if( root )        
	{
		printf("%i\n", root->val);
	}
	if( root->right ) 
	{
		inorder(root->right);     
	}
}
