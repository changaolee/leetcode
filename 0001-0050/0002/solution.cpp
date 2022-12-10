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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0), *cur = dummy;
        int sum = 0;
        while (l1 || l2 || sum) {
            if (l1) sum += l1->val, l1 = l1->next;
            if (l2) sum += l2->val, l2 = l2->next;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            sum /= 10;
        }
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
        buildList({2, 4, 3}),
        buildList({5, 6, 4}),
        buildList({7, 0, 8}),
    });
    examples.push_back({
        buildList({0}),
        buildList({0}),
        buildList({0}),
    });
    examples.push_back({
        buildList({9, 9, 9, 9, 9, 9, 9}),
        buildList({9, 9, 9, 9}),
        buildList({8, 9, 9, 9, 0, 0, 0, 1}),
    });
    
    Solution *solve = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        ListNode *ans = solve->addTwoNumbers(examples[i].l1, examples[i].l2);
        if (check(ans, examples[i].ans)) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    
    return 0;
}