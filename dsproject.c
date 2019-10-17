/*A CODE FOR SANITATION AND HYGIENE RESOLUTION SYSTEM */
//ROLLNO-18CO03,18CO04,18CO07

#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h>

// A structure to represent a queue 
struct Queue
{
	int front, rear, size;
	unsigned capacity;
	int* array;
};

// function to create a queue of given capacity. 
// It initializes size of queue as 0 
struct Queue* createQueue(unsigned capacity)
{
	struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1; // This is important, see the enqueue 
	queue->array = (int*)malloc(queue->capacity * sizeof(int));
	return queue;
}

// Queue is full when size becomes equal to the capacity 
int isFull(struct Queue* queue)
{
	return (queue->size == queue->capacity);
}

// Queue is empty when size is 0 
int isEmpty(struct Queue* queue)
{
	return (queue->size == 0);
}

// Function to add an item to the queue. 
// It changes rear and size 
void enqueue(struct Queue* queue, int item)
{
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	
}

// Function to remove an item from queue. 
// It changes front and size 
int dequeue(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;
	return item;
}

// Function to get front of queue 
int front(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}

// Function to get rear of queue 
int rear(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}
int Login(struct Queue* queue)
{
	int loginChoice = 0;

	printf("\n\n\tHOW DO YOU WANT TO LOGIN TO A SYSTEM\n1. END USER\n2. SANITATION WORKER \n3. EXIT \n\t\tPLEASE ENTER YOUR CHOICE::");
	scanf("%d", &loginChoice);
	if (loginChoice == 1)
		RegisterComplaints(queue);
	else if (loginChoice == 2)
		ResolveComplaints(queue);
	else if (loginChoice == 3)
		exit(0);
	else
		printf("\n INVALID CHOICE!");
}

int RegisterComplaints(struct Queue* queue)
{
	char enterComplaint = 'Y';
	int ch;
	printf("\n\nPLEASE ENTER YOUR COMPLAINT::");

	while (enterComplaint == 'Y')
	{
		printf("\n\nSELECT YOUR ISSUES\n1-WATER SHORTAGE\n2-ELECTRIC PROBLEM\n3-ACCESSORIES UNAVAILABLE\n4-UNHYGIENIC\n\tENTER YOUR CHOICE(PRESS ENTER)::");
		scanf("%d", &ch);
		enqueue(queue, ch);
		printf("IS THERE ANY OTHER ISSSUE YOU WANT TO REGISTER (Y / N) :");
		scanf(" %c", &enterComplaint);
	}

	printf("\nTHAN YOU FOR YOUR FEEDBACK.\nSANITATION WORKER WILL RESOLVE ISSUES AT THE EARLIEST.");
	printf("\n YOU'VE BEEN LOGGED OUT.\nKINDLY LOGIN AGAIN.\n");
	printf("\n\n\t\tQUEUE STATUS\n");
	printf("-----------------------------------------------------------\n");
	printf("FRONT ITEM - %d\n", front(queue));
	printf("REAR ITEM - %d\n", rear(queue));
	Login(queue);
	return 0;
}
int ResolveComplaints(struct Queue* queue)
{
	int userid;
	char taskChoice;
	printf("ENTER YOUR USERID::");
	scanf("%d",&userid);
	if(userid==20192020)
	{
	printf("\n\t\tWELCOME SANITATION WORKER!\n");
	while (queue->size != 0)
	{
		printf("\nYOU HAVE %d TASK TO RESOLVE.\nKINDLY COMPLETE TASK %d\n", queue->size, front(queue));
		printf("\nDO YOU WANT THIS TASK MARK AS DONE (Y/N) :");
		scanf(" %c", &taskChoice);
		if (taskChoice == 'Y')
			dequeue(queue);
	}
	printf("\nTHERE IS NO TASK LEFT.\n\t HAVE A NICE DAY\n");
	printf("\nYOU HAVE BEEN LOGGED OUT OF A SYSTEM.KINDLY LOGIN AGAIN.\n");
	Login(queue);
	}
	else
	{
		printf("YOU'VW ENTERED INCORREC USERID.KINDLY LOGIN AS A USER.");
		Login(queue);
	}
	return 0;
}

// Driver program to test above functions./ 
void main()
{
	struct Queue* queue = createQueue(5);
	printf("\n\n***************WELCOME TO SANITATION AND HYGIENE RESOLUTION SYSTEM**********************");
	Login(queue);
}
