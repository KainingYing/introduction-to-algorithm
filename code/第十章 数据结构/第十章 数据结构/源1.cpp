#include <iostream>
using namespace std;

#define MAX_SIZE 10
int keys[MAX_SIZE];
int count = 8;

struct tree_node
{
	int key;
	tree_node *left;
	tree_node *right;
	tree_node *parent;
};
struct tree
{
	tree_node* root;
};
void store(int key)
{
	keys[count++] = key;
}

void print_node(tree_node* t)
{
	store(t->key);
	if (t->left)
		print_node(t->left);
	if (t->right)
		print_node(t->right);
}
void print_node_version2(tree_node* t)
{
	tree_node *stack[MAX_SIZE];
	int count =0 ;
	stack[count++] = t;
	while (count)
	{
		t = stack[--count];
		store(t->key);
		if (t->left)
			stack[count++] = t->left;
		if (t->right)
			stack[count++] = t->right;
	}

}
int main()
{
	


	return 0;
}