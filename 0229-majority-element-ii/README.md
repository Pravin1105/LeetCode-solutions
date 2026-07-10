<h2><a href="https://leetcode.com/problems/majority-element-ii">229. Majority Element II</a></h2><h3>Medium</h3><hr><p>Given an integer array of size <code>n</code>, find all elements that appear more than <code>&lfloor;n / 3&rfloor;</code> times.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,2,3]
<strong>Output:</strong> [3]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1]
<strong>Output:</strong> [1]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2]
<strong>Output:</strong> [1,2]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you solve the problem in linear time and in <code>O(1)</code> space?</p>

## Approach

In this problem, we need to find all elements that appear **more than ⌊n/3⌋ times**.

### Why are there at most two majority elements?

Suppose there were three different elements, each appearing more than `n/3` times.

Then their total occurrences would exceed `n`, which is impossible.

Therefore, there can be **at most two majority elements**, allowing us to maintain only two candidates.

---

## Phase 1: Candidate Selection

We maintain:

- `can1` and `can2` → the two potential majority elements.
- `count1` and `count2` → their respective vote counts.

For each element:

- If it matches one of the candidates, increment its count.
- If a candidate's count becomes zero, replace it with the current element.
- Otherwise, decrement both counts.

This performs **pairwise cancellation**, eliminating groups of three distinct elements. After one pass, only the possible majority candidates remain.

### Example

Input:

```
nums = [3,2,3]
```

Candidate selection:

| Element | Candidate 1 | Count 1 | Candidate 2 | Count 2 |
|---------:|:-----------:|--------:|:-----------:|--------:|
| 3 | 3 | 1 | - | 0 |
| 2 | 3 | 1 | 2 | 1 |
| 3 | 3 | 2 | 2 | 1 |

Possible candidates:

```
3, 2
```

---

## Phase 2: Verification

The first pass only identifies **potential** majority elements.

A second traversal counts the actual occurrences of `can1` and `can2`.

Any candidate whose frequency is greater than `⌊n/3⌋` is added to the answer.

---

## Algorithm

1. Initialize two candidates and their counts.
2. Traverse the array:
   - If the current element matches a candidate, increment its count.
   - Else if a count is zero, replace that candidate.
   - Otherwise, decrement both counts.
3. Reset both counts to zero.
4. Traverse the array again to count the occurrences of both candidates.
5. Return every candidate whose frequency is greater than `⌊n/3⌋`.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - One pass for candidate selection and one pass for verification.

- **Space Complexity:** `O(1)`
  - Only two candidates and two counters are maintained.

---

## Key Idea

The Boyer-Moore Voting Algorithm can be extended for the `n/3` case by maintaining **two candidates** instead of one. Through pairwise cancellation, only the potential majority elements survive the first pass, and a final verification pass confirms which candidates actually occur more than `⌊n/3⌋` times.
