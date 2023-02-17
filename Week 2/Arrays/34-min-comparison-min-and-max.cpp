#include <iostream>
using namespace std;
struct Pair {
    int min;
    int max;
};
 
struct Pair getMinMax(int a[], int l, int r)
{
    struct Pair MM, mml, mmr;
    int mid;
    if (l == r) {
        MM.max = a[l];
        MM.min = a[l];
        return MM;
    }
    if (r == l + 1) {
        if (a[l] > a[r]) {
            MM.max = a[l];
            MM.min = a[r];
        }
        else {
            MM.max = a[r];
            MM.min = a[l];
        }
        return MM;
    }
    mid = (l + r) / 2;
    mml = getMinMax(a, l, mid);
    mmr = getMinMax(a, mid + 1, r);
    if (mml.min < mmr.min) MM.min = mml.min;
    else MM.min = mmr.min;
    if (mml.max > mmr.max) MM.max = mml.max;
    else MM.max = mmr.max;
    return MM;
}
 

int main()
{
    int a[] = { 1000, 11, 445, 1, 330, 3000 };
    int n = 6;
    struct Pair MM = getMinMax(a, 0, n - 1);
    cout << "Minimum element is " << MM.min << endl;
    cout << "Maximum element is " << MM.max;
    return 0;
}