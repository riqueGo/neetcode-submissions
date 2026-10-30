class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int greatest = -11, productUntil = 1;

        for(int i = 0; i < nums.size(); i++)
        {
            productUntil *= nums[i];
            greatest = max(greatest, max(nums[i], productUntil));
        }
        return greatest;
    }
};

/*
<greatest,productUntil>
[1,2,-3,4,-1]
i = 4
g = 24
p = 24

*/
