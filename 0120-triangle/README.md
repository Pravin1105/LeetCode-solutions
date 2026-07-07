<h2><a href="https://leetcode.com/problems/triangle">120. Triangle</a></h2><h3>Medium</h3><hr><p>Given a <code>triangle</code> array, return <em>the minimum path sum from top to bottom</em>.</p>

<p>For each step, you may move to an adjacent number of the row below. More formally, if you are on index <code>i</code> on the current row, you may move to either index <code>i</code> or index <code>i + 1</code> on the next row.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
<strong>Output:</strong> 11
<strong>Explanation:</strong> The triangle looks like:
   <u>2</u>
  <u>3</u> 4
 6 <u>5</u> 7
4 <u>1</u> 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> triangle = [[-10]]
<strong>Output:</strong> -10
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= triangle.length &lt;= 200</code></li>
	<li><code>triangle[0].length == 1</code></li>
	<li><code>triangle[i].length == triangle[i - 1].length + 1</code></li>
	<li><code>-10<sup>4</sup> &lt;= triangle[i][j] &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you&nbsp;do this using only <code>O(n)</code> extra space, where <code>n</code> is the total number of rows in the triangle?

## Approach

Starting from the top of the triangle, each element can be reached from one or two elements in the previous row:

- The **first element** of every row can only be reached from the first element of the previous row.
- The **last element** of every row can only be reached from the last element of the previous row.
- Every **middle element** can be reached from either:
  - The element directly above.
  - The element above-left.

Let `dp[i][j]` represent the minimum path sum to reach the element at row `i` and column `j`.

The transition for middle elements is:

```text
dp[i][j] = triangle[i][j] + min(dp[i-1][j-1], dp[i-1][j])
```

The DP table is initialized as a copy of the input triangle, and each row is updated from top to bottom. The minimum value in the last row gives the answer.

### Example

Input:

```
      2
     3 4
    6 5 7
   4 1 8 3
```

DP Table Construction:

```
      2
     5 6
    11 10 13
   15 11 18 16
```

The minimum path sum is:

```
11
```

Path:

```
2 → 3 → 5 → 1
```

---

## Algorithm

1. Make a DP table.
2. Traverse the triangle from the second row.
3. For each row:
   - Update the first element using the first element of the previous row.
   - Update all middle elements using the minimum of the two possible parent elements.
   - Update the last element using the last element of the previous row.
4. Traverse the last row of the DP table to find the minimum value.
5. Return the minimum path sum.

---

## Complexity Analysis

- **Time Complexity:** `O(n²)`
  - Every element in the triangle is processed exactly once.

- **Space Complexity:** `O(n²)`
  - A separate DP table of the same size as the triangle is maintained.

---

## Key Idea

Each position stores the minimum cost required to reach it from the top. Since every element depends only on the valid parent elements in the previous row, the solution builds the answer incrementally using Dynamic Programming. The smallest value in the final row represents the minimum path sum from the top to the bottom of the triangle.
