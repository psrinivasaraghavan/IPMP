#include <bits/stdc++.h>
using namespace std;


bool isPalindrome(string s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}


void generatePartitions(string s, vector<vector<string>>& res, vector<string>& cur, int start) {
    if (start == s.size()) {
        res.push_back(cur);
        return;
    }
    for (int i = start; i < s.size(); i++) {
        if (isPalindrome(s, start, i)) {
            cur.push_back(s.substr(start, i - start + 1));
            generatePartitions(s, res, cur, i + 1);
            cur.pop_back();
        }
    }
}


vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> cur;
    generatePartitions(s, res, cur, 0);
    return res;
}


int main() {
    string s = "aab";
    vector<vector<string>> partitions = partition(s);
    for (auto partition : partitions) {
        for (auto str : partition) cout << str << " ";
        cout << endl;
    }
    return 0;
}