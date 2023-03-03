#include <iostream>
#include <vector>
using namespace std;


int bsearch(vector<int> nums, int key) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m = (r + l) / 2;
        if (nums[m] == key)
            return m;
        else if (nums[m] < key)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1; 
}


int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11, 13};
    int key = 7;
    int index = bsearch(nums, key);
    if (index == -1) cout << "The key could not be found." << endl;
    else cout << "The key has been found at index " << index << endl;
    return 0;
}
