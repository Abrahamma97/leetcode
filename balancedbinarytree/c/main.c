/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int hbal(struct TreeNode* root, bool* f) {
    if(root ==  NULL) {
        return 0;
    }
    int left = hbal(root->left, f);
    int right = hbal(root->right, f);
    int diff = (left >= right)?(left-right):(right-left);
    if(diff > 1){
        *f = false;
    }
    return 1 + (left>right?left:right); 
}
bool isBalanced(struct TreeNode* root) {
    if( root == NULL) {
        return true;
    }
    bool f = true;
    hbal(root, &f);
    return f;
    
}
