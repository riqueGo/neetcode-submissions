class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r =  matrix.size()-1, m, rowIdx;

        while(l<=r) {
            m = l+(r-l)/2;
            if(target >= matrix[m][0]) {
                l = m+1;
                rowIdx = m;
            } else r = m-1;
        }

        l = 0; r = matrix[rowIdx].size()-1;

        while(l <= r) {
            m = l+(r-l)/2;

            if(matrix[rowIdx][m] > target) r = m-1;
            else if(matrix[rowIdx][m] < target) l = m+1;
            else return true;
        }

        return false;
    }
};
