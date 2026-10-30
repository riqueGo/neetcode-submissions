class Solution {
public:
    int maxProduct(vector<int>& nums) {
        pair<int,int> curr, prev, temp;
        curr = {-11,1};
        int greatest, productUntil;

        for(int i = 0; i < nums.size(); i++)
        {
            temp = curr;
            productUntil = curr.second*nums[i];
            greatest = max(curr.first, max(nums[i], productUntil));
            curr = {greatest, productUntil};
            prev = temp;
        }
        return curr.first;
    }
};

/*
<greatest,productUntil>
[1,2,-3,4,-1]

[<-11,1>,]
*/
