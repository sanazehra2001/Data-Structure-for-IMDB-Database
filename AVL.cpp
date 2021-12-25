#include <iostream>
using namespace std;

// An AVL tree AVLNode
template <class Type>
class AVLNode
{
public:
	Type key;
	AVLNode *left;
	AVLNode *right;
	int height;
};

template <class Type>
class AVL
{
public:
	// A utility function to get maximum
	// of two integers
	// A utility function to get maximum
	// of two elements
	int max(Type a, Type b)
	{
		return (a > b) ? a : b;
	}

	// A utility function to get the
	// height of the tree
	int height(AVLNode<Type> *N)
	{
		if (N == NULL)
			return 0;
		return N->height;
	}

	/* Helper function that allocates a
new AVLNode with the given key and
NULL left and right pointers. */
	AVLNode<Type> *newAVLNode(Type key)
	{
		AVLNode<Type> *node = new AVLNode<Type>();
		node->key = key;
		node->left = NULL;
		node->right = NULL;
		node->height = 1; // new AVLNode is initially
						  // added at leaf
		return (node);
	}

	// A utility function to right
	// rotate subtree rooted with y
	// See the diagram given above.
	AVLNode<Type> *rightRotate(AVLNode<Type> *y)
	{
		AVLNode<Type> *x = y->left;
		AVLNode<Type> *T2 = x->right;

		// Perform rotation
		x->right = y;
		y->left = T2;

		// Update heights
		y->height = max(height(y->left), height(y->right)) + 1;
		x->height = max(height(x->left), height(x->right)) + 1;

		// Return new root
		return x;
	}

	// A utility function to left
	// rotate subtree rooted with x
	// See the diagram given above.
	AVLNode<Type>* leftRotate(AVLNode<Type> *x)
	{
		AVLNode<Type>* y = x->right;
		AVLNode<Type>* T2 = y->left;

		// Perform rotation
		y->left = x;
		x->right = T2;

		// Update heights
		x->height = max(height(x->left),height(x->right)) +1;
		y->height = max(height(y->left),height(y->right)) +1;

		// Return new root
		return y;
	}

	// Get Balance factor of AVLNode N
	int getBalance(AVLNode<Type> *N)
	{
		if (N == NULL)
			return 0;
		return height(N->left) - height(N->right);
	}

	// Recursive function to insert a key
	// in the subtree rooted with AVLNode and
	// returns the new root of the subtree.
	AVLNode<Type>* insert(AVLNode<Type> *node, Type key)
	{
		/* 1. Perform the normal BST insertion */
		if (node == NULL)
			return (newAVLNode(key));

		if (key < node->key)
			node->left = insert(node->left, key);
		else if (key > node->key)
			node->right = insert(node->right, key);
		else // Equal keys are not allowed in BST
			return node;

		/* 2. Update height of this ancestor AVLNode */
		node->height = 1 + max(height(node->left),
							   height(node->right));

		/* 3. Get the balance factor of this ancestor
		AVLNode to check whether this AVLNode became
		unbalanced */
		int balance = getBalance(node);

		// If this AVLNode becomes unbalanced, then
		// there are 4 cases

		// Left Left Case
		if (balance > 1 && key < node->left->key)
			return rightRotate(node);

		// Right Right Case
		if (balance < -1 && key > node->right->key)
			return leftRotate(node);

		// Left Right Case
		if (balance > 1 && key > node->left->key)
		{
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

		// Right Left Case
		if (balance < -1 && key < node->right->key)
		{
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}

		/* return the (unchanged) AVLNode pointer */
		return node;
	}

	// A utility function to print preorder
	// traversal of the tree.
	// The function also prints height
	// of every AVLNode
	void preOrder(AVLNode<Type> *root)
	{
		if (root != NULL)
		{
			cout << root->key << " ";
			preOrder(root->left);
			preOrder(root->right);
		}
	}
};

// Driver Code
int main()
{
	AVLNode<int> *root = NULL;
	AVL<int> avl;
	/* Constructing tree given in
	the above figure */
	root = avl.insert(root, 10);
	root = avl.insert(root, 20);
	root = avl.insert(root, 30);
	root = avl.insert(root, 40);
	root = avl.insert(root, 50);
	root = avl.insert(root, 25);

	/* The constructed AVL Tree would be
				30
			/ \
			20 40
			/ \ \
		10 25 50
	*/
	cout << "Preorder traversal of the "
			"constructed AVL tree is \n";
	avl.preOrder(root);

	return 0;
}

// This code is contributed by
// rathbhupendra
