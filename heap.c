#include<stdio.h>
#include<stdlib.h>
int n,i,a[10],left,right;
 void swap(int *a,int *b)
 {
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
 }

 void heapify(int a[],int n,int i)
 {
        int largest;
        largest=i;
        left=2*i;
        right=(2*i)+1;
        if(left<n && a[left]>a[largest])        //if left is largest than root
        {
            largest=left;
        }
        if(right<n && a[right]>a[largest])        //if right is largest than root
        {
            largest=right;
        }

        //if the root is not the largest
        if(largest!=i)
        {
            swap(&a[largest],&a[i]);
            heapify(a,n,largest);
        }

        


 }


 void heapsort(int a[],int n)
 {
         for(i=n/2;i>=1;i--)
         {
            heapify(a,n,i);
         }

          //for heap sort
        for(i=n;i>=1;i--)
        {
            swap(&a[i],&a[1]);
            heapify(a,i,1);
        }

 }

void printarray(int a[],int n)
{
    for(i=1;i<=n;i++)
    {
            printf("%d\t",a[i]);
    }
}








 void main()
 {
    printf("enter the no of elements\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
   //heap sort
   heapsort(a,n);

   printf("the sorted array is\n");
   printarray(a,n);


 }