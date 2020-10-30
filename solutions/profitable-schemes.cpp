const int MAX_N = 101;
const int MOD = 1e9 + 7;

int dp[MAX_N][MAX_N][MAX_N];

class Solution {
private:
    int numWays(vector<int>& group, vector<int>& profit, int n, int G, int P) {
        if (G == 0) {
            return P <= 0 ? 1 : 0;
        }
        if (n == 0) {
            return P <= 0 ? 1 : 0;
        }

        if (dp[n][G][P] != -1) {
            return dp[n][G][P];
        }

        int res = numWays(group, profit, n - 1, G, P);
        if (group[n - 1] <= G) {
            res += numWays(group, profit, n - 1, G - group[n - 1], max(0, P - profit[n - 1]));
            res %= MOD;
        }
        dp[n][G][P] = res;
        return res;
    }
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        for (int i = 0; i < MAX_N; ++i) {
            for (int j = 0; j < MAX_N; ++j) {
                for (int k = 0; k < MAX_N; ++k) {
                    dp[i][j][k] = -1;
                }
            }
        }
        return numWays(group, profit, group.size(), G, P);
    }
};
