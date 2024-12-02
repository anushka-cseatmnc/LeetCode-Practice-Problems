class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumCount;
        sumCount[0] = 1;
        int currentSum = 0, result = 0;
        for (int num : nums) {
            currentSum += num;
            if (sumCount.find(currentSum - k) != sumCount.end()) {
                result += sumCount[currentSum - k];
            }
            sumCount[currentSum]++;
        }
        return result;       
    }
};