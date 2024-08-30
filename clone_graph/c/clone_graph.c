/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */
struct Node* clonenode(struct Node* s, struct Node** hashmap) {
    if(s == NULL) {
        return s;
    }
    if(hashmap[s->val - 1] != NULL) {
        return hashmap[s->val - 1];
    }
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    hashmap[s->val -1] = newnode;
    newnode->val = s->val;
    newnode->numNeighbors = s->numNeighbors;
    if (newnode->numNeighbors > 0) {
        newnode -> neighbors = (struct Node**)malloc(newnode->numNeighbors * sizeof(struct Node*));
    } else {
        newnode -> neighbors = NULL;
    }
    for(int i = 0; i < newnode->numNeighbors; i++) {
        newnode->neighbors[i] = clonenode(s->neighbors[i], hashmap);
    }
    return newnode;
}
struct Node *cloneGraph(struct Node *s) {
    struct Node** hashmap = (struct Node**)malloc(sizeof(struct Node*)*100);
    for(int i = 0; i < 100; i++) {
        hashmap[i] = NULL;
    }
    struct Node* res = clonenode(s, hashmap);
    free(hashmap);
    return res;
	
}
