/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> maxLevelVal;
        if(root == NULL)return maxLevelVal;
        queue<TreeNode*> levelQueue;
        levelQueue.push(root);
        while(!levelQueue.empty()){
            int sz = levelQueue.size();
            int maxValNode = INT_MIN;
            while(sz-->0){
                TreeNode * currNode = levelQueue.front();
                maxValNode = max(currNode->val, maxValNode);
                levelQueue.pop();
                if(currNode->left != NULL){
                    levelQueue.push(currNode->left);
                }
                if(currNode->right != NULL){
                    levelQueue.push(currNode->right);
                }
            }
            maxLevelVal.push_back(maxValNode);
        }
        return maxLevelVal;
    }
};
