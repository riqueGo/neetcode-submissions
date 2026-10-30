class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int>dp(amount+1, INT_MAX);
        dp[0] = 0;
        int tempMin;

        for(int i = 1; i < amount+1; i++)
        {
            for(int j = 0; j < coins.size() && i >= coins[j]; j++)
            {
                tempMin = min(dp[i-coins[j]], dp[i]);
                if(tempMin != INT_MAX && dp[i] != tempMin)
                    dp[i] = tempMin+1;
            }
        }

        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};

/*
coins=[11, 22, 33, 44, 55, 66, 77, 88, 99, 111]
amount=330
*/