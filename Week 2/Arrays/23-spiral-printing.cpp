#include <bits/stdc++.h>
using namespace std;


vector<int> spiral(vector<vector<int> >& matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<int> r;
    if (m == 0) return r;
    vector<vector<bool>> seen(m, vector<bool>(n, false));
    int delr[] = { 0, 1, 0, -1 };
    int delc[] = { 1, 0, -1, 0 };
    int x = 0, y = 0, di = 0;
    for (int i = 0; i < m * n; i++) {
        r.push_back(matrix[x][y]);
        seen[x][y] = true;
        int X = x + delr[di];
        int Y = y + delc[di];
        if (X >= 0 && X < m && 0 <= Y && Y < n && !seen[X][Y]) {
            x = X;
            y = Y;
        }
        else {
            di = (di + 1) % 4;
            x += delr[di];
            y += delc[di];
        }
    }
    return r;
}
  

int main()
{
    vector<vector<int>> a{ { 10, 20, 30, 40 },
                            { 50, 60, 70, 80 },
                            { 90, 100, 110, 120 },
                            { 130, 140, 150, 160 } };
    cout<<"The matrix when traversed in spiral order is: ";
    for (int x : spiral(a)) cout << x << " ";
    return 0;
}