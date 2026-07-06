<h2><a href="https://leetcode.com/problems/minimum-path-sum">64. Minimum Path Sum</a></h2><h3>Medium</h3><hr><p>Given a <code>m x n</code> <code>grid</code> filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.</p>

<p><strong>Note:</strong> You can only move either down or right at any point in time.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/minpath.jpg" style="width: 242px; height: 242px;" />
<pre>
<strong>Input:</strong> grid = [[1,3,1],[1,5,1],[4,2,1]]
<strong>Output:</strong> 7
<strong>Explanation:</strong> Because the path 1 &rarr; 3 &rarr; 1 &rarr; 1 &rarr; 1 minimizes the sum.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> grid = [[1,2,3],[4,5,6]]
<strong>Output:</strong> 12
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 200</code></li>
</ul>

## Approach

The robot starts at the top-left corner of the grid and can only move **right** or **down**. Each cell contains a cost, and the goal is to find the path with the minimum total cost.

Let `dp[i][j]` represent the minimum path sum required to reach cell `(i, j)`.

Since a cell can only be reached from:

- The cell directly **above**, or
- The cell directly **to the left**,

the minimum cost to reach the current cell is:

```text
dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
```

The first row and first column are handled separately because they have only one possible direction of movement.

### Example

Input:

```
1 3 1
1 5 1
4 2 1
```

DP Table Construction:

```
1  4  5
2  7  6
6  8  7
```

The minimum path sum is:

```
7
```

Path:

```
1 → 3 → 1
          ↓
          1
          ↓
          1
```

---

## Algorithm

1. Create an `m × n` DP table.
2. Traverse each cell in the grid.
3. For the starting cell:
   - `dp[0][0] = grid[0][0]`
4. For the first row:
   - Add the current cell value to the left neighbor.
5. For the first column:
   - Add the current cell value to the top neighbor.
6. For every other cell:
   - Add the current cell value to the minimum of the top and left DP values.
7. Return the value at the bottom-right corner.

---

## Complexity Analysis

- **Time Complexity:** `O(m × n)`
  - Every cell is processed exactly once.

- **Space Complexity:** `O(m × n)`
  - An `m × n` DP table is used to store intermediate results.

---

## Key Idea

Each cell stores the minimum cost required to reach it. Since movement is restricted to the right and downward directions, the optimal path to a cell depends only on the optimal paths to its top and left neighbors. Dynamic Programming builds these optimal values incrementally, ensuring each subproblem is solved only once.
