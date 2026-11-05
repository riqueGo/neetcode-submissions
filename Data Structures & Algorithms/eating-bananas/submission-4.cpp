class Solution {
private:
    int cellingDivision(int a, int b) {
        int quot = a / b;
        int res = a % b == 0 ? quot : quot+1;
        // cout << a << " " << b << " " << res << endl;
        return res;
    }

    long long hoursByEatingK(int k, vector<int>& piles) {
        long long h = 0;
        for(int p : piles) {
            h += cellingDivision(p,k);
        }
        return h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxVal = 0;
        for(int p : piles) {
            maxVal = max(maxVal, p);
        }

        int l = 1, r = maxVal, m, ans = maxVal;
        long long tmpAns;
        while(l<=r) {
            m = l + (r-l)/2;
            tmpAns = hoursByEatingK(m, piles);
            // cout << m << " " << tmpAns << endl;
            if(tmpAns > h) l = m+1;
            else {
                ans = min(ans, m);
                r = m-1;
            }
        }
        return ans;
    }
};
