#include <bits/stdc++.h>
using namespace std;


struct Box {
    int width, height, depth;
};


vector<Box> generate_rotations(Box box) {
    vector<Box> rotations;
    rotations.push_back(box);
    rotations.push_back({box.height, box.width, box.depth});
    rotations.push_back({box.height, box.depth, box.width});
    rotations.push_back({box.width, box.depth, box.height});
    rotations.push_back({box.depth, box.width, box.height});
    rotations.push_back({box.depth, box.height, box.width});
    rotations.push_back({box.width, box.height, box.depth});
    return rotations;
}


int main() {
    int n;
    cin >> n;
    Box boxes[n];
    for (int i = 0; i < n; i++) {
        int w, h, d;
        cin >> w >> h >> d;
        boxes[i] = {w, h, d};
    }
    vector<Box> rotated_boxes;
    for (int i = 0; i < n; i++) {
        vector<Box> rotations = generate_rotations(boxes[i]);
        rotated_boxes.insert(rotated_boxes.end(), rotations.begin(), rotations.end());
    }
    sort(rotated_boxes.begin(), rotated_boxes.end(), [](Box a, Box b) {
        return a.width * a.depth > b.width * b.depth;
    });
    int dp[rotated_boxes.size()];
    for (int i = 0; i < rotated_boxes.size(); i++) dp[i] = rotated_boxes[i].height;
    for (int i = 1; i < rotated_boxes.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (rotated_boxes[j].width > rotated_boxes[i].width &&  rotated_boxes[j].depth > rotated_boxes[i].depth) {
                dp[i] = max(dp[i], dp[j] + rotated_boxes[i].height);
            }
        }
    }
    int max_height = 0;
    for (int i = 0; i < rotated_boxes.size(); i++) max_height = max(max_height, dp[i]);
    cout << max_height << endl;
    return 0;
}