#include<bits/stdc++.h>

using namespace std;

void selectionsort(int a[], int n) {
  int i, j, k;
  for (i = 0; i < n - 1; i++) {
    k = i;
    for (int j = i + 1; j < n; j++) {
      if (a[k] > a[j]) k = j;
    }
    if (k != i) swap(a[i], a[k]);
  }
}


int main() {
  printf("Enter the number of elements in the array to be sorted: ");
  int n;
  scanf("%d", & n);
  int a[n];
  for (int i = 0; i < n; i++) {
    printf("Enter the element-%d of the array: ", i + 1);
    scanf("%d", & a[i]);
  }
  selectionsort(a, n);
  printf("The sorted array is: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}