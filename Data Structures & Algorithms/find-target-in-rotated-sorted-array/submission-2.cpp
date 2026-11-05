class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, m;
        while(l <= r) {
            m = l + (r-l)/2;

            if(target == nums[m]) break;
            else if(nums[m] >= nums[r]) {
                if(target > nums[m] || target <= nums[r]) l = m+1;
                else r = m-1;
            } else {
                if(target < nums[m] || target > nums[r]) r = m-1;
                else l = m+1;
            }
        }

        return nums[m] == target ? m : -1;
    }
};
