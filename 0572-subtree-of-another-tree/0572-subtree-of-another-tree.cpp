/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

  
    bool sameTree(TreeNode* p, TreeNode* q) {

        if (p == nullptr && q == nullptr)
            return true;

        if (p == nullptr || q == nullptr)
            return false;

        if (p->val != q->val)
            return false;

        return sameTree(p->left, q->left) &&
               sameTree(p->right, q->right);
    }

    bool isSubtree(TreeNode* p, TreeNode* q) {

       
        if (q == nullptr)
            return true;

      
        if (p == nullptr)
            return false;

        
        if (sameTree(p, q))
            return true;

    
        return isSubtree(p->left, q) ||
               isSubtree(p->right, q);
    }
};