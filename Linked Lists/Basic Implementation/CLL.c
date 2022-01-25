#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
typedef struct node NODE;
NODE *header;

	
void create_CLL()
{
	NODE *new, *cptr;
		char ch;	
	new = (NODE*)malloc(sizeof(NODE));
	printf("\nEnter the data of 1st node: ");
	scanf("%d", &new->data);
		cptr = new;
	header->link = new;
	new->link = header;
		do
	{
		new = (NODE*)malloc(sizeof(NODE));
		printf("\nEnter the data for the next node: ");
		scanf("%d", &new->data);
				new->link = header;
		cptr->link = new;
		cptr = new;
		
		printf("\nDo you want to continue (Y/N) ?   ");
		scanf(" %c", &ch);
	}
		while ((ch == 'Y') || (ch == 'y'));		
}


void traverse_CLL()
{
	if (header->link == header)
		printf("\nList is Empty");
		else
	{
		NODE *ptr;
				ptr = header->link;		
		while (ptr != header)
		{
			printf("%d\t", ptr->data);
				
			ptr = ptr->link;
		}
	}
}


void insert_beg_CLL(int item)
{
	NODE *new, *ptr;
			
	new = (NODE*)malloc(sizeof(NODE));
				
	new->data = item;
		ptr = header->link;	
	while (ptr->link != header)
		ptr = ptr->link;
		new->link = header->link;
	ptr->link = header;
	header->link = new;
		printf("\nThe Circular Linked List after insertion is,\n");
	traverse_CLL();
}

void insert_end_CLL(int item)
{
	NODE *new, *ptr;
				
	new = (NODE*)malloc(sizeof(NODE));
				
	new->data = item;
		ptr = header->link;	
	while (ptr->link != header)
		ptr = ptr->link;
		
	ptr->link = new;
	new->link = header;
		printf("\nThe Circular Linked List after insertion is,\n");
	traverse_CLL();
}

void insert_pos_CLL(int item, int key)
{
	NODE *new, *ptr;
					
	new = (NODE*)malloc(sizeof(NODE));
				
	new->data = item;
		ptr = header->link;	
	while ((ptr->data != key) && (ptr->link != header))
		ptr = ptr->link;
		
	if (ptr->link == header)
		printf("\nNo node with data %d exists, insertion is not possible", key);
		
	else
	{
		new->link = ptr->link;
		ptr->link = new;
				printf("\nThe Circular Linked List after insertion is,\n");
		traverse_CLL();
	}
}

void del_beg_CLL()
{
	if (header->link == header)
		printf("\nList is Empty, Deletion is not possible");
		else
	{	
		NODE *ptr;
		
		ptr = header->link;
		header->link = ptr->link;
			
		printf("\nThe element being deleted is %d", ptr->data);			
		free(ptr);
			
		printf("\n\nThe Circular Linked List after deletion is,\n");
		traverse_CLL();
	}		
}

void del_end_CLL()
{
	if (header->link == header)
		printf("\nList is Empty, Deletion is not possible");
		else if ((header->link)->link == header)
	{
		printf("\nThe element being deleted is %d", (header->link)->data);
		free(header->link);
				printf("\nThe Circular Linked List after deletion is,\n");
		traverse_CLL();
	}
	else
	{
		NODE *ptr, *prev;
		ptr = header->link;
		while (ptr->link != header)
		{
			prev = ptr;	
			ptr = ptr->link;
		}	
		printf("\nThe element being deleted is %d", ptr->data);
		free(ptr);
		prev->link = header;
		printf("\nThe Circular Linked List after deletion is,\n");
		traverse_CLL();
	}
}
void del_pos_CLL(int key)
{
	if (header->link == header)
		printf("\nList is Empty, Deletion is not possible");
	else if ((header->link)->link == header)
	{
		printf("\nThe element being deleted is %d", (header->link)->data);
		free(header->link);
		printf("\nThe Circular Linked List after deletion is,\n");
		traverse_CLL();
	}
	else
	{
		NODE *ptr, *prev;
		ptr = header;
		while ((ptr->data != key) && (ptr->link != header))
		{
			prev = ptr;
			ptr = ptr->link;
		}
		if (ptr->link == header)
			printf("\nKey not found, Deletion is not possible");
		else
		{	
			printf("\nThe element being deleted is %d", ptr->data);
			prev->link = ptr->link;
			free(ptr);	
			printf("\nThe Circular Linked List after deletion is,\n");
			traverse_CLL();
		}
	}
}		
void main()
{
	int t, item, key;
	header = (NODE*)malloc(sizeof(NODE));
	create_CLL();
	while(1)
	{
		printf("\n\nMain Menu:");
		printf("\n1: Display the elements of the Circular Linked List");
		printf("\n2: Insert an element at the beginning");
		printf("\n3: Insert an element at the end");
		printf("\n4: Insert an element at an arbitrary position");
		printf("\n5: Delete an element from the beginning");
		printf("\n6: Delete an element from the end");
		printf("\n7: Delete an element from an arbitrary position");
		printf("\n8: Exit");
		printf("\n\nEnter your choice: ");
		scanf("%d", &t);
		switch(t)
		{
			case 1:
					printf("\nThe elements of the Circular Linked List are,\n");
					traverse_CLL();
					break;	
			case 2:
					printf("\nEnter the element to be inserted: ");
					scanf("%d", &item);
					insert_beg_CLL(item);
					break;	
			case 3:
					printf("\nEnter the element to be inserted: ");
					scanf("%d", &item);
					insert_end_CLL(item);
					break;
			case 4:
					printf("\nEnter the element to be inserted: ");
					scanf("%d", &item);
					printf("\nEnter the data value of the node after which %d should be inserted: ", item);
					scanf("%d", &key);
					insert_pos_CLL(item, key);
					break;	
			case 5:
					del_beg_CLL();
					break;	
			case 6:
					del_end_CLL();
					break;			
			case 7:
					printf("\nEnter the data value of the node to be deleted: ");
					scanf("%d", &key);		
					del_pos_CLL(key);
					break;		
			case 8:
					exit(0);	
			default:
					printf("\nPlease enter a valid choice");	
		}
	}
}	
