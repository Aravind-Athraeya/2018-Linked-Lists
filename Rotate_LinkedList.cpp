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

node* Rotate(node* head, int K) {
	node *curr = head;
	node *nexter;
	int count = 1;
	while (count < K && curr != NULL)
	{
		curr = curr->Next;
		count++;
	}

	node *kthNode = curr;

	while (curr->Next != NULL)
		curr = curr->Next;


	curr->Next = head;


	head = kthNode->Next;

	kthNode->Next = NULL;




	return head;
}

// Make amaali,and cut



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

    push(&head, 60);
	push(&head, 50);
    push(&head, 40);
	push(&head, 30);
	push(&head, 20);
	push(&head, 10);
	node * nsew = Rotate(head,4);
	printList(nsew);
	return 0;

}

