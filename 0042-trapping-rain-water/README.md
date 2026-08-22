<h2><a href="https://leetcode.com/problems/trapping-rain-water">42. Trapping Rain Water</a></h2><h3>Hard</h3><hr><p>Given <code>n</code> non-negative integers representing an elevation map where the width of each bar is <code>1</code>, compute how much water it can trap after raining.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png" style="width: 412px; height: 161px;" />
<pre>
<strong>Input:</strong> height = [0,1,0,2,1,0,1,3,2,1,2,1]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> height = [4,2,0,3,2,5]
<strong>Output:</strong> 9
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == height.length</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= height[i] &lt;= 10<sup>5</sup></code></li>
</ul>


## Approach

The solution calculates the total amount of water trapped between the bars using two auxiliary arrays:

- `left[i]` stores the maximum height from the beginning of the array up to index `i`.
- `right[i]` stores the maximum height from the end of the array up to index `i`.

For any position `i`, water can only be trapped if there are boundaries on both sides. The amount of water trapped at that position is:

```text
min(left[i], right[i]) - height[i]
```

The smaller boundary determines the maximum possible water level.

---

### Step 1: Initialize the Boundary Arrays

Two arrays are created to store the maximum heights from both directions:

```cpp
vector<int> left(n, 0), right(n, 0);
```

The first and last elements are initialized with the corresponding heights:

```cpp
left[0] = height[0];
right[n-1] = height[n-1];
```

---

### Step 2: Calculate Maximum Heights from Both Sides

The `left` array is built from left to right:

```cpp
left[i] = max(left[i-1], height[i]);
```

This ensures that `left[i]` contains the tallest bar encountered from index `0` to index `i`.

The `right` array is built from right to left:

```cpp
right[n-1-i] = max(right[n-i], height[n-1-i]);
```

This ensures that `right[i]` contains the tallest bar encountered from the right side up to index `i`.

Both arrays are calculated in the same loop.

---

### Step 3: Calculate the Trapped Water

For every index, the water level is limited by the smaller of the maximum heights on both sides:

```text
Water at index i = min(left[i], right[i]) - height[i]
```

The result for every position is added to `ans`:

```cpp
ans += (min(left[i], right[i]) - height[i]);
```

---

## Example

Input:

```text
height = [0,1,0,2,1,0,1,3,2,1,2,1]
```

Consider index `2`:

```text
height[2] = 0

Maximum height on the left  = 1
Maximum height on the right = 3
```

Therefore:

```text
Water = min(1, 3) - 0
      = 1
```

The same calculation is performed for every position.

Total trapped water:

```text
6
```

---

## Algorithm

1. Create two arrays `left` and `right` of size `n`.
2. Store the maximum height from the left for every index in `left`.
3. Store the maximum height from the right for every index in `right`.
4. For every index `i`, calculate:
   ```text
   min(left[i], right[i]) - height[i]
   ```
5. Add the trapped water at every position to `ans`.
6. Return `ans`.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - The array is traversed a constant number of times.

- **Space Complexity:** `O(n)`
  - Two additional arrays of size `n` are used.

---

## Key Idea

The amount of water trapped at any position depends on the tallest bars available on its left and right sides. The shorter of these two boundaries determines the water level. By precomputing the maximum height from both directions, the trapped water at every position can be calculated efficiently in linear time.
