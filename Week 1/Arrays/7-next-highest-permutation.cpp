#include <bits/stdc++.h>
using namespace std;


int main()
{
    int num;
    cin>>num;
    string str = to_string(num);
    next_permutation(str.begin(), str.end());
    if(stoi(str)>num) cout<<stoi(str)<<endl;
    else cout<<-1<<endl;
    return 0;
}
