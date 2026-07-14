<h2><a href="https://leetcode.com/problems/largest-rectangle-in-histogram">84. Largest Rectangle in Histogram</a></h2><h3>Hard</h3><hr><p>Given an array of integers <code>heights</code> representing the histogram&#39;s bar height where the width of each bar is <code>1</code>, return <em>the area of the largest rectangle in the histogram</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/histogram.jpg" style="width: 522px; height: 242px;" />
<pre>
<strong>Input:</strong> heights = [2,1,5,6,2,3]
<strong>Output:</strong> 10
<strong>Explanation:</strong> The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/histogram-1.jpg" style="width: 202px; height: 362px;" />
<pre>
<strong>Input:</strong> heights = [2,4]
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= heights.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= heights[i] &lt;= 10<sup>4</sup></code></li>
</ul>

## Approach

The solution uses a **Monotonic Increasing Stack** to efficiently compute the largest rectangle in the histogram.

The stack stores the **indices** of bars in increasing order of their heights.

### Key Observation

For every bar, we want to determine:

- The **first smaller bar on the left**.
- The **first smaller bar on the right**.

Once these boundaries are known, the current bar can be extended across all bars that are at least as tall.

The area is then:

```text
Area = Height × Width
```

Instead of explicitly computing the left and right boundaries, the stack determines them during traversal.

---

## Processing the Histogram

While traversing the histogram:

- If the current bar is **taller** than the bar at the top of the stack, push its index.
- If it is **shorter**, the bar at the top can no longer extend further.

For every popped bar:

- Its height is known.
- The current index gives the **first smaller element on the right**.
- The new top of the stack gives the **first smaller element on the left**.

The width is calculated as:

- If the stack becomes empty:

```
width = current_index
```

- Otherwise:

```
width = current_index - stack.top() - 1
```

The rectangle area is then:

```
height × width
```

After the traversal, any remaining bars in the stack extend to the end of the histogram and are processed similarly.

---

## Example

Input:

```
heights = [2,1,5,6,2,3]
```

Processing:

```
Stack:

[2]
[2,5]
```

Encounter `2`:

```
5 > 2

Pop 6

Height = 6
Width = 1
Area = 6
```

Next pop:

```
Height = 5
Width = 2
Area = 10
```

Maximum area becomes:

```
10
```

Output:

```
10
```

---

## Algorithm

1. Initialize an empty stack to store indices.
2. Traverse the histogram.
3. While the current bar is smaller than the bar indexed by the top of the stack:
   - Pop the top index.
   - Compute the rectangle width.
   - Update the maximum area.
4. Push the current index onto the stack.
5. After traversal, process all remaining indices in the stack using the end of the array as the right boundary.
6. Return the maximum area found.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - Each index is pushed onto and popped from the stack at most once.

- **Space Complexity:** `O(n)`
  - The stack stores at most `n` indices.

---

## Key Idea

A **monotonic increasing stack** allows each bar to determine its maximum possible width when it is popped. The current index acts as the first smaller element on the right, while the new stack top represents the first smaller element on the left. Since every bar is pushed and popped only once, the algorithm computes the largest rectangle in linear time.
