<h2><a href="https://leetcode.com/problems/remove-duplicates-from-sorted-array">26. Remove Duplicates from Sorted Array</a></h2><h3>Easy</h3><hr><p>Given an integer array <code>nums</code> sorted in <strong>non-decreasing order</strong>, remove the duplicates <a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank"><strong>in-place</strong></a> such that each unique element appears only <strong>once</strong>. The <strong>relative order</strong> of the elements should be kept the <strong>same</strong>.</p>

<p>Consider the number of <em>unique elements</em> in&nbsp;<code>nums</code> to be <code>k<strong>​​​​​​​</strong></code>​​​​​​​. <meta charset="UTF-8" />After removing duplicates, return the number of unique elements&nbsp;<code>k</code>.</p>

<p><meta charset="UTF-8" />The first&nbsp;<code>k</code>&nbsp;elements of&nbsp;<code>nums</code>&nbsp;should contain the unique numbers in <strong>sorted order</strong>. The remaining elements beyond index&nbsp;<code>k - 1</code>&nbsp;can be ignored.</p>

<p><strong>Custom Judge:</strong></p>

<p>The judge will test your solution with the following code:</p>

<pre>
int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i &lt; k; i++) {
    assert nums[i] == expectedNums[i];
}
</pre>

<p>If all assertions pass, then your solution will be <strong>accepted</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,2]
<strong>Output:</strong> 2, nums = [1,2,_]
<strong>Explanation:</strong> Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,0,1,1,1,2,2,3,3,4]
<strong>Output:</strong> 5, nums = [0,1,2,3,4,_,_,_,_,_]
<strong>Explanation:</strong> Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>nums</code> is sorted in <strong>non-decreasing</strong> order.</li>
</ul>

## Approach

Since the array is already sorted, all duplicate elements appear consecutively.

The solution uses two pointers:

- `i` → Points to the last unique element found.
- `j` → Traverses the array to find the next unique element.

Initially:

- `i` starts at the first element.
- `j` starts at the second element.

As `j` moves through the array:

- If `nums[j]` is equal to `nums[i]`, it is a duplicate and is skipped.
- If `nums[j]` is different, a new unique element has been found:
  - Increment `i`.
  - Swap `nums[i]` and `nums[j]` to place the unique element immediately after the previously found unique elements.

After the traversal, all unique elements occupy the first `i + 1` positions of the array.

---

## Example

Input:

```
nums = [1,1,2,2,3,4,4]
```

Processing:

```
i = 0, j = 1

[1,1,2,2,3,4,4]
```

`1` is a duplicate.

```
j = 2

Found 2

↓

[1,2,1,2,3,4,4]
```

Next unique element:

```
Found 3

↓

[1,2,3,2,1,4,4]
```

Next unique element:

```
Found 4

↓

[1,2,3,4,1,2,4]
```

The first four elements are the unique values:

```
[1,2,3,4]
```

Return:

```
4
```

---

## Algorithm

1. Initialize:
   - `i = 0`
   - `j = 1`
2. Traverse the array using `j`.
3. If `nums[j]` is different from `nums[i]`:
   - Increment `i`.
   - Swap `nums[i]` and `nums[j]`.
4. Continue until the end of the array.
5. Return `i + 1`, which represents the number of unique elements.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - The array is traversed exactly once.

- **Space Complexity:** `O(1)`
  - The duplicates are removed in-place without using additional memory.

---

## Key Idea

Because the array is sorted, duplicate elements appear next to each other. By maintaining one pointer for the last unique element and another for scanning the array, each newly discovered unique element is moved to the front of the array. This produces the required in-place result in linear time using constant extra space.
