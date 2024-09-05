/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int max(int a, int b) {
    return a>b?a:b;
 }
 int finddiam(struct TreeNode* head, int* m) {
    if(head == NULL) {
        return 0;
    }
    int left = finddiam(head->right, m);
    int right = finddiam(head->left, m);
    *m  = max(*m,(left +right));
    return 1+ max(left,right);
 }
int diameterOfBinaryTree(struct TreeNode* root) {
    int m = 0;
    int i =finddiam(root, &m);
    return m;
}
