class Solution {
private:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<int>& curr, int idx) {
        if(curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        for(int i = idx; i > 0; i--) {
            solve(nums, curr, idx+1);
            swap(curr[i], curr[i-1]);
        }
        solve(nums, curr, idx+1);
        curr.erase(curr.begin());
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        solve(nums, curr, 0);
        return ans;
    }
};
