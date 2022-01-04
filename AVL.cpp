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

forward_list<Movie *> MovieAVL::search(string title)
{
	forward_list<Movie *> movies;
	search(title, root, &movies);
	return movies;
}

/* 
	searches the title in the avl (not necessarily complete title)
   	return a list of movies having matching title
*/
Movie *MovieAVL::search(string title, AVLNode<Movie *> *ptr, forward_list<Movie *> *movies) // errors to be fixeds
{
	string avlTitle;
	while (ptr)
	{
		avlTitle = ptr->key->getTitle();		 // title in avl node
		if (avlTitle.length() >= title.length()) // searching substring
		{
			if (title > avlTitle.substr(0, title.length()))
				ptr = ptr->right;
			else if (title < avlTitle.substr(0, title.length()))
				ptr = ptr->left;
			else
			{
				(*movies).emplace_front(ptr->key);
				search(title, ptr->right, movies);
				search(title, ptr->left, movies);
				return ptr->key;
			}
		}
		else
		{ // normal avl search
			if (title > avlTitle)
				ptr = ptr->right;

			else if (title < avlTitle)
				ptr = ptr->left;
		}
	}
	return NULL;
}

bool MovieAVL::isEmpty()
{
	return root == NULL;
}

// A utility function to print inorder traversal of the MovieAVL.
void inOrderUtil(AVLNode<Movie *> *node)
{
	if (node)
	{
		inOrderUtil(node->left);
		node->key->display();
		cout << endl
			 << endl;
		inOrderUtil(node->right);
	}
}

void MovieAVL::traverse()
{
	inOrderUtil(root);
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

Actor *ActorAVL::search(string name)
{
	AVLNode<Actor *> *ptr = root;
	while (ptr)
	{
		if (name > ptr->key->getName())
			ptr = ptr->right;
		else if (name < ptr->key->getName())
			ptr = ptr->left;
		else
			return ptr->key;
	}
	return NULL;
}

bool ActorAVL::isEmpty()
{
	return root == NULL;
}

void inOrderUtil(AVLNode<Actor *> *node)
{
	if (node)
	{
		inOrderUtil(node->left);
		cout << node->key->getName() << endl;
		inOrderUtil(node->right);
	}
}

void ActorAVL::traverse()
{
	inOrderUtil(root);
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

Director *DirectorAVL::search(string name)
{
	AVLNode<Director *> *ptr = root;
	while (ptr)
	{
		if (name > ptr->key->getName())
			ptr = ptr->right;
		else if (name < ptr->key->getName())
			ptr = ptr->left;
		else
			return ptr->key;
	}
	return NULL;
}

bool DirectorAVL::isEmpty()
{
	return root == NULL;
}
