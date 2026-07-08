<h2><a href="https://leetcode.com/problems/merge-intervals">56. Merge Intervals</a></h2><h3>Medium</h3><hr><p>Given an array&nbsp;of <code>intervals</code>&nbsp;where <code>intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]</code>, merge all overlapping intervals, and return <em>an array of the non-overlapping intervals that cover all the intervals in the input</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> intervals = [[1,3],[2,6],[8,10],[15,18]]
<strong>Output:</strong> [[1,6],[8,10],[15,18]]
<strong>Explanation:</strong> Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> intervals = [[1,4],[4,5]]
<strong>Output:</strong> [[1,5]]
<strong>Explanation:</strong> Intervals [1,4] and [4,5] are considered overlapping.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> intervals = [[4,7],[1,4]]
<strong>Output:</strong> [[1,7]]
<strong>Explanation:</strong> Intervals [1,4] and [4,7] are considered overlapping.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= intervals.length &lt;= 10<sup>4</sup></code></li>
	<li><code>intervals[i].length == 2</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
</ul>

## Approach

The idea is to first sort the intervals by their starting time. Once sorted, any overlapping intervals will appear next to each other.

We maintain a current interval (pointed to by `l`) and compare it with the next interval (`r`).

There are two possible cases:

- **No Overlap**
  - If the end of the current interval is smaller than the start of the next interval, the current interval is complete and is added to the answer.
  - Move `l` to the next interval.

- **Overlap**
  - Merge the two intervals by updating the ending value of the current interval to the larger of the two ending values.
  - Continue checking with the following intervals.

At the end of the traversal, the last merged interval is added to the result.

### Example

Input:

```
[[1,3], [2,6], [8,10], [15,18]]
```

After Sorting:

```
[[1,3], [2,6], [8,10], [15,18]]
```

Processing:

```
[1,3] and [2,6] overlap
↓

Merge to

[1,6]

Remaining intervals:

[8,10]
[15,18]
```

Output:

```
[[1,6], [8,10], [15,18]]
```

---

## Algorithm

1. Sort the intervals according to their starting value.
2. Initialize:
   - `l` as the current interval.
   - `r` as the next interval.
3. Traverse the intervals:
   - If there is no overlap:
     - Add the current interval to the answer.
     - Move `l` to `r`.
   - Otherwise:
     - Update the end of the current interval with the larger ending value.
4. After the traversal, add the final merged interval to the answer.
5. Return the merged intervals.

---

## Complexity Analysis

- **Time Complexity:** `O(n log n)`
  - Sorting takes `O(n log n)`, and the traversal takes `O(n)`.

- **Space Complexity:** `O(n)`
  - The result vector stores the merged intervals.

---

## Key Idea

Sorting places all potentially overlapping intervals together. A single linear traversal is then sufficient to either merge overlapping intervals or store completed intervals, resulting in an efficient solution.
