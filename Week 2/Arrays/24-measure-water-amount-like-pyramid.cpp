#include <bits/stdc++.h>
using namespace std;


float findWater(int i, int j, float x)
{
    if (j > i)
    {
        printf("Incorrect Inputn");
        exit(0);
    }
    float g[i * (i + 1) / 2];
    memset(g, 0, sizeof(g));
    int ind = 0;
    g[ind] = x;
    for (int row = 1; row <= i ; ++row)
    {
        for (int col = 1; col <= row; ++col, ++ind)
        {
            x = g[ind];
            g[ind] = (x >= 1.0f) ? 1.0f : x;
            x = (x >= 1.0f) ? (x - 1) : 0.0f;
            g[ind + row] += x / 2;
            g[ind + row + 1] += x / 2;
        }
    }
    return g[i*(i-1)/2 + j - 1];
}
 

int main()
{
    int i = 2, j = 2;
    float x = 2.0; 
    cout << "The amount of water in jth g of ith row is: " << findWater(i, j, x) << endl;
    return 0;
}