#include <climits>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* mergeTwoList(ListNode* list1, ListNode* list2) {
            ListNode head(0);
            ListNode* curr = &head;
            while (true) {
                if (list1 == nullptr && list2 == nullptr) {
                    return head.next;
                } else if (list1 == nullptr) {
                    curr->next = list2;
                    return head.next;
                } else if (list2 == nullptr) {
                    curr->next = list1;
                    return head.next;
                } else {
                    if (list1->val < list2->val) {
                        curr->next = list1;
                        curr = list1;
                        list1 = list1->next;
                    } else {
                        curr->next = list2;
                        curr = list2;
                        list2 = list2->next;
                    }
                }
            }
        }
};

void print_List(ListNode* head) {
    std::cout << "[";
    while (head) {
        std::cout << "\"" << head->val << "\"";
        if (head->next) {
            std::cout << ", ";
        }
        head = head->next;
    }
    std::cout << "]\n";
}

int main() {
    Solution solution;

    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* result = solution.mergeTwoList(list1, list2);

    print_List(result);

    return 0;
}
