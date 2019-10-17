/* Experiment 11
 * Subject : Data Structure Lab ( CSL303 )
 * Aim : Implementation of Binary Tree
 * Description : A binary tree is a tree data structure in which each node has at most two children,
 * which are referred to as the left child and the right child.
 * Different Functions performs different tasks in this program showing Modular Approach.*/

 #include<stdio.h>
 #include<stdlib.h>

 int binarySearch(int a[], int n, int k)
 {
	 int low,upper,mid;
	 low=0;
	 upper= n-1;
	 for(mid=(low+upper)/2;low<=upper;mid=(low+upper)/2)
	 {
		if(k==a[mid])
		return mid;
		if(k>a[mid])
		low=mid+1;
		else
		upper=mid-1;
	 }
	 return -1;
 }

 int main()
 {
	 int a[20],n,i,k;
	 printf("\n\tEnter total number of element : ");
	 scanf("%d",&n);
	 for(i=0;i<n;i++)
	 {
		printf("\n\tEnter elements in sorted order : ");
		scanf("%d",&a[i]);
	 }
	 printf("\n\tEnter key element to search : ");
	 scanf("%d",&k);
	 i=binarySearch(a,n,k);
	 if(i==-1)
	 printf("\n\tKey element does not exist");
	 else
	 printf("\n\tKey element exist at location %d",i);
 }
