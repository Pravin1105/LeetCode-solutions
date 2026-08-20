<h2><a href="https://leetcode.com/problems/single-number-iii">260. Single Number III</a></h2><h3>Medium</h3><hr><p>Given an integer array <code>nums</code>, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in <strong>any order</strong>.</p>

<p>You must write an&nbsp;algorithm that runs in linear runtime complexity and uses&nbsp;only constant extra space.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,1,3,2,5]
<strong>Output:</strong> [3,5]
<strong>Explanation: </strong> [5, 3] is also a valid answer.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [-1,0]
<strong>Output:</strong> [-1,0]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,1]
<strong>Output:</strong> [1,0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li>Each integer in <code>nums</code> will appear twice, only two integers will appear once.</li>
</ul>

## Approach

The array contains exactly two elements that appear once, while every other element appears exactly twice.

The solution uses **XOR** properties to isolate the two unique numbers.

### Step 1: XOR All Elements

All elements are XORed together:

```text
xor_sum = nums[0] ^ nums[1] ^ ... ^ nums[n-1]
```

Since:

```text
x ^ x = 0
x ^ 0 = x
```

Every element appearing twice cancels itself out. The result is:

```text
xor_sum = unique1 ^ unique2
```

Since the two unique numbers are different, `xor_sum` must contain at least one set bit.

---

### Step 2: Find a Differing Bit

The code finds the position of the first set bit in `xor_sum`:

```cpp
while(!(xor_sum & 1)){
    xor_sum >>= 1;
    k++;
}
```

This bit represents a position where the two unique numbers differ.

A mask is then created:

```cpp
int s = 1 << k;
```

---

### Step 3: Divide the Numbers into Two Groups

Using the selected bit, all numbers are divided into two groups:

- Numbers where the bit is set.
- Numbers where the bit is not set.

```text
Group 1: s & nums[i] != 0
Group 2: s & nums[i] == 0
```

The duplicate numbers always belong to the same group, so they cancel each other when XORed.

The two unique numbers belong to different groups because they differ at the selected bit.

---

### Step 4: XOR Both Groups

Each group is XORed separately:

```text
xor1 = XOR of all elements with the selected bit set
xor2 = XOR of all remaining elements
```

After all duplicate pairs cancel out:

```text
xor1 = first unique number
xor2 = second unique number
```

---

## Example

Input:

```text
nums = [1,2,1,3,2,5]
```

XOR of all elements:

```text
1 ^ 2 ^ 1 ^ 3 ^ 2 ^ 5
```

Duplicate pairs cancel:

```text
1 ^ 1 = 0
2 ^ 2 = 0
```

Therefore:

```text
xor_sum = 3 ^ 5
        = 6
        = 110
```

Find the first set bit:

```text
110
 ^
```

Using this bit, divide the numbers into two groups:

```text
Bit set:     [2,2,3]
Bit not set: [1,1,5]
```

XOR each group:

```text
2 ^ 2 ^ 3 = 3

1 ^ 1 ^ 5 = 5
```

Output:

```text
[3,5]
```

---

## Algorithm

1. XOR all elements of the array.
2. The result is the XOR of the two unique numbers.
3. Find a set bit where the two unique numbers differ.
4. Create a bit mask for that position.
5. Divide all numbers into two groups based on that bit.
6. XOR all numbers in each group separately.
7. Return the two XOR results.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - The array is traversed twice.

- **Space Complexity:** `O(1)`
  - Only a constant number of variables are used.

---

## Key Idea

XOR removes all numbers that appear twice. The remaining XOR value contains the combined information of the two unique numbers. By finding a bit where those two numbers differ, the array can be partitioned into two groups, allowing each unique number to be isolated independently.
