#include <stdio.h>


void recursive_bubble_sort(int a[], int n)
{
    if(n<2)
    {
        return;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(a[i+1]<a[i])
            {
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    recursive_bubble_sort(a, n-1);
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
recursive_bubble_sort(a, n);
printf("The sorted array is: ");
for(int i=0;i<n;i++){
    printf("%d ",a[i]);
}
}