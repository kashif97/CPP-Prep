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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v1;
        if(root==NULL){
            return v1;
        }
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        while(!q.empty()){
            int count=q.size();
            vector<int> v2;
            for(int i=0;i<count;i++){
                temp=q.front();
                q.pop();
                v2.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            v1.push_back(v2);
        }
        return v1;
    }
};
