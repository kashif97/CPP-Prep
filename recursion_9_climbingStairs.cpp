class Solution {

public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return climbStairsHelper(n, dp);
    }
private:
    int climbStairsHelper(int n, vector<int> &dp){
        if(n==0 || n ==1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] = climbStairsHelper(n-1, dp)+climbStairsHelper(n-2, dp);
        return dp[n];
    }
};