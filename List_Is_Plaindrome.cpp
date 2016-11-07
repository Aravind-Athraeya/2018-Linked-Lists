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

void IsPlaindrome(string str)
{
	bool IsPal = false;
	int length = str.length;
	for (int i = 0; i < length /2 ; i++)
	{
		
			if (str[i] == str[length - i - 1])
			{
				IsPal = true;
			}
			else
			{
				IsPal = false;
				break;
			}
		
	}

	cout << IsPal;
}

int main()
{
	node *head2 = NULL;
	push(&head2, "a");
	push(&head2, "dcb");
	push(&head2, "d");
	push(&head2, "bc");
	push(&head2, "a");
	string reverseTest = GetStringFromList(head2);
	IsPlaindrome(reverseTest);
	return 0; 

}

	