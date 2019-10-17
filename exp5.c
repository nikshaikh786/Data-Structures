/* EXPERIMENT 5
 * Subject : Data structure Lab ( CSL303 )
 * Aim : Array implementation of Queue
 * Description :Queue is a linear data structure where the first element is inserted from one end called REAR and deleted from the other end called as FRONT.
  The order is First In First Out (FIFO).
  Different Functions performs different tasks in this program showing Modular Approach.*/

 #include<stdio.h>
 #include<stdlib.h>
 #define MAX 5
 struct queue //Declaration of Structure
 {
	 int data[MAX];
	 int front,rear;
	 }q; //Declaration of Structure variable

 void ini(struct queue *q) //Declaration of ini Function
 {
	q->front=q->rear=-1;
 }

 int isFull(struct queue *q) //Declaration of isFull Function
 {
	return (q->rear==MAX-1?1:0);
 }

 int isEmpty(struct queue *q) //Declaration of isEmpty Function
 {
	return q->rear==-1?1:0;
 }

 int insert(struct queue *q,int d) //Declaration of insert Function
 {
	 if(isFull(q))
	 return 0;
	 q->data[++q->rear]=d;
	 if(q->front==-1)
	 q->front=0;
	 return 1;
	 }

 void display(struct queue *q) //Declaration of display Function
 {
	 if(isEmpty(q))
	 printf("\n\t\tQueue is Empty !!!\n");
	 else
 {
	 printf("\n\t\tContents of the Queue are ->->\n");
	 printf("\t\tQueue Size = %d\n\t\tFront = %d\n\t\tRear =%d\n",MAX,q->front,q->rear);

	 for(int i=q->front;i<=q->rear;i++)
 {
	printf("\t\t%d\n",q->data[i]);
 }
 }
 }

 int delete(struct queue *q) //Declaration of delete Function
 {
	 int d=q->data[q->front];
	 if(q->front==q->rear)
	 q->front=q->rear=-1;
	 else
	 q->front++;
	 return d;
	 }

 int search(struct queue *q,int d) //Declaration of search Function
 {
	for(int i=q->front;i<=q->rear;i++)
 {
	if(q->data[i]==d)
	return i;
 }
	return 0;
 }

 int main() //Declaration of main Function
 {
	 int ch,d;
	 ini(&q);
	 while(1)
	 {
	 printf("\n\t\t\tMENU\n\t1. Insert\n\t2. Delete\n\t3. Search\n\t4.Display\n\t5. Exit\n");
	 printf("\t\tEnter your choice : ");
	 scanf("%d",&ch);
	 switch(ch)
	 {
		 case 1:
		 printf("\t\tEnter data to insert : ");
		 scanf("%d",&d);
		 d=insert(&q,d);
		 if(d)
		 printf("\n\t\tInserted Successfully !!!\n");
		 else
		 printf("\n\t\tQueue is Full !!!\n");
		 break;
		 case 2:
		 if(isEmpty(&q))
		 printf("\n\t\tQueue is Empty !!!\n");
		 else
		 printf("\n\t\tDeleted element is : %d\n",delete(&q));
		 break;
		 case 3:
		 printf("\n\t\tEnter the data to Search : ");
		 scanf("%d",&d);
		 d=search(&q,d);
		 if(d==0)
		 printf("\n\t\tData not found !!!\n");
		 else
		 printf("\n\t\tData found at location : %d\n",d);
		 break;
		 case 4:
		 display(&q);
		 break;
		 case 5:
		 exit(0);
		 break;
		 default:
		 printf("\n\t\tEnter a valid choice !!!\n");
		 break;
		 }
	 }
	 return 0;
}
