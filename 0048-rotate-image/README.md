<h2><a href="https://leetcode.com/problems/rotate-image">48. Rotate Image</a></h2><h3>Medium</h3><hr><p>You are given an <code>n x n</code> 2D <code>matrix</code> representing an image, rotate the image by <strong>90</strong> degrees (clockwise).</p>

<p>You have to rotate the image <a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank"><strong>in-place</strong></a>, which means you have to modify the input 2D matrix directly. <strong>DO NOT</strong> allocate another 2D matrix and do the rotation.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/mat1.jpg" style="width: 500px; height: 188px;" />
<pre>
<strong>Input:</strong> matrix = [[1,2,3],[4,5,6],[7,8,9]]
<strong>Output:</strong> [[7,4,1],[8,5,2],[9,6,3]]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/mat2.jpg" style="width: 500px; height: 201px;" />
<pre>
<strong>Input:</strong> matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
<strong>Output:</strong> [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == matrix.length == matrix[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 20</code></li>
	<li><code>-1000 &lt;= matrix[i][j] &lt;= 1000</code></li>
</ul>

## Approach

A **90° clockwise rotation** of a square matrix can be achieved in two simple steps:

1. **Transpose** the matrix.
2. **Reverse** every row.

### Step 1: Transpose

Transposing swaps every element across the main diagonal:

```text
matrix[i][j] ↔ matrix[j][i]
```

Only the upper triangular portion (including the diagonal) is traversed to avoid swapping elements twice.

Example:

```
Original Matrix

1 2 3
4 5 6
7 8 9

↓

Transpose

1 4 7
2 5 8
3 6 9
```

### Step 2: Reverse Each Row

Reversing every row converts the transposed matrix into a 90° clockwise rotated matrix.

```
Transpose

1 4 7
2 5 8
3 6 9

↓

Reverse Each Row

7 4 1
8 5 2
9 6 3
```

This is the required rotated matrix.

---

## Algorithm

1. Find the size `n` of the matrix.
2. Transpose the matrix by swapping:
   ```
   matrix[i][j] ↔ matrix[j][i]
   ```
   for all `j ≥ i`.
3. Reverse every row of the matrix.
4. The matrix is now rotated by 90° clockwise.

---

## Complexity Analysis

- **Time Complexity:** `O(n²)`
  - Transposition processes each element once, and reversing all rows also takes `O(n²)`.

- **Space Complexity:** `O(1)`
  - The rotation is performed in-place without using any additional matrix.

---

## Key Idea

A 90° clockwise rotation can be decomposed into two in-place operations:

1. **Transpose** the matrix to interchange rows and columns.
2. **Reverse each row** to reposition the elements into their rotated locations.

This approach avoids using an extra matrix while maintaining optimal time and space complexity.
