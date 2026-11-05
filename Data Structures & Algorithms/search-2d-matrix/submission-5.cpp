class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0, r = m-1, midColumn;
        while(l <= r) {
            midColumn = l + (r-l)/2;
            if(matrix[midColumn][n-1] < target) l = midColumn+1;
            else if(matrix[midColumn][0] > target) r = midColumn-1;
            else break;
        }

        if(l > r) return false;

        l = 0, r = n-1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(matrix[midColumn][mid] < target) l = mid+1;
            else if(matrix[midColumn][mid] > target) r = mid-1;
            else return true;    
        }

        return false;
    }
};
