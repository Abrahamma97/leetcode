/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
    if(head == NULL) {
        return NULL;
    }
    struct Node *current = head, *newnode = NULL;

    while(current != NULL) {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->val = current->val;
        newnode->next = current->next;
        newnode->random = NULL;
        current->next = newnode;
        current = newnode->next;
    }
   
    current = head;
    while(current != NULL) {
            if(current->random != NULL) {
                current->next->random = current->random->next;
            }
            if(current->next != NULL) {
                    current = current->next->next;
                } else {
                    break;
                }  
    }
    current = head->next;
    while(current != NULL) {
        if(current->next != NULL) {
            current->next = current->next->next;
            current = current->next;
        } else {
            break;
        }
        
    }
	return head->next;
}
