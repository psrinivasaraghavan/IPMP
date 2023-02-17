#include <iostream>
using namespace std;

void subArraySum(int a[], int n, int sum)
{
    for (int i = 0; i < n; i++) {
        int currSum = a[i];
        if (currSum == sum)
        {
            cout << "Sum found at indexes " << i << endl;
            return;
        }
        else 
        {
            for (int j = i + 1; j < n; j++) {
                currSum += a[j];
                if (currSum == sum) {
                    cout << "Sum found between indexes " << i << " and " << j << endl;
                    return;
                }
            }
        }
    }
    cout << "No subarray found";
    return;
}
 

int main()
{
    int a[] = { 23, 8, 4, 2, 5, 9, 11, 10 }, n = sizeof(a) / sizeof(a[0]),sum = 30;
    subArraySum(a, n, sum);
    return 0;
}