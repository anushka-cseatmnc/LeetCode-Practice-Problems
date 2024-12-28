class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
          int n = nums.size();
        vector<int> sum(n + 1, 0), left(n, 0), right(n, 0), result(3, 0);

        for (int i = 0; i < n; ++i)
            sum[i + 1] = sum[i] + nums[i];

        for (int i = k, total = sum[k] - sum[0]; i < n; ++i) {
            if (sum[i + 1] - sum[i + 1 - k] > total) {
                left[i] = i + 1 - k;
                total = sum[i + 1] - sum[i + 1 - k];
            } else {
                left[i] = left[i - 1];
            }
        }

        right[n - k] = n - k;
        for (int i = n - k - 1, total = sum[n] - sum[n - k]; i >= 0; --i) {
            if (sum[i + k] - sum[i] >= total) {
                right[i] = i;
                total = sum[i + k] - sum[i];
            } else {
                right[i] = right[i + 1];
            }
        }

        int max_sum = 0;
        for (int i = k; i <= n - 2 * k; ++i) {
            int l = left[i - 1], r = right[i + k];
            int total = (sum[i + k] - sum[i]) + (sum[l + k] - sum[l]) + (sum[r + k] - sum[r]);
            if (total > max_sum) {
                max_sum = total;
                result = {l, i, r};
            }
        }

        return result;
    }
};