// https://leetcode.com/problems/binary-subarrays-with-sum/description/
// https://www.geeksforgeeks.org/problems/binary-subarray-with-sum/1

#include <bits/stdc++.h>
using namespace std;

// Helper function to count subarrays with sum at most 'goal'
int kSum(vector<int>& nums, int goal) {
    // If goal is negative, no valid subarray exists
    if (goal < 0) return 0;

    int cnt = 0, sum = 0;
    int l = 0, r = 0;

    // Sliding window to maintain a running sum ≤ goal
    while (r < nums.size()) {
        sum += nums[r];

        // Shrink the window from the left if sum exceeds goal
        while (sum > goal) {
            sum -= nums[l];
            l++;
        }

        // All subarrays from index l to r have a valid sum
        cnt += (r - l + 1);
        r++;
    }

    return cnt;
}

// Main function to count subarrays with sum exactly equal to goal
int numSubarraysWithSum(vector<int>& nums, int goal) {
    // Trick: number of subarrays with exact sum = at most goal - at most (goal - 1)
    return kSum(nums, goal) - kSum(nums, goal - 1);
}

int main() {
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    // Output: 4 → There are 4 subarrays with exactly 2 ones
    cout << numSubarraysWithSum(nums, goal) << endl;

    return 0;
}
