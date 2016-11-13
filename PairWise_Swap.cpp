#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include <queue>
using namespace std;


typedef struct ListNode
{
	string  value;
	struct ListNode *Next;
	struct ListNode *Prev;
}node;



void push(node** head_ref, string  new_data)
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


string GetStringFromList(node* test)
{
	string mmeh = "";
	while(test != NULL)
	{
		mmeh = mmeh + test->value;
		test = test->Next;
	}

	return mmeh;

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

void thorughSwap(node** test)
{


	if (*(test) == NULL || (*test)->Next == NULL)
		return ;

	node* rest = (*test)->Next->Next;
	node* curr = (*test);
	node* next = curr->Next;
	string temp = curr->value;
	curr->value = next->value;
	next->value = temp;
	thorughSwap(&rest);


	
	 
}

int main()
{
	node *head2 = NULL;
	push(&head2, "6");
	push(&head2, "5");
	push(&head2, "4");
	push(&head2, "3");
	push(&head2, "2");
	push(&head2, "1"); 

	thorughSwap(&head2);
	return 0; 

}

		