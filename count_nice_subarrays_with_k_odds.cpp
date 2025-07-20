// https://leetcode.com/problems/count-number-of-nice-subarrays/description/
// https://www.geeksforgeeks.org/problems/count-subarray-with-k-odds/1

#include <bits/stdc++.h>
using namespace std;

// Helper function to count subarrays with AT MOST k odd numbers
int kCountOdd(vector<int>& nums, int k){
    int cnt = 0, oddcnt = 0, l = 0, r = 0;

    // Sliding window approach
    while (r < nums.size()) {
        // If current number is odd, increase odd count
        if (nums[r] & 1) {
            oddcnt++;
        }

        // Shrink window from the left if odd count exceeds k
        while (oddcnt > k && l <= r) {
            if (nums[l] % 2 == 1) {
                oddcnt--;
            }
            l++;
        }

        // All subarrays ending at r and starting from l to r are valid
        cnt += (r - l + 1);
        r++;
    }

    return cnt;
}

// Function to count subarrays with EXACTLY k odd numbers
int numberOfSubarrays(vector<int>& nums, int k) {
    // Count of subarrays with exactly k odds = at most k odds - at most (k-1) odds
    return kCountOdd(nums, k) - kCountOdd(nums, k - 1);
}

int main() {
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    cout << "Number of nice subarrays with exactly " << k << " odd numbers: " 
         << numberOfSubarrays(nums, k) << endl; // Output: 2

    return 0;
}
