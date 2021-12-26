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

	AVLNode(Type key)
	{
		this->key = key;
		left = NULL;
		right = NULL;
		height = 1;
	}
};

template <class Type>
class AVL
{
	AVLNode<Type> *root = NULL;

public:
	// A utility function to get maximum of two elements
	int max(Type a, Type b)
	{
		return (a > b) ? a : b;
	}

	// A utility function to get the height of the tree
	int height(AVLNode<Type> *N)
	{
		if (N == NULL)
			return 0;
		return N->height;
	}

	/* Helper function that allocates a new AVLNode with the given key */
	AVLNode<Type> *newAVLNode(Type key)
	{
		AVLNode<Type> *node = new AVLNode<Type>(key);
		return (node);
	}

	// A utility function to right rotate subtree rooted with y
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

	// A utility function to left rotate subtree rooted with x
	AVLNode<Type> *leftRotate(AVLNode<Type> *x)
	{
		AVLNode<Type> *y = x->right;
		AVLNode<Type> *T2 = y->left;

		// Perform rotation
		y->left = x;
		x->right = T2;

		// Update heights
		x->height = max(height(x->left), height(x->right)) + 1;
		y->height = max(height(y->left), height(y->right)) + 1;

		// Return new root
		return y;
	}

	// Get Balance factor of AVLNode
	int getBalance(AVLNode<Type> *N)
	{
		if (N == NULL)
			return 0;
		return height(N->left) - height(N->right);
	}

	void insert(Type key)
	{
		root = insertNode(root, key);
	}

	// Recursive function to insert a key in the subtree rooted with AVLNode and
	// returns the new root of the subtree.
	AVLNode<Type> *insertNode(AVLNode<Type> *node, Type key)
	{
		/* 1. Perform the normal BST insertion */
		if (node == NULL)
			return (newAVLNode(key));

		if (key < node->key)
			node->left = insertNode(node->left, key);
		else if (key > node->key)
			node->right = insertNode(node->right, key);
		else // Equal keys are not allowed in BST
			return node;

		/* 2. Update height of this ancestor AVLNode */
		node->height = 1 + max(height(node->left),
							   height(node->right));

		/* 3. Get the balance factor of this ancestor AVLNode to check whether this AVLNode became unbalanced */
		int balance = getBalance(node);

		// If this AVLNode becomes unbalanced, then there are 4 cases

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

	void preOrder()
	{
		preOrderUtil(root);
	}

	// A utility function to print preorder traversal of the tree.
	void preOrderUtil(AVLNode<Type> *node)
	{
		if (node)
		{
			cout << node->key << " ";
			preOrderUtil(node->left);
			preOrderUtil(node->right);
		}
	}

	void inOrder()
	{
		inOrderUtil(root);
	}

	// A utility function to print inorder traversal of the tree.
	void inOrderUtil(AVLNode<Type> *node)
	{
		if (node)
		{

			inOrderUtil(node->left);
			cout << node->key << " ";
			inOrderUtil(node->right);
		}
	}

	void postOrder()
	{
		postOrderUtil(root);
	}

	// A utility function to print postorder traversal of the tree.
	void postOrderUtil(AVLNode<Type> *node)
	{
		if (node)
		{
			postOrderUtil(node->left);
			postOrderUtil(node->right);
			cout << node->key << " ";
		}
	}
};

// Driver Code
int main()
{
	AVL<int> avl;
	/* Constructing tree given in
	the above figure */
	avl.insert(10);
	avl.insert(20);
	avl.insert(30);
	avl.insert(40);
	avl.insert(50);
	avl.insert(25);

	/* The constructed AVL Tree would be
			30
			/ \
		  20   40
		 / \     \
		10 25     50
	*/
	cout << "Preorder traversal of the constructed AVL tree is \n";
	avl.preOrder();
	cout << endl;
	avl.inOrder();
	cout << endl;
	avl.postOrder();

	return 0;
}
