<h2><a href="https://leetcode.com/problems/remove-nth-node-from-end-of-list">19. Remove Nth Node From End of List</a></h2><h3>Medium</h3><hr><p>Given the <code>head</code> of a linked list, remove the <code>n<sup>th</sup></code> node from the end of the list and return its head.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg" style="width: 542px; height: 222px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4,5], n = 2
<strong>Output:</strong> [1,2,3,5]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> head = [1], n = 1
<strong>Output:</strong> []
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> head = [1,2], n = 1
<strong>Output:</strong> [1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is <code>sz</code>.</li>
	<li><code>1 &lt;= sz &lt;= 30</code></li>
	<li><code>0 &lt;= Node.val &lt;= 100</code></li>
	<li><code>1 &lt;= n &lt;= sz</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you do this in one pass?</p>


## Approach

This solution uses the **Fast and Slow Pointer** technique to remove the `n`th node from the end in a single traversal.

Two pointers are initialized at the head of the linked list:

- `fast` moves `n` nodes ahead.
- `slow` starts from the head.

After creating this gap of `n` nodes, both pointers move one step at a time until `fast` reaches the last node.

At this point:

- `slow` is positioned immediately before the node that needs to be removed.
- The target node can be deleted by updating the `next` pointer.

A special case occurs when `fast` becomes `NULL` after the initial movement. This means the node to remove is the head of the list.

### Example

Input:

```
1 → 2 → 3 → 4 → 5
n = 2
```

Initial gap:

```
Slow

↓

1 → 2 → 3 → 4 → 5
                ↑
              Fast
```

Move both pointers together:

```
Slow

        ↓
1 → 2 → 3 → 4 → 5
                    ↑
                  Fast
```

Now, `slow` points to the node before the one to be deleted (`4`).

After deletion:

```
1 → 2 → 3 → 5
```

---

## Algorithm

1. Handle the single-node list as a special case.
2. Initialize:
   - `slow = head`
   - `fast = head`
3. Move `fast` ahead by `n` nodes.
4. If `fast` becomes `NULL`:
   - Remove the head node.
5. Otherwise:
   - Move both pointers together until `fast->next` becomes `NULL`.
6. Delete `slow->next` by updating the links.
7. Return the head of the modified list.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - The linked list is traversed at most once.

- **Space Complexity:** `O(1)`
  - Only two pointers are used.

---

## Key Idea

Maintaining a gap of `n` nodes between the fast and slow pointers allows the slow pointer to reach the node immediately before the target when the fast pointer reaches the end of the list. This enables deletion in a single traversal while using constant extra space.
