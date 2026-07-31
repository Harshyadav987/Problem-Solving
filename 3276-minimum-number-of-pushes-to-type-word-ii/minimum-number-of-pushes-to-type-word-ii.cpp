class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        // Count frequency of each letter
        for (char c : word) {
            freq[c - 'a']++;
        }

        // Sort frequencies in descending order
        sort(freq.begin(), freq.end(), greater<int>());

        int ans = 0;

        // 8 letters can have cost 1,
        // next 8 cost 2, etc.
        for (int i = 0; i < 26; i++) {
            int pushes = i / 8 + 1;
            ans += freq[i] * pushes;
        }

        return ans;
    }
};