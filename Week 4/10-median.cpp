#include <bits/stdc++.h>
using namespace std;


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int l = 0, r = n-1;

    while(l <= r) {
        int m1 = (l + r) / 2;
        int m2 = (n + m + 1) / 2 - m1;

        int l1 = (m1 == 0) ? INT_MIN : nums1[m1-1];
        int l2 = (m2 == 0) ? INT_MIN : nums2[m2-1];
        int r1 = (m1 == n) ? INT_MAX : nums1[m1];
        int r2 = (m2 == m) ? INT_MAX : nums2[m2];

        if(l1 <= r2 && l2 <= r1) {
            if((n + m) % 2 == 0) return (max(l1, l2) + min(r1, r2)) / 2.0;
            else return max(l1, l2);
        }
        else if(l1 > r2) r = m1 - 1;
        else l = m1 + 1;
    }

    return -1;
}


int main() {
    vector<int> nums1 = {1, 3, 5, 7, 9};
    vector<int> nums2 = {2, 4, 6, 8, 10};
    double median = findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << median << endl;
    return 0;
}
