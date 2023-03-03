#include <iostream>
using namespace std;


int bsearch(int arr[], int l, int r) {
    while (l <= r) {
        int m = (r + l) / 2;
        if (arr[m] == 1 && (m == 0 || arr[m - 1] == 0)) return m;
        else if (arr[m] == 0) l = m + 1;
        else r = m - 1;
    }
}


int main() {
    int arr[] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, n = sizeof(arr) / sizeof(arr[0]);
    int ans = bsearch(arr, 0, n - 1);
    if (ans == -1) cout << "1 is not present in the array.\n";
    else cout << "Position of the first 1 in the array is " << ans << endl;
    return 0;
}
