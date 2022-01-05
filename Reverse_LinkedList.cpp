#include <iostream>
#include <string> 
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



void Push(node** head_ref, int new_data)
{
	node* new_node = new node();	
	new_node->value = new_data;	

	

	/* link the old list off the new node */
	new_node->Next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;


}





	
 void reverse(node ** lst)
{
	 node* prev = NULL;
	 node* curr = (*lst);
	 node* next;
	 while (curr != NULL)
	 {

		 next = curr->Next;
		 curr->Next = prev; // REfer the pointer to back
		 prev = curr;  // Move previous to current one step
		 curr = next;  // move current to next one step
	 }
	 *lst = prev;

}


int main()
{
	node *lstOne = NULL;
	//node *lndTwo = NULL;
	Push(&lstOne, 1);
	Push(&lstOne, 2);
	Push(&lstOne, 3);
	Push(&lstOne, 4);
	reverse(&lstOne);
	node *ldstOne = lstOne;

	return 0;

}






