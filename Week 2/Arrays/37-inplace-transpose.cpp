#include <bits/stdc++.h>
#define HASH_SIZE 128
using namespace std;
 

void arrayprint(int *A, int nr, int nc)
{
    for(int r = 0; r < nr; r++)
    {
        for(int c = 0; c < nc; c++) cout<<setw(4)<<*(A + r*nc + c);
        cout<<endl;
    }
    cout<<endl;
}
 

void transpose(int *A, int r, int c)
{
    int s = r * c - 1, t, next, cb,  i; 
    bitset<HASH_SIZE> b;
    b.reset();
    b[0] = b[s] = 1;
    i = 1;
    while (i < s)
    {
        cb = i;
        t = A[i];
        do
        {
            next = (i * r) % s;
            swap(A[next], t);
            b[i] = 1;
            i = next;
        }
        while (i != cb);
        for (i = 1; i < s && b[i]; i++);
        cout << endl;
    }
}
 

int main()
{
    int r = 5, c = 6, s = r * c;
    int *A = new int[s];
    for(int i = 0; i < s; i++)  A[i] = i+1;
    arrayprint(A, r, c);
    transpose(A, r, c);
    arrayprint(A, c, r);
    delete[] A;
    return 0;
}