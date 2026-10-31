class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> fromLToR (n, 1);
        vector<int> fromRToL (n, 1);
        fromLToR[0] = nums[0];
        fromRToL[n-1] = nums[n-1];

        for(int i = 1, j = n-2; i < n; i++, j--) {
            fromLToR[i] = fromLToR[i-1] * nums[i];
            fromRToL[j] = fromRToL[j+1] * nums[j];
        }

        vector<int> ans(n,1);
        ans[0] = fromRToL[1];
        ans[n-1] = fromLToR[n-2];

        for(int i = 1; i < n-1; i++) {
            ans[i] = fromLToR[i-1] * fromRToL[i+1];
        }

        return ans;
    }
};
