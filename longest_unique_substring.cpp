// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// https://www.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1

#include <bits/stdc++.h>
using namespace std;

int longestUniqueSubstr(string s) {
    // Stores the last seen index of each character. Initialized to -1.
    vector<int> freq(256, -1);

    int maxi = 0; // Stores the length of the longest valid substring
    int l = 0, r = 0; // Window pointers

    while (r < s.size()) {
        // If current character was seen before and is inside the current window
        if (freq[s[r]] != -1 && freq[s[r]] >= l) {
            // Move the left pointer just past the last occurrence to avoid repeating character
            l = freq[s[r]] + 1;
        }

        // Update the max length of substring without repeating characters
        maxi = max(maxi, r - l + 1);

        // Mark the current character as seen at index r
        freq[s[r]] = r;

        r++; // Move right pointer forward
    }

    return maxi;
}

int main() {
    string s = "abcabcbb";

    // Expected Output: 3 ("abc" is the longest substring without repeating characters)
    cout << "Length of the longest substring without repeating characters: "
         << longestUniqueSubstr(s) << endl;

    return 0;
}
