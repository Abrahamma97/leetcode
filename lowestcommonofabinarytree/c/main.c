/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode* current = root;
    while(current != NULL) {
        if(p->val  < current->val && q->val < current->val) {
            current = current->left;
        } else if(p->val  > current->val && q->val > current->val) {
            current = current->right;
        } else{
            return current;
        }

    }
    return current;
    
}
