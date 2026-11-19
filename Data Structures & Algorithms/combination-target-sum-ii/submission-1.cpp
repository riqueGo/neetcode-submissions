class Solution {
private:
    vector<vector<int>> ans;

    void solve(vector<int>& candidates, vector<int>& curr, int target, int sum, int idx) {
        if(sum >= target || idx >= candidates.size()) {
            if(sum == target) ans.push_back(curr);
            return;
        }

        curr.push_back(candidates[idx]);
        solve(candidates, curr, target, sum+candidates[idx], ++idx);
        curr.pop_back();

        while(idx < candidates.size() && candidates[idx] == candidates[idx-1])idx++;
        solve(candidates, curr, target, sum, idx);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        solve(candidates, curr, target, 0, 0);
        return ans;
    }
};
