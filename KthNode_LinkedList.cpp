#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include <queue>
using namespace std;

//
typedef struct ListNode
{
	int value;
	struct ListNode *Next;
	struct ListNode *Prev;
}node;



void push(node** head_ref, int new_data)
{
	/* allocate node */
	node* new_node = new node();

	/* put in the data  */
	new_node->value = new_data;

	/* link the old list off the new node */
	new_node->Next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}



int CountList(node *nodex)
{
	int count = 0;
	while (nodex != NULL)
	{
		count = count + 1 ;
		nodex = nodex->Next;
	}

	return count;
}

node* deletenode(node* head, int K) {

	if (head == NULL || K == 1) return NULL;

	 node *prev = head;
	 node *curr = head->Next;

	int index = 1;

	while (curr != NULL)
	{
		if (index % K == 0)
		{
			// remove current node and advance pointers
			prev->Next = curr->Next;
			curr = curr->Next;
		}
		else
		{
			// otherwise just advance pointers
			prev = curr;
			curr = curr->Next;
		}

		++index;
	}

	return head;
}





void printList(node *nodex)
{
	while (nodex != NULL)
	{
		cout << nodex->value;
		nodex = nodex->Next;
	}
}





int main()
{
	node *head = NULL;
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	node * nsew = deletenode(head, 2);
	printList(nsew);
	return 0;

}

