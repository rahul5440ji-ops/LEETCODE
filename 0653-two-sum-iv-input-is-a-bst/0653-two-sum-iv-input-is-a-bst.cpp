class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;

        return dfs(root, k, st);
    }

    bool dfs(TreeNode* root, int k, unordered_set<int>& st) {
        if (root == nullptr)
            return false;

        if (st.count(k - root->val))
            return true;

        st.insert(root->val);

        return dfs(root->left, k, st) ||
               dfs(root->right, k, st);
    }
};