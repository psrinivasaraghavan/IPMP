#include <bits/stdc++.h>
using namespace std;
 

vector <int> getIntersection(vector < vector <int> > &sets)
{
    vector <int> r; 
    int smallSetInd = 0, minSize = sets[0].size(); 
    for (int i = 1 ; i < sets.size() ; i++)
    {
        sort(sets[i].begin(), sets[i].end());
        if (minSize > sets[i].size())
        {
            minSize = sets[i].size();
            smallSetInd = i;
        }
    }
    map<int,int> eMap;
    for (int i = 0; i < sets[smallSetInd].size(); i++)
    {
        if (eMap.find( sets[smallSetInd][i] ) == eMap.end()) eMap[ sets[smallSetInd][i] ] = 1;
        else eMap[ sets[smallSetInd][i] ]++;
    }
    map<int,int>::iterator it;
    for (it = eMap.begin(); it != eMap.end(); ++it)
    {
        int e = it->first, freq = it->second;
        bool bFound = true;
        for (int j = 0 ; j < sets.size() ; j++)
        {
            if (j != smallSetInd)
            {
                if (binary_search( sets[j].begin(), sets[j].end(), e ))
                {
                   int lInd = lower_bound(sets[j].begin(), sets[j].end(), e) - sets[j].begin();
                   int rInd = upper_bound(sets[j].begin(), sets[j].end(), e) - sets[j].begin();
                   if ((rInd - lInd) < freq) freq = rInd - lInd;
                }
                else
                {
                    bFound = false;
                    break;
                }
            }
        }
        if (bFound)
        {
            for (int k = 0; k < freq; k++)
                r.push_back(e);
        }
    }
    return r;
}


int main()
{
    vector < vector <int> > sets;
    vector <int> set1;
    set1.push_back(3);
    set1.push_back(1);
    set1.push_back(2);
    set1.push_back(9);
    set1.push_back(5);
    sets.push_back(set1);
 
    vector <int> set2;
    set2.push_back(1);
    set2.push_back(1);
    set2.push_back(3);
    set2.push_back(5);
    set2.push_back(9);
    sets.push_back(set2);
 
    vector <int> set3;
    set3.push_back(1);
    set3.push_back(3);
    set3.push_back(2);
    set3.push_back(9);
    set3.push_back(5);
    set3.push_back(6);
    sets.push_back(set3);
 
    vector <int> r = getIntersection(sets);
    for (int i = 0 ; i < r.size() ; i++) cout << r[i] << " ";
    return 0;
}