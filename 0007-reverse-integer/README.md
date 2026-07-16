<h2><a href="https://leetcode.com/problems/reverse-integer">7. Reverse Integer</a></h2><h3>Medium</h3><hr><p>Given a signed 32-bit integer <code>x</code>, return <code>x</code><em> with its digits reversed</em>. If reversing <code>x</code> causes the value to go outside the signed 32-bit integer range <code>[-2<sup>31</sup>, 2<sup>31</sup> - 1]</code>, then return <code>0</code>.</p>

<p><strong>Assume the environment does not allow you to store 64-bit integers (signed or unsigned).</strong></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> x = 123
<strong>Output:</strong> 321
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> x = -123
<strong>Output:</strong> -321
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> x = 120
<strong>Output:</strong> 21
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= x &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

## Approach

The solution reverses the digits of the given integer by repeatedly extracting the last digit and appending it to the result.

The process uses the following operations:

- **Extract the last digit:**

```text
digit = x % 10
```

- **Remove the last digit:**

```text
x = x / 10
```

- **Append the extracted digit to the reversed number:**

```text
result = result × 10 + digit
```

Since the reversed integer must fit within the **32-bit signed integer** range, an overflow check is performed before updating the result. If the reversed number exceeds the valid range, the function returns `0`.

---

## Example 1

Input:

```
x = 123
```

Processing:

```
ans = 0

↓

Extract 3

ans = 3

↓

Extract 2

ans = 32

↓

Extract 1

ans = 321
```

Output:

```
321
```

---

## Example 2

Input:

```
x = -123
```

Processing:

```
-123

↓

-321
```

Output:

```
-321
```

---

## Example 3

Input:

```
x = 120
```

Processing:

```
120

↓

12

↓

1
```

Output:

```
21
```

Leading zeros are naturally discarded during the reversal.

---

## Algorithm

1. Initialize the reversed number as `0`.
2. While the input number is not `0`:
   - Check for potential overflow.
   - Extract the last digit using `% 10`.
   - Append the digit to the reversed number.
   - Remove the last digit from the original number.
3. Return the reversed integer.
4. If an overflow occurs, return `0`.

---

## Complexity Analysis

- **Time Complexity:** `O(log₁₀ n)`
  - Each iteration processes one digit of the integer.

- **Space Complexity:** `O(1)`
  - Only a constant amount of extra memory is used.

---

## Key Idea

The integer is reversed by repeatedly taking its last digit and appending it to the result. By checking for overflow before each update, the algorithm ensures the reversed integer always remains within the 32-bit signed integer range while using constant extra space.
