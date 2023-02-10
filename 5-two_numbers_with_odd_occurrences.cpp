#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, x, first=0, second=0;;
    cin >> n;
    unordered_map<int, int> m;
    for (int i=0; i<n; i++)
    {
    cin>>x;
    m[x]++;
    }
    for (auto it: m)
    {
    if (it.second%2 != 0)
    {
        if (first==0) first=it.first;
        else 
        {
            second=it.first;
            break;
        }
    }
    }
    cout<<first<<" "<<second<<endl;
    return 0;
}
