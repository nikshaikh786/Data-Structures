 /* EXPERIMENT 4
  * Subject : Data Structure Lab ( CSL303 )
  * Aim : Evaluation of Postfix Expression
  * Description :The given program evaluates the given Postfix expression using
vairous functions and displays the Result.
 * Different Functions performs different tasks in this program showing Modular
Approach.*/

 #include<stdio.h>
 #include<stdlib.h>
 #include<math.h>
 #define MAX 50

 struct stack //Declaration of Structure
 {
	 int data[MAX];
	 int top;
	 }s; //Declaration of Structure variable

 int isEmpty(struct stack *s) //Declaration of isEmpty Function
 {
	return(s->top==-1?1:0);
 }

 void push(struct stack *s,int a) //Declaration of push Function
 {
	 if(s->top==MAX-1)
	 printf("\t\tStack is Full !!!!!\n");
	 else
	 s->data[++s->top]=a;
	 }

 int pop(struct stack *s) //Declaration of pop Function
 {
	 if(isEmpty(s))
	 return 0;
	 else
	 return(s->data[s->top--]);
 }

 int eval(char *expr) //Declaration of eval Function
 {
	 char c;
	 int i,res,op2;
	 s.top=-1;
	 for(i=0;expr[i]!=0;i++)
 {
	 c=expr[i];
	 switch(c)
 {
	 case'+':op2=pop(&s);
	 res=pop(&s)+op2;
	 push(&s,res);
	 break;
	 case'-':op2=pop(&s);
	 res=pop(&s)-op2;
	 push(&s,res);
	 break;
	 case'*':op2=pop(&s);
	 res=pop(&s)*op2;
	 push(&s,res);
	 break;
	 case'/':op2=pop(&s);
	 res=pop(&s)/op2;
	 push(&s,res);
	 break;
	 case'^':op2=pop(&s);
	 res=pow(pop(&s),op2);
	 push(&s,res);
	 break;
	 default:push(&s,c-'0');
	 break;
 }
 }
	return pop(&s);
 }

 int main() //Declaration of main Function
 {
	 char *post;
	 int res;
	 post=(char*)malloc(1);
	 printf("\n\t\tPostfix Evaluation\n\t-----------------------------------");
	 printf("\n\tEnter Postfix expression : ");
	 scanf("%s",post);
	 res=eval(post);
	 printf("\tResult of Postfix is : %d\n",res);
	 }
