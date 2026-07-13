<h2><a href="https://leetcode.com/problems/reverse-words-in-a-string">151. Reverse Words in a String</a></h2><h3>Medium</h3><hr><p>Given an input string <code>s</code>, reverse the order of the <strong>words</strong>.</p>

<p>A <strong>word</strong> is defined as a sequence of non-space characters. The <strong>words</strong> in <code>s</code> will be separated by at least one space.</p>

<p>Return <em>a string of the words in reverse order concatenated by a single space.</em></p>

<p><b>Note</b> that <code>s</code> may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;the sky is blue&quot;
<strong>Output:</strong> &quot;blue is sky the&quot;
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;  hello world  &quot;
<strong>Output:</strong> &quot;world hello&quot;
<strong>Explanation:</strong> Your reversed string should not contain leading or trailing spaces.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;a good   example&quot;
<strong>Output:</strong> &quot;example good a&quot;
<strong>Explanation:</strong> You need to reduce multiple spaces between two words to a single space in the reversed string.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> contains English letters (upper-case and lower-case), digits, and spaces <code>&#39; &#39;</code>.</li>
	<li>There is <strong>at least one</strong> word in <code>s</code>.</li>
</ul>

<p>&nbsp;</p>
<p><b data-stringify-type="bold">Follow-up:&nbsp;</b>If the string data type is mutable in your language, can&nbsp;you solve it&nbsp;<b data-stringify-type="bold">in-place</b>&nbsp;with&nbsp;<code data-stringify-type="code">O(1)</code>&nbsp;extra space?</p>

## Approach

The idea is to extract each word from the string and store it in a **stack**. Since a stack follows the **Last-In-First-Out (LIFO)** principle, popping the words produces them in reverse order.

While traversing the string:

- Consecutive spaces are ignored.
- Characters are collected to form a word.
- Whenever a space is encountered after a word, the completed word is pushed onto the stack.

After processing the entire string, any remaining word is also pushed onto the stack.

Finally, words are popped from the stack and concatenated with a single space between them to form the reversed string.

### Example

Input:

```
"  the   sky  is blue  "
```

Words extracted:

```
["the", "sky", "is", "blue"]
```

Stack (top at right):

```
the | sky | is | blue
```

Pop all elements:

```
blue → is → sky → the
```

Output:

```
"blue is sky the"
```

---

## Algorithm

1. Initialize an empty stack and an empty string to store the current word.
2. Traverse the input string:
   - If the character is not a space, append it to the current word.
   - If a space is encountered and the current word is non-empty:
     - Push the word onto the stack.
     - Clear the current word.
   - Ignore consecutive spaces.
3. Push the last word if it exists.
4. Pop every word from the stack and append it to the answer string with a single space.
5. Remove the leading space and return the final string.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - The string is traversed once, and each word is pushed and popped exactly once.

- **Space Complexity:** `O(n)`
  - In the worst case, the stack stores all words from the string.

---

## Key Idea

A stack naturally reverses the order of words due to its **Last-In-First-Out (LIFO)** behavior. By extracting each word while ignoring extra spaces and then popping them in reverse order, the required output is obtained while maintaining a single space between consecutive words.
