class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0, n = pref.length();
        for (const auto& word : words) {
            if (word.substr(0, n) == pref) {
                count++;
            }
        }
        return count;
    }
};