#include <bits/stdc++.h>
using namespace std;
 

void reverse(char* str, int low, int high)
{
    while(low<high)
    {
        swap(str[low], str[high]);
        ++low;
        --high;
    }
}
 

void cl(char* str, int sh, int len)
{
    int j;
    char item;
    for (int i=1; i<len; i=i*3 )
    {
        j=i;
        item=str[j+sh];
        do
        {
            if (j&1) j=len/2+j/2;
            else j/=2;
            swap(str[j+sh], item);
        }
        while(j!=i);
    }
}
 

void evenoddsep(char* str)
{
    int k, lenFirst;
    int remlength=strlen(str);
    int sh=0;
    while(remlength)
    {
        k = 0;
        while(pow(3, k)+1 <= remlength) k++;
        lenFirst=pow(3, k-1)+1;
        remlength-=lenFirst;
        cl(str, sh, lenFirst);
        reverse(str, sh/2, sh-1);
        reverse(str, sh, sh+lenFirst/2-1 );
        reverse(str, sh/2, sh+lenFirst/2-1);
        sh+=lenFirst;
    }
}
 

int main()
{
    char str[] = "a1b2c3d4e5f6g7h8i9j0";
    evenoddsep(str);
    cout<<str<<endl;
    return 0;
}