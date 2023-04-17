#include <bits/stdc++.h>
using namespace std;


struct Project {
    int start, end, reward;
};


bool compareProjects(Project a, Project b) {
    return a.end < b.end;
}


int maxMoney(vector<Project>& projects) {
    int n = projects.size();
    sort(projects.begin(), projects.end(), compareProjects);
    vector<int> dp(n, 0);
    dp[0] = projects[0].reward;
    for (int i = 1; i < n; i++) {
        int prevMaxReward = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (projects[j].end <= projects[i].start) {
                prevMaxReward = dp[j];
                break;
            }
        }
        dp[i] = max(prevMaxReward + projects[i].reward, dp[i - 1]);
    }
    return dp[n - 1];
}


int main() {
    int n;
    cout << "Enter the number of projects: ";
    cin >> n;
    vector<Project> projects(n);
    cout << "Enter the starting day, ending day, and reward for each project:\n";
    for (int i = 0; i < n; i++) {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }
    int maxReward = maxMoney(projects);
    cout << "The maximum amount of money you can earn is: " << maxReward << endl;
    return 0;
}