<h2><a href="https://leetcode.com/problems/linked-list-cycle-ii/">142. Linked List Cycle II</a></h2><h3>Medium</h3><hr><p>Given the <code>head</code> of a linked list, return <em>the node where the cycle begins. If there is no cycle, return </em><code>null</code>.</p>

<p>There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the <code>next</code> pointer. Internally, <code>pos</code> is used to denote the index of the node that tail&#39;s <code>next</code> pointer is connected to (<strong>0-indexed</strong>). It is <code>-1</code> if there is no cycle. <strong>Note that</strong> <code>pos</code> <strong>is not passed as a parameter</strong>.</p>

<p><strong>Do not modify</strong> the linked list.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png" style="height: 145px; width: 450px;" />
<pre>
<strong>Input:</strong> head = [3,2,0,-4], pos = 1
<strong>Output:</strong> tail connects to node index 1
<strong>Explanation:</strong> There is a cycle in the linked list, where tail connects to the second node.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png" style="height: 105px; width: 201px;" />
<pre>
<strong>Input:</strong> head = [1,2], pos = 0
<strong>Output:</strong> tail connects to node index 0
<strong>Explanation:</strong> There is a cycle in the linked list, where tail connects to the first node.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png" style="height: 65px; width: 65px;" />
<pre>
<strong>Input:</strong> head = [1], pos = -1
<strong>Output:</strong> no cycle
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

This solution uses **Floyd's Cycle Detection Algorithm (Tortoise and Hare Algorithm)** to find the node where a cycle begins in a linked list.

The algorithm consists of two phases:

1. **Detect whether a cycle exists.**
2. **Locate the starting node of the cycle.**

### Phase 1: Detect the Cycle

Two pointers are initialized at the head of the linked list:

- `slow` moves **one node** at a time.
- `fast` moves **two nodes** at a time.

There are two possible outcomes:

- If the linked list has **no cycle**, the `fast` pointer eventually reaches `NULL`.
- If a **cycle exists**, the `fast` pointer eventually catches up to the `slow` pointer, and both pointers meet inside the cycle.

### Phase 2: Find the Start of the Cycle

Once the two pointers meet:

- Reset the `fast` pointer to the head of the linked list.
- Move both `fast` and `slow` **one step at a time**.

The node where they meet again is the **starting node of the cycle**.

This works because the distance from the head to the cycle's entry is equal to the distance from the meeting point to the cycle's entry.

### Example

Input:

```
3 → 2 → 0 → -4
    ↑       ↓
    └───────┘
```

Phase 1:

```
Slow and Fast meet inside the cycle.
```

Phase 2:

```
Reset Fast to Head.

Fast → 3
Slow → Meeting Point

Move both one step at a time.

↓

Both meet at:

2
```

Output:

```
Node with value 2
```

---

## Algorithm

1. Initialize:
   - `slow = head`
   - `fast = head`
2. Traverse the list:
   - Move `slow` one step.
   - Move `fast` two steps.
3. If `slow == fast`:
   - Reset `fast` to `head`.
   - Move both pointers one step at a time.
   - Return the node where they meet.
4. If `fast` reaches `NULL`, return `NULL` since no cycle exists.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - The list is traversed at most a constant number of times.

- **Space Complexity:** `O(1)`
  - Only two pointers are used.

---

## Key Idea

The fast pointer moves twice as fast as the slow pointer, ensuring they meet if a cycle exists. After the first meeting, resetting one pointer to the head and moving both pointers at the same speed causes them to meet exactly at the cycle's entry point. This elegant property allows the starting node of the cycle to be found in linear time using constant extra space.
