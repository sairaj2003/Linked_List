#include <stdio.h>
#include <stdlib.h>


struct node
{
	int data;
	struct node *addrnxt;
}*start,*last,*curr,*newnode;

int create(int);
void addnextnode(int);
void display();
int searchnode(int);
void insertBeg(int);
void insertMiddle(int,int);
int deletefirst();

int main() 
{
	int n;
	int ch;
	int elm,pos;
	int s,flag=0;
	start=NULL;   //	Initially our 'start' is NULL means linked list is empty
	do
	{
		printf("\n1.Create\n2.add node\n3.Display\n4.Search node\n5.Insert at Begining\n6.Insert at Middle\n7.Delete first");
		printf("\nEnter your choice..");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("\nEnter any number:");
				scanf("%d",&n);
				create(n);
				display();
				break;
				
			case 2:
				printf("\nEnter next node:");
				scanf("%d",&n);
				addnextnode(n);
				break;
				
			case 3:
				display();
				break;
				
			case 4:
				printf("\nEnter element to search:");
				scanf("%d",&s);
				flag=searchnode(s);
				if(flag>0)
				{
					printf("\nElement is found at %d location...",flag);
				}
				else
				{
					printf("\nElemeent not found");
				}
				break;
				
			case 5:
				printf("\nEnter any number to insert in linked list:");
				scanf("%d",&elm);
				insertBeg(elm);
				break;
				
			case 6:
				printf("\nEnter Element you want to insert:");
				scanf("%d",&elm);
				printf("\nEnter Position:");
				scanf("%d",&pos);
				insertMiddle(elm,pos);
				break;
				
			case 7:
				deletefirst(n);
				printf("\n %d is successfully deleted from linked list",n);
				break;
				
		}	
		printf("\n\nDo you want to continue:(1:yes other:No)");
		scanf("%d",&ch);
		printf("\n-----------------------------------------------------------\n");
	}while(ch==1);
	return 0;
}

int create(int n)
{
	newnode=malloc(sizeof(struct node));  //memory is allocated
	newnode->data=n;
	newnode->addrnxt=NULL;
	
	if(start==NULL)
	{
		start=newnode;
		last=newnode;
	}
	return newnode;
//	else
//	{
//		//Now we are finding last node in linked list:
//		curr=start;
//		
//		while(curr->addrnxt != NULL)
//		{
//			curr=curr->addrnxt;    //This is nothing but like increment now our curr is not start now current is incremented
//		}
//		curr->addrnxt=newnode;
//	}
}

void addnextnode(int n)
{
	last->addrnxt=create(n);   //create() func will return value of newnode
	last=last->addrnxt;
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
int searchnode(int s)
{
	int cnt=0;   //it is  used to count how many times loop execute
	int flag=0;
	
	if(start==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		curr=start;
		while(curr!=NULL)
		{
			cnt++;
			if(curr->data==s)
			{
				flag=cnt;
				break;
			}
			curr=curr->addrnxt;
		}
	}
	return flag;
}
void insertBeg(int elm)
{
//	newnode=malloc(sizeof(struct node));
//	newnode->data=elm;
//	newnode->addrnxt=start;   
//	start=newnode;

	curr=create(elm);
	curr->addrnxt=start;
	start=curr;
	printf("\nElement Inserted Successfully...");
}

void insertMiddle(int elm,int pos)
{
	int cnt=1;
	curr=start;
	while(cnt<pos-1)
	{
		curr=curr->addrnxt;
		cnt++;
	}
	//from above step we got location here
	//now insert node after current node
	
	//	newnode=malloc(sizeof(struct node));
	//	newnode->data=elm;
	//	newnode->addrnxt=curr->addrnxt;
	//	curr->addrnxt=newnode;
	newnode=create(elm);
	newnode->addrnxt=curr->addrnxt;
	curr->addrnxt=newnode;
	
	
	printf("\nNode inserted successfully....");
}
int deletefirst()
{
	int n;
	curr=start;
	start=start->addrnxt;
	curr->addrnxt=NULL;
	n=curr->data;
	free(curr);
	return n;
	
//	1.Declare an integer variable n to store the data value of the deleted node.
//	2.Set the curr pointer to point to the start node, which represents the first node in the linked list.
//	3.Update the start pointer to point to the next node in the list, effectively removing the first node from the list.
//	4.Set the addrnxt (presumably the "next" pointer) of the curr node to NULL to remove its connection to the next node.
//	5.Assign the data value of the curr node to the variable n.
//	6.Free the memory occupied by the curr node using the free() function.
//	7.Return the value of n, which represents the data value of the deleted node.
		
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
