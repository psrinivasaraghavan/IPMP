#include <iostream>
using namespace std;


void rotatingAnArray(int arr[], int places, int n)
{
    int temp[n], k = 0;
    for (int i = places; i < n; i++) temp[k++] = arr[i];
    for (int i = 0; i < places; i++) temp[k++] = arr[i];
    for (int i = 0; i < n; i++) arr[i] = temp[i];
}
 


int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int places = 10;
    places %= n;
    rotatingAnArray(arr, places, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}