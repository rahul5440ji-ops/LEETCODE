class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int> st;
        vector<int> res(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && temp[st.top()] <= temp[i]) {
                st.pop();
            }
            res[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return res;
    }
};