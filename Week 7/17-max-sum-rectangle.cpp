#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int a[MAXN][MAXN], n, m;


int maxSumRectangle() {
    int ans = INT_MIN;
    int sum[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum[i][j] = a[i][j];
            if (i > 0) sum[i][j] += sum[i - 1][j];
            if (j > 0) sum[i][j] += sum[i][j - 1];
            if (i > 0 && j > 0) sum[i][j] -= sum[i - 1][j - 1];
            ans = max(ans, sum[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < m; l++) {
                    int rect = sum[k][l];
                    if (i > 0) rect -= sum[i - 1][l];
                    if (j > 0) rect -= sum[k][j - 1];
                    if (i > 0 && j > 0) rect += sum[i - 1][j - 1];
                    ans = max(ans, rect);
                }
            }
        }
    }
    return ans;
}


int main() {
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    cout << "Maximum sum rectangle: " << maxSumRectangle() << endl;
    return 0;
}