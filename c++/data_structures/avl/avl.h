
#ifndef AVL_H
#define AVL_H

template <typename type>
class avl
{
private:
	
public:
	struct node
	{
		type data;
		node* left;
		node* right;
		int height;
	}; 
	
	int height(node*) const;
	int max(int, int) const;
	node* rotate_left(node*);
	node* rotate_right(node*);
};

#include "avl.cpp"

#endif
