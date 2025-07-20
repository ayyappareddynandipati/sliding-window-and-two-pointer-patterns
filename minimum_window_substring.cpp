// https://leetcode.com/problems/minimum-window-substring/
// https://www.geeksforgeeks.org/problems/minimum-window-subsequence/1

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    int sindex = -1;                 // Starting index of the minimum window found
    int minilen = INT_MAX;          // Length of the smallest valid window
    int l = 0, r = 0;               // Sliding window pointers
    int n = s.size(), m = t.size(), cnt = 0;

    vector<int> freq(256, 0);       // Frequency map of characters in t

    // Populate freq with how many times each character appears in t
    for (int i = 0; i < m; i++) {
        freq[t[i]]++;
    }

    vector<int> window(256, 0);     // Current character counts in the window

    while (r < n) {
        // Add character at r to the current window
        window[s[r]]++;

        // If the character is needed (i.e., present in t) and not overused
        if (freq[s[r]] > 0 && window[s[r]] <= freq[s[r]]) {
            cnt++;  // We matched one more required character
        }

        // When we've matched all characters from t
        while (cnt == m) {
            // Update minimum window if the current one is smaller
            if (r - l + 1 < minilen) {
                minilen = r - l + 1;
                sindex = l;
            }

            // Try to reduce the window size from the left
            window[s[l]]--;
            if (freq[s[l]] > 0 && window[s[l]] < freq[s[l]]) {
                cnt--;  // We lost a required character
            }
            l++;  // Move left pointer ahead
        }

        r++;  // Move right pointer ahead
    }

    // Return the smallest window substring if found
    return sindex == -1 ? "" : s.substr(sindex, minilen);
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << "Minimum window substring: " << minWindow(s, t) << endl;

    return 0;
}
