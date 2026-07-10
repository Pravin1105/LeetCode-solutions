<h2><a href="https://leetcode.com/problems/merge-two-sorted-lists">21. Merge Two Sorted Lists</a></h2><h3>Easy</h3><hr><p>You are given the heads of two sorted linked lists <code>list1</code> and <code>list2</code>.</p>

<p>Merge the two lists into one <strong>sorted</strong> list. The list should be made by splicing together the nodes of the first two lists.</p>

<p>Return <em>the head of the merged linked list</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg" style="width: 662px; height: 302px;" />
<pre>
<strong>Input:</strong> list1 = [1,2,4], list2 = [1,3,4]
<strong>Output:</strong> [1,1,2,3,4,4]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> list1 = [], list2 = []
<strong>Output:</strong> []
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> list1 = [], list2 = [0]
<strong>Output:</strong> [0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in both lists is in the range <code>[0, 50]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
	<li>Both <code>list1</code> and <code>list2</code> are sorted in <strong>non-decreasing</strong> order.</li>
</ul>


## Approach

Since both linked lists are already sorted, they can be merged in a manner similar to the **merge step of Merge Sort**.

A **dummy node** is created to simplify list construction. A pointer `temp` is used to build the merged list by always attaching the smaller node from the two input lists.

Three pointers are maintained:

- `temp1` → traverses the first linked list.
- `temp2` → traverses the second linked list.
- `temp` → points to the last node of the merged list.

At each step:

- Compare the values of `temp1` and `temp2`.
- Attach the node with the smaller value to the merged list.
- Move the corresponding pointer forward.

Once one list is exhausted, append the remaining nodes of the other list, as they are already sorted.

Finally, the dummy node is removed, and the head of the merged list is returned.

### Example

Input:

```
List 1: 1 → 2 → 4
List 2: 1 → 3 → 4
```

Merging process:

```
Dummy

↓

0 → 1 → 1 → 2 → 3 → 4 → 4
```

Output:

```
1 → 1 → 2 → 3 → 4 → 4
```

---

## Algorithm

1. Create a dummy node.
2. Initialize pointers:
   - `temp1` for the first list.
   - `temp2` for the second list.
   - `temp` pointing to the dummy node.
3. While both lists are non-empty:
   - Compare the current nodes.
   - Attach the smaller node to the merged list.
   - Move the corresponding pointer.
4. Append the remaining nodes from the non-empty list.
5. Remove the dummy node and return the merged list.

---

## Complexity Analysis

- **Time Complexity:** `O(m + n)`
  - Each node from both linked lists is visited exactly once.

- **Space Complexity:** `O(1)`
  - No additional list is created; the existing nodes are relinked in-place. Only a single dummy node is used.

---

## Key Idea

By always selecting the smaller of the two current nodes, the merged list remains sorted throughout the process. The dummy node eliminates special handling for the head of the list, making the implementation simpler while achieving linear time and constant extra space.
