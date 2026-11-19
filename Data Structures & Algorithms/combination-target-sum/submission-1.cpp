class Solution {
private:
    vector<vector<int>> ans;

    bool solve(vector<int>& nums, vector<int>& curr, int target, int sum, int start) {
        if(sum >= target) {
            if (sum == target) ans.push_back(curr);
            return true;
        }

        for(int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            bool isSolved = solve(nums, curr, target, sum + nums[i], i);
            curr.pop_back();
            if(isSolved) break;
        }

        return false;
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        solve(nums, curr, target, 0, 0);
        return ans;
    }
};
