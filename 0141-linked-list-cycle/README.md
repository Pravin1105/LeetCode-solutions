<h2><a href="https://leetcode.com/problems/linked-list-cycle">141. Linked List Cycle</a></h2><h3>Easy</h3><hr><p>Given <code>head</code>, the head of a linked list, determine if the linked list has a cycle in it.</p>

<p>There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the&nbsp;<code>next</code>&nbsp;pointer. Internally, <code>pos</code>&nbsp;is used to denote the index of the node that&nbsp;tail&#39;s&nbsp;<code>next</code>&nbsp;pointer is connected to.&nbsp;<strong>Note that&nbsp;<code>pos</code>&nbsp;is not passed as a parameter</strong>.</p>

<p>Return&nbsp;<code>true</code><em> if there is a cycle in the linked list</em>. Otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png" style="width: 300px; height: 97px; margin-top: 8px; margin-bottom: 8px;" />
<pre>
<strong>Input:</strong> head = [3,2,0,-4], pos = 1
<strong>Output:</strong> true
<strong>Explanation:</strong> There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png" style="width: 141px; height: 74px;" />
<pre>
<strong>Input:</strong> head = [1,2], pos = 0
<strong>Output:</strong> true
<strong>Explanation:</strong> There is a cycle in the linked list, where the tail connects to the 0th node.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png" style="width: 45px; height: 45px;" />
<pre>
<strong>Input:</strong> head = [1], pos = -1
<strong>Output:</strong> false
<strong>Explanation:</strong> There is no cycle in the linked list.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of the nodes in the list is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li><code>pos</code> is <code>-1</code> or a <strong>valid index</strong> in the linked-list.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Can you solve it using <code>O(1)</code> (i.e. constant) memory?</p>


## Approach

The solution uses **Floyd's Cycle Detection Algorithm**, also known as the **Tortoise and Hare Algorithm**, to determine whether a linked list contains a cycle.

Two pointers are initialized at the head of the linked list:

- `slow` moves **one node** at a time.
- `fast` moves **two nodes** at a time.

There are two possible outcomes:

- If the linked list **does not contain a cycle**, the `fast` pointer will eventually reach the end of the list (`NULL`).
- If the linked list **contains a cycle**, the `fast` pointer will eventually catch up with the `slow` pointer, causing both pointers to meet inside the cycle.

As soon as the two pointers meet, a cycle is confirmed.

### Example

Input:

```
3 → 2 → 0 → -4
    ↑       ↓
    └───────┘
```

Pointer movement:

| Step | Slow | Fast |
|-----:|:----:|:----:|
| Start | 3 | 3 |
| 1 | 2 | 0 |
| 2 | 0 | 2 |
| 3 | -4 | -4 |

Since both pointers meet at the same node, the linked list contains a cycle.

Output:

```
true
```

---

## Algorithm

1. Initialize two pointers:
   - `slow = head`
   - `fast = head`
2. While:
   - `fast` is not `NULL`, and
   - `fast->next` is not `NULL`
   - Move:
     - `slow = slow->next`
     - `fast = fast->next->next`
3. If `slow == fast`, return `true`.
4. If the loop terminates because `fast` reaches `NULL`, return `false`.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - In the worst case, each node is visited at most a constant number of times before the pointers either meet or the list ends.

- **Space Complexity:** `O(1)`
  - Only two pointers are used regardless of the size of the linked list.

---

## Key Idea

The fast pointer moves twice as quickly as the slow pointer. If a cycle exists, the fast pointer will eventually lap the slow pointer and both will meet inside the cycle. If there is no cycle, the fast pointer reaches the end of the list first, proving that the list is acyclic. This provides an efficient solution with linear time and constant extra space.
