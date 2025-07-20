// https://leetcode.com/problems/fruit-into-baskets/
// https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits, int k) {
    int maxi = 0, l = 0, r = 0;
    unordered_map<int, int> mpp;  // Tracks the count of fruit types in the current window

    while (r < fruits.size()) {
        mpp[fruits[r]]++;  // Add current fruit to the map

        // If we have more than k distinct fruits, shrink the window from the left
        if (mpp.size() > k) {
            mpp[fruits[l]]--;  // Reduce count of the leftmost fruit
            if (mpp[fruits[l]] == 0) {
                mpp.erase(fruits[l]);  // Remove the fruit type if its count is zero
            }
            l++;  // Move left pointer to shrink the window
        }

        // If window has at most k types, update the max length
        if (mpp.size() <= k) {
            maxi = max(maxi, r - l + 1);
        }

        r++;  // Expand window from the right
    }

    return maxi;
}

int main() {
    vector<int> fruits = {1, 2, 1, 2, 3, 2, 1};
    int k = 2;

    // Expected Output: 4 (subarray [1,2,1,2] is the longest with at most 2 fruit types)
    cout << "Maximum length of subarray with at most " << k << " types of numbers: "
         << totalFruit(fruits, k) << endl;

    return 0;
}
