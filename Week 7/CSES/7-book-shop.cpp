#include <bits/stdc++.h>
using namespace std;


int maxPages(int n, int x, vector<int>& prices, vector<int>& pages) {
    vector<pair<int, int>> books(n);
    for (int i = 0; i < n; i++) books[i] = make_pair(prices[i], pages[i]);
    sort(books.begin(), books.end());
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (books[i-1].first <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-books[i-1].first] + books[i-1].second);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][x];
}


int main() {
    int n, x;
    cout << "Enter the number of books and the maximum price: ";
    cin >> n >> x;
    vector<int> prices(n), pages(n);
    cout << "Enter the prices and pages of the books:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> prices[i] >> pages[i];
    }
    int maxNumPages = maxPages(n, x, prices, pages);
    cout << "The maximum number of pages you can buy is " << maxNumPages << endl;
    return 0;
}