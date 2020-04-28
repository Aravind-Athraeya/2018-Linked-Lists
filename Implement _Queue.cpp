#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include <queue>
using namespace std;

// http://btechsmartclass.com/data_structures/queue-using-linked-list.html
typedef struct ListNode
{
	int value;
	struct ListNode *header;
	struct ListNode *Next;
	struct ListNode *tailer;
}node;



void Queue(node** head_ref, int new_data)
{
	node* new_node = new node();	
	new_node->value = new_data;	


	if((*head_ref)->tailer == NULL)
	{ 
		 (*head_ref)->header = (*head_ref)->tailer = new_node; // Mark both head and tail
		
		//seperately kepe track of head and tail
	}
	else
	{
		(*head_ref)->tailer->Next = new_node; //Add new node as tail
		(*head_ref)->tailer = new_node; // Mark it as tail
	  
	}
	
	




}




void Dequeue(node** head_ref)
{
	node *temp = (*head_ref)->header->Next;
	free((*head_ref));
	(*head_ref) = temp;

}

	



int main()
{
	node *head = new node();
	head->header = head->tailer = NULL;
	Queue(&head, 2);
	Queue(&head, 4);
	Queue(&head, 8);
	Queue(&head, 10);
	Dequeue(&head);
	Dequeue(&head);
    return 0;

}
