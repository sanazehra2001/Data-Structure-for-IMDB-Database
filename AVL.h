#ifndef AVL_H
#define AVL_H

#include "Movie.h"
#include "Actor.h"
#include "Director.h"

class Actor;
class Director;

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


class MovieAVL
{
	AVLNode<Movie *> *root = NULL;

public:
	void insert(Movie *);
	AVLNode<Movie *> *insertNode(AVLNode<Movie *> *, Movie *);
	Movie * search(string , AVLNode<Movie *> *, forward_list<Movie *>*);
	forward_list<Movie *> search(string);
	bool isEmpty();
	void traverse();
};

class ActorAVL
{
	AVLNode<Actor *> *root = NULL;

public:
	void insert(Actor *);
	AVLNode<Actor *> *insertNode(AVLNode<Actor *> *, Actor *);
	Actor *search(string);
	bool isEmpty();
	void traverse();
};

class DirectorAVL
{
	AVLNode<Director *> *root = NULL;

public:
	void insert(Director *);
	AVLNode<Director *> *insertNode(AVLNode<Director *> *, Director *);
	Director *search(string);
	bool isEmpty();
};

#endif