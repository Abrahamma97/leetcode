/* Question:
num1 = 123
num2 = 478
sum =  601

1->2->3
4->7->8

 Result 6->0->1
3 2 1
8 7 4
----------
1 0 6

6 0 1
Algorithm:


*/
#include <stdio.h>
#include <stdlib.h>

struct node {
  int val;
  struct node* next;
};


void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

void revLinkedlist(struct node** head) {
  struct node *current = *head, *prev = NULL, *next = NULL;
  while(current != NULL) {

    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head = prev;
}

struct node* addLinkedlist(struct node* list1, struct node* list2) {
  int carry = 0;
  int sum = 0;
  struct node *res = NULL, *last_res = NULL, *rl1 = NULL, *rl2 = NULL;
  revLinkedlist(&list1);
  rl1 = list1;
  printList(rl1);
  revLinkedlist(&list2);
  rl2 = list2;
  printList(rl2);
    //.  123 and 478 =>. 321 and 874

  while(rl1 != NULL || rl2 != NULL || carry != 0) {

    sum = carry;
    if(rl1 != NULL) {
      sum += rl1->val;
      rl1 = rl1->next;
    }
    if(rl2 != NULL) {
      sum += rl2->val;
      rl2 = rl2->next;
    }
    carry = sum/10;
    sum = sum%10;
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->val = sum;
    newnode->next = NULL;

    if(res == NULL) {
      res = newnode;
      last_res = res;
    }
      res->next = newnode;
      res = res->next;
  }

  // 106
  revLinkedlist(&last_res);

  return last_res;
}
int main() {

struct node node1 = {1, NULL};
struct node node2 = {2, NULL};
struct node node3 = {3, NULL};
struct node node4 = {4, NULL};
struct node node5 = {7, NULL};
struct node node6 = {8, NULL};
// Link the nodes together
node1.next = &node2;
node2.next = &node3;
node4.next = &node5;
node5.next = &node6;

struct node* list1 = &node1;
struct node* list2 = &node4;

struct node* res = addLinkedlist(list1, list2);

printList(res);

}
