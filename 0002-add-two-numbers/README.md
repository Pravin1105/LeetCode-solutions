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
- Digits are stored in **reverse order**, meaning the least significant digit comes first.

The addition is performed in the same way as elementary arithmetic:

1. Add the corresponding digits from both lists.
2. Include any carry from the previous addition.
3. Store the current digit (`sum % 10`) in the result list.
4. Carry forward (`sum / 10`) to the next iteration.

A **dummy node** is used to simplify the construction of the result linked list.

The traversal continues until both lists are exhausted. If a carry remains after processing all digits, a new node is appended to store it.

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

Addition:

```
2 + 5 = 7
4 + 6 = 10  → store 0, carry 1
3 + 4 + 1 = 8
```

Result:

```
7 → 0 → 8
```

which represents:

```
807
```

---

## Algorithm

1. Create a dummy node to build the answer list.
2. Initialize:
   - Two pointers for the input lists.
   - A pointer for the result list.
   - `carry = 0`.
3. While both lists contain nodes:
   - Compute the sum of both digits and the carry.
   - Create a new node containing `sum % 10`.
   - Update the carry to `sum / 10`.
4. Process any remaining nodes from either list using the carry.
5. If a carry remains after all nodes are processed, append one final node.
6. Remove the dummy node and return the head of the result list.

---

## Complexity Analysis

- **Time Complexity:** `O(max(m, n))`
  - Each node from both linked lists is processed exactly once.

- **Space Complexity:** `O(max(m, n))`
  - A new linked list is created to store the result.

---

## Key Idea

The linked lists are traversed simultaneously while simulating digit-by-digit addition. A carry is maintained across iterations just as in manual addition. Using a dummy node simplifies list construction, allowing the result to be built efficiently in a single pass.
