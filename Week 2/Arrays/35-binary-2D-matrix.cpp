#include <iostream>
#include <vector>
using namespace std;

void setRCtoOne(vector<vector<int>>& m) {
    vector<bool> rowsToSet(m.size(), false);
    vector<bool> colsToSet(m[0].size(), false);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
            if (m[i][j] == 1) {
                rowsToSet[i] = true;
                colsToSet[j] = true;
            }
        }
    }
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
            if (rowsToSet[i] || colsToSet[j]) {
                m[i][j] = 1;
            }
        }
    }
}

int main() {
    vector<vector<int>> m = { {0, 1, 0},
                                   {0, 0, 0},
                                   {1, 1, 0} };
    setRCtoOne(m);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
