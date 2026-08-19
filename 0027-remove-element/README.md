<h2><a href="https://leetcode.com/problems/remove-element">27. Remove Element</a></h2><h3>Easy</h3><hr><p>Given an integer array <code>nums</code> and an integer <code>val</code>, remove all occurrences of <code>val</code> in <code>nums</code> <a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank"><strong>in-place</strong></a>. The order of the elements may be changed. Then return <em>the number of elements in </em><code>nums</code><em> which are not equal to </em><code>val</code>.</p>

<p>Consider the number of elements in <code>nums</code> which are not equal to <code>val</code> be <code>k</code>, to get accepted, you need to do the following things:</p>

<ul>
	<li>Change the array <code>nums</code> such that the first <code>k</code> elements of <code>nums</code> contain the elements which are not equal to <code>val</code>. The remaining elements of <code>nums</code> are not important as well as the size of <code>nums</code>.</li>
	<li>Return <code>k</code>.</li>
</ul>

<p><strong>Custom Judge:</strong></p>

<p>The judge will test your solution with the following code:</p>

<pre>
int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i &lt; actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
</pre>

<p>If all assertions pass, then your solution will be <strong>accepted</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,2,2,3], val = 3
<strong>Output:</strong> 2, nums = [2,2,_,_]
<strong>Explanation:</strong> Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,1,2,2,3,0,4,2], val = 2
<strong>Output:</strong> 5, nums = [0,1,4,0,3,_,_,_]
<strong>Explanation:</strong> Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 50</code></li>
	<li><code>0 &lt;= val &lt;= 100</code></li>
</ul>


## Approach

The solution uses a **Two Pointer** technique to remove all occurrences of a given value `val` from the array **in-place**.

Two indices are used:

- `i` → Traverses every element of the array.
- `j` → Tracks the position where the next valid element should be placed.

For every element:

- If `nums[i]` is different from `val`, it is a valid element.
  - Copy it to `nums[j]`.
  - Increment `j`.
- If `nums[i] == val`, simply skip it.

After the traversal, the first `j` positions contain all elements that are different from `val`.

The value of `j` is therefore the new length of the valid portion of the array.

### Example

Input:

```text
nums = [3,2,2,3]
val = 3
```

Processing:

```text
3 → skip

2 → nums[0] = 2

2 → nums[1] = 2

3 → skip
```

Result:

```text
[2,2,_,_]
```

Returned length:

```text
2
```

Only the first two positions are considered part of the resulting array.

---

## Algorithm

1. Initialize `j = 0`.
2. Traverse the array using `i`.
3. If `nums[i] != val`:
   - Copy `nums[i]` to `nums[j]`.
   - Increment `j`.
4. Ignore elements equal to `val`.
5. Return `j` as the new length.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - The array is traversed exactly once.

- **Space Complexity:** `O(1)`
  - The array is modified in-place using only two pointers.

---

## Key Idea

Instead of physically deleting elements or shifting the array repeatedly, the solution **compacts all elements that are not equal to `val` toward the beginning of the array**. The pointer `j` always represents the next position where a valid element should be placed, resulting in an efficient in-place solution.
