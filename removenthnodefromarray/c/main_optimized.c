/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 typedef struct ListNode node;
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
node* slow  = head;
node* fast = head;
if(head == NULL) {
    return NULL;
}
while(n){
    fast = fast->next;
    n--;
}
if(fast == NULL) {
    slow = slow->next;
    return slow;
} else {
    while(fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}
}
