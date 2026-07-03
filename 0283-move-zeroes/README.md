<h2><a href="https://leetcode.com/problems/move-zeroes">283. Move Zeroes</a></h2><h3>Easy</h3><hr><p>Given an integer array <code>nums</code>, move all <code>0</code>&#39;s to the end of it while maintaining the relative order of the non-zero elements.</p>

<p><strong>Note</strong> that you must do this in-place without making a copy of the array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [0,1,0,3,12]
<strong>Output:</strong> [1,3,12,0,0]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [0]
<strong>Output:</strong> [0]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you minimize the total number of operations done?


## Approach

The idea is to move all non-zero elements to the front of the array while maintaining their relative order. After placing all non-zero elements, the remaining positions are filled with `0`.

We use two pointers:

- `j` traverses the entire array.
- `i` marks the position where the next non-zero element should be placed.

Whenever a non-zero element is encountered:

- Copy it to index `i`.
- Increment `i`.

Once all elements have been processed, every index from `i` to the end of the array is filled with `0`.

### Example

```
nums = [0, 1, 0, 3, 12]

Step 1: Move non-zero elements

[1, 3, 12, 3, 12]
 ↑
 i = 3

Step 2: Fill remaining positions with zeros

[1, 3, 12, 0, 0]
```

---

## Algorithm

1. Initialize two pointers:
   - `i = 0` (next position for a non-zero element)
   - `j = 0` (current element being processed)
2. Traverse the array using `j`.
3. If `nums[j]` is non-zero:
   - Copy it to `nums[i]`.
   - Increment `i`.
4. After traversal, fill every index from `i` to `n - 1` with `0`.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - The array is traversed once, followed by filling the remaining positions with zeros.

- **Space Complexity:** `O(1)`
  - The operation is performed in-place without using any extra data structure.

---

## Key Idea

Instead of swapping every zero with a non-zero element, we simply compact all non-zero values at the beginning of the array and then overwrite the remaining positions with zeros. This preserves the relative order of non-zero elements while using constant extra space.
