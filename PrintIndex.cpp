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
	root->Next->Next->Next->Next = getNewNode(657);
	root->Next->Next->Next->Next->Next = getNewNode(76);
	return root;
}


//assuming root lies in the given range
void GetIndex(node *ptr1 , int value, int getindex)
 {
	if (ptr1 == NULL)
	{
		return ;
	}
	
	if (value == getindex)
	{
		cout << ptr1->value;
		return;
	}

	GetIndex(ptr1->Next, value+ 1, getindex);


}


int main()
{
	node *head = NULL;
	head = createList();
	int indexvalue = 1;
	int getindex =  5;
    GetIndex(head , indexvalue, getindex);
	return 0;

}


