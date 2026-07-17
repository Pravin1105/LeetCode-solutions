<h2><a href="https://leetcode.com/problems/valid-parentheses/">20. Valid Parentheses</a></h2><h3>Easy</h3><hr><p>Given a string <code>s</code> containing just the characters <code>&#39;(&#39;</code>, <code>&#39;)&#39;</code>, <code>&#39;{&#39;</code>, <code>&#39;}&#39;</code>, <code>&#39;[&#39;</code> and <code>&#39;]&#39;</code>, determine if the input string is valid.</p>

<p>An input string is valid if:</p>

<ol>
	<li>Open brackets must be closed by the same type of brackets.</li>
	<li>Open brackets must be closed in the correct order.</li>
	<li>Every close bracket has a corresponding open bracket of the same type.</li>
</ol>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;()&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;()[]{}&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;(]&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">false</span></p>
</div>

<p><strong class="example">Example 4:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;([])&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>
</div>

<p><strong class="example">Example 5:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;([)]&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">false</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists of parentheses only <code>&#39;()[]{}&#39;</code>.</li>
</ul>

## Approach

The solution uses a **stack** to keep track of opening brackets while traversing the string.

Whenever an opening bracket is encountered:

- Push it onto the stack.

When a closing bracket is encountered:

- Check whether the stack is non-empty.
- Verify that the top of the stack contains the corresponding opening bracket.
- If it matches, pop the opening bracket from the stack.
- Otherwise, the string is invalid.

After processing the entire string:

- If the stack is empty, every opening bracket has been matched with its corresponding closing bracket.
- Otherwise, some opening brackets remain unmatched, so the string is invalid.

---

## Example 1

Input:

```
s = "()[]{}"
```

Processing:

```
(

↓

)

Stack: Empty

↓

[

↓

]

Stack: Empty

↓

{

↓

}

Stack: Empty
```

Output:

```
true
```

---

## Example 2

Input:

```
s = "([)]"
```

Processing:

```
(

↓

[
```

Encounter:

```
)
```

Top of the stack:

```
[
```

The brackets do not match.

Output:

```
false
```

---

## Algorithm

1. Create an empty stack.
2. Traverse each character in the string.
3. If the character is an opening bracket:
   - Push it onto the stack.
4. Otherwise (closing bracket):
   - If the stack is empty, return `false`.
   - If the top of the stack is the matching opening bracket:
     - Pop it.
   - Otherwise, return `false`.
5. After the traversal, return `true` if the stack is empty; otherwise return `false`.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - Each bracket is pushed onto and popped from the stack at most once.

- **Space Complexity:** `O(n)`
  - In the worst case, all characters are opening brackets and are stored in the stack.

---

## Key Idea

A stack naturally models the nested structure of parentheses. Every opening bracket is stored until its corresponding closing bracket is encountered. If every closing bracket matches the most recently opened bracket and no unmatched brackets remain, the string is valid.
