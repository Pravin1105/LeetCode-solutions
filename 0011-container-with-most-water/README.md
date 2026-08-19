<h2><a href="https://leetcode.com/problems/container-with-most-water">11. Container With Most Water</a></h2><h3>Medium</h3><hr><p>You are given an integer array <code>height</code> of length <code>n</code>. There are <code>n</code> vertical lines drawn such that the two endpoints of the <code>i<sup>th</sup></code> line are <code>(i, 0)</code> and <code>(i, height[i])</code>.</p>

<p>Find two lines that together with the x-axis form a container, such that the container contains the most water.</p>

<p>Return <em>the maximum amount of water a container can store</em>.</p>

<p><strong>Notice</strong> that you may not slant the container.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg" style="width: 600px; height: 287px;" />
<pre>
<strong>Input:</strong> height = [1,8,6,2,5,4,8,3,7]
<strong>Output:</strong> 49
<strong>Explanation:</strong> The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> height = [1,1]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == height.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= height[i] &lt;= 10<sup>4</sup></code></li>
</ul>


## Approach

The solution uses the **Two Pointer** technique to find the maximum amount of water that can be contained between two vertical lines.

Two pointers are initialized at opposite ends of the array:

- `i` → left pointer.
- `j` → right pointer.

The area between two lines is determined by:

```text
Area = min(height[i], height[j]) × (j - i)
```

The limiting factor is always the **shorter line**.

Therefore, after calculating the current area:

- If `height[i] < height[j]`, move `i` to the right.
- Otherwise, move `j` to the left.

The reasoning is that moving the pointer corresponding to the taller line cannot improve the area while the shorter line remains unchanged, because the width decreases and the minimum height cannot increase.

### Example

Input:

```text
height = [1,8,6,2,5,4,8,3,7]
```

Start with:

```text
i = 0
j = 8
```

Current area:

```text
min(1,7) × (8-0) = 8
```

Since the left height is smaller:

```text
i++
```

The process continues until the two pointers meet.

Maximum area:

```text
49
```

---

## Algorithm

1. Initialize:
   - `i = 0`
   - `j = n - 1`
   - `ans = INT_MIN`
2. While `i < j`:
   - Calculate the area using the two current heights.
   - Update `ans` if the current area is larger.
   - Move the pointer corresponding to the shorter height.
3. Return `ans`.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - Each pointer moves only toward the other pointer, so at most `n` positions are processed.

- **Space Complexity:** `O(1)`
  - Only a constant number of variables are used.

---

## Key Idea

The area is limited by the **shorter of the two heights**. Moving the taller pointer cannot produce a better area because the width decreases while the limiting height remains unchanged or decreases. Therefore, only the pointer at the shorter height is moved, allowing the maximum area to be found in a single pass.
