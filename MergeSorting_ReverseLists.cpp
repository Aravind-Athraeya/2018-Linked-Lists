#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include <queue>
#include "Sorting.h"
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
		count = count + 1;
		nodex = nodex->Next;
	}

	return count;
}

void SplitList(node* head, node** split_a, node** split_b) {

	node* slowPntr = head;
	node* fastPntr = head;
	if (slowPntr->Next->Next == NULL)
	{
		*split_a = slowPntr;
		*split_b = slowPntr->Next;
		slowPntr->Next = NULL;
	}
	else
	{ 
	while (fastPntr && fastPntr->Next)
	{

		slowPntr = slowPntr->Next;
		fastPntr = fastPntr->Next->Next;
		 

	}


	*(split_a) = head;
	*(split_b) = slowPntr->Next;
	slowPntr->Next = NULL;
	}

}

node* MergePart(node* a, node*  b) {

	node*  temp = NULL;


	/* Base cases */
	if (a == NULL)
		return(b);
	else if (b == NULL)
		return(a);


	if (a->value <= b->value)
	{
	
	temp = a;
	temp->Next = MergePart(a->Next, b);
    }
	else
	{ 
		temp = b;
	    temp->Next = MergePart(a, b->Next);
	}


	return temp;



}

void MergeSort(node** head1) {
	node* head = *head1;
	node* a;
	node* b;

	if ((head == NULL) || (head->Next == NULL))
	{
		return;
	}


	SplitList(head , &a , &b);
	MergeSort(&a);
	MergeSort(&b);




	*(head1) = MergePart(a,b);

//	return MergedSortedList;
}



void Reverse(node ** head)
{
	node* prev = NULL;
	node* curr = (*head);
	node* next;


	while (curr != NULL)
	{    
		next = curr->Next;
		curr->Next = prev;
		prev = curr;
		curr = next;
	}

	(*head) = prev;

}


int main()
{
	node *head1 = NULL;
	node *head2 = NULL;
	push(&head1, 1);
	push(&head1, 1);
	push(&head2, 4);
	push(&head2, 2);

	node* reverseTest = MergePart(head1, head2);
	Reverse(&reverseTest);
	return 0; 

}

	