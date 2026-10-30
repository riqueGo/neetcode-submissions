class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;

        for(int i = 0; i < nums.size(); i++) {
            int reminder = target-nums[i];
            if(umap.find(reminder) != umap.end()) {
                return {umap[reminder], i};
            }
            umap[nums[i]] = i;
        }

        return {};
    }
};
