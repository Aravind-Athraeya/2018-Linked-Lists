#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include <queue>
using namespace std;

 
typedef struct ListNode
{
	int value;
	struct ListNode *Next;
}node;



// create a new node
node* getNewNode(int value) {

    node *new_node = new node;
	new_node->value = value;
	new_node->Next = NULL;	
	return new_node;
}
// create the tree
node *createList() {
	node *root = getNewNode(1);
	root->Next = getNewNode(2);
	root->Next->Next = getNewNode(3);
	root->Next->Next->Next = getNewNode(4);
	return root;
}


//assuming root lies in the given range
int CountList(node *ptr1)
 {
	if (ptr1 == NULL)
	{
		return 0 ;
	}
	
	int count = CountList(ptr1->Next);
	return count + 1;

}


int main()
{
	node *head = NULL;
	head = createList();
    int count = CountList(head);
	return 0;

}


