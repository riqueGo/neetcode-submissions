class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];

        if(nums.size() == 2)
            return max(nums[0], nums[1]);
            
        return max(helper(nums, 0, nums.size()-1), helper(nums, 1, nums.size()));
    }

    int helper(vector<int>& nums, int start, int end)
    {
        int res = 0, prev = 0, temp;
        for(; start < end; start++)
        {
            temp = res;
            res = max(prev + nums[start], res);
            prev = temp;
        }
        return res;
    }
};
