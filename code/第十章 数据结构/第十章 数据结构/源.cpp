#include <iostream>
using namespace std;
struct node_t
{
	int key;
	node_t *next;
};
struct list_t
{
	node_t nil;
};
void init_list(list_t *list)
{
	list->nil.key = 0;
	list->nil.next = &(list->nil);
}
void destory_list(list_t *list) //销毁链表
{
	node_t *node = list->nil.next;
	node_t *next;
	while (node != &(list->nil))
	{
		next = node->next;
		free(node);
		node = next;
	}
}
void insert(list_t *list, int key)//插入到链表的开端
{
	node_t * newlist = new node_t;
	newlist->key = key;
	newlist->next = list->nil.next;
	list->nil.next = newlist;
}
node_t *search(list_t *list, int key)
{
	node_t *x = list->nil.next;
	list->nil.key = key;
	while (x->key != key)
		x = x->next;
	return x;
}
void delete_node(list_t *list, int key)
{
	node_t *node = &(list->nil);
	while (node->next!= &(list->nil))//不是最后一个元素
	{
		if (node->next->key == key)
		{
			node_t * old_delete = node->next;
			node->next = node->next->next;
			delete old_delete;
		}
		else
			node = node->next;
	}
}
int main()
{

	return 0;
}