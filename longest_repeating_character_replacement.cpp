// https://leetcode.com/problems/longest-repeating-character-replacement/description/
// https://www.geeksforgeeks.org/problems/longest-repeating-character-replacement/1

#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    int maxilen = 0;      // To track the maximum window length
    int maxifreq = 0;     // Frequency of the most common character in the current window
    int l = 0, r = 0;     // Sliding window pointers
    vector<int> freq(26, 0); // Frequency count for each character (assuming uppercase A-Z)

    while (r < s.size()) {
        freq[s[r] - 'A']++;                            // Include current character in frequency map
        maxifreq = max(maxifreq, freq[s[r] - 'A']);    // Update max repeating character freq

        // Check if we need to shrink the window
        // Total chars to change = window size - max repeating char
        if ((r - l + 1) - maxifreq > k) {
            freq[s[l] - 'A']--; // Shrink from the left
            l++;
        }

        // Always update max length if current window is valid
        if ((r - l + 1) - maxifreq <= k) {
            maxilen = max(maxilen, r - l + 1);
        }

        r++; // Expand window
    }

    return maxilen;
}

int main() {
    string s = "AABABBA";
    int k = 1;

    // Output: 4 → "AABA" or "ABBA" after 1 replacement
    cout << "Length of the longest substring with at most " << k 
         << " character replacements: " << characterReplacement(s, k) << endl;

    return 0;
}
