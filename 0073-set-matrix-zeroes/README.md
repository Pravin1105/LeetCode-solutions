<h2><a href="https://leetcode.com/problems/set-matrix-zeroes/">73. Set Matrix Zeroes</a></h2><h3>Medium</h3><hr><p>Given an <code>m x n</code> integer matrix <code>matrix</code>, if an element is <code>0</code>, set its entire row and column to <code>0</code>&#39;s.</p>

<p>You must do it <a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in place</a>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/17/mat1.jpg" style="width: 450px; height: 169px;" />
<pre>
<strong>Input:</strong> matrix = [[1,1,1],[1,0,1],[1,1,1]]
<strong>Output:</strong> [[1,0,1],[0,0,0],[1,0,1]]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/17/mat2.jpg" style="width: 450px; height: 137px;" />
<pre>
<strong>Input:</strong> matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
<strong>Output:</strong> [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[0].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>-2<sup>31</sup> &lt;= matrix[i][j] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<ul>
	<li>A straightforward solution using <code>O(mn)</code> space is probably a bad idea.</li>
	<li>A simple improvement uses <code>O(m + n)</code> space, but still not the best solution.</li>
	<li>Could you devise a constant space solution?</li>
</ul>


## Approach

The idea is to first identify all the rows and columns that contain at least one `0`. These row and column indices are stored in two hash sets.

The solution is performed in two phases:

1. **Scan the matrix**
   - Whenever a cell containing `0` is found:
     - Store its row index in the `rows` set.
     - Store its column index in the `cols` set.

2. **Update the matrix**
   - Set every element in the recorded rows to `0`.
   - Set every element in the recorded columns to `0`.

Using hash sets ensures that each row and column is processed only once, even if multiple zeros are present.

### Example

Input:

```
1 1 1
1 0 1
1 1 1
```

Rows containing zero:

```
{1}
```

Columns containing zero:

```
{1}
```

After updating rows:

```
1 1 1
0 0 0
1 1 1
```

After updating columns:

```
1 0 1
0 0 0
1 0 1
```

Output:

```
1 0 1
0 0 0
1 0 1
```

---

## Algorithm

1. Create two hash sets:
   - `rows` to store row indices.
   - `cols` to store column indices.
2. Traverse the matrix.
3. For every cell containing `0`:
   - Insert its row into `rows`.
   - Insert its column into `cols`.
4. Set every element in the rows stored in `rows` to `0`.
5. Set every element in the columns stored in `cols` to `0`.
6. Return the modified matrix.

---

## Complexity Analysis

Let:

- `n` = number of rows
- `m` = number of columns

- **Time Complexity:** `O(n × m)`
  - One traversal to identify zeros and another to update the marked rows and columns.

- **Space Complexity:** `O(n + m)`
  - The hash sets store at most `n` row indices and `m` column indices.

---

## Key Idea

Instead of modifying the matrix immediately upon encountering a zero, the solution first records all affected rows and columns. This prevents newly assigned zeros from influencing subsequent decisions during the scan. After identifying all required rows and columns, the matrix is updated in a separate pass.
