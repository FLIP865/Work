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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* fast = head;
            ListNode* slow = head;
            for (int i = 0; i < n; i++) fast = fast->next;
            if (fast == NULL) return head->next;
            while (fast->next != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
            ListNode* delNode = slow->next;
            slow->next = slow->next->next;
            free(delNode);
            return head;
        }
};

void print_listNode(ListNode* head) {
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

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    ListNode* result = solution.removeNthFromEnd(head, n);
    
    print_listNode(result);

    while (result) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }
    return 0;
}
