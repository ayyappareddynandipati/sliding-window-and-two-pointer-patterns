// https://www.geeksforgeeks.org/problems/subarrays-with-k-different-integers/1

#include <bits/stdc++.h>
using namespace std;

// Helper function to count number of subarrays with at most 'k' distinct integers
int kMost(vector<int> &arr, int k){
    int cnt = 0, l = 0, r = 0;
    unordered_map<int, int> mpp;  // Stores frequency of elements in current window

    while (r < arr.size()) {
        mpp[arr[r]]++;  // Include current element in the window

        // If number of distinct elements exceeds k, shrink window from the left
        while (mpp.size() > k) {
            mpp[arr[l]]--;
            if (mpp[arr[l]] == 0) {
                mpp.erase(arr[l]);  // Remove element if its frequency becomes 0
            }
            l++;
        }

        // Count all subarrays ending at index r with at most k distinct elements
        cnt += (r - l + 1);
        r++;
    }

    return cnt;
}

// Function to count subarrays with exactly k distinct integers
int exactlyK(vector<int> &arr, int k) {
    // Subarrays with exactly k distinct elements = 
    // subarrays with at most k - subarrays with at most (k-1)
    return kMost(arr, k) - kMost(arr, k - 1);
}

int main() {
    vector<int> arr = {1, 2, 1, 2, 3};
    int k = 2;

    cout << "Number of subarrays with exactly " << k << " distinct elements: " 
         << exactlyK(arr, k) << endl;  // Output: 7

    return 0;
}
