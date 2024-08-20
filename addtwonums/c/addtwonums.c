/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = l1;
    int carry = 0, sum = 0;
    if(l1 == NULL || l2 == NULL) {
        return NULL;
    }
    while(head != NULL || l2 != NULL) {
        
        if(l2 == NULL) {
         sum = head->val + carry;   
        } else {
            sum = head->val + l2->val + carry;
        }
        
        head->val = (sum > 9) ? (sum%10):sum;
        carry = (sum > 9) ? (sum/10):0; 
        if(head->next != NULL) {
            head = head->next;
        } else if (l2->next != NULL) {
            printf("Hello\n");

            head->next = l2->next;
            head = head->next;
            l2->next = NULL;
        } else {
            head->next = NULL;
            break;
        }
        if(l2->next != NULL) {
            l2 = l2->next;
        } else {
            l2->val = 0;
        }
    }
    if(carry > 0 ) {
        struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val = carry;
        newnode->next = NULL;
        head->next = newnode;
    }
    return l1;
}
