#include<stdio.h>
#include<stdlib.h>
#define n 4
int dqueue[n], front = -1, rear = -1;
void display()
{
	if ((front == -1) && (rear == -1))
		printf("\nDouble Ended Queue Empty");
	else
	{	
		int i;
		if (front <= rear)
		{
			for (i=front ; i<=rear ; i++)
				printf("%d\t", dqueue[i]);
		}
		else
		{
			for (i=front ; i<n ; i++)
				printf("%d\t", dqueue[i]);
			for (i=0 ; i<=rear ; i++)
				printf("%d\t", dqueue[i]);
		}		
	}	
}		
void add_rear(int item)
{
	if (front == (rear + 1) % n)
		printf("\nDouble Ended Queue is Full");
	else
	{
		rear = (rear + 1) % n;
		dqueue[rear] = item;
		if (front == -1)
			front = 0;
		printf("\nThe Double Ended Queue after insertion of %d is,\n", item);
		display();
	}
}	
void add_front(int item)
{
	int pos;
	if (front == -1)
		pos = 0;
	else if (front == 0)
		pos = n-1;
	else
		pos = front - 1;
	if (pos == rear)
		printf("\nDouble Ended Queue is Full");
	else
	{
		front = pos;
		dqueue[front] = item;
		if (rear == -1)
			rear = 0;
		printf("\nThe Double Ended Queue after insertion of %d is,\n", item);
		display();
	}
}
void del_front()
{	
	if((front == -1) && (rear == -1))
		printf("\nDouble Ended Queue is Empty");
	else
	{
		int item = dqueue[front];
		printf("\nThe deleted element is %d\n", item);
		if (front == rear)
			front = rear = -1;
		else
			front = (front + 1) % n;
		printf("\nThe Double Ended Queue after deletion of %d is,\n", item);
		display();
	}
}
void del_rear()
{
	if (front == -1)
		printf("\nDouble Ended Queue is Empty");
	else
	{
		int item = dqueue[rear];
		printf("\nThe deleted element is %d", item);
		if (rear == 0)
			rear = n-1;
		else if (front == rear)
			front = rear = -1;
		else
			rear = rear - 1;
		printf("\nThe Double Ended Queue after deletion of %d is,\n", item);
		display();
	}
}	
void main()
{
	int ch, item;
	while(1)
	{
		printf("\n\nMain Menu:");
		printf("\n1: Add an Element at the rear");
		printf("\n2: Add an Element at the front");
		printf("\n3: Delete an Element from the front");
		printf("\n4: Delete an Element from the rear");
		printf("\n5: Display the contents of the Double Ended Queue");
		printf("\n6: Exit");
		printf("\n\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
					printf("\nEnter the element to be added: ");
					scanf("%d", &item);
					add_rear(item);
					break;		
			case 2:	
					printf("\nEnter the element to be added: ");
					scanf("%d", &item);
					add_front(item);
					break;		
			case 3:
					del_front();
					break;		
			case 4: 
					del_rear();
					break;		
			case 5:
					printf("\nThe contents of the Double Ended Queue are,\n");
					display();
					break;		
			case 6:
					exit(0);		
			default:
					printf("\nPlease enter a valid choice");			
		}
	}
}
