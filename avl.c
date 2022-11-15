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



int max(int a, int b)
{
    if (a>b)
    {
        return a;
    }

    else if (b>a)
    {
        return b;
    }

    else 
    {
        return a;
    }
}

int find_height(nodeaddress node)
{
    if (node == NULL)
    {
        return 0;
    }

    return node->height;
}

nodeaddress createNode(int data)
{
    nodeaddress node = malloc(sizeof(struct nodeType));
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 0; // since when inserting node it becomes a leaf node
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

    
}






