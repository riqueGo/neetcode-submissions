class Solution {
private:
    vector<string> ans;

    void solve(string& curr, int open, int close) {
        if(open == 0 && close == 0) {
            ans.push_back(curr);
            return;
        }

        if(open > 0) {
            solve(curr += "(", open-1, close);
            curr.pop_back();
        }
        if(close > open){
            solve(curr += ")", open, close-1);
            curr.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string s;
        solve(s, n, n);
        return ans;
    }
};
