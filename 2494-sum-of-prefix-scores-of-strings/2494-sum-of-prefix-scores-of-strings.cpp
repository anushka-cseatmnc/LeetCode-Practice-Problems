#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
using namespace std;

struct TrieNode {
    unordered_map<char, unique_ptr<TrieNode>> children;
    int count = 0;
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;

        for (const string& word : words)
            insert(word);

        for (const string& word : words)
            ans.push_back(getScore(word));

        return ans;
    }

private:
    unique_ptr<TrieNode> root = make_unique<TrieNode>();

    void insert(const string& word) {
        TrieNode* node = root.get();
        for (const char c : word) {
            if (!node->children[c])
                node->children[c] = make_unique<TrieNode>();
            node = node->children[c].get();
            ++node->count;
        }
    }

    int getScore(const string& word) {
        TrieNode* node = root.get();
        int score = 0;
        for (const char c : word) {
            node = node->children[c].get();
            score += node->count;
        }
        return score;
    }
};