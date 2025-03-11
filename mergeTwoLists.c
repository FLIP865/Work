#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    struct ListNode dummy;
    struct ListNode* curr = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            curr->next = list1;
            list1 = list1->next;
        } else {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }
    if (list1 != NULL) {
        curr->next = list1;
    } else {
        curr->next = list2;
    }
    return dummy.next;
}

void print_List(ListNode* head) {
    printf("[");
    while (head) {
        printf("\"%d\"", head->val);
        if (head->next) {
            printf(", ");
        }
        head = head->next;
    }
    printf("]\n");
}

void free_list(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    ListNode* list1 = (ListNode*)malloc(sizeof(ListNode));
    list1->val = 1;
    list1->next = (ListNode*)malloc(sizeof(ListNode));
    list1->next->val = 2;
    list1->next->next = (ListNode*)malloc(sizeof(ListNode));
    list1->next->next->val = 4;
    list1->next->next->next = NULL;

    ListNode* list2 = (ListNode*)malloc(sizeof(ListNode));
    list2->val = 1;
    list2->next = (ListNode*)malloc(sizeof(ListNode));
    list2->next->val = 3;
    list2->next->next = (ListNode*)malloc(sizeof(ListNode));
    list2->next->next->val = 4;
    list2->next->next->next = NULL;

    ListNode* result = mergeTwoLists(list1, list2);
    print_List(result);
    free_list(result);

    printf("-------------------------------\n");

    list1 = NULL;
    list2 = NULL;
    result = mergeTwoLists(list1, list2);
    print_List(result);
    free_list(result);

    printf("\n");
    
    list1 = NULL;
    list2 = (ListNode*)malloc(sizeof(ListNode));
    list2->val = 0;
    list2->next = NULL;
    result = mergeTwoLists(list1, list2);
    print_List(result);
    free_list(result);

    return 0;
}