<h2><a href="https://leetcode.com/problems/longest-substring-without-repeating-characters">3. Longest Substring Without Repeating Characters</a></h2><h3>Medium</h3><hr><p>Given a string <code>s</code>, find the length of the <strong>longest</strong> <span data-keyword="substring-nonempty"><strong>substring</strong></span> without duplicate characters.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abcabcbb&quot;
<strong>Output:</strong> 3
<strong>Explanation:</strong> The answer is &quot;abc&quot;, with the length of 3. Note that <code>&quot;bca&quot;</code> and <code>&quot;cab&quot;</code> are also correct answers.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;bbbbb&quot;
<strong>Output:</strong> 1
<strong>Explanation:</strong> The answer is &quot;b&quot;, with the length of 1.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;pwwkew&quot;
<strong>Output:</strong> 3
<strong>Explanation:</strong> The answer is &quot;wke&quot;, with the length of 3.
Notice that the answer must be a substring, &quot;pwke&quot; is a subsequence and not a substring.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>s</code> consists of English letters, digits, symbols and spaces.</li>
</ul>

## Approach

The solution uses the **Sliding Window** technique to maintain the longest substring containing only unique characters.

Two pointers define the current window:

- `i` → Left boundary of the window.
- `j` → Right boundary of the window.

A frequency array of size `256` keeps track of the characters currently present in the window.

The window is expanded by moving the `j` pointer one character at a time.

- If the current character is **not already present** in the window, it is simply added.
- If the character is already present, the left pointer `i` is moved forward, removing characters from the window until the previous occurrence of the current character is removed.
- The current character is then inserted, restoring the property that all characters inside the window are unique.

After each iteration, the window length (`j - i`) is computed and the maximum length is updated.

---

## Example

Input:

```
s = "abcabcbb"
```

Window progression:

```
[a]
```

```
[ab]
```

```
[abc]
```

Encounter another `'a'`:

```
abc

↓

Remove 'a'

↓

[bca]
```

Continue expanding:

```
[bcab]

↓

[cab]

↓

[abc]
```

The maximum window obtained is:

```
"abc"
```

Length:

```
3
```

---

## Algorithm

1. Initialize two pointers:
   - `i = 0`
   - `j = 0`
2. Create a frequency array to track characters inside the current window.
3. While `j < n`:
   - If the current character already exists in the window:
     - Move `i` forward, removing characters until the previous occurrence of the current character is removed.
   - Add the current character to the window.
   - Move `j` forward.
   - Update the maximum window length.
4. Return the maximum length found.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - Each character is added to and removed from the sliding window at most once.

- **Space Complexity:** `O(1)`
  - A fixed-size frequency array of 256 characters is used.

---

## Key Idea

The sliding window always represents a substring with **no repeating characters**. Whenever a duplicate character is encountered, the left boundary is advanced just enough to remove its previous occurrence, allowing the window to continue expanding. This ensures that each character is processed at most twice, resulting in an efficient linear-time solution.
