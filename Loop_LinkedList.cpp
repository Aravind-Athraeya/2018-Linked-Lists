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

bool detectloop(node* head) {

	node* slowPntr = head;
	node* fastPntr = head;

	while (slowPntr && fastPntr && fastPntr->Next)
	{
	
		slowPntr = slowPntr->Next;
		fastPntr = fastPntr->Next->Next;


		if (slowPntr == fastPntr)
		{
			return true;
		}
	
	}


	return false;



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
	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 10);

	/* Create a loop for testing */
//	head->Next->Next->Next->Next = head;
	detectloop(head);
	return 0;

}

