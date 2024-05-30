class Solution {
public:
    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    // Function to evaluate a postfix expression.
    int evaluatePostfix(std::string S) {
        std::stack<int> st;
        for (char c : S) {
            if (isOperator(c)) {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (c == '+') {
                    st.push(b + a);  // Note the order: b first, then a
                } else if (c == '-') {
                    st.push(b - a);  // Note the order: b first, then a
                } else if (c == '*') {
                    st.push(b * a);
                } else if (c == '/') {
                    st.push(b / a);  // Note the order: b first, then a
                }
            } else {
                st.push(c - '0');  // Convert char to int by subtracting '0'
            }
        }
        return st.top();  // The result is the last element in the stack
    }
};
