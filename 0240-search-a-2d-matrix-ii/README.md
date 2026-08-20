<h2><a href="https://leetcode.com/problems/search-a-2d-matrix-ii">240. Search a 2D Matrix II</a></h2><h3>Medium</h3><hr><p>Write an efficient algorithm that searches for a value <code>target</code> in an <code>m x n</code> integer matrix <code>matrix</code>. This matrix has the following properties:</p>

<ul>
	<li>Integers in each row are sorted in ascending from left to right.</li>
	<li>Integers in each column are sorted in ascending from top to bottom.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/24/searchgrid2.jpg" style="width: 300px; height: 300px;" />
<pre>
<strong>Input:</strong> matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/24/searchgrid.jpg" style="width: 300px; height: 300px;" />
<pre>
<strong>Input:</strong> matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= n, m &lt;= 300</code></li>
	<li><code>-10<sup>9</sup> &lt;= matrix[i][j] &lt;= 10<sup>9</sup></code></li>
	<li>All the integers in each row are <strong>sorted</strong> in ascending order.</li>
	<li>All the integers in each column are <strong>sorted</strong> in ascending order.</li>
	<li><code>-10<sup>9</sup> &lt;= target &lt;= 10<sup>9</sup></code></li>
</ul>

## Approach

The matrix has two important properties:

- Each row is sorted in ascending order from left to right.
- Each column is sorted in ascending order from top to bottom.

The solution starts searching from the **bottom-left corner** of the matrix.

At position `(i, j)`:

- All elements **above** are smaller.
- All elements **to the right** are larger.

This allows one row or one column to be eliminated after every comparison.

### Decision

- If `matrix[i][j] == target`, return `true`.
- If `matrix[i][j] > target`, move **up**:
  ```text
  i--
  ```
  because all elements to the right are even larger.
- If `matrix[i][j] < target`, move **right**:
  ```text
  j++
  ```
  because all elements above are smaller.

The search continues until the target is found or the pointers move outside the matrix.

---

## Example

Input:

```text
1   4   7  11  15
2   5   8  12  19
3   6   9  16  22
10 13  14 17  24
18 21  23 26  30

Target = 5
```

Start from the bottom-left:

```text
18 > 5
```

Move up:

```text
10 > 5
```

Move up:

```text
3 < 5
```

Move right:

```text
6 > 5
```

Move up:

```text
5 == 5
```

Target found.

---

## Algorithm

1. Start at the bottom-left corner:
   - `i = n - 1`
   - `j = 0`
2. While `i >= 0` and `j < m`:
   - If `matrix[i][j] == target`, return `true`.
   - If `matrix[i][j] > target`, move up by decrementing `i`.
   - Otherwise, move right by incrementing `j`.
3. If the search exits the matrix, return `false`.

---

## Complexity Analysis

Let:

- `n` = number of rows
- `m` = number of columns

- **Time Complexity:** `O(n + m)`
  - At every step, either one row or one column is eliminated.

- **Space Complexity:** `O(1)`
  - Only two indices are used.

---

## Key Idea

Starting from the **bottom-left corner** makes each comparison decisive. If the current value is too large, the entire part to its right can be eliminated, so we move upward. If the current value is too small, the entire part above can be eliminated, so we move right. This creates a staircase-like traversal through the matrix.
