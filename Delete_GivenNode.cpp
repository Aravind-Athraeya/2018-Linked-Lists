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


//free
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



void deletenode(node**  test)
{

	node* ftest = *(test);
	node* temp = ftest->Next;
	free(*(test));
	*(test) = temp;
	
}

int main()
{
	node *head2 = NULL;
	push(&head2, "0");
	push(&head2, "2");
	push(&head2, "6");
	push(&head2, "11");
	push(&head2, "3");

	deletenode(&(head2->Next->Next));

	return 0; 

}

		
