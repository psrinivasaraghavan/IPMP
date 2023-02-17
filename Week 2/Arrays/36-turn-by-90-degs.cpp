#include <bits/stdc++.h>
using namespace std;

             
void displayMatrix(unsigned int const *p, unsigned int r, unsigned int c)
{
    unsigned int row, col;
    cout << "\n\n";
    for (row = 0; row < r; row++)
    {
        for (col = 0; col < c; col++)
            cout << * (p + row * c + col) << "\t";
        cout << "\n";
    }
}


void rotate(unsigned int *pS, unsigned int *pD, unsigned int row, unsigned int col)
{
    unsigned int r, c;
    for (r = 0; r < row; r++)
    {
        for (c = 0; c < col; c++)
        {
            *(pD + c * row + (row - r - 1)) =
                        *(pS + r * col + c);
        }
    }
}
 

int main()
{
    unsigned int image[][4] = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};
    unsigned int *ps, *pd;
    unsigned int m, n;
    m = 4, n = 4, ps = (unsigned int *)image;
    pd = (unsigned int *)malloc(sizeof(int) * m * n);
    displayMatrix(ps, m, n);
    rotate(ps, pd, m, n);
    displayMatrix(pd, n, m);
    free(pd);
    return 0;
}