<h2><a href="https://leetcode.com/problems/search-a-2d-matrix/">74. Search a 2D Matrix</a></h2><h3>Medium</h3><hr><p>You are given an <code>m x n</code> integer matrix <code>matrix</code> with the following two properties:</p>

<ul>
	<li>Each row is sorted in non-decreasing order.</li>
	<li>The first integer of each row is greater than the last integer of the previous row.</li>
</ul>

<p>Given an integer <code>target</code>, return <code>true</code> <em>if</em> <code>target</code> <em>is in</em> <code>matrix</code> <em>or</em> <code>false</code> <em>otherwise</em>.</p>

<p>You must write a solution in <code>O(log(m * n))</code> time complexity.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/05/mat.jpg" style="width: 322px; height: 242px;" />
<pre>
<strong>Input:</strong> matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg" style="width: 322px; height: 242px;" />
<pre>
<strong>Input:</strong> matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>-10<sup>4</sup> &lt;= matrix[i][j], target &lt;= 10<sup>4</sup></code></li>
</ul>

## Approach

The matrix satisfies the following properties:

- Each row is sorted in **ascending order** from left to right.
- Each column is sorted in **ascending order** from top to bottom.

The search begins at the **top-right corner** of the matrix.

At any position `(i, j)`:

- All elements **to the left** are smaller.
- All elements **below** are larger.

This allows one row or one column to be eliminated in every step.

### Decision

- If the current element equals the target, return `true`.
- If the current element is **greater** than the target:
  - Move **left**, since everything below is even larger.
- If the current element is **smaller** than the target:
  - Move **down**, since everything to the left is smaller.

The process continues until the target is found or the search moves outside the matrix.

---

## Example

Input:

```
1   4   7  11  15
2   5   8  12  19
3   6   9  16  22
10 13  14 17  24
18 21  23 26  30

Target = 5
```

Search path:

```
15 > 5  → Move Left

11 > 5  → Move Left

7 > 5   → Move Left

4 < 5   → Move Down

5 == 5  → Found
```

Output:

```
true
```

---

## Algorithm

1. Start at the **top-right** corner of the matrix.
2. While the current position is within the matrix:
   - If the current element equals the target, return `true`.
   - If the current element is greater than the target, move one column left.
   - Otherwise, move one row down.
3. If the search exits the matrix without finding the target, return `false`.

---

## Complexity Analysis

Let:

- `n` = number of rows
- `m` = number of columns

- **Time Complexity:** `O(n + m)`
  - At each step, either one row or one column is discarded.

- **Space Complexity:** `O(1)`
  - Only two indices are maintained.

---

## Key Idea

Starting from the **top-right corner** provides enough information to eliminate either an entire row or an entire column after each comparison. This "staircase search" reduces the search space efficiently, achieving linear complexity with respect to the matrix dimensions while using constant extra space.
