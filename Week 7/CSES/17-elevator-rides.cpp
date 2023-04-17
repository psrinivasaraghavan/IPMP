#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, max_weight;
    cin >> n >> max_weight;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) cin >> weights[i];
    sort(weights.begin(), weights.end());
    int rides = 0;
    int i = 0, j = n - 1;
    while (i <= j) {
        if (weights[j] <= max_weight) {
            max_weight -= weights[j];
            j--;
        }
        if (i <= j && weights[i] <= max_weight) {
            max_weight -= weights[i];
            i++;
        }
        rides++;
    }
    cout << rides << endl;
    return 0;
}