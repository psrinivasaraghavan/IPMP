#include <bits/stdc++.h>
using namespace std;


int main() 
{
    cout<<"The Pythogorean triplets in which the greatest number among them is lesser than or equal to fifty are:"<<endl;
    for (int c=1; c<=50; c++) 
    {
        for (int b=1; b<c; b++) 
        {
            for (int a=1; a<b; a++)
             {
                if (a*a+b*b==c*c) cout<<a<<", "<<b<<", "<<c<<endl;
            }
        }
    }
    return 0;
}