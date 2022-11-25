#include <stdio.h>
#include <stdlib.h>
#define COUNT 10


struct nodeType {
	int val;
	struct nodeType * left;  // smaller
	struct nodeType * right; // larger
    int height;
};

typedef struct nodeType * nodeaddress; 

int max(int a, int b);
int find_height(nodeaddress node);
nodeaddress createNode(int data);
int balancing_factor(nodeaddress node);
nodeaddress left_rotate(nodeaddress x);
nodeaddress right_rotate(nodeaddress y);
nodeaddress insert(nodeaddress node, int data);
nodeaddress balance_tree(nodeaddress node, int data);
void print2DUtil(nodeaddress root, int space);
void print2D(nodeaddress root);



int max(int a, int b)
{
    if (a>b) {return a;}
    else if (b>a) {return b;}
    else {return a;}
}

int find_height(nodeaddress node)
{
    if (node == NULL)
    {
        return 0;
    }

    if (node->left == NULL && node->right == NULL)
    {
        return 1;
    }

    else {return node->height;}
}

nodeaddress createNode(int data)
{
    nodeaddress node = malloc(sizeof(struct nodeType));
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // since when inserting node it becomes a leaf node
    return node;
}

int balancing_factor(nodeaddress node)
{
    if (!node)
    {
        return 0;
    }

    int k = find_height(node->left) - find_height(node->right); // if k > 1 then left heavy and if < -1 then right heavy

    return k;
}

nodeaddress left_rotate(nodeaddress x)
{
    nodeaddress y = x->right;
    //nodeaddress A = x->left;
    nodeaddress B = y->left;
    //nodeaddress C = y->right;

    y->left = x;
    x->right = B;

    y->height = max(find_height(y->left), find_height(y->right)) + 1;
    x->height = max(find_height(x->left), find_height(x->right)) + 1;

    return y;

}

nodeaddress right_rotate(nodeaddress y)
{
    nodeaddress x = y->left;
    nodeaddress B = x->right;

    x->right = y;
    y->left = B;

    y->height = max(find_height(y->left), find_height(y->right)) + 1;
    x->height = max(find_height(x->left), find_height(x->right)) + 1;

    return x;

}


nodeaddress insert(nodeaddress node, int data)
{
    if (node == NULL)
    {
        return createNode(data);
    }

    else if (data < node->val)
    {
        node->left = insert(node->left, data);
    }
    else if (data > node->val)
    {
        node->right = insert(node->right, data);
    }

    else
    {
        return node;
    }

    node->height = max(find_height(node->left), find_height(node->right)) + 1;

    node = balance_tree(node, data);
    

    return node;
    

    
}


nodeaddress balance_tree(nodeaddress node, int data)
{
    int factor = balancing_factor(node);

    if (factor > 1 && data < node->left->val ) // both x and y heavy in left direction
    {
        return right_rotate(node);
    }
    else if (factor < -1 && data > node->right->val ) // both x and y heavy in right direction
    {
        return left_rotate(node);
    }
    else if (factor > 1 && data > node->left->val ) // x is left heavy and y is right heavy
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    else if (factor < -1 && data < node->right->val ) // x is right heavy and y is left heavy
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    
    else {return node;}
}




void print2DUtil(nodeaddress root, int space)
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
void print2D(nodeaddress root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}
//utility functions to print tree in tree form https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/




void inorder(nodeaddress root) 
{
    if(!root)
    {
        return;
    }
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



int main(void)
{
    nodeaddress root = NULL;
 
 
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 8);

    root = insert(root, 4);
    root = insert(root, 1);
    root = insert(root, 9);
    root = insert(root, 10);
    root = insert(root, 11);

    print2D(root); // prints tree horizontally

    inorder(root);

    //free(root);
    
    return 0;
}



