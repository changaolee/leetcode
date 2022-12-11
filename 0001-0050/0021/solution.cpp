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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0), *cur = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                cur->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy->next;
    }
};

struct Example {
    ListNode *l1, *l2;
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
        buildList({1, 2, 4}),
        buildList({1, 3, 4}),
        buildList({1, 1, 2, 3, 4, 4}),
    });
    examples.push_back({
        buildList({}),
        buildList({}),
        buildList({}),
    });
    examples.push_back({
        buildList({}),
        buildList({0}),
        buildList({0}),
    });
    
    Solution *solve = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        ListNode *ans = solve->mergeTwoLists(examples[i].l1, examples[i].l2);
        if (check(ans, examples[i].ans)) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    
    return 0;
}