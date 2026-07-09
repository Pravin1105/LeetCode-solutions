<h2><a href="https://leetcode.com/problems/find-the-duplicate-number/">287. Find the Duplicate Number</a></h2><h3>Medium</h3><hr><p>Given an array of integers <code>nums</code> containing&nbsp;<code>n + 1</code> integers where each integer is in the range <code>[1, n]</code> inclusive.</p>

<p>There is only <strong>one repeated number</strong> in <code>nums</code>, return <em>this&nbsp;repeated&nbsp;number</em>.</p>

<p>You must solve the problem <strong>without</strong> modifying the array <code>nums</code>&nbsp;and using only constant extra space.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,4,2,2]
<strong>Output:</strong> 2
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,1,3,4,2]
<strong>Output:</strong> 3
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,3,3,3,3]
<strong>Output:</strong> 3</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>nums.length == n + 1</code></li>
	<li><code>1 &lt;= nums[i] &lt;= n</code></li>
	<li>All the integers in <code>nums</code> appear only <strong>once</strong> except for <strong>precisely one integer</strong> which appears <strong>two or more</strong> times.</li>
</ul>

<p>&nbsp;</p>
<p><b>Follow up:</b></p>

<ul>
	<li>How can we prove that at least one duplicate number must exist in <code>nums</code>?</li>
	<li>Can you solve the problem in linear runtime complexity?</li>
</ul>

## Approach

The array can be viewed as a **linked list**, where:

- Each index represents a node.
- The value at each index represents the next node to visit.

Since there are `n + 1` numbers ranging from `1` to `n`, at least one number must appear more than once. This duplicate causes multiple indices to point to the same value, creating a **cycle** in the linked list.

To detect this cycle, we use **Floyd's Tortoise and Hare Algorithm**.

### Phase 1: Detect the Cycle

Two pointers are initialized:

- **Slow pointer (`i`)** moves one step at a time.
- **Fast pointer (`j`)** moves two steps at a time.

```
slow = nums[slow]
fast = nums[nums[fast]]
```

If a cycle exists, the two pointers will eventually meet inside the cycle.

### Phase 2: Find the Entrance of the Cycle

Once the pointers meet:

- Reset one pointer to the beginning.
- Move both pointers one step at a time.

The point where they meet again is the **entrance of the cycle**, which corresponds to the duplicate number.

### Example

Input:

```
nums = [1,3,4,2,2]
```

Linked List Representation:

```
0 → 1 → 3 → 2 → 4
          ↑     ↓
          └─────┘
```

The cycle begins at `2`, so the duplicate number is:

```
2
```

---

## Algorithm

1. Initialize two pointers:
   - `slow = nums[0]`
   - `fast = nums[0]`
2. Move:
   - `slow` by one step.
   - `fast` by two steps.
3. Continue until both pointers meet.
4. Reset one pointer to the start.
5. Move both pointers one step at a time.
6. The meeting point is the duplicate number.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - Each pointer traverses the array a constant number of times.

- **Space Complexity:** `O(1)`
  - Only two pointers are used.

---

## Key Idea

By interpreting the array as a linked list, the duplicate number naturally forms a cycle. Floyd's Cycle Detection algorithm efficiently identifies the cycle and its entry point without modifying the array or using extra memory, making it the optimal solution.
