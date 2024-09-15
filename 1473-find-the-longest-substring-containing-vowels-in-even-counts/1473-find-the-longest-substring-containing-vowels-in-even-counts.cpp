class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length(), mask = 0, maxLen = 0;
        vector<int> pos(32, -1);
        pos[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') mask ^= 1;
            else if (s[i] == 'e') mask ^= 2;
            else if (s[i] == 'i') mask ^= 4;
            else if (s[i] == 'o') mask ^= 8;
            else if (s[i] == 'u') mask ^= 16;
            if (pos[mask] != -1) maxLen = max(maxLen, i + 1 - pos[mask]);
            else pos[mask] = i + 1;
        }
        return maxLen;    
    }
};