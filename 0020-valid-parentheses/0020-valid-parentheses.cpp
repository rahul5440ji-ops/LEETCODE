class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char ch : s) {
            // Push opening brackets onto the stack
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                // If we see a closing bracket but the stack is empty, it's invalid
                if (st.empty()) {
                    return false;
                }
                
                char top = st.top();
                st.pop();
                
                // Check if the current closing bracket matches the top opening bracket
                if ((ch == ')' && top != '(') ||
                    (ch == ']' && top != '[') ||
                    (ch == '}' && top != '{')) {
                    return false;
                }
            }
        }
        
        // If the stack is empty, all brackets were properly matched
        return st.empty();
    }
};