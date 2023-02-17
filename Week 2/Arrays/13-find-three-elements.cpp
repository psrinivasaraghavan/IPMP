#include <bits/stdc++.h>
using namespace std;
 

void find3Numbers(vector<int>& a)
{
  if (a.size() < 3) {
    cout << "No such triplet found";
    return;
  }  
  int min = a[0]; 
  int m = INT_MAX;     
  int sm = min;  
  for (int i = 1; i < a.size(); i++)
  {
    if (a[i] == min)
      continue;
     
    else if (a[i] < min)
    {
      min = a[i];
      continue;
    }
    else if (a[i] < m) {   
      m = a[i];    
      sm = min;           
    }
    else if (a[i] > m)
    {    
        cout << "The triplet is: " << sm <<
                 ", " << m << ", " <<
                           a[i] << endl;
        return;
    }
  }
  cout << "No such triplet found" << endl;
}
 

int main() {
  vector<int> a { 1, 2, 4, 3, 5 };
  find3Numbers(a);
}