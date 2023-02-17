#include <bits/stdc++.h>
using namespace std;


bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second) return a.second > b.second;
    else return a.first < b.first;
}


void sortByFreq(int a[], int n)
{
    vector<pair<int, int>> fp;
    for (int i = 0; i < n; i++)
    {
        bool isDuplicate = false;
        for (int j = 0; j < fp.size(); j++)
        {
            if (fp[j].first == a[i])
            {
                fp[j].second++;
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) fp.push_back(make_pair(a[i], 1));
    }
    sort(fp.begin(), fp.end(), compare);
    int index = 0;
    for (int i = 0; i < fp.size(); i++)
    {
        int e = fp[i].first;
        int freq = fp[i].second;
        for (int j = 0; j < freq; j++) a[index++] = e;
    }
}


int main()
{
    int a[] = {4, 2, 2, 3, 3, 1, 2, 2, 4, 5}, n = sizeof(a) / sizeof(a[0]);
    sortByFreq(a, n);
    cout << "The sorted array by frequency is: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}
