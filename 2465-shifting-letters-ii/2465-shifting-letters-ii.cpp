class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
         int n = s.size();
    vector<int> diff(n + 1, 0);

    for (const auto& shift : shifts) {
        int start = shift[0], end = shift[1], direction = shift[2];
        diff[start] += (direction == 1 ? 1 : -1);
        diff[end + 1] -= (direction == 1 ? 1 : -1);
    }

    int shift_sum = 0;
    for (int i = 0; i < n; ++i) {
        shift_sum += diff[i];
        int new_char = (s[i] - 'a' + shift_sum) % 26;
        if (new_char < 0) new_char += 26;
        s[i] = 'a' + new_char;
    }

    return s;
    }
};