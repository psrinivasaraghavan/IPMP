#include <bits/stdc++.h>
using namespace std;


vector<int> findPts(int a[], int n)
{
    vector<int> pts;
    int totalSum = 0;
    for (int i = 0; i < n; i++) totalSum += a[i];
    int lSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (lSum == totalSum - a[i] - lSum) pts.push_back(i);
        lSum += a[i];
    }
    return pts;
}


int main()
{
    int a[] = {1, 2, 3, 15, 3, 1, 2}, n = sizeof(a) / sizeof(a[0]);
    vector<int> pts = findPts(a, n);
    if (pts.size() == 0) cout << "No points found." << endl;
    else
    {
        cout << "The points where left-sum equals right-sum are: ";
        for (int i = 0; i < pts.size(); i++) cout << pts[i] << " ";
        cout << endl;
    }
    return 0;
}
