class Solution {
public:
    bool isMatch(string s, string p) {
        int S = s.size();
        int P = p.size();
        vector<vector<bool>> dp(S + 1, vector<bool>(P + 1, false));
        dp[0][0] = true;

        for (int j = 1; j <= P; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= S; ++i) {
            for (int j = 1; j <= P; ++j) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[S][P];
    }
};