#include <stdio.h>

void insertion_sort(int a[], int n)
{
    for(int i=1;i<n;i++)
    {
        int x=a[i], j=i-1;
        while(j>=0 && a[j]>x)
        {   
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}

void main()
{
printf("Enter the number of elements in the array to be sorted: ");
int n;
scanf("%d",&n);
int a[n];
for(int i=0;i<n;i++)
{
    printf("Enter the element-%d of the array: ",i+1);
    scanf("%d",&a[i]);
}
insertion_sort(a, n);
printf("The sorted array is: ");
for(int i=0;i<n;i++){
    printf("%d ",a[i]);
}
}