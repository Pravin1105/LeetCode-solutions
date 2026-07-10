<h2><a href="https://leetcode.com/problems/reverse-linked-list">206. Reverse Linked List</a></h2><h3>Easy</h3><hr><p>Given the <code>head</code> of a singly linked list, reverse the list, and return <em>the reversed list</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg" style="width: 542px; height: 222px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4,5]
<strong>Output:</strong> [5,4,3,2,1]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg" style="width: 182px; height: 222px;" />
<pre>
<strong>Input:</strong> head = [1,2]
<strong>Output:</strong> [2,1]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> head = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is the range <code>[0, 5000]</code>.</li>
	<li><code>-5000 &lt;= Node.val &lt;= 5000</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> A linked list can be reversed either iteratively or recursively. Could you implement both?</p>


## Approach

The idea is to reverse the direction of every link in the linked list while traversing it only once.

Three pointers are maintained throughout the traversal:

- `prev` → points to the previous node in the reversed list.
- `curr` → points to the current node being processed.
- `next` → temporarily stores the next node so the remaining list is not lost.

For each node:

1. Save the next node.
2. Reverse the current node's link to point to the previous node.
3. Move both `prev` and `curr` one step forward.

When the traversal is complete, `prev` points to the new head of the reversed linked list.

### Example

Input:

```
1 → 2 → 3 → 4 → 5 → NULL
```

Iteration:

```
NULL ← 1 → 2 → 3 → 4 → 5

↓

NULL ← 1 ← 2 → 3 → 4 → 5

↓

NULL ← 1 ← 2 ← 3 → 4 → 5

↓

NULL ← 1 ← 2 ← 3 ← 4 → 5

↓

NULL ← 1 ← 2 ← 3 ← 4 ← 5
```

Output:

```
5 → 4 → 3 → 2 → 1 → NULL
```

---

## Algorithm

1. Initialize:
   - `prev = NULL`
   - `curr = head`
2. While `curr` is not `NULL`:
   - Store `curr->next` in `next`.
   - Reverse the link:
     ```
     curr->next = prev
     ```
   - Move:
     - `prev = curr`
     - `curr = next`
3. Return `prev`, which becomes the new head of the reversed list.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - Each node is visited exactly once.

- **Space Complexity:** `O(1)`
  - Only three pointers are used, regardless of the size of the list.

---

## Key Idea

The list is reversed in-place by changing the direction of each node's `next` pointer. Using three pointers ensures that no part of the list is lost during reversal, resulting in an efficient linear-time, constant-space solution.
