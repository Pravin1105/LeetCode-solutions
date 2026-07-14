<h2><a href="https://leetcode.com/problems/search-in-rotated-sorted-array">33. Search in Rotated Sorted Array</a></h2><h3>Medium</h3><hr><p>There is an integer array <code>nums</code> sorted in ascending order (with <strong>distinct</strong> values).</p>

<p>Prior to being passed to your function, <code>nums</code> is <strong>possibly left rotated</strong> at an unknown index <code>k</code> (<code>1 &lt;= k &lt; nums.length</code>) such that the resulting array is <code>[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]</code> (<strong>0-indexed</strong>). For example, <code>[0,1,2,4,5,6,7]</code> might be left rotated by&nbsp;<code>3</code>&nbsp;indices and become <code>[4,5,6,7,0,1,2]</code>.</p>

<p>Given the array <code>nums</code> <strong>after</strong> the possible rotation and an integer <code>target</code>, return <em>the index of </em><code>target</code><em> if it is in </em><code>nums</code><em>, or </em><code>-1</code><em> if it is not in </em><code>nums</code>.</p>

<p>You must write an algorithm with <code>O(log n)</code> runtime complexity.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [4,5,6,7,0,1,2], target = 0
<strong>Output:</strong> 4
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [4,5,6,7,0,1,2], target = 3
<strong>Output:</strong> -1
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [1], target = 0
<strong>Output:</strong> -1
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5000</code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li>All values of <code>nums</code> are <strong>unique</strong>.</li>
	<li><code>nums</code> is an ascending array that is possibly rotated.</li>
	<li><code>-10<sup>4</sup> &lt;= target &lt;= 10<sup>4</sup></code></li>
</ul>

## Approach

A rotated sorted array consists of two sorted portions separated by a pivot. Even after rotation, at least one half of the current search range remains sorted.

This solution applies **Binary Search** while determining whether the middle element lies in the left sorted portion, the right sorted portion, or in a completely sorted subarray.

During each iteration:

- If the middle element is the target, return its index.
- If the middle element belongs to the **left sorted portion**, determine whether the target lies within that range.
- If the middle element belongs to the **right sorted portion**, determine whether the target lies within that range.
- Otherwise, the current search range is completely sorted, so perform a normal binary search step.

By eliminating half of the search space in every iteration, the target is found efficiently.

### Example

Input:

```
nums = [4,5,6,7,0,1,2]
target = 0
```

Initial search:

```
4 5 6 7 0 1 2
      ↑
     mid
```

The middle element lies in the left sorted portion, but the target does not.

Search the right half:

```
0 1 2
 ↑
mid
```

The middle element matches the target.

Output:

```
4
```

---

## Algorithm

1. Initialize:
   - `low = 0`
   - `high = n - 1`
2. While `low <= high`:
   - Compute the middle index.
   - If the middle element equals the target, return its index.
   - If the middle element belongs to the left sorted portion:
     - Check whether the target lies within that range.
     - Otherwise, search the opposite half.
   - Else if the middle element belongs to the right sorted portion:
     - Check whether the target lies within that range.
     - Otherwise, search the opposite half.
   - Otherwise:
     - Apply the normal binary search comparison.
3. If the target is not found, return `-1`.

---

## Complexity Analysis

- **Time Complexity:** `O(log n)`
  - The search space is halved during each iteration.

- **Space Complexity:** `O(1)`
  - Only a constant number of variables are used.

---

## Key Idea

Even though the array is rotated, at least one side of the current search interval is always sorted. By identifying whether the middle element belongs to the left or right sorted portion and checking if the target falls within that range, half of the remaining search space can be discarded in every iteration, preserving the efficiency of Binary Search.
