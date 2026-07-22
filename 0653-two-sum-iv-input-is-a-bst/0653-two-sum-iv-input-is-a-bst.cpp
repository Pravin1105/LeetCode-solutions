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
    void traversal(TreeNode* root, vector<int> &v){
        if(root == NULL) return;
        traversal(root->left, v);
        v.push_back(root->val);
        traversal(root->right, v);
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        traversal(root, v);
        int n = v.size(), i = 0, j = n-1;
        while(i<j){
            if(v[i] + v[j] == k) return true;
            else if(v[i] + v[j] < k) i++;
            else j--;
        }
        return false;
    }
};