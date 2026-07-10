<h2><a href="https://leetcode.com/problems/middle-of-the-linked-list">908. Middle of the Linked List</a></h2><h3>Easy</h3><hr><p>Given the <code>head</code> of a singly linked list, return <em>the middle node of the linked list</em>.</p>

<p>If there are two middle nodes, return <strong>the second middle</strong> node.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/23/lc-midlist1.jpg" style="width: 544px; height: 65px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4,5]
<strong>Output:</strong> [3,4,5]
<strong>Explanation:</strong> The middle node of the list is node 3.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/23/lc-midlist2.jpg" style="width: 664px; height: 65px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4,5,6]
<strong>Output:</strong> [4,5,6]
<strong>Explanation:</strong> Since the list has two middle nodes with values 3 and 4, we return the second one.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[1, 100]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 100</code></li>
</ul>


## Approach

The solution uses the **Fast and Slow Pointer** technique to find the middle node in a single traversal.

Two pointers are initialized at the head of the linked list:

- `slow` moves **one node** at a time.
- `fast` moves **two nodes** at a time.

As the traversal progresses:

- When `fast` reaches the end of the list, `slow` will be positioned at the middle node.

If the linked list contains an **even** number of nodes, the problem requires returning the **second middle node**, which this approach naturally does.

### Example 1

Input:

```
1 → 2 → 3 → 4 → 5
```

Pointer movement:

| Step | Slow | Fast |
|-----:|:----:|:----:|
| Start | 1 | 1 |
| 1 | 2 | 3 |
| 2 | 3 | 5 |

`fast` reaches the end, so the answer is:

```
3 → 4 → 5
```

---

### Example 2

Input:

```
1 → 2 → 3 → 4 → 5 → 6
```

Pointer movement:

| Step | Slow | Fast |
|-----:|:----:|:----:|
| Start | 1 | 1 |
| 1 | 2 | 3 |
| 2 | 3 | 5 |
| 3 | 4 | NULL |

The returned node is:

```
4 → 5 → 6
```

which is the required **second middle node**.

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
3. Return `slow`.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - The linked list is traversed only once.

- **Space Complexity:** `O(1)`
  - Only two pointers are used.

---

## Key Idea

Since the fast pointer moves twice as quickly as the slow pointer, it reaches the end of the list in half the time. By that moment, the slow pointer has covered half the distance and is positioned exactly at the middle node, providing an efficient one-pass solution with constant extra space.
