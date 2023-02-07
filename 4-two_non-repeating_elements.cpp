#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int a[] = {3, 3, 6, 15, 9, 11, 4, 11, 4, 15};
    int n = sizeof(a) / sizeof(*a);
    sort(a, a + n);
    vector<int> res;
    for (int i = 0; i < n - 1; i = i + 2) {
        if (a[i] != a[i + 1]) {
            res.push_back(a[i]);
            i = i - 1;
        }
    }
    if (res.size() == 1) res.push_back(a[n - 1]);
    cout << "The non-repeating elements are " << res[0]
         << " and " << res[1];
}