class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        if (intervals.empty()) return mergedIntervals;
        sort(intervals.begin(), intervals.end());
        vector<int> currentInterval = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= currentInterval[1]) {
                currentInterval[1] = max(currentInterval[1], intervals[i][1]);
            } else {
                mergedIntervals.push_back(currentInterval);
                currentInterval = intervals[i];
            }
        }
        mergedIntervals.push_back(currentInterval);
        return mergedIntervals;
    }
};