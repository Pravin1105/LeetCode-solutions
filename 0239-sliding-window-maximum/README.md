<h2><a href="https://leetcode.com/problems/sliding-window-maximum">239. Sliding Window Maximum</a></h2><h3>Hard</h3><hr><p>You are given an array of integers&nbsp;<code>nums</code>, there is a sliding window of size <code>k</code> which is moving from the very left of the array to the very right. You can only see the <code>k</code> numbers in the window. Each time the sliding window moves right by one position.</p>

<p>Return <em>the max sliding window</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,-1,-3,5,3,6,7], k = 3
<strong>Output:</strong> [3,3,5,5,6,7]
<strong>Explanation:</strong> 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       <strong>3</strong>
 1 [3  -1  -3] 5  3  6  7       <strong>3</strong>
 1  3 [-1  -3  5] 3  6  7      <strong> 5</strong>
 1  3  -1 [-3  5  3] 6  7       <strong>5</strong>
 1  3  -1  -3 [5  3  6] 7       <strong>6</strong>
 1  3  -1  -3  5 [3  6  7]      <strong>7</strong>
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1], k = 1
<strong>Output:</strong> [1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>

## Approach

The solution uses a **monotonic decreasing deque** to efficiently find the maximum element in every sliding window of size `k`.

The deque stores the **indices** of elements rather than the elements themselves. The indices are maintained such that their corresponding values are in decreasing order:

```text
nums[pq.front()] ≥ ... ≥ nums[pq.back()]
```

Therefore, the index at the front of the deque always represents the maximum element of the current window.

### Building the First Window

For the first `k` elements:

- Remove indices from the back while their values are smaller than the current element.
- Add the current index to the back.
- After processing `k` elements, the front contains the index of the maximum element.

### Sliding the Window

For every new element:

1. Remove the front index if it has moved outside the current window.
2. Remove indices from the back whose values are smaller than the new element.
3. Insert the new index at the back.
4. The element at `pq.front()` is the maximum of the current window.

---

## Example

Input:

```text
nums = [1,3,-1,-3,5,3,6,7]
k = 3
```

First window:

```text
[1,3,-1]
```

Deque after processing the window:

```text
[3,-1]
```

Maximum:

```text
3
```

Next window:

```text
[3,-1,-3]
```

Maximum:

```text
3
```

Next window:

```text
[-1,-3,5]
```

The smaller elements are removed from the back when `5` arrives:

```text
[5]
```

Maximum:

```text
5
```

Continuing for all windows:

```text
[3,3,5,5,6,7]
```

---

## Algorithm

1. Create an empty deque to store indices.
2. Process the first `k` elements:
   - Remove smaller elements from the back.
   - Insert the current index.
3. Store the element at the front as the maximum of the first window.
4. For every remaining element:
   - Remove the front index if it is outside the current window.
   - Remove smaller elements from the back.
   - Insert the current index.
   - Add the front element to the answer.
5. Return the result.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - Every index is inserted into the deque once and removed at most once.

- **Space Complexity:** `O(k)`
  - The deque stores indices from the current sliding window.

---

## Key Idea

The deque maintains only **useful candidates for the maximum**. Any smaller element that appears before a larger element can never become the maximum while the larger element remains in the window, so it is removed. As a result, the front of the deque always gives the maximum element in constant time.
