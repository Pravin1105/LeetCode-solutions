<h2><a href="https://leetcode.com/problems/first-missing-positive">41. First Missing Positive</a></h2><h3>Hard</h3><hr><p>Given an unsorted integer array <code>nums</code>. Return the <em>smallest positive integer</em> that is <em>not present</em> in <code>nums</code>.</p>

<p>You must implement an algorithm that runs in <code>O(n)</code> time and uses <code>O(1)</code> auxiliary space.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,0]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The numbers in the range [1,2] are all in the array.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,4,-1,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 1 is in the array but 2 is missing.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [7,8,9,11,12]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The smallest positive integer 1 is missing.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

## Approach

The smallest missing positive integer must lie within the range:

```
[1, n + 1]
```

where `n` is the size of the array.

The idea is to place every positive integer `x` (where `1 ≤ x ≤ n`) at its correct index:

```
value x → index x - 1
```

We iterate through the array and repeatedly swap an element into its correct position until:

- It is already in the correct position.
- It is out of the valid range (`≤ 0` or `> n`).
- Its correct position already contains the same value (duplicate).

After all valid numbers have been placed, the first index whose value does not match `index + 1` is the smallest missing positive.

If every position contains the correct value, then all numbers from `1` to `n` are present, and the answer is `n + 1`.

### Example

Input:

```
[3,4,-1,1]
```

After cyclic placement:

```
[-1,1,3,4]

↓

[1,-1,3,4]
```

Scanning the array:

```
Index : 0  1  2  3
Value : 1 -1  3  4
```

The first mismatch occurs at:

```
Index 1

Expected: 2
Found:   -1
```

Answer:

```
2
```

---

## Algorithm

1. Traverse the array.
2. While the current value:
   - is positive,
   - is less than or equal to `n`,
   - and is not already at its correct position,
   swap it with the element at its target index.
3. After all swaps, traverse the array from left to right.
4. Return the first index where:
   ```
   nums[i] != i + 1
   ```
5. If every position is correct, return:
   ```
   n + 1
   ```

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - Each element is moved to its correct position at most once.

- **Space Complexity:** `O(1)`
  - The rearrangement is performed in-place without using any additional data structure.

---

## Key Idea

Instead of searching for the missing number directly, place every valid positive integer in its correct index. Once the array is rearranged, the first position where the expected value is missing immediately reveals the smallest missing positive integer. This achieves linear time complexity while using constant extra space.
