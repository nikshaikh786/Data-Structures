/* EXPERIMENT 3
 * Subject : Data Structure Lab ( CSL303 )
 * Aim : Conversion of Infix to Postfix
 * Description :The given program converts the given Infix expression to it's
Postfix equivalent using vairous functions.
 * Different Functions performs different tasks in this program showing Modular
Approach.*/

 #include<stdlib.h>
 #include<stdio.h>
 #include<stdbool.h>
 #define MAX 5

 struct stack //Declaration of Structure
 {
	 char data[MAX];
	 int top;
 };

 bool empty(struct stack *s) //Declaration of empty Function
 {
	return (s->top==-1)?true:false;
 }

 void push(struct stack *s,char ele) //Declaration of push Function
 {
	 if (s->top < MAX-1)
	 s->data[++s->top]=ele;
	 else
	 printf("\nSTACK OVERFLOW !!!");
 }

 char pop(struct stack *s) //Declaration of pop Function
 {
	 if(!empty(s))
	 return s->data[s->top--];
	 else
	 return (char)-1;
 }

 int precedence(char a) //Declaration of precedence Function
 {
	switch(a)
 {
	 case '+':
	 return 1;
	 case '-':
	  return 1;
	 case '*':
	 return 2;
	 case '/':
	 return 2;
	  case '^':
	 return 3;
	 case '$':
	 return 3;
  }
	return 0;
 }
 char *convert(char *expr) //Declaration of convert Function
 {
	 char *pexpr;
	 char c,sc='\0';
	 int i,j,n;
	 struct stack st;
	 st.top=-1;
	 for(n=0;expr[n]!='\0';n++)
	 pexpr=(char *)malloc(n+1);
     for(i=0,j=0;expr[i]!='\0';i++)
 {
	 c=expr[i];
	 switch(c)
 {
	 case '+':
	 case '-':
	 case '*':
	 case '/':
	 case '^':
	 case '$':
	 while(!empty(&st)&& precedence(st.data[st.top])>=precedence(c))
 {
	 sc=pop(&st);
	  pexpr[j++]=sc;
 }
	 push(&st,c);
	 break;
	 case '(':
	 push(&st,c);
	 break;
	 case ')':
	 while((sc=pop(&st))!='(')
	 pexpr[j++]=sc;
	 break;
	 default:
	 pexpr[j++]=c;
	 }
	 }
	 while(!empty(&st))
	 pexpr[j++]=pop(&st);
	 pexpr[j]='\0';
	 return pexpr;
	 }
 int main() //Declaration of main Function
 {
	 char *infix , *postfix;
	 infix=(char*)malloc(1);
	 printf("\n\t\tInfix to Postfix Conversion\n\t-------------------------------------------");

	 printf("\n\tEnter Infix Expression : " );
	 scanf("%s",infix);
	 postfix=convert(infix);
	 printf("\n\tPostfix convesion is : %s\n",postfix);
	 return 0;
 }
