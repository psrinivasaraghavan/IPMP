#include <bits/stdc++.h>
using namespace std;
 

int longestUniqueSubsttr(string s)
{
    if (s.length() == 0) return 0;
    if (s.length() == 1) return 1;
    int maxLength = 0;
    bool v[256] = { false };
    int l = 0, r = 0;
    for (; r < s.length(); r++)
    {
        if (v[s[r]] == false) v[s[r]] = true;
        else 
        {
            maxLength = max(maxLength, (r - l));
            while (l < r) 
            {
                if (s[l] != s[r]) v[s[l]] = false;
                else 
                {
                    l++;
                    break;
                }
                l++;
            }
        }
    }
    maxLength = max(maxLength, (r - l));
    return maxLength;
}


int main()
{
    string s = "holamahola";
    cout << longestUniqueSubsttr(s) << endl;  
    return 0;
}