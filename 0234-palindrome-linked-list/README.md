<h2><a href="https://leetcode.com/problems/palindrome-linked-list">234. Palindrome Linked List</a></h2><h3>Easy</h3><hr><p>Given the <code>head</code> of a singly linked list, return <code>true</code><em> if it is a </em><span data-keyword="palindrome-sequence"><em>palindrome</em></span><em> or </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg" style="width: 422px; height: 62px;" />
<pre>
<strong>Input:</strong> head = [1,2,2,1]
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg" style="width: 182px; height: 62px;" />
<pre>
<strong>Input:</strong> head = [1,2]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 9</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you do it in <code>O(n)</code> time and <code>O(1)</code> space?


## Approach

The idea is to compare the first half of the linked list with the reversed second half.

The solution consists of three steps:

1. **Find the middle of the linked list** using the Fast and Slow Pointer technique.
2. **Reverse the second half** of the list.
3. **Compare** the first half and the reversed second half node by node.

If every corresponding node has the same value, the linked list is a palindrome.

### Step 1: Find the Middle

Two pointers are used:

- `slow` moves one node at a time.
- `fast` moves two nodes at a time.

When `fast` reaches the end of the list, `slow` points to the middle.

For an odd-length list, `slow` stops at the middle element, which does not need to be compared.

### Step 2: Reverse the Second Half

The list is split into two halves:

```
First Half → NULL

Second Half
```

The second half is reversed in-place.

Example:

```
Original:

1 → 2 → 3 → 2 → 1

Split:

1 → 2 → 3

2 → 1

Reverse second half:

1 → 2
```

### Step 3: Compare Both Halves

Traverse both halves simultaneously.

```
1 == 1 ✔
2 == 2 ✔
```

Since every compared node matches, the linked list is a palindrome.

---

## Example

Input:

```
1 → 2 → 2 → 1
```

Find the middle:

```
1 → 2 | 2 → 1
```

Reverse the second half:

```
1 → 2 | 1 → 2
```

Compare:

```
1 == 1
2 == 2
```

Output:

```
true
```

---

## Algorithm

1. Find the middle of the linked list using fast and slow pointers.
2. Split the list into two halves.
3. Reverse the second half.
4. Traverse both halves simultaneously:
   - If any pair of nodes differs, return `false`.
5. If all corresponding nodes match, return `true`.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - One traversal to find the middle, one to reverse the second half, and one to compare both halves.

- **Space Complexity:** `O(1)`
  - The reversal is performed in-place using a constant number of pointers.

---

## Key Idea

Instead of using extra memory to store node values, the linked list is divided into two halves. By reversing the second half and comparing it with the first half, the palindrome property can be verified in linear time while using constant extra space.
