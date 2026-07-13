<h2><a href="https://leetcode.com/problems/single-element-in-a-sorted-array">540. Single Element in a Sorted Array</a></h2><h3>Medium</h3><hr><p>You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.</p>

<p>Return <em>the single element that appears only once</em>.</p>

<p>Your solution must run in <code>O(log n)</code> time and <code>O(1)</code> space.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,1,2,3,3,4,4,8,8]
<strong>Output:</strong> 2
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [3,3,7,7,10,11,11]
<strong>Output:</strong> 10
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

## Approach

Since the array is sorted and every element appears exactly twice except one, we can use **Binary Search** to locate the single element in `O(log n)` time.

### Key Observation

Before the single element:

- The **first occurrence** of every pair is at an **even index**.
- The **second occurrence** is at an **odd index**.

Example:

```
[1,1,2,2,3,3,4,5,5,6,6]

Index:
 0 1 2 3 4 5 6 7 8 9 10
```

Notice:

```
1 → (0,1)
2 → (2,3)
3 → (4,5)
```

After the single element (`4`), this pattern reverses:

```
5 → (7,8)
6 → (9,10)
```

The first occurrence now appears at an **odd index**.

This change in parity allows us to determine which half of the array contains the unique element.

---

## Binary Search

For each middle index:

### Case 1: Middle is the single element

If the current element is different from both its neighbors, it is the answer.

```text
nums[mid] != nums[mid-1]
and
nums[mid] != nums[mid+1]
```

---

### Case 2: Pair starts at `mid`

```
nums[mid] == nums[mid + 1]
```

- If `mid` is **even**, the unique element lies on the **right**.
- If `mid` is **odd**, the unique element lies on the **left**.

---

### Case 3: Pair ends at `mid`

```
nums[mid] == nums[mid - 1]
```

- If `mid` is **even**, the unique element lies on the **left**.
- If `mid` is **odd**, the unique element lies on the **right**.

Using these rules, the search space is halved after every iteration.

---

## Example

Input:

```
[1,1,2,3,3,4,4,8,8]
```

Binary Search:

```
mid = 4

3 == 3 (pair ends at mid)

mid is even

↓

Search Left
```

Remaining:

```
[1,1,2]
```

Next:

```
mid = 2

2 has no equal neighbor

↓

Answer = 2
```

---

## Algorithm

1. Initialize:
   - `low = 0`
   - `high = n - 1`
2. While `low <= high`:
   - Compute the middle index.
   - If the middle element differs from both neighbors, return it.
   - Otherwise, determine which side contains the single element using the parity of `mid`.
3. Return the unique element.

---

## Complexity Analysis

- **Time Complexity:** `O(log n)`
  - Binary search halves the search space in every iteration.

- **Space Complexity:** `O(1)`
  - Only a constant amount of extra space is used.

---

## Key Idea

The single element disrupts the normal pairing pattern of the sorted array. Before the unique element, pairs begin at even indices, while after it they begin at odd indices. By checking the parity of the middle index and how it pairs with its neighbors, Binary Search efficiently narrows the search to the half containing the unique element.
