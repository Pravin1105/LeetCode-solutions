<h2><a href="https://leetcode.com/problems/top-k-frequent-elements">347. Top K Frequent Elements</a></h2><h3>Medium</h3><hr><p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <em>the</em> <code>k</code> <em>most frequent elements</em>. You may return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,1,1,2,2,3], k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">[1,2]</span></p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1], k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">[1]</span></p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,1,2,1,2,3,1,3,2], k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">[1,2]</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>k</code> is in the range <code>[1, the number of unique elements in the array]</code>.</li>
	<li>It is <strong>guaranteed</strong> that the answer is <strong>unique</strong>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Your algorithm&#39;s time complexity must be better than <code>O(n log n)</code>, where n is the array&#39;s size.</p>

## Approach

The solution uses a combination of a **Hash Map** and a **Max Heap (Priority Queue)**.

The algorithm works in two phases:

1. **Count the frequency** of every element using a hash map.
2. **Retrieve the `k` most frequent elements** by storing the frequency-element pairs in a max heap.

The priority queue automatically keeps the element with the highest frequency at the top, allowing us to efficiently extract the `k` most frequent elements.

### Example

Input:

```
nums = [1,1,1,2,2,3]
k = 2
```

Frequency Map:

```
1 → 3
2 → 2
3 → 1
```

Max Heap:

```
(3,1)
(2,2)
(1,3)
```

Extract the top `k = 2` elements:

```
1
2
```

Output:

```
[1,2]
```

---

## Algorithm

1. Create a hash map to store the frequency of each element.
2. Traverse the array and update the frequency count.
3. Insert every `(frequency, element)` pair into a max heap.
4. Repeat `k` times:
   - Extract the top element from the heap.
   - Add its value to the answer.
5. Return the resulting list.

---

## Complexity Analysis

Let:

- `n` = size of the input array
- `m` = number of distinct elements

- **Time Complexity:** `O(n + m log m)`
  - Building the frequency map: `O(n)`
  - Inserting `m` elements into the heap: `O(m log m)`
  - Extracting the top `k` elements: `O(k log m)`

  Since `k ≤ m`, the overall complexity is:

  ```
  O(n + m log m)
  ```

- **Space Complexity:** `O(m)`
  - The hash map and priority queue each store at most one entry for every distinct element.

---

## Key Idea

The hash map efficiently counts the frequency of each element, while the max heap keeps the elements ordered by frequency. By repeatedly extracting the heap's maximum element, the algorithm obtains the `k` most frequent elements without sorting the entire array.
