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

node* RemoveDuplicates(node* head) {

	//	if (head == NULL || K == 1) return NULL;

	node *prev = head;
	node *nexter;

	while (prev->Next != NULL)
	{
		if (prev->value == prev->Next->value)
		{
			nexter = prev->Next->Next;
			free(prev->Next);
			prev->Next = nexter;


		}
		else {
		prev = prev->Next;
	}
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




/* Function to remove duplicates from a 
   unsorted linked list */
void removeDuplicateshash(struct Node *start) 
{ 
    // Hash to store seen values 
    unordered_set<int> seen; 
  
    /* Pick elements one by one */
    struct Node *curr = start; 
    struct Node *prev = NULL; 
    while (curr != NULL) 
    { 
        // If current value is seen before 
        if (seen.find(curr->data) != seen.end()) 
        { 
           prev->next = curr->next; 
           delete (curr); 
        } 
        else
        { 
           seen.insert(curr->data); 
           prev = curr; 
        } 
        curr = prev->next; 
    } 
} 

int main()
{
	node *head = NULL;
	push(&head, 11);
	//push(&head, 5;
	push(&head, 11);
	push(&head, 11);
	push(&head, 23);
	push(&head, 43);
	push(&head, 43);
	push(&head, 60);
	node * nsew = RemoveDuplicates(head); //removeDuplicateshash(head);  // Using hashing
	printList(nsew);
	return 0;

}

