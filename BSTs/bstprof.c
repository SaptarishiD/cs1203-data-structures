#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 10


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
void print2DUtil(nodeAddress root, int space);
void print2D(nodeAddress root);





int main(void)
{
	nodeAddress root = NULL;
	srand(time(NULL));

	root = insert(root, rand()%20); //need to assign root only for the first time. Now root  points to/has the address of  the first/highest/mainroot node of the bst

	for (int i = 0; i < 10; i++)
	{
		insert(root, rand()%20);
	}

	inorder(root);
	print2D(root);
	

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


void print2DUtil(nodeAddress root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->val);
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(nodeAddress root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}