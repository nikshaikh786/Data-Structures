/* EXPERIMENT 1
 * Subject : Data Structure Lab ( CSL303 )
 * Description : The given program is a menu based program comprising of Three
Functions Factoial ,Fibonacci Series & Palindrome.
 * Different Function can be performed different task in a single program showing
Modular Approach. */
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 void fact() //Factorial Function
 {
	 int i,fact=1,no;
	 printf("Enter number for Finding Factorial\n");
	 scanf("%d",&no);
	 for(i=1;i<=no;i++)
	 {
		fact=fact*i;
	 }
	 printf("\nThe Factorial of %d is %d\n",no,fact);
 }
 void palindrome() //Palindrome Function
 {
	 int no,num,rev=0,x;
	 printf("\nEnter a number : ");
	 scanf("%d",&no);
	 num=no;
	 while(no>0)
	 {
		 x=no%10;
		 rev=rev*10+x;
		 no=no/10;
	 }
	 if(num==rev)
	 printf("\nIt is a palindrome\n");
	 else
	 printf("\nIt is not a palindrome\n");
 }
 void fibo() //Fibonacci Function
 {
	 int a=0,b=1,c,num,i;
	 printf("\nEnter the number of series upto\n");
	 scanf("%d",&num);
	 printf("\n\t\tFibonnaci series upto %d:\n\t0\t1",num);
	 for (i=1;i<=num-2;i++)
	 {
		 c=a+b;
		 printf("\t %d",c);
		 a=b;
		 b=c;
	 }
	 printf("\n");
 }

 int main() //Main Function
	 {
		 int n;
		 while(1)
	 {
		 printf("\n\n\n\tEnter the number of operation to perform\n\n1.Factorial\n2.Fibonacci\n3.Palindrome\n4.Exit\n");
		 scanf("%d",&n);
		 switch(n)
	 {
		 case 1:fact();
		 break;
		 case 2:fibo();
		 break;
		 case 3:palindrome();
		 break;
		 case 4:exit(0);
		 break;
		 default:printf("\nPlease enter a valid Choice !!!\n");
		 break;
		 }
		 printf("\n\n*********************************************************");
		 }
		 return 0;
	}
