<h2><a href="https://leetcode.com/problems/rotate-list">61. Rotate List</a></h2><h3>Medium</h3><hr><p>Given the <code>head</code> of a linked&nbsp;list, rotate the list to the right by <code>k</code> places.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/rotate1.jpg" style="width: 450px; height: 191px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4,5], k = 2
<strong>Output:</strong> [4,5,1,2,3]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/roate2.jpg" style="width: 305px; height: 350px;" />
<pre>
<strong>Input:</strong> head = [0,1,2], k = 4
<strong>Output:</strong> [2,0,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[0, 500]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
	<li><code>0 &lt;= k &lt;= 2 * 10<sup>9</sup></code></li>
</ul>

## Approach

The idea is to temporarily convert the linked list into a **circular linked list**, then break the circle at the appropriate position to obtain the rotated list.

The process consists of three steps:

1. **Find the length of the linked list** and the last node.
2. **Connect the last node to the head**, forming a circular linked list.
3. **Find the new tail** after rotation and break the circle.

Since rotating the list by its length results in the original list, the effective number of rotations is:

```text
k = k % n
```

The new tail is located at:

```text
n - k - 1
```

steps from the original head.

The node immediately after the new tail becomes the new head.

### Example

Input:

```
1 → 2 → 3 → 4 → 5
k = 2
```

Create a circular list:

```
1 → 2 → 3 → 4 → 5
↑                 ↓
└─────────────────┘
```

Effective rotation:

```
k = 2
```

New tail:

```
3
```

Break the circle after node `3`:

```
4 → 5 → 1 → 2 → 3
```

Output:

```
4 → 5 → 1 → 2 → 3
```

---

## Algorithm

1. Handle the edge cases:
   - Empty list.
   - `k = 0`.
2. Traverse the list to:
   - Find its length `n`.
   - Locate the last node.
3. Compute the effective rotation:
   ```
   k = k % n
   ```
4. Connect the last node to the head, creating a circular linked list.
5. Move to the `(n - k - 1)`th node from the head.
6. Set:
   - The next node as the new head.
   - The current node's `next` pointer to `NULL` to break the circle.
7. Return the new head.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - One traversal to determine the length and another partial traversal to locate the new tail.

- **Space Complexity:** `O(1)`
  - The rotation is performed in-place using a constant number of pointers.

---

## Key Idea

Instead of repeatedly rotating the list one node at a time, the list is first converted into a circular linked list. By identifying the new tail after the effective rotation (`k % n`), the circle can be broken at exactly one point to obtain the rotated list efficiently in linear time and constant extra space.
