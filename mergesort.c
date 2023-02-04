#include <stdio.h>
// https://www.geeksforgeeks.org/merge-sort/
// Merges two subarrays of a[]. First subarray is a[l..m] Second subarray is a[m+1..r]
void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Creating two temp arrays and copying data into them
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = a[l+i];
    for (j = 0; j < n2; j++)
        R[j] = a[m+j+1];
 
    // Merge the temp arrays back into a[l...r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i<n1 && j<n2) {
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        }
        else {
            a[k++] = R[j++];
        }
    }
 
    // Copying the remaining elements of L[], if there are any
    while (i < n1) {
        a[k++] = L[i++];
    }
 
    // Copying the remaining elements of R[], if there are any 
    while (j < n2) {
        a[k++] = R[j++];
    }
}
 

// l is for left index and r is right index of the sub-array of a to be sorted
void mergeSort(int a[], int l, int r)
{
    if (l<r) {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m=l+(r-l)/2;
        // Sort first and second halves
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
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
    mergeSort(a, 0, n-1);
    printf("\nThe sorted array is: \n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", a[i]);
    }
    return 0;
}