/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode)) ;
    if (root != NULL) {
        if(root->left != NULL && root->right != NULL) {
            node = root->left;
            root->left = invertTree((root->right));
            root->right = invertTree(node);
        } else if(root->left != NULL) {
            node = root->left;
            root->left = NULL;
            root->right = invertTree(node);
        } else {
            root->left = invertTree((root->right));
            root->right = NULL;
        } 
    }
    return root;

}
