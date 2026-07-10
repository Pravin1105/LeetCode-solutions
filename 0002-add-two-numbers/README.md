<h2><a href="https://leetcode.com/problems/add-two-numbers">2. Add Two Numbers</a></h2><h3>Medium</h3><hr><p>You are given two <strong>non-empty</strong> linked lists representing two non-negative integers. The digits are stored in <strong>reverse order</strong>, and each of their nodes contains a single digit. Add the two numbers and return the sum&nbsp;as a linked list.</p>

<p>You may assume the two numbers do not contain any leading zero, except the number 0 itself.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg" style="width: 483px; height: 342px;" />
<pre>
<strong>Input:</strong> l1 = [2,4,3], l2 = [5,6,4]
<strong>Output:</strong> [7,0,8]
<strong>Explanation:</strong> 342 + 465 = 807.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> l1 = [0], l2 = [0]
<strong>Output:</strong> [0]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
<strong>Output:</strong> [8,9,9,9,0,0,0,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in each linked list is in the range <code>[1, 100]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 9</code></li>
	<li>It is guaranteed that the list represents a number that does not have leading zeros.</li>
</ul>

## Approach

Each linked list represents a non-negative integer where:

- Each node stores a single digit.
- Digits are stored in **reverse order**, with the least significant digit appearing first.

Instead of creating a new node for every digit in the result, this solution **reuses the nodes of the input linked lists**. The digit stored in the current node is updated with the computed result, and the existing nodes are relinked to form the answer.

A **dummy node** is used only to simplify the construction of the resulting linked list.

At each step:

1. Add the corresponding digits from both lists along with the carry.
2. Store the resulting digit (`sum % 10`) in the current node.
3. Link the next available node from one of the input lists.
4. Update the carry (`sum / 10`) and continue.

Once one list is exhausted, the remaining nodes of the other list are processed in the same manner. If a carry remains after all digits have been processed, it is stored in the final available node. Otherwise, the extra unused node is removed.

### Example

Input:

```
l1 = 2 → 4 → 3
l2 = 5 → 6 → 4
```

These represent:

```
342 + 465
```

Processing:

```
2 + 5 = 7
4 + 6 = 10  → store 0, carry 1
3 + 4 + 1 = 8
```

Reusing nodes produces:

```
7 → 0 → 8
```

which represents:

```
807
```

---

## Algorithm

1. Create a dummy node.
2. Initialize pointers for:
   - The two input lists.
   - The result list.
   - Carry value.
3. While both lists have nodes:
   - Compute the sum of both digits and the carry.
   - Store `sum % 10` in the current result node.
   - Link the next node from the first list.
   - Advance both input pointers.
4. Process any remaining nodes from either list while propagating the carry.
5. If a carry remains:
   - Store it in the final node.
   - Otherwise, remove the unused extra node.
6. Return the head of the modified linked list.

---

## Complexity Analysis

- **Time Complexity:** `O(max(m, n))`
  - Each node from the input lists is visited exactly once.

- **Space Complexity:** `O(1)`
  - No additional result nodes are allocated. The existing nodes of the input lists are reused, requiring only a single dummy node.

---

## Key Idea

Rather than allocating a new linked list, this solution recycles the nodes of the input lists to store the result. Each node's value is overwritten with the computed digit, and the nodes are relinked as the traversal progresses. This in-place approach maintains linear time complexity while minimizing memory usage by avoiding unnecessary node allocations.
