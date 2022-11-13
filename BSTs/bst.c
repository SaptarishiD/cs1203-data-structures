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


void print2DUtil(nodeaddress root, int space);
void print2D(nodeaddress root);







int main(void)
{
    int n = 10;
    int * array = makearray(n);

    nodeaddress bstroot = createBST(array, n);
    
    
    print2D(bstroot);










}



int * makearray(int size) 
{
	int * array = malloc( size * sizeof(int) );
	if(array) 
    {
        for (int i = 0; i < size; i++)
        {
            array[0] = 15;
            array[1] = 10;
            array[2] = 2;
            array[3] = 19;
            array[4] = 5;
            array[5] = 20;
            array[6] = 4;
            array[7] = 19;
            array[8] = 6;
            array[9] = 0;
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


//===========================================================================================


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