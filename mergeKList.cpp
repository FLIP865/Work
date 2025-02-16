#include <iostream>
#include <queue>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* mergeKList(std::vector<ListNode*>& lists) {
            auto cmp = [](ListNode *a, ListNode *b){ return a->val > b->val; };
            std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> PQ(cmp);

            for (auto l : lists)
                if (l) PQ.push(l);

            ListNode dummy(0);
            ListNode* curr = &dummy;

            while (!PQ.empty()) {
                ListNode *n = PQ.top();
                PQ.pop();
                curr->next = n;
                curr = n;
                if (n->next) PQ.push(n->next);
            }
            return dummy.next;
        }
};

void print_mergeKList(ListNode* head) {
    std::cout << "[";
    while (head) {
        std::cout << head->val;
        if (head->next) std::cout << "->";
        head = head->next;
    }
    std::cout << "]\n";
}

ListNode* createList(const std::vector<int>& values) {
    ListNode dummy(0);
    ListNode* curr = &dummy;
    for (int val : values) {
        curr->next = new ListNode(val);
        curr = curr->next;
    }
    return dummy.next;
}

int main() {
    Solution solution;

    std::vector<ListNode*> lists = {
        createList({1, 4, 5}),
        createList({1, 3, 4}),
        createList({2, 6})
    };

    ListNode* result = solution.mergeKList(lists);

    print_mergeKList(result);

    while (result) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }
    return 0;
}
