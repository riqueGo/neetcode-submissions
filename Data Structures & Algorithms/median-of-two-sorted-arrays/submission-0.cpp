class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> all(nums1.size() + nums2.size());
        int i = 0, j = 0, idx = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) all[idx] = nums1[i++];
            else all[idx] = nums2[j++];
            idx++;
        }

        while(i < nums1.size()) all[idx++] = nums1[i++];
        while(j < nums2.size()) all[idx++] = nums2[j++];

        double ans = 0;

        int mid = all.size()/2;
        if(all.size() % 2 == 0) {
            ans = ((double)(all[mid] + all[mid-1])) /2;
        } else {
            ans = all[mid];
        }

        return ans;
    }
};
