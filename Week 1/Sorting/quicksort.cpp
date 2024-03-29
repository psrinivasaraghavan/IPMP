#include <bits/stdc++.h>
using namespace std;


void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 

int partition(int a[], int low, int high)
{
    int pivot =a[high]; 
    int i = low-1; 
    for (int j=low; j<=high-1;j++) 
    {
        if (a[j]<pivot) 
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[high]);
    return i+1;
}
 

void quickSort(int a[], int low, int high)
{
    if (low < high) 
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}


int main()
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
    quickSort(a, 0, n-1);
    cout << "The sorted array is: \n";
    int i;
    for (i=0; i<n; i++)
        cout<<a[i]<<" ";
    return 0;
}