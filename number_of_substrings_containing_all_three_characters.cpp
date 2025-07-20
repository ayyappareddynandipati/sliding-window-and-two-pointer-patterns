// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
// https://www.geeksforgeeks.org/problems/count-substring/1

#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    int cnt = 0;
    vector<int> lastseen(3, -1);  // Stores the latest index where 'a', 'b', and 'c' were seen

    for (int i = 0; i < s.size(); i++) {
        lastseen[s[i] - 'a'] = i;  // Update the latest index for current character

        // Only count when all 'a', 'b', and 'c' have been seen at least once
        if (lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1) {
            // The number of valid substrings ending at index i is (1 + minimum index among a, b, and c)
            cnt += (1 + min({lastseen[0], lastseen[1], lastseen[2]}));
        }
    }

    return cnt;
}

int main() {
    string s = "abcabc";
    cout << "Number of substrings containing all three characters: " 
         << numberOfSubstrings(s) << endl; // Output: 10
    return 0;
}
