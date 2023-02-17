#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4


int rowWithMax1s(bool m[R][C]) {
  int j, maxrowind = 0;
  j = C - 1;
  for (int i = 0; i < R; i++) {
    bool flag = false;
    while (j >= 0 && m[i][j] == 1) {
      j = j - 1;
      flag = true;
    }
    if (flag) maxrowind = i;
  }
  if (maxrowind == 0 && m[0][C - 1] == 0) return -1;
  return maxrowind;
}


int main()
{
    bool m[R][C] = { {0, 0, 0, 1},
                    {1, 1, 0, 1},
                    {0, 1, 0, 1},
                    {0, 0, 0, 0} };
    cout << "Index of row with maximum 1s is " << rowWithMax1s(m) << endl;
    return 0;
}