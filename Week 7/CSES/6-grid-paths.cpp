#include <bits/stdc++.h>
using namespace std;


int countPaths(vector<vector<int>>& grid, int n, int row, int col) {
    if (grid[row][col] == 1) return 0;
    if (row == n-1 && col == n-1) return 1;
    int paths = 0;
    if (col < n-1) paths += countPaths(grid, n, row, col+1);
    if (row < n-1) paths += countPaths(grid, n, row+1, col);
    return paths;
}


int main() {
    int n;
    cout << "Enter the size of the grid: ";
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    cout << "Enter the grid (0 for empty square, 1 for trap square):" << endl;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> grid[i][j];
    int numPaths = countPaths(grid, n, 0, 0);
    cout << "The number of paths from the upper-left square to the lower-right square is " << numPaths << endl;
    return 0;
}