// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/
// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

#include <bits/stdc++.h>
using namespace std;

int longestKSubstr(string &s, int k) {
    int maxi = 0;         // To store the maximum length of a valid window
    int l = 0, r = 0;     // Window pointers
    unordered_map<char, int> mpp; // Keeps track of character frequencies in current window

    while (r < s.size()) {
        mpp[s[r] - 'a']++;   // Add current character to the frequency map

        // Shrink window if we have more than k distinct characters
        if (mpp.size() > k) {
            mpp[s[l] - 'a']--;         // Decrease frequency of leftmost character
            if (mpp[s[l] - 'a'] == 0)  // If frequency becomes 0, remove from map
                mpp.erase(s[l] - 'a');
            l++; // Move left pointer to maintain at most k unique characters
        }

        // Update max length of valid window
        maxi = max(maxi, r - l + 1);
        r++; // Expand window to the right
    }

    return maxi;
}

int main() {
    string s = "aabbcc";
    int k = 2;

    // Output: 4 → "aabb" or "bbcc" are valid substrings with at most 2 distinct characters
    cout << longestKSubstr(s, k) << endl;

    return 0;
}
