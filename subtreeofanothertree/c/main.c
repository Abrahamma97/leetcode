/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool equaltree(struct TreeNode* root1, struct TreeNode* root2 ) {
    if(root1 == NULL && root2 == NULL) {
        return true;
    } else {
        if(root1 == NULL || root2 == NULL || root1->val != root2->val) {
            return false;
        }
        return (equaltree(root1->left, root2->left) && equaltree(root1->right, root2->right));

    }
}
bool isSubtree(struct TreeNode* root, struct TreeNode* subroot) {
    if(root == NULL) {
        return false;
    }
    bool compare = equaltree(root,subroot);
        printf("The node is %d and bool is %d\n", root->val, compare);


    return (isSubtree(root->left,subroot) || isSubtree(root->right,subroot) || compare );
    
}
