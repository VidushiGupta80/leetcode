class Solution {

public:
    double KnightProbability(int N, int K, int r, int c, vector<vector<vector<double>>>& memo) {
        if(K == 0 && r >= 0 && r < N && c >= 0 && c < N)
            return 1;
        if(r < 0 || r >= N || c < 0 || c >= N)
            return 0;
        if(memo[r][c][K] != -1)
            return memo[r][c][K];
        double ans = 0;
        ans += KnightProbability(N, K - 1, r - 2, c - 1, memo);
        ans += KnightProbability(N, K - 1, r - 2, c + 1, memo);
        ans += KnightProbability(N, K - 1, r - 1, c - 2, memo);
        ans += KnightProbability(N, K - 1, r + 1, c - 2, memo);
        ans += KnightProbability(N, K - 1, r - 1, c + 2, memo);
        ans += KnightProbability(N, K - 1, r + 1, c + 2, memo);
        ans += KnightProbability(N, K - 1, r + 2, c - 1, memo);
        ans += KnightProbability(N, K - 1, r + 2, c + 1, memo);
        ans /= 8;
        return memo[r][c][K] = ans;
        
    }
    double knightProbability(int N, int K, int r, int c){
        vector<vector<vector<double>>> memo(N, vector<vector<double>>(N, vector<double>(K+1,-1)));
        return KnightProbability(N, K, r, c, memo);
    }
};