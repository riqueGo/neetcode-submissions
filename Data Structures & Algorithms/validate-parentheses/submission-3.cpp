class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> umap = {
            {'}', '{'},
            {']', '['},
            {')', '('}
        };

        stack<char> st;

        for(char ch : s) {
            if(umap.find(ch) != umap.end()) {
                if(st.empty() || umap[ch] != st.top()) return false;
                st.pop();
            } else {
                st.push(ch);
            }
        }

        return st.empty();
    }
};
