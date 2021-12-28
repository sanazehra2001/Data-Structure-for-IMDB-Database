#include <iostream>
#include "Movie.cpp"
// #include "Actor.cpp"
// #include "Director.cpp"
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

// functions common to all
// A utility function to get maximum of two elements
int max(int a, int b)
{
	return (a > b) ? a : b;
}

// A utility function to get the height of the tree
int height(AVLNode<Movie *> *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

/* Helper function that allocates a new AVLNode with the given key */
AVLNode<Movie *> *newAVLNode(Movie *key)
{
	AVLNode<Movie *> *node = new AVLNode<Movie *>(key);
	return (node);
}

// A utility function to right rotate subtree rooted with y
AVLNode<Movie *> *rightRotate(AVLNode<Movie *> *y)
{
	AVLNode<Movie *> *x = y->left;
	AVLNode<Movie *> *T2 = x->right;

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
AVLNode<Movie *> *leftRotate(AVLNode<Movie *> *x)
{
	AVLNode<Movie *> *y = x->right;
	AVLNode<Movie *> *T2 = y->left;

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
int getBalance(AVLNode<Movie *> *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

// A utility function to print preorder traversal of the tree.
void preOrderUtil(AVLNode<Movie *> *node)
{
	if (node)
	{
		cout << node->key->getTitle() << " ";
		preOrderUtil(node->left);
		preOrderUtil(node->right);
	}
}

// A utility function to print inorder traversal of the tree.
void inOrderUtil(AVLNode<Movie *> *node)
{
	if (node)
	{

		inOrderUtil(node->left);
		cout << node->key->getTitle() << " ";
		inOrderUtil(node->right);
	}
}

// A utility function to print postorder traversal of the tree.
void postOrderUtil(AVLNode<Movie *> *node)
{
	if (node)
	{
		postOrderUtil(node->left);
		postOrderUtil(node->right);
		cout << node->key->getTitle() << " ";
	}
}

class AVLMovieByTitle
{
	AVLNode<Movie *> *root = NULL;

public:
	void insert(Movie *key)
	{
		root = insertNode(root, key);
	}

	// Recursive function to insert a key in the subtree rooted with AVLNode and
	// returns the new root of the subtree.
	AVLNode<Movie *> *insertNode(AVLNode<Movie *> *node, Movie *key)
	{
		/* 1. Perform the normal BST insertion */
		if (node == NULL)
			return (newAVLNode(key));
		if (key->getTitle() < node->key->getTitle())
			node->left = insertNode(node->left, key);
		else if (key->getTitle() > node->key->getTitle())
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
	void postOrder()
	{
		postOrderUtil(root);
	}
	void inOrder()
	{
		inOrderUtil(root);
	}
};

class AVLMovieByYear
{
	AVLNode<Movie *> *root = NULL;

public:
	void insert(Movie *key)
	{
		root = insertNode(root, key);
	}

	// Recursive function to insert a key in the subtree rooted with AVLNode and
	// returns the new root of the subtree.
	AVLNode<Movie *> *insertNode(AVLNode<Movie *> *node, Movie *key)
	{
		/* 1. Perform the normal BST insertion */
		if (node == NULL)
			return (newAVLNode(key));
		if (key->getTitleYear() < node->key->getTitleYear())
			node->left = insertNode(node->left, key);
		else if (key->getTitleYear() > node->key->getTitleYear())
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
	void postOrder()
	{
		postOrderUtil(root);
	}
	void inOrder()
	{
		inOrderUtil(root);
	}
};
