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


//easy
void Push(node** head_ref, int new_data)
{
	node* new_node = new node();
	new_node->value = new_data;



	/* link the old list off the new node */
	new_node->Next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;


}






int GetConsoloflist(node * lst)
{
	int consol = 0;

	while (lst != NULL)
	{
		consol = consol * 10 + lst->value;
		lst = lst->Next;
	}




	return consol;
}


node* MakeList(int digit)
{
	int tempmod , tempdiv = digit;
	node * lst = NULL;
	while (tempdiv > 0)
	{
		 
		tempmod = tempdiv % 10;
		Push(&lst, tempmod);
		tempdiv = tempdiv / 10;

	}
	return lst;

}


int main()
{
	node *lstOne = NULL;
	node *lndTwo = NULL;
	Push(&lstOne, 0);
	Push(&lstOne, 0);
	Push(&lstOne, 1);
	Push(&lndTwo, 1);
	int lstOneSum = GetConsoloflist(lstOne);
	int lstTwoSum = GetConsoloflist(lndTwo);
	int final;
	if (lstOneSum > lstTwoSum)
	{
		final = lstOneSum - lstTwoSum;
	}
	else
	{
		final = lstTwoSum - lstOneSum;
	}

	node * FinalOne = MakeList(final);
	return 0;

}



