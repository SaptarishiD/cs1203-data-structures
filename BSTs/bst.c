#include <stdio.h>
#include <stdlib.h>
#define COUNT 10


struct nodeType {
	int val;
	struct nodeType * left;  // smaller
	struct nodeType * right; // larger
};

typedef struct nodeType * nodeaddress; 

int * makearray(int size);
nodeaddress createBST(int * array, int size);
nodeaddress createNode(int data);
nodeaddress insert(nodeaddress root, int data);
nodeaddress delete(nodeaddress root, int nodedata);
nodeaddress find_node_with_min_val(nodeaddress root);
void freenode(nodeaddress root);
void inorder(nodeaddress root); 



void print2DUtil(nodeaddress root, int space);
void print2D(nodeaddress root);







int main(void)
{
    int n = 7;
    int * array = makearray(n);

    nodeaddress bstroot = createBST(array, n);
    //print2D(bstroot);
    inorder(bstroot);
    bstroot = delete(bstroot, 17);
    
    printf("\n");
    inorder(bstroot);
    //print2D(bstroot);


    free(array);
    
    freenode(bstroot);





}


void inorder(nodeaddress root) 
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


int * makearray(int size) 
{
	int * array = malloc( size * sizeof(int) );
	if(array) 
    {
        for (int i = 0; i < size; i++)
        {
            array[0] = 15;
            array[1] = 3;
            array[2] = 17;
            array[3] = 1;
            array[4] = 2;
            array[5] = 16;
            array[6] = 18;
            // array[7] = 18;
            // array[8] = 6;
            // array[9] = 0;
        }       
     
	}
	return array;
}


nodeaddress createBST(int * array, int size)
{
    nodeaddress root = NULL;
    root = insert(root, array[0]);
    for (int i = 1; i < size; i++)
    {
        insert(root, array[i]);
    }

    return root;

}


nodeaddress createNode(int data)
{
	nodeaddress newNode = malloc(sizeof(struct nodeType)); //this needs to be sizeof(struct nodeType) not sizeof(nodeaddress) since nodeaddress is just a pointer to a struct nodeType
	newNode->val = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}


nodeaddress insert(nodeaddress root, int data) 
{
	if (root == NULL) 
	{
		return createNode(data);
	}

	else if (data <= root->val) 
	{
		root->left  = insert(root->left , data);
	}
	else if (data >= root->val)
	{ 
		root->right = insert(root->right, data);
	}

	return root;
}


nodeaddress search(nodeaddress root, int data) 
{
	if(root==NULL) return NULL;

	if (data < root->val) 
	{ 
        return search(root->left , data);
    }
	else if (data > root->val) 
	{ 
        return search(root->right, data);
    }
	else                        
	{ 
        return root;
    }
}


nodeaddress delete(nodeaddress root, int nodedata)
{

    if (root == NULL)
    {
        return NULL;
    }
    if (nodedata < root->val) 
	{ 
        root->left = delete(root->left , nodedata);
    }
	else if (nodedata > root->val) 
	{ 
        root->right = delete(root->right, nodedata);
    }

    else 
    {
        nodeaddress tempnode = NULL;

        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return tempnode;
        }

        else if(root->left == NULL && root->right != NULL)
        {
            tempnode = root->right;
            free(root);
            return tempnode;
        }

        else if(root->left != NULL && root->right == NULL)
        {
            tempnode = root->left;
            free(root);
            return tempnode;
        }

        else if (root->left != NULL && root->right != NULL)
        {
            nodeaddress min_node = find_node_with_min_val(root->right);       // the minimum valued node in the right subtree
            root->val = min_node->val;
            free(min_node);     // need to actually free the node associate with min
        }

    }


    return root;


}


nodeaddress find_node_with_min_val(nodeaddress root)
{
    nodeaddress temp = root;

    while(temp->left !=NULL)
    {
        temp = temp->left;
    }

    return temp;

}


void freenode(nodeaddress root)
{
    if (root == NULL)
    {
        return;
    }

    else if(root->left == NULL && root->right != NULL)
    {
        freenode(root->right);
        free(root);
        root = NULL;
    }

    else if(root->left != NULL && root->right == NULL)
    {
        freenode(root->left);
        free(root);
        root = NULL;
      
    }

    else if (root->left != NULL && root->right != NULL)
    {
      freenode(root->right);
      freenode(root->left);
      free(root);
      root = NULL;
    }

}









//===========================================================================================
// these are just to visualise the binary tree
// https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/ 


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