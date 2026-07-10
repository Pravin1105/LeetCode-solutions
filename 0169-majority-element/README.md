<h2><a href="https://leetcode.com/problems/majority-element">169. Majority Element</a></h2><h3>Easy</h3><hr><p>Given an array <code>nums</code> of size <code>n</code>, return <em>the majority element</em>.</p>

<p>The majority element is the element that appears more than <code>&lfloor;n / 2&rfloor;</code> times. You may assume that the majority element always exists in the array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [3,2,3]
<strong>Output:</strong> 3
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [2,2,1,1,1,2,2]
<strong>Output:</strong> 2
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li>The input is generated such that a majority element will exist in the array.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow-up:</strong> Could you solve the problem in linear time and in <code>O(1)</code> space?


## Approach

The **Boyer-Moore Voting Algorithm** finds the majority element by maintaining:

- A **candidate** for the majority element.
- A **count** representing the candidate's current vote balance.

The key idea is **pairwise cancellation**:

- If the current element is the same as the candidate, increase the count.
- Otherwise, decrease the count, effectively canceling one occurrence of the candidate with a different element.
- When the count becomes zero, choose the current element as the new candidate.

Since the majority element appears more than **⌊n/2⌋** times, it cannot be completely canceled by the remaining elements. Therefore, it will always be the final candidate.

### Example

Input:

```
nums = [2,2,1,1,1,2,2]
```

| Element | Candidate | Count |
|---------:|:---------:|------:|
| 2 | 2 | 1 |
| 2 | 2 | 2 |
| 1 | 2 | 1 |
| 1 | 2 | 0 |
| 1 | 1 | 1 |
| 2 | 1 | 0 |
| 2 | 2 | 1 |

Output:

```
2
```

---

## Algorithm

1. Initialize:
   - `candidate = nums[0]`
   - `count = 1`
2. Traverse the remaining elements.
3. For each element:
   - If `count == 0`, make the current element the new candidate and set `count = 1`.
   - Else if the current element equals the candidate, increment `count`.
   - Otherwise, decrement `count`.
4. Return the final candidate.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - The array is traversed exactly once.

- **Space Complexity:** `O(1)`
  - Only two variables are maintained throughout the traversal.

---

## Key Idea

Every occurrence of a non-majority element can cancel out one occurrence of the majority element. Because the majority element appears more than half the time, it always survives this cancellation process and remains the final candidate. This allows the majority element to be found in linear time using constant extra space.
