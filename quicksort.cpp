#include <bits/stdc++.h>
using namespace std;
 
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = low-1; 
 
    for (int j=low; j<=high-1;j++) {
        if (arr[j]<pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
