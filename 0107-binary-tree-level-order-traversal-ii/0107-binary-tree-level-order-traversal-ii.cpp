
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root==nullptr) return ans;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>level;
            for(int i=0;i<n;i++){
                TreeNode*temp=q.front();
                level.push_back(temp->val);
                q.pop();
                if(temp->left!=nullptr){
                    q.push(temp->left);
                }
                if(temp->right!=nullptr){
                    q.push(temp->right);
                }
                
            }
            ans.push_back(level);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

        
    
};