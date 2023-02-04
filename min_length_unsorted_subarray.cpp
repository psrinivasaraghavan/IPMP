#include<bits/stdc++.h>
using namespace std;
//https://www.geeksforgeeks.org/minimum-length-unsorted-subarray-sorting-which-makes-the-complete-array-sorted/


int findUnsortedSubarray(vector<int>& nums) {
    vector<int> temp_array=nums;
    sort(temp_array.begin(), temp_array.end());
    int start=0, end=0;
    for (int i=0; i<nums.size();i++) {
        if (nums[i]!=temp_array[i]) {
            start=i;
            break;
        }
    }
    for (int i=nums.size()-1; i>=0; i--) {
        if (nums[i]!=temp_array[i]) {
            end=i;
            break;
        }
    }
    if(end==0 && start==0) return 0;
    return (end-start+1);
}


int main()
{
    vector<int> a= {60, 12, 20, 25, 30, 31, 32, 35, 40, 10 };
    cout << "Minimum length of the subarray is: "<< findUnsortedSubarray(a)<<endl;
    return 0;
}

