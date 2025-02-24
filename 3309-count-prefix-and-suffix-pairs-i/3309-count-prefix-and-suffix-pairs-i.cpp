class Solution {
public:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int len1 = str1.length(), len2 = str2.length();
        if (len1 > len2) return false;
        return str2.substr(0, len1) == str1 && str2.substr(len2 - len1) == str1;
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
         int count = 0, n = words.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    ++count;
                }
            }
        }
        return count;
    }
};