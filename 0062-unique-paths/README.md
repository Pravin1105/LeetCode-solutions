<h2><a href="https://leetcode.com/problems/unique-paths/">62. Unique Paths</a></h2><h3>Medium</h3><hr><p>There is a robot on an <code>m x n</code> grid. The robot is initially located at the <strong>top-left corner</strong> (i.e., <code>grid[0][0]</code>). The robot tries to move to the <strong>bottom-right corner</strong> (i.e., <code>grid[m - 1][n - 1]</code>). The robot can only move either down or right at any point in time.</p>

<p>Given the two integers <code>m</code> and <code>n</code>, return <em>the number of possible unique paths that the robot can take to reach the bottom-right corner</em>.</p>

<p>The test cases are generated so that the answer will be less than or equal to <code>2 * 10<sup>9</sup></code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png" style="width: 400px; height: 183px;" />
<pre>
<strong>Input:</strong> m = 3, n = 7
<strong>Output:</strong> 28
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> m = 3, n = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -&gt; Down -&gt; Down
2. Down -&gt; Down -&gt; Right
3. Down -&gt; Right -&gt; Down
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
</ul>

# Unique Paths - Dynamic Programming

## Approach

To reach any cell in the grid, the robot can only come from:

- The cell directly **above** it.
- The cell directly **to the left** of it.

Therefore, the number of unique paths to a cell is simply the sum of the paths to these two neighboring cells.

Let `dp[i][j]` represent the number of unique paths to reach cell `(i, j)`.

The recurrence relation is:

```text
dp[i][j] = dp[i-1][j] + dp[i][j-1]
```

### Why initialize with `1`?

- Every cell in the **first row** can only be reached by moving right.
- Every cell in the **first column** can only be reached by moving down.

Hence, there is exactly **one** way to reach each of these cells, so the entire first row and first column are initialized to `1`.

### Example

For `m = 3` and `n = 4`:

Initial DP table:

```
1 1 1 1
1 1 1 1
1 1 1 1
```

Fill the remaining cells:

```
1 1 1 1
1 2 3 4
1 3 6 10
```

The answer is:

```
dp[2][3] = 10
```

---

## Algorithm

1. Create an `m × n` DP table initialized with `1`.
2. Iterate from the second row and second column.
3. For each cell:
   - Compute `dp[i][j] = dp[i-1][j] + dp[i][j-1]`.
4. Return the value in the bottom-right corner.

---

## Complexity Analysis

- **Time Complexity:** `O(m × n)`
  - Every cell in the grid is processed exactly once.

- **Space Complexity:** `O(m × n)`
  - An `m × n` DP table is used.

---

## Key Idea

Each cell's value depends only on the number of ways to reach the cell directly above and the cell directly to its left. By building the DP table from the top-left to the bottom-right, we efficiently compute the total number of unique paths without recalculating overlapping subproblems.
