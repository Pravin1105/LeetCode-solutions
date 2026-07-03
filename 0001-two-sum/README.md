<h2><a href="https://leetcode.com/problems/two-sum">1. Two Sum</a></h2><h3>Easy</h3><hr><p>Given an array of integers <code>nums</code>&nbsp;and an integer <code>target</code>, return <em>indices of the two numbers such that they add up to <code>target</code></em>.</p>

<p>You may assume that each input would have <strong><em>exactly</em> one solution</strong>, and you may not use the <em>same</em> element twice.</p>

<p>You can return the answer in any order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,7,11,15], target = 9
<strong>Output:</strong> [0,1]
<strong>Explanation:</strong> Because nums[0] + nums[1] == 9, we return [0, 1].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,2,4], target = 6
<strong>Output:</strong> [1,2]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,3], target = 6
<strong>Output:</strong> [0,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= target &lt;= 10<sup>9</sup></code></li>
	<li><strong>Only one valid answer exists.</strong></li>
</ul>

<p>&nbsp;</p>
<strong>Follow-up:&nbsp;</strong>Can you come up with an algorithm that is less than <code>O(n<sup>2</sup>)</code><font face="monospace">&nbsp;</font>time complexity?


## Approach

Instead of checking every possible pair (which takes **O(n²)** time), we first store each number along with its original index.

```cpp
(value, original_index)
```

For example:

```
nums = [2, 7, 11, 15]

↓

[(2,0), (7,1), (11,2), (15,3)]
```

After sorting the array based on values, we use the **two-pointer technique**:

- `i` starts from the beginning (smallest value).
- `j` starts from the end (largest value).

At each step:

- If `vp[i].first + vp[j].first == target`, we have found the answer.
- If the sum is smaller than the target, move `i` to the right.
- If the sum is larger than the target, move `j` to the left.

Since each element still stores its original index, we can return the correct indices even after sorting.

---

## Algorithm

1. Store every element with its original index.
2. Sort the vector by value.
3. Initialize two pointers:
   - Left pointer at the beginning.
   - Right pointer at the end.
4. Compare the current pair:
   - Equal to target → return original indices.
   - Less than target → increment left pointer.
   - Greater than target → decrement right pointer.
5. Continue until the pair is found.

---

## Complexity Analysis

- **Time Complexity:** `O(n log n)`
  - Sorting takes `O(n log n)`.
  - Two-pointer traversal takes `O(n)`.

- **Space Complexity:** `O(n)`
  - Extra vector is used to store values with their original indices.

---

## Key Idea

Sorting allows us to efficiently search for the required pair using two pointers, while storing the original indices ensures we can return the correct answer after the array order changes.
