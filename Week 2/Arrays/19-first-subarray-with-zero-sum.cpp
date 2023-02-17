#include <bits/stdc++.h>
using namespace std;


vector<int> ZeroSumSubarray(int a[], int n)
{
    unordered_set<int> sumSet;
    vector<int> result;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (a[i] == 0 || sum == 0 || sumSet.find(sum) != sumSet.end())
        {
            for (int j = 0; j < result.size(); j++) result.pop_back();
            for (int j = 0; j <= i; j++) result.push_back(a[j]);
            return result;
        }
        sumSet.insert(sum);
    }
    return result;
}


int main()
{
    int a[] = {4, 2, -3, 1, 6}, n = sizeof(a) / sizeof(a[0]);
    vector<int> result = ZeroSumSubarray(a, n);
    if (result.size() == 0)  cout << "No subarray found." << endl;
    else
    {
        cout << "The first subarray with zero sum is: ";
        for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
