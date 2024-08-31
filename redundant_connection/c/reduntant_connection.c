/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int findparent(int *parent, int val) {
    if(parent[val] == val)
        return val;
    return(findparent(parent, parent[val]));
 }
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int *res = (int *)malloc(2*sizeof(int));
    *returnSize = 2;
    int parent[edgesSize+1], f1, f2;

    for(int i = 0; i <= edgesSize; i++) {
        parent[i] = i;
    }
    
    for(int i = 0; i < edgesSize; i++) {
        f1 = findparent(parent, edges[i][0]);
        f2 = findparent(parent, edges[i][1]);

        if(f1 == f2){
            res[0] = edges[i][0];
            res[1] = edges[i][1];
        } else{
            parent[f1] = f2;
        }
        
    }
    return res;
}
