## 题目

[2. 两数相加](https://leetcode.cn/problems/add-two-numbers/)

---

给你两个 **非空** 的链表，表示两个非负的整数。它们每位数字都是按照 **逆序** 的方式存储的，并且每个节点只能存储 **一位** 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

**示例 1：**

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/01/02/addtwonumber1.jpg)

```txt
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
```

**示例 2：**

```txt
输入：l1 = [0], l2 = [0]
输出：[0]
```

**示例 3：**

```txt
输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]
```

**提示：**

- 每个链表中的节点数在范围 `[1, 100]` 内
- `0 <= Node.val <= 9`
- 题目数据保证列表表示的数字不含前导零

## 解析

按位模拟加法，注意循环条件不要忘记 `|| sum`。

## 代码

### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
```

### Go

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) (ans *ListNode) {
    cur, sum := ans, 0
    for l1 != nil || l2 != nil || sum != 0 {
        if l1 != nil {
            sum += l1.Val
            l1 = l1.Next
        }
        if l2 != nil {
            sum += l2.Val
            l2 = l2.Next
        }
        if ans == nil {
            ans = &ListNode{Val: sum % 10}
            cur = ans
        } else {
            cur.Next = &ListNode{Val: sum % 10}
            cur = cur.Next
        }
        sum = sum / 10
    }
    return
}
```

### Python

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        cur = dummy
        sum = 0
        while l1 or l2 or sum:
            if l1:
                sum += l1.val
                l1 = l1.next
            if l2:
                sum += l2.val
                l2 = l2.next
            cur.next = ListNode(sum % 10)
            cur = cur.next
            sum //= 10
        return dummy.next
```
