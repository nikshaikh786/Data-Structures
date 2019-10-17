/* EXPERIMENT 8
 * Subject : Data Structure Lab ( CSL303 )
 * Aim : Implementation of Doubly Linked List
 * Description : A doubly linked list is a linked data structure that consists of a set of sequentially linked records called nodes.
 * Each node contains three fields: two link fields (references to the previous and to the next node in the sequence of nodes) and one data field.
 * The last node has a reference to null. The entry point into a linked list is called the head of the list.
 * Different Functions performs different tasks in this program showing Modular Approach.*/

 #include<stdio.h>
 #include<stdlib.h>

 struct dll //Declaration of Structure
 {
	int data;
	struct dll *next,*prev;
 };

 struct dll *insertAtEnd(struct dll *h,int d) //Declaration of insertAtEnd Function
 {
	 struct dll *p,*temp;
	 p=(struct dll *)malloc(sizeof(struct dll)); //Memory Allocation
	 if(p==NULL)
	 {
		printf("\n\tNot Enough Memory!");
		return h;
	 }
	 p->data=d;
	 p->next=NULL;
	 p->prev=NULL;
	 if(h==NULL)
	 h=p;
	 else
	 {
		 temp=h;
		 while(temp->next!=NULL)
		 temp=temp->next;
		 temp->next=p;
		 p->prev=temp;
	 }
	 return h;
 }

 struct dll *insertAtStart(struct dll *h,int d) //Declaration of insertAtStart Function
 {
	 struct dll *p;
	 p=(struct dll *)malloc(sizeof(struct dll)); //Memory Allocation
	 if(p==NULL)
	 {
	 printf("\n\tNot Enough Memory!");
	 return h;
	 }
	 p->data=d;
	 p->next=h;
	 p->prev=NULL;
	 if(h!=NULL)
	 h->prev=p;
	 h=p;
	 return h;
 }
 struct dll *insertAfter(struct dll *h,int d,int key)//Declaration of insertAfter Function
 {
	 struct dll *p,*temp;
	 p=(struct dll *)malloc(sizeof(struct dll)); //Memory Allocation
	 if(p==NULL)
	 {
	 printf("\n\tNot Enough Memory!");
	 return h;
	 }
	 p->data=d;
	 p->next=NULL;
	 p->prev=NULL;
	 if(h==NULL)
	 {
	 h=p;
	 }
	 else
	 {
	 temp=h;
	 while(temp!=NULL && temp->data!=key)
	 temp=temp->next;
	 if(temp!=NULL)
	 {
	 p->next=temp->next;
	 p->prev=temp;
	 if(temp->next!=NULL)
	 (temp->next)->prev=p;
	 temp->next=p;
	 }
	 else
	 {
	 printf("\n\tGiven Node %d does not Exist in the Linked List!!!",key);
	 free(p);
	 }
	 }
	 return h;
 }

 struct dll *removeLast(struct dll *h) //Declaration of removeLast Function
 {
	 struct dll *temp;
	 temp=h;
	 if(h!=NULL)
	 {
	 if(h->next!=NULL)
	 {
	 while(temp->next!=NULL)
	 {
	 temp=temp->next;
	 }
	 (temp->prev)->next=NULL;
	 }
	 else
	 h=NULL;
	 free(temp);
	 }
	 else
	 {
	 printf("\n\tLinked List is Empty!!!!!");
	 }
	 return h;
  }

 struct dll *removeFirst(struct dll *h) //Declaration of removeFirst Function
 {
	 struct dll *temp;
	 temp=h;
	 if(h!=NULL)
	 {
	 if(temp->next!=NULL)
	 {
	 h=h->next;
	 h->prev=NULL;
	 free(temp);
	 }
	 else
	 h=NULL;
	 }
	 else
	 {
	 printf("\n\tLinked List is Empty!!!!!");
	 }
	 return h;
}
 struct dll *removeAfter(struct dll *h,int key) //Declaration of removeAfter Function
 {
	 struct dll *temp,*p;
	 temp=h;
	 if(h!=NULL)
	 {
	  while(temp!=NULL && temp->data!=key)
	 temp=temp->next;
	 if(temp!=NULL)
	 {
	 if(temp->next!=NULL)
	 {
	 p=temp->next;
	 if(p->next!=NULL)
	 (p->next)->prev=temp;
	 temp->next=p->next;
	 p->next=NULL;
	 p->prev=NULL;
	 free(p);
	 }
	 else
	 printf("\n\tGiven Node is Last Node !!!!!");
	 }
	 else
	 printf("\n\tGiven Key Does not Exist !!!!!");
	 }
	  else
	 {
	 printf("\n\tLinked List is Empty!!!!!");
	 }
	 return h; 
 }

 void display(struct dll *h) //Declaration of display Function
 {
	 struct dll *temp;
	 temp=h;
	 if(h!=NULL)
	 {
	 printf("\n\tContents of Linked List ->\n");
	 while(temp!=NULL)
	 {
	 printf("\t%d\n",temp->data);
	 temp=temp->next;
	 }
	 }
	 else
	 {
	 printf("\n\tLinked List is Empty!!!!!");
	 }
 }

 void displayRev(struct dll *h) //Declaration of displayRev Function
 {
	 struct dll *temp;
	 temp=h;
	 if(h!=NULL)
	 {
	 printf("\n\tContents of Linked List in Reverse order are ->\n");
	 while(temp->next!=NULL)
	 {
	 temp=temp->next;
	 }
	 do
	 {
	 printf("\t%d\n",temp->data);
	 temp=temp->prev;
	 }while(temp!=NULL);
	 }
	 else
	 {
	 printf("\n\tLinked List is Empty!!!!!");
	 }
 }

 void search(struct dll *h,int key) //Declaration of search Function
 {
	 struct dll *temp;
	 int count=0;
	 if(h==NULL)
	 {
	  printf("\n\tLinked List is Empty!!!");
	 }
	 else
	 {
	 temp=h;
	 while(temp!=NULL && temp->data!=key)
	 {
	 temp=temp->next;
	 count++;
	 }
	  if(temp==NULL)
	 {
	 printf("\n\tGiven Node does not Exist in the Linked List!!!");
	 }
	 else
	 {
	 printf("\n\tGiven Node found at %d position in the Linked List!!!",count);
	 }
	 }
 }

 int main() //Declaration of main Function
 {
	 struct dll *head; //Declaration of Structure Variable
	 int ch,d,k;
	 head=NULL;
	 while(1)
	 {
	 printf("\n\t\t\tMENU\n\t1 Insert Node\n\t\t11 Insert At Start\n\t\t12 Insert at End\n\t\t13 Insert After\n\t2 Delete Node\n\t\t21 Delete First\n\t\t22 Delete Last\n\t\t23 Delete After\n\t3 Display\n\t\t31 Display Normal\n\t\t32 Display Reverse\n\t4 Search\n\t5 Exit\n\n\t\tEnter your Choice :");
	 scanf("%d",&ch);
	 switch(ch)
	 {
		 case 11:
		 printf("\n\tEnter Data : ");
		 scanf("%d",&d);
		 head=insertAtStart(head,d);
		 break;
		 case 12:
		 printf("\n\tEnter Data : ");
		 scanf("%d",&d);
		 head=insertAtEnd(head,d);
		 break;
		 case 13:
		 printf("\n\tEnter Data : ");
		 scanf("%d",&d);
		 printf("\n\tEnter key : ");
		 scanf("%d",&k);
		 head=insertAfter(head,d,k);
		 break;
		 case 21:
		 head=removeFirst(head);
		 break;
		 case 22:
		 head=removeLast(head);
		 break;
		 case 23:
		 printf("\n\tEnter key : ");
		 scanf("%d",&k);
		 head=removeAfter(head,k);
		 break;
		 case 31:
		 display(head);
		 break;
		 case 32:
		 displayRev(head);
		 break;
		 case 4:
		 printf("\n\tEnter key : ");
		 scanf("%d",&k);
		 search(head,k);
		 break;
		 case 5:
		 exit(0);
		 break;
		 default:
		 printf("Enter Correct Choice!!!!!");
		 break;
		 }
	 }
	return 0;
 }
