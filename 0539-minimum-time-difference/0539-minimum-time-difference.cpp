class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
    
    for (const string& time : timePoints) {
        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3, 2));
        minutes.push_back(h * 60 + m);
    }

    sort(minutes.begin(), minutes.end());

    int minDiff = 1440 - (minutes.back() - minutes[0]);

    for (int i = 1; i < minutes.size(); ++i) {
        minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
    }

    return minDiff;
        
    }
};