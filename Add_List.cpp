#include <iostream>
#include<conio.h>
#include <string>
#include <sstream>
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


template <typename T>
string NumberToString(T pNumber)
{
	ostringstream oOStrStream;
	oOStrStream << pNumber;
	return oOStrStream.str();
}

template <typename T>
string charToString(T mychar)
{
	ostringstream oOStrStream;
	string target;
	oOStrStream << mychar;
	return oOStrStream.str();
}


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

void Add(node* onetest, node* testtwo)
{
	node* newnode = NULL;
	string carry = "0";
	int carryInt = 0;

	while(onetest || testtwo)
	{		
		int  oneString = 0;
		int  TwoString = 0;
		
		if(onetest)
		{
			oneString = atoi(onetest->value.c_str());
			onetest = onetest->Next;
		}
		
		if (testtwo)
		{
			TwoString = atoi(testtwo->value.c_str());
			testtwo = testtwo->Next;
		}

	    carryInt = atoi(carry.c_str());
	
	   
		int Final = oneString + TwoString + carryInt;

		//Get First digit for carry
		string Getcarry = NumberToString(Final);
		
		if (Getcarry.length() > 1)
		{
			push(&newnode, charToString(Getcarry[1]));
			carry = charToString(Getcarry[0]);
		}
		else
		{
			push(&newnode, Getcarry);
			carry = "0";
		}

        
		

	}

	 
}

int main()
{
	node *head1 = NULL;
	node *head2 = NULL; //64957
	push(&head1, "6");
	push(&head1, "4");
	push(&head1, "9");
	push(&head1, "5");
	push(&head1, "7");
//	push(&head2, "3"); 
	push(&head2, "4");
	push(&head2, "8");
	Add(head1,head2);
	return 0; 

}

		