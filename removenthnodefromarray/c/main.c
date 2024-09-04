/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reversef(struct ListNode** head) {
    struct ListNode *current = *head, *prev = NULL, *next = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
} 
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *temp, *current = head;
    if((current->next) == NULL && ( n == 1)) {
        free(current);
        return NULL;
    } 
    reversef(&current);
    head = current;
    if((current->next) != NULL && ( n == 1)) {
        temp = current;
        current = current->next;
        reversef(&current);
        free(temp);
        return current;
    }
    for(int i = 2; i < n; i++) {
    current = current->next;
    }
    temp = current->next;
    current->next = temp->next;
    free(temp);
    reversef(&head);
    return head;
}
