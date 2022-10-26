
struct nodeType {
	int val;
	struct nodeType * left;  // smaller
	struct nodeType * right; // larger
};

typedef struct nodeType * NodeAddress;


NodeAddress search(NodeAddress root, int val) {
	if(root==NULL) return NULL;

	if      ( val < root->val ) { return search(root->left , val);}
	else if ( val > root->val ) { return search(root->right, val);}
	else                        { return root;}
}

NodeAddress search2(NodeAddress root, int val) {
	return root?((val==root->val)? root : (  ( val < root->val )? search2(root->left , val): search2(root->right, val)  ) ): NULL;
}

NodeAddress insert(NodeAddress root, int val) {
	if(root==NULL) {return createNode(val);}

	if      ( val < root->val ) { root->left  = insert(root->left , val);}
	else if ( val > root->val ) { root->right = insert(root->right, val);}

	return root;
}

NodeAddress insert2(NodeAddress root, int val) {
	if(root==NULL) {return createNode(val);}

	if ( val < root->val ) { 
		if(root->left) return insert2(root->left, val);
		else root->left = createNode(val);
		return root->left;
	}
	else if ( val > root->val ) { 
		if(root->right) return insert2(root->right, val);
		else root->right = createNode(val);
		return root->right;
	}
	
	return root;
}

void inorder(NodeAddress root) {
	if( root->left )  { inorder(root->left);       }
	if( root )        { printf(" %s ", root->val); }
	if( root->right ) { inorder(root->right);      }
}
