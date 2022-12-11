#include <iostream>
#include <vector>

using namespace std;

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
        ListNode *dummy = new ListNode(0);
        ListNode *slow = dummy, *fast = dummy;
        dummy->next = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};

struct Example {
    ListNode *head;
    int n;
    ListNode *ans;
};

ListNode* buildList(vector<int> nums) {
    ListNode *dummy = new ListNode(0), *cur = dummy;
    for (auto& num: nums) {
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    return dummy->next;
}

bool check(ListNode* l1, ListNode* l2) {
    ListNode *p = l1, *q = l2;
    while (p && q && p->val == q->val) {
        p = p->next;
        q = q->next;
    }
    return p == q;
}

int main() {
    vector<Example> examples;
    examples.push_back({
        buildList({1, 2, 3, 4, 5}),
        2,
        buildList({1, 2, 3, 5}),
    });
    examples.push_back({
        buildList({1}),
        1,
        buildList({}),
    });
    examples.push_back({
        buildList({1, 2}),
        1,
        buildList({1}),
    });

    
    Solution *solve = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        ListNode *ans = solve->removeNthFromEnd(examples[i].head, examples[i].n);
        if (check(ans, examples[i].ans)) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    
    return 0;
}