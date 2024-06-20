class Solution {
public:
    void sortColors(vector<int>& nums) {
         int low = 0, current = 0, high = nums.size() - 1;

    while (current <= high) {
        if (nums[current] == 0) {
            swap(nums[low], nums[current]);
            low++;
            current++;
        } else if (nums[current] == 1) {
            current++;
        } else { // nums[current] == 2
            swap(nums[high], nums[current]);
            high--;
        }
    }
         
    }
};