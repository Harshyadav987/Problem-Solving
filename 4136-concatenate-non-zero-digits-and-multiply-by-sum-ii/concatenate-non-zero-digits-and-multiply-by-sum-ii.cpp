class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        // Prefix count of non-zero digits in the original string
        vector<int> cntNZ(n + 1, 0);

        // Prefix hash (concatenated number) and prefix digit sum
        vector<long long> prefHash(1, 0), prefSum(1, 0);

        for (int i = 0; i < n; i++) {
            cntNZ[i + 1] = cntNZ[i];

            if (s[i] != '0') {
                int d = s[i] - '0';
                cntNZ[i + 1]++;

                prefHash.push_back((prefHash.back() * 10 + d) % MOD);
                prefSum.push_back(prefSum.back() + d);
            }
        }

        int m = prefHash.size() - 1;

        // Powers of 10
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = cntNZ[l];
            int R = cntNZ[r + 1] - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long x = (prefHash[R + 1] -
                           prefHash[L] * pow10[len] % MOD +
                           MOD) % MOD;

            long long sum = prefSum[R + 1] - prefSum[L];

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};