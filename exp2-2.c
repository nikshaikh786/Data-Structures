/* EXPERIMENT 2 
 * Subject : Data Structure Lab ( CSL303 )
 * Description : A Stack is a linear data structure in which the data element is inserted and deleted from the same end.
 * This end is called TOP of Stack.
 * Below Program is performing operations of data using Stack
 * 1. The process of addind Data to Stack is reffered to as "Push"
 * 2. The process of retrieving data from the Stack is called as "Pop"
 * 3. The process of Displaying top most element is called as "Peek" */
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct stack					//Declaration of Structure
{
	int data[MAX];
	int top;
}s;								//Declaration of Structure variable
void ini(struct stack *s)		//Declaration of Initialize Function
{
	s->top=(-1);
}
int isEmpty(struct stack *s)	//Declaration of isEmpty Function
{
	return (s->top==-1?1:0);
}
int isFull(struct stack *s)		//Declaration of isFull Function
{
	return (s->top==MAX-1?1:0);
}
int push(struct stack *s,int no)//Declaration of push Function
{
	if(isFull(s))
	return 1;
	++s->top;
	s->data[s->top]=no;
	printf("\t\t\tPushed Successfully !!!\n");
	return 0;
}
int pop(struct stack *s)		//Declaration of pop Function
{
	if(isEmpty(s))
	return 1;
	printf("\t\t\tPoped element is : %d\n",s->data[s->top]);
	(s->top)--;
	return 0;
}
int peek(struct stack *s)		//Declaration of peek Function
{
	if(isEmpty(s))
	return 1;
	printf("\t\t\tPeeked element is : %d\n",s->data[s->top]);
	return 0;
}
int display(struct stack *s)	//Declaration of display Function
{
	int i;
	if(isEmpty(s))
	return 1;
	printf("\tThe elements of Stack are ->\n");
	for(i=s->top;i>=0;i--)
	{
		printf("\t%d\n",s->data[i]);
	}
	return 0;
}
int main()						//Declaration of main Function
{
	int n,num;
	ini(&s);
	while(1)
	{
		printf("\n\t\t\tList of Operations\n1.Push\n2.Peek\n3.Pop\n4.Display\n5.Exit\n\n\t\t\tEnter your choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
			printf("\t\tEnter element to be pushed : ");
			scanf("%d",&num);
			if(push(&s,num))
			printf("\t\t\tStack is Full !!!!!\n");
			break;
			case 2:
			if(peek(&s))
			printf("\t\t\tStack is Empty !!!!!\n");
			break;
			case 3:
			if(pop(&s))
			printf("\t\t\tStack Underflows !!!!!\n");
			break;
			case 4:
			if(display(&s))
			printf("\t\t\tStack is Empty !!!!!\n");
			break;
			case 5:exit(0);
			break;
			default:
			printf("\t\t\tEnter valid Choice !!!!!\n");
		}
	}
	return 0;
}
