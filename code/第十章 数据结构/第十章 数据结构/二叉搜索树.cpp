#include <iostream>
#include <stack>
using namespace std;
struct BST_node {
	int key;
	BST_node *left;
	BST_node *right;
};
struct BST
{
	BST_node *head;
};
void inorder_tree_walk(BST tree)
{
	inorder_recursion(tree.head);
}
void inorder_recursion(BST_node*node)
{
	if (node != NULL)
	{
		inorder_recursion(node->left);
		cout << node->key << " ";
		inorder_recursion(node->right);
	}
}
void inoder_nonrecur(BST tree)
{
	//��ջʵ�ּ򵥵��������
	BST_node* T = tree.head;
	stack<BST_node*> s;
	while (T || s.empty())
	{
		while (T)
		{
			s.push(T);
			T = T->left;
		}
		T = s.top();
		cout << T->key;
		s.pop();
		T = T->right;
	}
	 
}
BST_node* tree_search(BST_node* node, int key)
{
	//�򵥵��õݹ�ʵ������
	if ((node == NULL) || node->key == key)
		return node;
	else if (node->key < key)
		return tree_search(node->left, key);
	else
		return tree_search(node->right, key);
}
BST_node* tree_search_nonrecursion(BST_node* node, int key)
{
	/*while (node != NULL)
	{
		if (node->key = key)
			return node;
		else if (node->key < key)
			node = node->left;
		else
			node = node->right;
	}
	return NULL;*/
	//���������ϵİ汾����������
	while (node != NULL && node->key != key)
	{
		if (node->key < key)
			node = node->left;
		else
			node = node->right;
	}
	return node;
}
BST_node* tree_minimum(BST_node* node)
{
	if (node == NULL||node->left==NULL)
		return node;
	else
	{
		return tree_minimum(node->left);
	}
}
BST_node* tree_maximum(BST_node* node)
{
	if (node == NULL || node->right == NULL)
		return node;
	else
	{
		return tree_maximum(node->right);
	}
}
BST_node* tree_predecessor(BST_node* node)
{
	if (node->left != NULL)
		return tree_maximum(node-> left);
	/*BST_node y = x.p;*/
	//Ҫ�õ�˫�׽ڵ㣬���ڿӣ���д�ˡ�

}
int main()
{


	return 0;
}