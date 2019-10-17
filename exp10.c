/* Experiment 10
 * Subject : Data Structure Lab ( CSL303 )
 * Aim : Implementation of Quick Sort
 * Description : QuickSort is one of the most efficient sorting algorithms and
 * is based on the splitting of an array into smaller ones. The name comes from
 * the fact that, quick sort is capable of sorting a list of data elements
 * significantly faster than any of the common sorting algorithms. Different
 * Functions performs different tasks in this program showing Modular Approach.*/
 #include<stdio.h>
 #include<stdlib.h>
 int partition(int a[], int low, int high)
 {
	 int pivot,i,j,k;
	 pivot=a[low];
	 i=low;
	 j=high;
	 while(i<j)
	 {
		 while(a[i]<=pivot && i<high)
		 i++;
		 while(a[j]>pivot && j>low)
		 j--;
		 if(i<j)
	 {
		 k=a[i];
		 a[i]=a[j];
		 a[j]=k;
		 }
	 }
	 a[low]=a[j];
	 a[j]=pivot;
	 return j;
 }
 void quicksort(int a[],int low,int high)
 {
	 int p,i;
	 if(low<high)
	 {
		 printf("\n\nLow=%d and High=%d\n",low,high);
		 for(i=low;i<=high;i++)
		 printf("\t%d",a[i]);
		 p=partition(a,low,high);
		 quicksort(a,low,p-1);
		 quicksort(a,p+1,high);
	 }
 }
 int main()
 {
	 int a[20],n,i;
	 printf("\n\tEnter total number of element :");
	 scanf("%d",&n);
	 for(i=0;i<n;i++)
	 {
		printf("\n\tEnter element :");
		scanf("%d",&a[i]);
	 }
	 quicksort(a,0,n-1);
	 printf("\n\n\tSorted list \n");
	 for(i=0;i<n;i++)
	 printf("\t%d",a[i]);
 }
