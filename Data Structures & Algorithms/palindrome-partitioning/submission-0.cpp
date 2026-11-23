class Solution {
private:
    vector<vector<string>> ans;

    void solve(vector<string>& curr, const string& s, int i) {
        if(i >= s.length()) {
            ans.push_back(curr);
            return;
        }

        for(int j = i; j < s.length(); j++) {
            if(isPalindrome(s, i, j)) {
                curr.push_back(s.substr(i, j-i+1));
                solve(curr, s, j+1);
                curr.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int i, int j) {
        while(i <= j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        solve(curr, s, 0);
        return ans;
    }
};
