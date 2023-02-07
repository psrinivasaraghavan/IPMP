#include <stdio.h>
void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = a[l+i];
    for (j = 0; j < n2; j++)
        R[j] = a[m+j+1];
 
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        }
        else {
            a[k++] = R[j++];
        }
    }
    while (i < n1) {
        a[k++] = L[i++];
    }
    while (j < n2) {
        a[k++] = R[j++];
    }
}
 

// l is for left index and r is right index of the sub-array of a to be sorted
void mergeSort(int a[], int l, int r)
{
    if (l<r) {
        int m=l+(r-l)/2;
        // Sorting the first and second halves
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
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
