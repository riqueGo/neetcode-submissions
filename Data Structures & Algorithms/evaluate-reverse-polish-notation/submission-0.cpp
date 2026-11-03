class Solution {
private:
    bool isOperator(string op) {
        return op == "+" || op == "-" || op == "*" || op == "/";
    }

    int evalOp(int a, int b, string op) {
        if(op == "+") return a + b;
        else if(op == "-") return a - b;
        else if(op == "*") return a * b;
        else return a / b;
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;


        for(string t : tokens) {
            if(isOperator(t)) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(evalOp(a,b,t));
            } else st.push(stoi(t));
        }

        return st.top();
    }
};
