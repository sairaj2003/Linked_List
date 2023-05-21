#include <stdio.h>
#include <stdlib.h>


struct node
{
	int data;
	struct node *addrnxt;
}*start,*curr,*newnode;

void create(int);
void display();

int main() 
{
	int n;
	int ch;
	start=NULL;   //	Initially our 'start' is NULL means linked list is empty
	do
	{
		printf("\nEnter any number:");
		scanf("%d",&n);
			
		create(n);
		display();
		printf("\n\nDo you want to continue:(1:yes other:No)");
		scanf("%d",&ch);
		printf("\n-----------------------------------------------------------\n");
	}while(ch==1);
	return 0;
}

void create(int n)
{
	newnode=malloc(sizeof(struct node));  //memory is allocated
	newnode->data=n;
	newnode->addrnxt=NULL;
	
	if(start==NULL)
	{
		start=newnode;
	}
	else
	{
		//Now we are finding last node in linked list:
		curr=start;
		
		while(curr->addrnxt != NULL)
		{
			curr=curr->addrnxt;    //This is nothing but like increment now our curr is not start now current is incremented
		}
		curr->addrnxt=newnode;
	}
}

void display()
{
	if(start==NULL)
	{
		printf("\nLinked List is empty...");
	}
	else
	{
		curr=start;
		printf("\n The Linked List is:\n");
		while(curr != NULL)
		{
			printf("| %d | %u | ===> ",curr->data,curr->addrnxt);
			curr=curr->addrnxt;
		}
	}
	
}

/*
		1.The structure node represents a node in the linked list. It contains an integer data value and a 
		  pointer to the next node (addrnxt).
		  
		2.The create function is used to create a new node with the given data value. It allocates memory for
		  the new node using malloc and initializes its data and next pointer. If the linked list is empty 
		  (start is NULL), the new node becomes the start of the list. Otherwise, it traverses the list to find
		  the last node and adds the new node after it.
		  
		3.The display function is used to print the contents of the linked list. It traverses the list from the 
		  start node and prints the data value and the address of the next node for each node.
		  
		4.In the main function, the program repeatedly prompts the user to enter a number. It calls the create 
		  function to create a new node with the entered number and then calls the display function to print the
		  updated linked list. It asks the user if they want to continue, and the loop continues as long as the 
		  user enters 1.
		
		5.The program exits when the user enters any number other than 1.
*/
