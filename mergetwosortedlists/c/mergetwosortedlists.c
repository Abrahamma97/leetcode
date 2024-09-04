/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* newl = NULL;
    struct ListNode* head = NULL;
    if(list1 == NULL && list2 == NULL) {
        return NULL;
    } else if(list1 == NULL) {
        return list2;
    } else if(list2 == NULL) {
        return list1;
    }
    if(list1->val <= list2->val) {
        newl = list1;
        list1 =  list1->next;
    } else {
        newl = list2;
        list2 = list2->next;
    }
    
    head = newl;

    while(list1 != NULL || list2 != NULL) {
        if(list2 == NULL || (list1 != NULL && list1->val <= list2->val)) {
            newl->next = list1;
            list1 = list1->next;
        }  else {
            newl->next = list2;
            list2 = list2->next;
        }
        newl = newl->next;
    }
    return head;
}
