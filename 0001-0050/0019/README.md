## 题目

[19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)

---

给你一个链表，删除链表的倒数第 `n` 个结点，并且返回链表的头结点。

**示例 1：**

![](https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg)

```txt
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
```

**示例 2：**

```txt
输入：head = [1], n = 1
输出：[]
```

**示例 3：**

```txt
输入：head = [1,2], n = 1
输出：[1]
```

**提示：**

- 链表中结点的数目为 `sz`
- `1 <= sz <= 30`
- `0 <= Node.val <= 100`
- `1 <= n <= sz`

**进阶：** 你能尝试使用一趟扫描实现吗？

## 解析

快慢双指针，令快指针先走 n 步，之后两指针再同步移动，直到快指针移动到链表结尾，此时慢指针指向的下一个位置即为要删除元素。

注意：

- 在头部插入一个虚拟结点，可以避免对头结点的特殊处理。
- 边界情况可以测试几个 case 确定。

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
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    dummy := &ListNode{Val: 0}
    slow, fast := dummy, dummy
    dummy.Next = head
    for i := 0; i < n; i++ {
        fast = fast.Next
    }
    for fast.Next != nil {
        slow = slow.Next
        fast = fast.Next
    }
    slow.Next = slow.Next.Next
    return dummy.Next
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
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        slow, fast = dummy, dummy
        dummy.next = head
        for i in range(n):
            fast = fast.next
        while fast.next:
            slow = slow.next
            fast = fast.next
        slow.next = slow.next.next
        return dummy.next
```