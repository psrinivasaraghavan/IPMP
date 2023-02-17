#include <iostream>
using namespace std;


int main()
{
    int A[] = { 7, 6, 8, 0, 23, 0, 9, 0, 13 }, n = sizeof(A) / sizeof(A[0]), j = 0;
    for (int i = 0; i < n; i++) if (A[i] != 0) swap(A[j++], A[i]); 
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    return 0;
}