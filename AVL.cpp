#include <iostream>
#include "Movie.cpp"
#include "ActorNode.cpp"
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
template <class Type>
int height(AVLNode<Type *> *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

/* Helper function that allocates a new AVLNode with the given key */
template <class Type>
AVLNode<Type *> *newAVLNode(Type *key)
{
	AVLNode<Type *> *node = new AVLNode<Type *>(key);
	return (node);
}

// A utility function to right rotate subtree rooted with y
template <class Type>
AVLNode<Type *> *rightRotate(AVLNode<Type *> *y)
{
	AVLNode<Type *> *x = y->left;
	AVLNode<Type *> *T2 = x->right;

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
template <class Type>
AVLNode<Type *> *leftRotate(AVLNode<Type *> *x)
{
	AVLNode<Type *> *y = x->right;
	AVLNode<Type *> *T2 = y->left;

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
template <class Type>
int getBalance(AVLNode<Type *> *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

// A utility function to print preorder traversal of the tree.
template <class Type>
void preOrderUtil(AVLNode<Type *> *node)
{
	if (node)
	{
		cout << node->key->getTitle() << " ";
		preOrderUtil(node->left);
		preOrderUtil(node->right);
	}
}

// A utility function to print inorder traversal of the tree.
template <class Type>
void inOrderUtil(AVLNode<Type *> *node)
{
	if (node)
	{

		inOrderUtil(node->left);
		cout << node->key->getTitle() << " ";
		inOrderUtil(node->right);
	}
}

// A utility function to print postorder traversal of the tree.
template <class Type>
void postOrderUtil(AVLNode<Type *> *node)
{
	if (node)
	{
		postOrderUtil(node->left);
		postOrderUtil(node->right);
		cout << node->key->getTitle() << " ";
	}
}

class AVLMoviesByTitle
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
		if (balance > 1 && key->getTitle()  < node->left->key->getTitle() )
			return rightRotate(node);

		// Right Right Case
		if (balance < -1 && key->getTitle()  > node->right->key->getTitle() )
			return leftRotate(node);

		// Left Right Case
		if (balance > 1 && key->getTitle()  > node->left->key->getTitle() )
		{
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

		// Right Left Case
		if (balance < -1 && key->getTitle()  < node->right->key->getTitle() )
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

class AVLMoviesByRating
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
		if (key->getContentRating().compare(node->key->getContentRating())<0)
			node->left = insertNode(node->left, key);
		else if (key->getContentRating().compare( node->key->getContentRating())>0)
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
		if (balance > 1 && key->getContentRating()  < node->left->key->getContentRating() )
			return rightRotate(node);

		// Right Right Case
		if (balance < -1 && key->getContentRating()  > node->right->key->getContentRating() )
			return leftRotate(node);

		// Left Right Case
		if (balance > 1 && key->getContentRating()  > node->left->key->getContentRating() )
		{
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

		// Right Left Case
		if (balance < -1 && key->getContentRating()  < node->right->key->getContentRating() )
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

class AVLActors
{
	AVLNode<ActorNode *> *root = NULL;

public:
	void insert(ActorNode *key)
	{
		root = insertNode(root, key);
	}

	// Recursive function to insert a key in the subtree rooted with AVLNode and
	// returns the new root of the subtree.
	AVLNode<ActorNode *> *insertNode(AVLNode<ActorNode *> *node, ActorNode *key)
	{
		/* 1. Perform the normal BST insertion */
		if (node == NULL)
			return (newAVLNode(key));
		if (key->getName().compare(node->key->getName())<0)
			node->left = insertNode(node->left, key);
		else if (key->getName().compare( node->key->getName())>0)
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
		if (balance > 1 && key->getName()  < node->left->key->getName() )
			return rightRotate(node);

		// Right Right Case
		if (balance < -1 && key->getName()  > node->right->key->getName() )
			return leftRotate(node);

		// Left Right Case
		if (balance > 1 && key->getName()  > node->left->key->getName() )
		{
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

		// Right Left Case
		if (balance < -1 && key->getName()  < node->right->key->getName() )
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

	void preOrderUtil(AVLNode<ActorNode*> *node){
		if (node)
	{
		cout << node->key->getName() << " ";
		preOrderUtil(node->left);
		preOrderUtil(node->right);
	}
	}
	
};



// Driver Code
int main()
{
	// AVLMoviesByTitle avl;
	AVLMoviesByRating avl;
	AVLActors actors;
	/* Constructing tree given in
	the above figure */
	Movie m;
	m.setTitle("c");
	m.setTitleYear(2020);
	m.setContentRating("c");
	Movie m1;
	m1.setTitle("a");
	m1.setTitleYear(2022);
	m1.setContentRating("a");
	Movie m2;
	m2.setTitle("b");
	m2.setTitleYear(2019);
	m2.setContentRating("b");

	avl.insert(&m);
	avl.insert(&m1);
	avl.insert(&m2);

	ActorNode a ("a");
	actors.insert(&a);
	actors.preOrder();


	cout << "Preorder traversal of the constructed AVL tree is \n";
	// avl.preOrder();
	// cout << endl;
	// avl.inOrder();
	// cout << endl;
	// avl.postOrder();

	// string a = "2020";
	// string b= "2022";
	// cout <<a>(b)<<endl;

	return 0;
}