<h2><a href="https://leetcode.com/problems/kth-largest-element-in-an-array">215. Kth Largest Element in an Array</a></h2><h3>Medium</h3><hr><p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <em>the</em> <code>k<sup>th</sup></code> <em>largest element in the array</em>.</p>

<p>Note that it is the <code>k<sup>th</sup></code> largest element in the sorted order, not the <code>k<sup>th</sup></code> distinct element.</p>

<p>Can you solve it without sorting?</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [3,2,1,5,6,4], k = 2
<strong>Output:</strong> 5
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [3,2,3,1,2,4,5,5,6], k = 4
<strong>Output:</strong> 4
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

## Approach

The solution uses a **min heap** to efficiently find the `k`th largest element.

All elements of the array are first inserted into a min heap. Since a min heap always keeps the smallest element at the top, elements are repeatedly removed until only `k` elements remain.

At that point:

- The heap contains the `k` largest elements in the array.
- The smallest element among these `k` elements is the `k`th largest element.

Therefore, `pq.top()` gives the required answer.

---

## Example

Input:

```text
nums = [3,2,1,5,6,4]
k = 2
```

Min heap initially contains:

```text
[1,2,3,4,5,6]
```

Remove elements until only `k = 2` elements remain:

```text
Pop 1 → [2,3,4,5,6]
Pop 2 → [3,4,5,6]
Pop 3 → [4,5,6]
Pop 4 → [5,6]
```

Now the heap contains the two largest elements:

```text
[5,6]
```

The smallest among them is:

```text
5
```

Output:

```text
5
```

---

## Algorithm

1. Create a min heap containing all elements of `nums`.
2. While the heap size is greater than `k`:
   - Remove the smallest element.
3. Return the element at the top of the heap.

---

## Complexity Analysis

Let `n` be the number of elements.

- **Time Complexity:** `O(n log n)`
  - Building the heap takes `O(n)`.
  - Removing `n - k` elements takes `O((n - k) log n)`.

- **Space Complexity:** `O(n)`
  - The priority queue stores all elements.

---

## Key Idea

By repeatedly removing the smallest elements from a min heap, only the `k` largest elements remain. The smallest among those remaining elements is exactly the **kth largest element**.
