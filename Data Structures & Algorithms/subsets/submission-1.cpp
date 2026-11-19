class Solution {
private:
    vector<vector<int>> ans;

    void solve (vector<int>& nums, vector<int>& curr, int idx) {
        if(idx == nums.size()){
            ans.push_back(curr);
            return;
        }

        solve(nums, curr, idx+1);
        curr.push_back(nums[idx]);
        solve(nums, curr, idx+1);
        curr.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        solve(nums, curr, 0);
        return ans;
    }
};
