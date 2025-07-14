#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *createNode(int val);
void freeList(struct ListNode *head);
struct ListNode *reverseList(struct ListNode *head);
bool isPalindrome(struct ListNode *head);
void printList(struct ListNode *head);

int main()
{

    struct ListNode *head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(2);
    head1->next->next->next = createNode(1);
    printf("Test 1 [1, 2, 2, 1]: %s\n", isPalindrome(head1) ? "true" : "false");
    freeList(head1);

    struct ListNode *head2 = createNode(1);
    head2->next = createNode(2);
    printf("Test 2 [1, 2]: %s\n", isPalindrome(head2) ? "true" : "false");
    freeList(head2);

    struct ListNode *head3 = createNode(1);
    head3->next = createNode(2);
    head3->next->next = createNode(3);
    head3->next->next->next = createNode(4);
    head3->next->next->next->next = createNode(5);
    printf("Test 3 [1, 2, 3, 4, 5]: %s\n", isPalindrome(head3) ? "true" : "false");
    freeList(head3);

    return 0;
}

struct ListNode *createNode(int val)
{
    struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void freeList(struct ListNode *head)
{
    struct ListNode *current = head;
    while (current != NULL) {
        struct ListNode *next = current->next;
        free(current);
        current = next;
    }
}

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *prev = NULL;
    struct ListNode *current = head;
    while (current != NULL) {
        struct ListNode *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode *head)
{
    if (head == NULL || head->next == NULL) {
        return false;
    }

    struct ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
       slow = slow->next;
       fast = fast->next->next;
    }

    struct ListNode *secondHalfStart = slow->next;
    slow->next = NULL;
    struct ListNode *reverseSecondHalf = reverseList(secondHalfStart);
    
    struct ListNode *p1 = head;
    struct ListNode *p2 = reverseSecondHalf;
    bool isPalin = true;

    while (p2 != NULL) {
       if (p1->val != p2->val) {
          isPalin = false;
          break;
       }
       p1 = p1->next;
       p2 = p2->next;
    }

    slow->next = reverseSecondHalf;
    
    return isPalin; 
}

void printList(struct ListNode *head)
{
    struct ListNode *current = head;
    printf("[");
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) printf(", ");
        current = current->next;
    }
    printf("]\n");
}
