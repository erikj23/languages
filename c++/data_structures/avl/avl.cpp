
#ifndef AVL_CPP
#define AVL_CPP

#include "avl.h"

// private --------------------------------------------------------------------




// public ---------------------------------------------------------------------
	template <typename type>
	int avl<type>::height(node* subtree) const
	{
		return 0;
	}
	
	int avl<type>::max(int left, int right) const
	{
		return 0;
	}
	
	template <typename type>
	node* avl<type>::rotate_left(node* x)
	{
		node* y = x->right;
		node* temp = y->left;
		
		y->left = x;
		x->right = temp;
		
		x->height = this->max(this->height(x->left), this->height(x->right))
			+ 1;
		y->height = this->max(this->height(y->left), this->height(y->right)) 
			+ 1;
		
		return y;
	}

	template <typename type>
	node* avl<type>::rotate_right(node* x)
	{
		node* y = x->left;
		node* temp = y->right;
		
		y->right = x;
		x->left = temp;
		
		x->height = this->max(this->height(x->left), this->height(x->right))
			+ 1;
		y->height = this->max(this->height(y->left), this->height(y->left))
			+ 1;
		
		return y;
	}

#endif
