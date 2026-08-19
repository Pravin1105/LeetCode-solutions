<h2><a href="https://leetcode.com/problems/single-number-ii">137. Single Number II</a></h2><h3>Medium</h3><hr><p>Given an integer array <code>nums</code> where&nbsp;every element appears <strong>three times</strong> except for one, which appears <strong>exactly once</strong>. <em>Find the single element and return it</em>.</p>

<p>You must&nbsp;implement a solution with a linear runtime complexity and use&nbsp;only constant&nbsp;extra space.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [2,2,3,2]
<strong>Output:</strong> 3
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [0,1,0,1,0,1,99]
<strong>Output:</strong> 99
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li>Each element in <code>nums</code> appears exactly <strong>three times</strong> except for one element which appears <strong>once</strong>.</li>
</ul>

## Approach

The solution uses **bit manipulation** to find the element that appears exactly once when every other element appears three times.

For each of the **32 bits** of an integer, the solution counts how many numbers have that bit set.

Since every repeated number appears exactly three times:

- Bits belonging only to the repeated numbers will have a count divisible by `3`.
- The bit belonging to the unique number will leave a remainder of `1` after taking the count modulo `3`.

Therefore, for every bit position:

```text
bit_count % 3
```

gives the corresponding bit of the unique number.

The solution stores these remainders in an array of size `32` and reconstructs the answer from them.

### Example

Input:

```text
nums = [2,2,3,2]
```

Binary representation:

```text
2 = 0010
3 = 0011
2 = 0010
2 = 0010
```

Count each bit:

```text
Bit 0 → 1
Bit 1 → 4
Bit 2 → 0
Bit 3 → 0
```

Taking modulo `3`:

```text
Bit 0 → 1 % 3 = 1
Bit 1 → 4 % 3 = 1
```

So the resulting bits are:

```text
0011
```

which represents:

```text
3
```

---

## Algorithm

1. Create an array of `32` integers initialized to `0`.
2. For each of the 32 bit positions:
   - Traverse all elements.
   - Extract the least significant bit using:
     ```cpp
     nums[j] & 1
     ```
   - Add it to the corresponding bit count.
   - Right-shift every number by one:
     ```cpp
     nums[j] >>= 1
     ```
   - Take the bit count modulo `3`.
3. Reconstruct the unique number:
   - For every bit position with a remainder of `1`, set that bit in `ans`.
4. Return the result.

---

## Complexity Analysis

- **Time Complexity:** `O(32 × n) = O(n)`
  - Each of the 32 bits is processed for every element.

- **Space Complexity:** `O(1)`
  - The bit-count array always contains exactly 32 elements.

---

## Key Idea

When every number except one appears exactly three times, the total count of every bit is also a multiple of three except for the bits belonging to the unique number. Taking each bit count modulo `3` removes the contribution of the repeated numbers and leaves only the bits of the single element.
