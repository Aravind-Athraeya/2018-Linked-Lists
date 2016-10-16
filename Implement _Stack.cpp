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




void pop(node** head_ref)
{
		*head_ref = (*head_ref)->Next;
	


}

int main()
{
	node *head = NULL;
	push(&head, 2);
	push(&head, 4);
	push(&head, 8);
	push(&head, 10);
	pop(&head);
    return 0;

}