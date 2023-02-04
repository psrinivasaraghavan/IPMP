#include <bits/stdc++.h>
using namespace std;
 
// https://www.geeksforgeeks.org/quick-sort/


void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
/* This function takes last element as pivot, places the pivot element at its correct position in sorted array, and 
places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot */
int partition(int arr[], int low, int high)
{
    int pivot =arr[high]; // pivot
    int i = low-1; // Index of smaller element and indicates
                 // the right position of pivot found so far
 
    for (int j=low; j<=high-1;j++) {
        // If current element is smaller than the pivot
        if (arr[j]<pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
        // Separately sort elements before
        // partition and after partition
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