class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> suf(n + 1, m);

        // suf[i] = first position of word2
        // that cannot be matched using word1[i...]
        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }

            suf[i] = j + 1;
        }

        vector<int> ans;

        j = 0;
        bool used = false;

        for (int i = 0; i < n && j < m; i++) {

            // Exact match
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }

            // Use our one mismatch
            else if (!used && suf[i + 1] <= j + 1) {
                ans.push_back(i);
                j++;
                used = true;
            }
        }

        if (ans.size() == m)
            return ans;

        return {};
    }
};