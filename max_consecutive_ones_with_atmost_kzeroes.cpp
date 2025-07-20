// https://leetcode.com/problems/max-consecutive-ones-iii/description/
// https://www.geeksforgeeks.org/problems/maximize-number-of-1s0905/1

#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveOnesWithAtMostKZeroes(vector<int>& nums, int k) {
    int left = 0, right = 0;
    int maxLength = 0;    // Stores the maximum length of valid window
    int zeroCount = 0;    // Number of 0s in the current window

    while (right < nums.size()) {
        // If we hit a 0, increase the zero count for the current window
        if (nums[right] == 0) {
            zeroCount++;
        }

        // If number of 0s exceeds k, shrink the window from the left
        while (zeroCount > k) {
            if (nums[left] == 0) {
                zeroCount--;
            }
            left++;  // Move left pointer to reduce the window
        }

        // Update the maxLength if current window is valid and larger
        maxLength = max(maxLength, right - left + 1);

        right++; // Expand the window from the right
    }

    return maxLength;
}

int main() {
    vector<int> nums = {1, 1, 0, 0, 1, 0, 1, 1, 1};
    int k = 2;

    // Expected Output: 6 (we can flip two 0s to get "1 1 1 1 1 1")
    cout << "Maximum consecutive ones with at most " << k << " zeroes: "
         << maxConsecutiveOnesWithAtMostKZeroes(nums, k) << endl;

    return 0;
}
