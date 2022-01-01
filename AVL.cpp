#include "AVL.h"

class Movie;
class Actor;
class Director;

void MovieAVL::insert(Movie *key)
{
	root = insertNode(root, key);
}

AVLNode<Movie *> *MovieAVL::insertNode(AVLNode<Movie *> *node, Movie *key)
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
	if (balance > 1 && key->getTitle() < node->left->key->getTitle())
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key->getTitle() > node->right->key->getTitle())
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key->getTitle() > node->left->key->getTitle())
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key->getTitle() < node->right->key->getTitle())
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) AVLNode pointer */
	return node;
}

void ActorAVL::insert(Actor *key)
{
	root = insertNode(root, key);
}

AVLNode<Actor *> *ActorAVL::insertNode(AVLNode<Actor *> *node, Actor *key)
{
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return (newAVLNode(key));
	if (key->getName().compare(node->key->getName()) < 0)
		node->left = insertNode(node->left, key);
	else if (key->getName().compare(node->key->getName()) > 0)
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
	if (balance > 1 && key->getName() < node->left->key->getName())
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key->getName() > node->right->key->getName())
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key->getName() > node->left->key->getName())
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key->getName() < node->right->key->getName())
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) AVLNode pointer */
	return node;
}

void DirectorAVL::insert(Director *key)
{
	root = insertNode(root, key);
}

AVLNode<Director *> *DirectorAVL::insertNode(AVLNode<Director *> *node, Director *key)
{
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return (newAVLNode(key));
	if (key->getName().compare(node->key->getName()) < 0)
		node->left = insertNode(node->left, key);
	else if (key->getName().compare(node->key->getName()) > 0)
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
	if (balance > 1 && key->getName() < node->left->key->getName())
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key->getName() > node->right->key->getName())
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key->getName() > node->left->key->getName())
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key->getName() < node->right->key->getName())
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) AVLNode pointer */
	return node;
}
