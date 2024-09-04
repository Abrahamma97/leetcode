/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reversef(struct ListNode** head) {
    struct ListNode *prev = NULL, *current = *head, *next = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev =  current;
        current = next;
    }
    *head = prev;
}

void mergef(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1, *p2;

    while(l1 != NULL) {
        p1 = l1->next;
        p2 = l2->next;
        
        l1->next = l2;
        if(p1 == NULL) {
            break;
        }
        l2->next = p1;

        l1 = p1;
        l2 = p2;
    }
}

void reorderList(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head;
    if(head == NULL) {
        return;
    } else if(head->next == NULL) {
        return;
    }
    fast = head->next;
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;
    reversef(&fast);
    slow = head;

    mergef(slow,fast);
    
}
