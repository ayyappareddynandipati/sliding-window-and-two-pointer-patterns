// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
// https://www.geeksforgeeks.org/problems/maximum-point-you-can-obtain-from-cards/1

#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int maxsum = 0, lsum = 0, rsum = 0;

    // Take the first 'k' cards from the left side
    for (int i = 0; i < k; i++) {
        lsum += cardPoints[i];
    }

    maxsum = lsum;  // Initial score is taking all 'k' cards from the left

    // Try shifting the window by taking cards from the right one by one
    for (int i = 0; i < k; i++) {
        lsum -= cardPoints[k - i - 1];  // Remove one card from the end of the left part
        rsum += cardPoints[cardPoints.size() - i - 1];  // Add one card from the right
        maxsum = max(maxsum, lsum + rsum);  // Track the maximum sum between left + right combination
    }

    return maxsum;
}

int main() {
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    // Expected output: 12 (Best choice is picking [1, 2] from left and [6] from right OR [1] left + [6,5] right)
    cout << maxScore(cardPoints, k) << endl;

    return 0;
}
