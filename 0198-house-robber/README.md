<h2><a href="https://leetcode.com/problems/house-robber">198. House Robber</a></h2><h3>Medium</h3><hr><p>You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and <b>it will automatically contact the police if two adjacent houses were broken into on the same night</b>.</p>

<p>Given an integer array <code>nums</code> representing the amount of money of each house, return <em>the maximum amount of money you can rob tonight <b>without alerting the police</b></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,7,9,3,1]
<strong>Output:</strong> 12
<strong>Explanation:</strong> Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 400</code></li>
</ul>

# House Robber - Dynamic Programming

## Approach 1: Dynamic Programming (DP Array)

The key observation is that for every house, there are only two choices:

- **Rob the current house** and add its money to the maximum amount robbed up to the house two positions before.
- **Skip the current house** and keep the maximum amount robbed up to the previous house.

Let `dp[i]` represent the maximum money that can be robbed from the first `i + 1` houses.

The recurrence relation is:

```text
dp[i] = max(dp[i-1], nums[i] + dp[i-2])
```

### Example

```
nums = [2, 7, 9, 3, 1]

dp[0] = 2
dp[1] = 7
dp[2] = max(7, 2 + 9) = 11
dp[3] = max(11, 7 + 3) = 11
dp[4] = max(11, 11 + 1) = 12

Answer = 12
```

### Algorithm

1. Handle arrays of size 1 and 2 separately.
2. Initialize:
   - `dp[0] = nums[0]`
   - `dp[1] = max(nums[0], nums[1])`
3. For every remaining house:
   - Compute `dp[i] = max(dp[i-1], nums[i] + dp[i-2])`.
4. Return `dp[n-1]`.

### Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

# Approach 2: Space-Optimized Dynamic Programming

Notice that the DP transition only depends on the previous two states:

```text
dp[i-1] and dp[i-2]
```

Therefore, storing the entire DP array is unnecessary.

This implementation maintains only two variables:

- `sum0` → DP value for the latest even-indexed state.
- `sum1` → DP value for the latest odd-indexed state.

Depending on whether the current index is even or odd, the corresponding variable is updated using the same DP recurrence.

```text
current = max(previous, nums[i] + two_steps_back)
```

The final answer is the maximum of the two maintained states.

### Algorithm

1. Handle the cases where `n` is 1 or 2.
2. Initialize:
   - `sum0 = nums[0]`
   - `sum1 = max(nums[0], nums[1])`
3. Traverse the remaining houses.
4. Update:
   - `sum0` for even indices.
   - `sum1` for odd indices.
5. Return `max(sum0, sum1)`.

### Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Key Idea

The problem follows the classic Dynamic Programming pattern:

> At each house, choose the better of:
>
> - **Robbing it** (`current value + best till i-2`)
> - **Skipping it** (`best till i-1`)

The first approach stores every DP state, while the second optimizes the space requirement by keeping only the states needed for future computations.
